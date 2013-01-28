/*
 * =====================================================================================
 *
 *       Filename:  utiles.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/01/13 21:59:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alexis Ibarra (ai), ar.ibarrasalas@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "utiles.h"
#include <stdlib.h>
#include <string.h>

char*
getCabeza (char* string)
{
	return strndup(string+0, 1);
}

char*
getCola (char* string)
{
	return strndup(string+1,strlen(string));
}

