#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libad.h"
#include "list.h"

typedef struct datos{
    char name[30];
    char app[30];
    int id;

    struct datos *siguiete;
    struct datos *anterior;
}datos;



int main()
{
    struct datos *list = NULL;
    int op = 0;
    do
    {
        printf("Que accion quiere realizar?\n");
        printf("1.-Inicio\t2.-Final\t3.-Posicion\t0.-Salir\n");
        op=valid("Fuera de rango",0,3);
        
        switch(op)
        {
            case 1:

            break;
            case 2:

            break;
            case 3:

            break;
            case 0:

        }

    } while (op!=0);
    

}

datos *create_bin(struct datos *nodo)
{
    datos* newnodo = (struct datos*)malloc(sizeof(datos));
    newnodo->siguiete=NULL;
    newnodo->anterior=NULL;
    nodo->siguiete=newnodo;
    return newnodo;
}
