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
	printf("Elem: %d\n", a->Elem);
}

Arbol
ramaIzq(Arbol a)
{
	return a->izq;
}

Arbol
ramaDer(Arbol a)
{
	return a->der;
}


void
Insertar(Arbol a, int elem, char *camino)
{
	char *siguiente = (char*)cabeza(camino);
	char *resto = (char*)cola(camino);
	if (strcmp(siguiente,"I")==0){
		printf("Izquierda\n");
		Insertar(a,elem,resto);
	}
	if (strcmp(siguiente,"D")==0 ) {
		printf("Derecha\n");
		Insertar(a,elem,resto);
	}
	if (strcmp(siguiente,"")==0 ) {
		printf("Insertar elem\n");
	}
}

///* 
// * ===  FUNCTION  ======================================================================
// *       Nombre:  EliminarEst
// *  Descripción:  Elimina un estudiante de la lista identificado por su carnet.
// *  							Si el estudiante no se encuentra en la lista ésta no se modifica y se 
// *  							indica al usuario.
// *			Entrada:	Lista l en la cual se eliminará el estudiante.
// *								Entero Carnet del estudiante a eliminar
// *			 Salida:  Lista con la eliminación realizada
// * =====================================================================================
// */
//Lista
//EliminarEst (Lista l, int Carnet)
//{
//  Lista Temp, anterior;
//
//  if (l == NULL)
//    return NULL;		/* lista vacia */
//  if (Carnet == l->Carnet)
//    {				/* Caso especial: el empleado a
//				   eliminar esta de primero */
//      Temp = l;
//      l = l->proximo;		/* la lista empieza ahora en el segundo */
//      free (Temp->Nombre);	/* libera espacio del Nombre primero! */
//      free (Temp);		/* libera espacio de Empleado eliminado */
//      return l;
//    }
//  else
//    {				/* empleado no esta de primero */
//      anterior = l;
//      Temp = l->proximo;
//      /* Ahora recorre la lista buscando por el campo  Cedula */
//      while (Temp != NULL && Temp->Carnet != Carnet)
//	{
//	  anterior = Temp;
//	  Temp = Temp->proximo;
//	}
//    }
//  if (Temp != NULL)
//    {				/* Encontro empleado con esa cedula */
//      anterior->proximo = Temp->proximo;
//      free (Temp->Nombre);	/* libera espacio del Nombre primero! */
//      free (Temp);		/* libera espacio de Empleado eliminado */
//      return l;
//    }
//  else
//    {				/* No se encontro empleado con esa cedula */
//      printf ("\n\nEste estudiante no se encuentra en la nomina\n\n");
//      return l;
//    }
//}
//
///* 
// * ===  FUNCTION  ======================================================================
// *       Nombre:  Consultar
// *  Descripcion:  Lista todos los estudiantes con nora mayor a un corte de notas
// *  		Entrada:  Lista l a imprimir
// *  							Entero corte para el corte de nota
// * =====================================================================================
// */
///* Consultar
// * Imprime en pantalla los datos de todos los empleados existentes
// * l: lista a imprimir
// */
//void
//Consultar (Lista l, int corte)
//{
//  if (l == NULL)
//    {
//      printf ("\n\nNo hay estudiantes registrados.\n\n");
//    }
//  else
//    {
//      printf ("\n\nLista de estudiantes registrados: \n\n");
//      while (l != NULL && l->Nota > corte)
//	{
//	  printf ("%s%s\n", "Nombre: ", l->Nombre);
//	  printf ("%s%d\n", "Nota: ", l->Nota);
//	  printf ("%s%d\n", "Carnet: ", l->Carnet);
//	  if (l->proximo != NULL)
//	    {
//	  		printf ("--------------------------------------\n");
//	      l = l->proximo;
//	    }
//	  else
//	    {
//	      printf ("\n\n\n");
//	      return;
//	    }
//	}
//    }
//}
///* ===  FUNCTION  ======================================================================
// *       Nombre:  EliminarEst
// *  Descripción:  Elimina un estudiante de la lista identificado por su carnet.
// *  							Si el estudiante no se encuentra en la lista ésta no se modifica y se 
// *  							indica al usuario.
// *			Entrada:	Lista l en la cual se eliminará el estudiante.
// *								Entero Carnet del estudiante a eliminar
// *			 Salida:  Lista con la eliminación realizada
// * =====================================================================================
// */
//int
//Verificar (Lista l, int Carnet)
//{
//  Lista Temp;
//  if (l == NULL)
//    return 0;	
//  if (Carnet == l->Carnet)
//    {
//      return 1;
//    }
//  else
//    {	
//      Temp = l->proximo;
//      while (Temp != NULL && Temp->Carnet != Carnet)
//				{
//					Temp = Temp->proximo;
//				}
//			if (Temp->Carnet == Carnet){
//				return 1;
//			}
//    }
////  if (Temp != NULL)
////    {				/* Encontro empleado con esa cedula */
////      anterior->proximo = Temp->proximo;
////      free (Temp->Nombre);	/* libera espacio del Nombre primero! */
////      free (Temp);		/* libera espacio de Empleado eliminado */
////      return l;
////    }
////  else
////    {				/* No se encontro empleado con esa cedula */
////      printf ("\n\nEste estudiante no se encuentra en la nomina\n\n");
////      return l;
////    }
//}
