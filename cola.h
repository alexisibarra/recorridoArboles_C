/*
 * =====================================================================================
 *
 *       Filename:  cola.h
 *
 *    Description:  Archivo de cabecera para la implementacion de una cola de árboles
 *
 *        Version:  1.0
 *        Created:  27/01/13 10:31:18
 *       Modified:  27/01/13 10:31:27
 *       Compiler:  gcc
 *
 *         Author:  Alexis Ibarra (ai), ar.ibarrasalas@gmail.com
 *   Organization:  Universidad Simón Bolívar 
 *
 * =====================================================================================
 */

#include "arbol.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Celda{
   Arbol elemento;
 	 struct Celda *siguiente;
 } celda;

typedef struct {
	celda *ant,*post;
} tcola;

typedef tcola *cola;
//
//struct NodoC {
//       Arbol Elem;
//       struct NodoC *sig;
//};
//
//typedef struct NodoC NODOC;
//typedef struct NodoC *Cola;
//
///* Prototipos de funciones definidas en listas.c */
////extern cola Insertar(cola a, NODO *, char[]);
//extern Cola nuevaCola();
//extern void encolar(Cola);
//extern void desencolar(Cola);

extern cola Crear();
extern int vacia (cola); 
extern void QUITAR_DE_COLA (cola);
extern void PONER_EN_COLA (Arbol,cola);
