#include "palindromo.h"

int main(void)
{
	int estado = 0;	//Variable de estado.
	printf("Bienvenido! Tenga en cuenta que el maximo de letras que se pueden ingresar es 100.\nPara salir del programa ingrese 'EXIT' (sin espacios y en mayusculas).\n");
	do
	{
		printf("Ingrese la frase a analizar: \n");
		char pal[MAX];	//Maxima cantidad de letras = 100.
		char copia[MAX];	//Copia del arreglo para imprimir luego.
		int len = tecl(pal, copia);	//Se cargan los dos arreglos y se obtiene la longitud del arreglo pal.

		estado = check(copia);
		if ((estado != EXIT) && (len != ERR))	//Si lo ingresado no es valido o se ingreso EXIT, no analiza el string.
		{
			char *pi = &(pal[0]);	//Apunta el primer puntero al primer elemento.
			char *pf = &(pal[len -1]);	//Apunta el segundo puntero al ultimo elemento.

			int value = is_capicua(pi, pf);
			if (value == CAPI)	//Es capicua.
			{
				printf("La frase: '%s', es un palindromo.\n", copia);
			}
			else	//No es capicua.
			{
				printf("La frase: '%s', NO es un palindromo.\n", copia);
			}
		}
	}
	while (estado != EXIT);	//Si no se ingresa el comando de salida, permite volver a ingresar otro string.

	printf("Ha finalizado el programa.\n");

	return 0;
}

int check (char arr1[])
{
	int rta = 0, i, fsm = 0;
	char exit[] = {"EXIT"};	//Defino un arreglo con la palabra EXIT.

	for (i = 0; ( (i <= 4) && (fsm != ERR) ); ++i)	//Compara con EXIT.
	{
		if (arr1[i] == exit[i])	//Si son iguales.
		{
			rta = EXIT;
		}
		else	//Si no es EXIT.
		{
			rta = 0;
			fsm = ERR;	//Cambia el estado para salir de la funcion.
		}
	}

	return rta;
}

int tecl(char arr[], char copia[])
{
	char c = getchar();
	int i = 0;
	int cont = 0;
	while ((c != '\n') && (i < 100))	//Carga las primeras 100 letras. 
	{
		copia[i] = c;	//Guarda lo ingresado en un arreglo copia para luego imprimirla.

		if ((c == ' ') || (c == ',') || (c == '.'))	//Saltea los signos de puntuacion.
		{
			c = getchar();
		}
		else
		{
			if ((c >= 'A') && (c <= 'Z'))	//Si son letras mayusculas las transforma a minuscula.
			{
				c += ('a' - 'A');    //Transforma mayuscula a minuscula
			}
			arr[cont] = c;	//Carga el caracter.
			++cont;
			c = getchar();
		}

		++i;
	}

	arr[cont] = 0;	//Pone terminadores.
	copia[i] = 0;
	
	if (c != '\n')	//Si hay mas de 100 caracteres.
	{
		while (c != '\n')	//Saca todos los caracteres de mas.
		{
			c = getchar();
		}
		cont = ERR;	//Informa del error.
		printf("Se excedio el limite de letras posibles a ingresar.\n");
	}

	return cont;
}

int is_capicua(char* p1, char *p2)
{
	if (p2 <= p1)	//Caso base, los punteros apuntan al mismo elemento o estan al lado.
	{
		return 1;
	}
	else
	{

		if (*p1 == *p2)	//Caso recursiva, si los elementos a los que apunta.
		{
			return is_capicua(++p1, --p2);	//Llama a la funcion con los punteros apuntando al elemento siguiente/anterior.
		}
		else
		{
			return 0;
		}
	}
}
