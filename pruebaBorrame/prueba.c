/* Implementación de una cola mediante lista enlazada circular */
/* ----------------------------------------------------------- */

#include "arbol.h"
#include <stdio.h>
#include <stdlib.h>

  /* declaracion */
  /* ----------- */
struct tcola
{
  int clave;
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

void encolar(struct tcola **cola, int elem)
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

void desencolar(struct tcola **c1, int *elem)
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

  /* Programa de prueba */
  /* ------------------ */
#include <stdio.h>

int main(void)
{
  struct tcola *cola;
  int elem;

  crear(&cola);
  if (vacia(cola)) printf("\nCola vacia!");
  encolar(&cola, 3);
  desencolar(&cola, &elem) ;
  printf("%d",elem) ;

  return 0;
}
