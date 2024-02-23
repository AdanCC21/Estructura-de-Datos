/*
    Gonzalez Ceseña Adan
    372799
    Estructura de datos
    22/02/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libad.h"


struct Nodo{
    char name[30];
    int ind;
    struct Nodo *next,*previous,*head;
};



//Prototipos
void menu ();

struct Nodo* crearNodo(char name[], int ind);
void del (struct Nodo **head,int p);
void destruir (struct Nodo *nodo);

void start (struct Nodo**head,char name[],int ind);
void end (struct Nodo **head,char name[],int ind);
void specific (struct Nodo **head, char name[],int ind,int p);
void pri (struct Nodo *head);

//Main
int main()
{
    int op=0,p=0,sp;
    char name[20];
    struct Nodo* Lista=NULL;
    do
    {
        system("CLS");
        menu();
        op=valid("Fuera de rango",0,5);
        switch(op)
        {
            case 1:
                printf("Ingrese su nombre\n");
                gets(name);
                p++;
                start(&Lista,name,p);
                system("PAUSE");
                break;
            case 2:
                printf("Ingrese su nombre\n");
                gets(name);
                p++;
                end(&Lista,name,p);
                system("PAUSE");
                break;
            case 3:
                printf("Ingrese su nombre\n");
                gets(name);
                printf("En que posicion quiere agregarlo\n");
                sp=valid("FUERA DE RANGO",0,p);

                specific(&Lista,name,p,sp);
                p++;
                break;
            case 4:
                pri(Lista);
                system("PAUSE");
                break;
            case 5:
                printf("Que posicion desea eliminar\n");
                sp=valid("FUERA DE RANGO",0,p);
                del(&Lista,sp);
                break;
            case 0:
                printf("Seguro que quieres salir?\n1.-Salir\t2.-continuar\n");
                op=valid("Fuera de rango",1,2);
                op--;
        }
        
    } while (op!=0);
    
}

void menu ()
{
    printf("Que desea hacer\n");
    printf("1.-Inicio\t2.-Final\t3.-Posicion especifica\t\t4.-Imprimir\t0.-salir\n");
}

struct Nodo* crearNodo(char name[], int ind)
{
    //Reserva de espacio
    struct Nodo*nd = (struct Nodo *)malloc(sizeof(struct Nodo));
    //Copiar datos hacia el nodo
    strcpy(nd->name,name);
    nd->ind=ind;
    //Posicionamos a nullos aunque se cambie proximamente
    nd->next=NULL;
    nd->previous=NULL;

    return nd;
}

void del (struct Nodo **head,int p)
{
    struct Nodo *temp=*head;
    int i=1;

    if(p==1)
    {
        *head=temp->next;
        destruir(temp);
    }
    else
    {
        while(i<p-1 && temp != NULL)
        {
            temp=temp->next;
            i++;
        }
        struct Nodo *temp2 = temp->next;
        temp->next=temp->next->next;
        destruir(temp2);

    }
    
}

void destruir (struct Nodo *nodo)
{
    free(nodo);
}

void start (struct Nodo**head,char name[],int ind)
{
    struct Nodo *nodo = crearNodo(name,ind);
    if(*head==NULL)
    {
        *head=nodo;
    }
    else
    {
        nodo->next=*head;
        nodo->previous=NULL;
        *head=nodo;
    }
}

void end (struct Nodo **head,char name[],int ind)
{
    struct Nodo *nodo = crearNodo(name,ind);
    if(*head==NULL)
    {
        *head=nodo;
    }
    else
    {
        struct Nodo *temp = *head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nodo;
        nodo->previous=temp;
        
    }
    
}

void specific (struct Nodo **head, char name[],int ind,int p)
{
    ind++;
    struct Nodo *nodo = crearNodo(name,ind);
    int i=1;
    if(*head==NULL)
    {
        *head=nodo;
    }
    else
    {
        struct Nodo *temp=*head;
        //Normalmente pondria i<p, pero esto hace que colocen el nodo despues de la posicion p, por lo tanto me coloco una posicion antes de la posicion deseada
        while(i<p-1 && temp!=NULL)
        {
            temp=temp->next;
            i++;
        }
        nodo->previous=temp;
        nodo->next=temp->next;
        temp->next=nodo;
        
    }
}

void pri (struct Nodo *head)
{
    struct Nodo *temp = head;
    while(temp!=NULL)
    {
        printf("Nombre %-10s | Id %-10d\n",temp->name,temp->ind);
        temp=temp->next;
    }
    destruir(temp);
}
