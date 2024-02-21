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
    int op = 0,ind=0;
    char name[20],
        app[20];
    
    do
    {
        printf("Que accion quiere realizar?\n");
        printf("1.-Inicio\t2.-Final\t3.-Posicion\t4.-Imprimir\t0.-Salir\n");
        op=valid("Fuera de rango",0,4);
        
        switch(op)
        {
            case 1:
            printf("Ingrese su nombre\n");
                gets(name);

                printf(" Ingrese su apellido\n");
                gets(app);
                ind++;
                create_bin(&list,name,app,ind);
            break;
            case 2:
            printf("Ingrese su nombre\n");
                gets(name);

                printf(" Ingrese su apellido\n");
                gets(app);
                ind++;
                c_end(&list,name,app,ind);            

            break;
            case 3:

            break;
            case 4:
                print(list);
            case 0:
            break;
        }

    } while (op!=0);
    

}

void create_bin(struct datos **nodo,char name[],char app[],int ind)
{
    datos* newnodo = (struct datos*)malloc(sizeof(datos));
    strcpy(newnodo->name,name);
    strcpy(newnodo->app,app);
    newnodo->id=ind;

    newnodo->siguiete=*nodo;
    newnodo->anterior=NULL;

    *nodo=newnodo;

}

void c_end(struct datos** nodo, char name[],char app[],int ind)
{
    datos* newnodo = (struct datos*)malloc(sizeof(datos));
    strcpy(newnodo->name,name);
    strcpy(newnodo->app,app);
    newnodo->id=ind;

    newnodo->siguiete=NULL;
    if(*nodo ==NULL)
    {
        *nodo=newnodo;
    }
    else
    {
        struct datos *temp = *nodo;
        while(temp->siguiete!=NULL)
        {
            temp=temp->siguiete;
        }
        temp->siguiete=newnodo;
        newnodo->anterior=temp;
        
    }

}

void specific_position()
{
    
}

void print(struct datos* head)
{
    struct datos *temp = head;
    while(temp !=NULL)
    {
        printf("%-10s | %-10s | %-10d\n",temp->name,temp->app,temp->id);
        temp=temp->siguiete;
    }
}

