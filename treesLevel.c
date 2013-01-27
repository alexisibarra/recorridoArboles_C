/*
 * =====================================================================================
 *
 *       Filename:  treesLevel.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/01/13 11:49:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alexis Ibarra (ai), ar.ibarrasalas@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	Arbol a = nuevoArbol();
//	a->Elem=2;
	a->izq	=	nuevoArbol(a);
	Imprimir(a);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

