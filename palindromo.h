/******************************************************************************
  @file     +palindromo.h+
  @brief    +Conjunto de constantes y libreria de stdio+
  @author   +Grupo 6+
******************************************************************************/
#ifndef PALINDROMO_H
#define PALINDROMO_H
/***********************************************************
			Headers
***********************************************************/
#include <stdio.h>
/***********************************************************
                        Prototipos
***********************************************************/
//is_capicua evalua el string ingresado.
int is_capicua(char *p1, char *p2);
//tecl recibe lo ingresado por la terminal.
int tecl(char arr[], char copia[]);
//check evalua si lo ingresado es el comando de salida.
int check (char arr[]);
/***********************************************************
			Constantes
***********************************************************/
#define MAX 101
#define EXIT -1
#define ERR -2
#define CAPI 1

#endif //PALINDROMO_H
