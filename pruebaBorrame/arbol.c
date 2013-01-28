/*
 * =====================================================================================
 *
 *       Filename:  lista.c
 *
 *    Description:  Implementación de tipo Arbol binario de enteros
 *
 *        Version:  1.0
 *        Created:  18/01/13 21:41:16
 *       Modified:  27/01/13 10:25:09
 *       Compiler:  gcc
 *
 *         Author:  Alexis Ibarra (ai), ar.ibarrasalas@gmail.com
 *   Organization: 	Universidad Simón Bolívar 
 *
 * =====================================================================================
 */
#include "arbol.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  nuevoArbol
 *  Description:  Crea un nuevo árbol unitario y lo inicializa con su elementto en 0
 *  							y dos ramas nulas
 * =====================================================================================
 */
Arbol
nuevoArbol()
{
	Arbol Temp = malloc (sizeof (NODO));
	if (Temp==NULL){
		fprintf(stderr,"Se produjo un error de manejo de memoria. Fin del programa\n");
		exit(EX_DATAERR);
	}
	Temp->Elem=-1;
	Temp->izq=NULL;
	Temp->der=NULL;
	return Temp;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  nuevoNodo
 *  Description:  Crea un nuevo árbol unitario y lo inicializa con su elementto en 0
 *  							y dos ramas nulas
 * =====================================================================================
 */
Arbol
nuevoNodo(int elem)
{
	Arbol Temp = malloc (sizeof (NODO));
	if (Temp==NULL){
		fprintf(stderr,"Se produjo un error de manejo de memoria. Fin del programa\n");
		exit(EX_DATAERR);
	}
	Temp->Elem=elem;
	Temp->izq=NULL;
	Temp->der=NULL;
	return Temp;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Imprimir
 *  Description:  Imprime el arbol en recorrido preorden 
 * =====================================================================================
 */
void preOrden(Arbol a){
  if (a != NULL) {
		printf("%d\n",a->Elem);
    preOrden(a->izq);
    preOrden(a->der);
  }
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Imprimir
 *  Description:  Imprime el arbol en recorrido postorden
 * =====================================================================================
 */
void postOrden(Arbol a){
  if (a != NULL) {
    preOrden(a->izq);
    preOrden(a->der);
		printf("%d\n",a->Elem);
  }
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Imprimir
 *  Description:  Imprime el arbol en recorrido inorden
 * =====================================================================================
 */
void inOrden(Arbol a){
  if (a != NULL) {
    preOrden(a->izq);
		printf("%d\n",a->Elem);
    preOrden(a->der);
  }
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Imprimir
 *  Description:  Imprime el arbol seleccionando el tipo de recorrido 
 * =====================================================================================
 */
void
Imprimir (Arbol a, int n){
	switch ( n ) {
		case 0:	
			preOrden(a);
			break;

		case 1:	
			postOrden(a);
			break;

		case 2:	
			inOrden(a);
			break;

		default:	
			break;
	}				/* -----  end switch  ----- */
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ramaIzq
 *  Description:  Devuelve la rama izquierda del arbol
 * =====================================================================================
 */
Arbol
ramaIzq(Arbol a)
{
	return a->izq;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ramaDer
 *  Description:  Devuelve la rama derecha del arbol
 * =====================================================================================
 */
Arbol
ramaDer(Arbol a)
{
	return a->der;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Insertar
 *  Description:  Inserta un entero positivo en el arbol
 * =====================================================================================
 */
void
Insertar(Arbol a, int elem, char *camino)
{
	char *siguiente = (char*)getCabeza(camino);
	char *resto = (char*)getCola(camino);
	if (strcmp(siguiente,"I")==0){
		if (a->izq==NULL){
			a->izq=nuevoArbol();
		}
		Insertar(a->izq,elem,resto);
	}
	if (strcmp(siguiente,"D")==0 ) {
		if (a->der==NULL){
			a->der=nuevoArbol();
		}
		Insertar(a->der,elem,resto);
	}
	if (strcmp(siguiente,"")==0) {
		a->Elem=elem;
	}
}

