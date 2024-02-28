#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libad.h"

#define TRUE 1
#define FALSE 0

struct Datos
{
    char name[20];
    int mat;
    struct Datos *next,*previous;
};


//Prototipos
void menu ();
struct Datos *CrearNodo (char name[],int mat);
void del (struct Datos *head);
void eliminar (struct Datos **head,int p);

void start (struct Datos **head,char name[],int mat);
void top (struct Datos **head,char name[],int mat);
void specific (struct Datos **head,char name[],int mat,int p);

void pri(struct Datos *head);

int main()
{
    struct Datos *list = NULL;
    int v,
        p,
        mat;
    char name[20];
    do
    {
        system("CLS");
        menu();
        v=valid("FUERA DE RANGO",0,5);
        switch(v)
        {
            case 1:
                system("CLS");
                printf("INICIO\n");
                
                printf("NOMBRE\n");
                gets(name);
                
                system("CLS");
                printf("MATRICULA\n");
                mat=valid("FUERA DE RANGO",300000,399999);

                start(&list,name,mat);
                break;
            case 2:
                system("CLS");
                printf("FINAL\n");
                
                printf("NOMBRE\n");
                gets(name);
                
                system("CLS");
                printf("MATRICULA\n");
                mat=valid("FUERA DE RANGO",300000,399999);
                
                top(&list,name,mat);
                break;
            case 3:
                system("CLS");
                printf("Posicion especifica\n");
                
                printf("NOMBRE\n");
                gets(name);
                
                system("CLS");
                printf("MATRICULA\n");
                mat=valid("FUERA DE RANGO",300000,399999);

                system("CLS");
                printf("En que posicion\n");
                p=valid("FUERA DE RANGO",0,399999);

                specific(&list,name,mat,p);

                break;
            case 4:
                system("CLS");
                printf("En que posicion\n");
                p=valid("FUERA DE RANGO",0,399999);

                eliminar(&list,p);

                break;
            case 5:
                pri(list);
                system("PAUSE");
                break;
            case 0:
                printf("Seguro que quieres salir?\n1.-Salir\t2.-Continuar\n");
                v=valid("FUERA DE RANGO",1,2);
                v--;
        }
    } while (v!=FALSE);
    return 0;
}

void menu ()
{
    printf("MENU\n");
    printf("1.-Inicio\t2.-Final\t3.-Posicion\t4.-Eliminar\t5.-Imprimir\n");
}

struct Datos *CrearNodo (char name[],int mat)
{
    struct Datos *nodo = (struct Datos*)malloc(sizeof(struct Datos));
    strcpy(nodo->name,name);
    nodo->mat=mat;
    
    nodo->next=NULL;
    nodo->previous=NULL;

    return nodo;
}

void eliminar (struct Datos **head,int p)
{
    struct Datos *temp=*head;
    int i=1;
    if(p==1)
    {
        *head=temp->next;
        del(temp);
    }
    else
    {
        while(i<p-1 && temp!=NULL)
        {
            temp=temp->next;
            i++;
        }
        struct Datos *temp2=temp->next;
        temp->next=temp->next->next;
        del(temp2);

    }
}

void del (struct Datos *head)
{
    free(head);
}

void start (struct Datos **head,char name[],int mat)
{
    struct Datos *nodo = CrearNodo(name,mat);
    if(*head==NULL)
    {
        *head=nodo;
    }
    else
    {
        nodo->next=*head;
        *head=nodo;
    }
}

void top (struct Datos **head,char name[],int mat)
{
    struct Datos *nodo = CrearNodo(name,mat);
    if(*head==NULL)
    {
        *head=nodo;
    }
    else
    {
        struct Datos *temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nodo;
        nodo->previous=temp;
    }
}

void specific (struct Datos **head,char name[],int mat,int p)
{
    struct Datos *nodo = CrearNodo(name,mat);
    if(*head==NULL)
    {
        *head=nodo;
    }
    else
    {
        struct Datos *temp=*head;
        int i=1;
        while(i<p-1 && temp->next!=NULL)
        {
            temp=temp->next;
            i++;
        }
        nodo->next=temp->next;
        temp->next=nodo;
    }
}

void pri(struct Datos *head)
{
    struct Datos *temp=head;
    while(temp!=NULL)
    {
        printf("%s | %d\n",temp->name,temp->mat);
        temp=temp->next;
    }
}