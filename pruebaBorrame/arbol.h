/*
 * =====================================================================================
 *
 *       Filename:  arbol.h
 *
 *    Description:  Archivo de cabecera para la implementacion de un árbol binario de 
 *    							enteros
 *
 *        Version:  1.0
 *        Created:  18/01/13 21:33:46
 *       Modified:  18/01/13 21:33:52
 *       Compiler:  gcc
 *
 *         Author:  Alexis Ibarra (ai), ar.ibarrasalas@gmail.com
 *   Organization:  Universidad Simón Bolívar 
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Nodo {
       int Elem;
       struct Nodo *izq;
       struct Nodo *der;
};

typedef struct Nodo NODO;
typedef struct Nodo *Arbol;

/* Prototipos de funciones definidas en listas.c */
//extern Arbol Insertar(Arbol a, NODO *, char[]);
extern Arbol nuevoArbol();
extern Arbol ramaIzq(Arbol);
extern Arbol ramaDer(Arbol);
extern void Imprimir(Arbol,int);

