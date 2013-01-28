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
#include "amplitud.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  struct tcola *cola;
  Arbol a = nuevoArbol();
	Insertar(a,1,"");  	
	Insertar(a,2,"I");  	
	Insertar(a,3,"D");  	
	Insertar(a,4,"II");  	
	Insertar(a,5,"ID");  	
	Insertar(a,6,"DI");  	
	Insertar(a,7,"III");  	
	Insertar(a,8,"IID");  	
	Insertar(a,9,"IDD");  	

	amplitud(a);

	free(a);
	return EXIT_SUCCESS;
}
