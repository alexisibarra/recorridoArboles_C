/*
 * =====================================================================================
 *
 *       Filename:  cola.c
 *
 *    Description:  Implementación de tipo cola binario de enteros
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
#include "cola.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

cola nuevaCola () 
{
	cola C = malloc(sizeof(tcola));
	if (C==NULL){
		fprintf(stderr,"Se produjo un error de manejo de memoria. Fin del programa\n");
		exit(EX_DATAERR);
	}
	C->ant = C->post = (celda *)malloc(sizeof(celda));
	if (C->ant == NULL) 
		 error("Memoria insuficiente.");
	C->ant->siguiente = NULL;
	return C;
}

int vacia (cola C)  
{
	return(C->ant == C->post);
}

void encolar (Arbol a,cola C) 
 {
  C->post->siguiente = (celda *) malloc(sizeof(celda));
  if (C->post->siguiente == NULL) 
     error("Memoria insuficiente.");
  C->post = C->post->siguiente;
  C->post->elemento = a;
  C->post->siguiente = NULL;
 }

Arbol desencolar (cola C) 
{
	celda *aux;
	Arbol a;

	if (vacia(C))
		 error("Cola vacia.");
	aux = C->ant;
	a = C->ant->elemento;
//	printf("%d\n",a);
	C->ant = C->ant->siguiente;
	free(aux);
	return(a);
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  encolar
 *  Description:  
 * =====================================================================================
 */
//void
//encolar (cola c)
//{
////	return 0;
//}		/* -----  end of function encolar  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  desencolar
 *  Description:  
 * =====================================================================================
 */
//void
//desencolar (cola c)
//{
////	return 0;
//}		/* -----  end of function desencolar  ----- */

