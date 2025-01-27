/*
 * joaquin.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Usuario
 */

#ifndef JOAQUIN_H_
#define JOAQUIN_H_



#endif /* JOAQUIN_H_ */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/// @brief imprime por pantalla una lista de opciones de informes, le pide al usuario que ingrese una opcion y la retorna
///
/// @return int retorna la opcion ingresada si puedo guardarla, devuelve -1 si no lo logro
int menuInformes(void);

/// @brief imprime por pantalla una lista de opciones, le pide al usuario que ingrese una opcion y la guarda en una variable
///
/// @param opcion int* direccion de memoria donde se guarda la opcion
/// @return int retorna 1 si pudo guardar la opcion y -1 si no lo logro
int menuOpciones(int* opcion);

/// @brief imprime por pantalla una lista de opciones de modificacion, le pide al usuario que ingrese una opcion y la retorna
///
/// @return int retorna la opcion ingresada si pudo guardarla, devuelve -1 si no lo logro
int menuModificaciones(void);


/** \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio en memoria donde se dejara el resultado de la funcion
 * \param mensaje char* El mensaje a ser mostrado
 * \param mensajeError char* El mensaje de error a ser mostrado
 * \param minimo int El numero minimo a ser aceptado
 * \param maximo int El numero maximo a ser aceptado
 * \param reintentos int Cantidad de reintentos permitidos
 * \return int Retorna 1 si se obtuvo el numero o -1 si no
 *
 */
int joaquin_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado int* Puntero al espacio en memoria donde se dejara el resultado de la funcion
/// @param mensaje char* El mensaje a ser mostrado
/// @param mensajeError char* El mensaje de error a ser mostrado
/// @param minimo int El numero minimo a ser aceptado
/// @param maximo int El numero maximo a ser aceptado
/// @param reintentos int Cantidad de reintentos permitidos
/// @return int Retorna 1 si se obtuvo el numero o -1 si no
int joaquin_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/// @brief Solicita un caracter al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado int* Puntero al espacio en memoria donde se dejara el resultado de la funcion
/// @param mensaje char* El mensaje a ser mostrado
/// @param mensajeError char* El mensaje de error a ser mostrado
/// @param opcion1 char primera opcion a ser aceptada
/// @param opcion2 char segunda opcion a ser aceptada
/// @param reintentos int Cantidad de reintentos permitidos
/// @return int Retorna 1 si se obtuvo el numero o -1 si no
int joaquin_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char opcion1, char opcion2, int reintentos);

/// @brief Solicita una cadena de caracteres al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado int* Puntero al espacio en memoria donde se dejara el resultado de la funcion
/// @param mensaje char* El mensaje a ser mostrado
/// @param mensajeError char* El mensaje de error a ser mostrado
/// @param sizeNombre int tama�o limite
/// @param reintentos int Cantidad de reintentos permitidos
/// @return int Retorna 1 si se obtuvo el numero o -1 si no
int joaquin_getString(char* pResultado, char* mensaje, char* mensajeError, int sizeNombre, int reintentos);

