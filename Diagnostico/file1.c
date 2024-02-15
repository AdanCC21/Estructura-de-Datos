#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libad.h"
#include "list.h"

struct datos {
    char name[30];
    char app[30];
    char apm[30];
    int mat;
    struct datos *next;
    struct datos *previous;
};

//Prototipos
void start (struct datos** head, char name[],char app[], char apm[], int mat);
void end (struct datos** head, char name[],char app[], char apm[], int mat);
void print(struct datos* head);
//Main
int main()
{
    struct datos *list = NULL;//Lista declarada vacia al inicio
    char name[30], app[30], apm[30];
    int mat,op;
    do
    {
        system("CLS");
        printf("Ingrese los datos correspondientes\nNombe\n");
        gets(name);
        printf("Apellido Paterno\n");
        gets(app);

        printf("Apellido Materno\n");
        gets(apm);
        printf("Matricula\n");
        mat=valid("Fuera de rango",300000,399999);

        printf("Al inicio o al final del nodo\n1.-Inicio\t2.-Final\n");
        op=valid("fuera de rango",1,3);
        if(op==1)
        {
            start(&list,name,app,apm,mat);
        }
        if(op==2)
        {
            end(&list,name,app,apm,mat);
        }
        if(op==3)
        {
            int position;
            printf("En que posicion\n");
            position=valid("fuera de rango",1,100);
            specific_position(&list,name,app,apm,mat,position);
        }

        print(list);
        system("PAUSE");
        system("CLS");
        printf("desea repetir?\n1.-Salir\t2.-Repetir\n");
        op=valid("Fuera de rango",1,2);

    }while(op!=1);
    
    return 0;
}

//Funciones
void start (struct datos** head, char name[],char app[], char apm[], int mat)
{
    //reservo memoria
    struct datos *newnodo = (struct datos*)malloc(sizeof(struct datos));
    //paso los datos al nuevo nodo
    strcpy(newnodo->name,name);
    strcpy(newnodo->app,app); 
    strcpy(newnodo->apm,apm);
    newnodo->mat=mat;

    //Posiciono el nuevo nodo
    newnodo->next = *head;
    newnodo->previous = NULL;

    //Hace que la cabeza apunte al nuevo nodo, haciendo que el inicio sea el nuevo nodo que creamos
    if(*head != NULL)
    {
        (*head)->previous = newnodo;
    }
    *head = newnodo;
}

void end (struct datos** head, char name[],char app[], char apm[], int mat)
{
    struct datos *newnodo = (struct datos*)malloc(sizeof(struct datos));
    strcpy(newnodo->name,name);
    strcpy(newnodo->app,app);
    strcpy(newnodo->apm,apm);
    newnodo->mat=mat;
    newnodo->previous=NULL;
    newnodo->next=NULL;

    if(*head==NULL)
    {
        *head=newnodo;
    }
    else
    {
        struct datos *last = *head;
        while(last->next!=NULL)
        {
            last=last->next;
        }
        last->next=newnodo;
        newnodo->previous=last;
    }

}

void specific_position (struct datos** head, char name[],char app[], char apm[], int mat, int position)
{
    struct datos *newnodo = (struct datos *) malloc(sizeof(struct datos));
    strcpy(newnodo->name,name);
    strcpy(newnodo->app,app); 
    strcpy(newnodo->apm,apm);
    newnodo->mat=mat;
    
    int i=0;
    struct datos *temp = head;

    if(position>1)
    {
        while(i<position)
        {
            
        }
    }
    else
    {
        start(&head,name,app,apm,mat);
    }

}

void print(struct datos* head)
{
    struct datos *temp = head;
    while(temp !=NULL)
    {
        printf("%-10s | %-10s | %-10s | %-10d\n",temp->name,temp->app,temp->apm,temp->mat);
        temp=temp->next;
    }
}

