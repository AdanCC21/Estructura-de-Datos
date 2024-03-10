#include <stdio.h>
#include <stdlib.h>
#include "libad.h"

struct nodo {
    int dato;
    struct nodo *next;
};

struct nodo* crear(int dato)
{
    struct nodo*newnodo=(struct nodo*)malloc(sizeof(struct nodo));
    newnodo->next=NULL;
    newnodo->dato=dato;
    return newnodo;
}

void start (struct nodo **head,int dato){
    struct nodo *nodo=crear(dato);
    if(*head==NULL)
    {
        *head=nodo;
    }
    else
    {
        nodo->next=*head;
    }
    *head=nodo;
}

int main()
{
    struct nodo* lista=NULL;
    int op,dato;
    do
    {
        print("1.-inicio");
        op=valid("FIERA DE RANGO",0,1);
        switch(op)
        {
            case 1:
                print("Ingrese su dato");
                
        }
    } while (op!=0);
    
}