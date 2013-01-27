/*
 * =====================================================================================
 *
 *       Filename:  lista.c
 *
 *    Description:  Implementación de tipo Arbol binario de enteros
 *
 *        Version:  1.0
 *        Created:  18/01/13 21:41:16
 *       Modified:  18/01/13 21:41:23
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
 *  Description:  Imprime el arbol por niveles
 * =====================================================================================
 */
void
Imprimir (Arbol a){
//	printf("Elem: %d\n", a->Elem);
  if (a != NULL) {
		printf("%d\n",a->Elem);
    Imprimir(a->izq);
    Imprimir(a->der);
  }
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
	char *siguiente = (char*)cabeza(camino);
	char *resto = (char*)cola(camino);
	if (strcmp(siguiente,"I")==0){
		printf("Izquierda\n");
		a->izq=nuevoArbol();
		Insertar(a->izq,elem,resto);
	}
	if (strcmp(siguiente,"D")==0 ) {
		printf("Derecha\n");
		a->der=nuevoArbol();
		Insertar(a->der,elem,resto);
	}
	if (strcmp(siguiente,"")==0 ) {
		a->Elem=elem;
		printf("Insertar elem\n");
	}
}

