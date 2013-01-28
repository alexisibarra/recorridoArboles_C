/* Implementación de una cola mediante lista enlazada circular */
/* ----------------------------------------------------------- */

#include "amplitud.h"
#include <stdio.h>
#include <stdlib.h>

  /* declaracion */
  /* ----------- */
struct tcola
{
  Arbol clave;
  struct tcola *sig;
};

  /* prototipos y codificación */
  /* ------------------------- */

void crear(struct tcola **cola)
{
  *cola = NULL;
}

int vacia(struct tcola *cola)
{
  return (cola == NULL);
}

void encolar(struct tcola **cola, Arbol elem)
{
  struct tcola *nuevo;

  nuevo = (struct tcola *) malloc(sizeof(struct tcola));
  nuevo->clave = elem;
  if (*cola == NULL)
  nuevo->sig = nuevo;
  else {
    nuevo->sig = (*cola)->sig;
    (*cola)->sig = nuevo;
  }
  (*cola) = nuevo;
}

void desencolar(struct tcola **c1, Arbol *elem)
{
  struct tcola *aux;

  *elem = (*c1)->sig->clave;
  if ((*c1) == (*c1)->sig) {
    free(*c1);
    *c1 = NULL;
  }
  else {
    aux = (*c1)->sig;
    (*c1)->sig = aux->sig;
    free(aux);
  }
}

void amplitud(Arbol a)
{  
  struct tcola *cola;
	Arbol aux;    
	if (a != NULL) 
	{    
		crear(&cola);
		encolar(&cola,a);    
		while (!vacia(cola)) {      
			desencolar(&cola,&aux);      
			printf("%d\n",aux->Elem); //visitar(aux);      
			if (aux->izq != NULL)
				encolar(&cola,aux->izq);     
			if (aux->der!= NULL)
				encolar(&cola,aux->der);    
		}  
	}
}


