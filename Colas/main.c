/*
    Gonzalez Ceseña Adan
    372799
    Estructura de datos
    08/03/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libad.h"

#define limit 5


struct Cola{
    int dato;
    int ind;
    struct Cola *next;
};

void menu();
struct Cola* create(int dato, int p);
void insertar(struct Cola **head,struct Cola **last,int dato, int p);
void sacar (struct Cola **head,struct Cola **last);
void pri(struct Cola **head,struct Cola **last);

int main()
{
    struct Cola* head=NULL,*last=NULL;
    int op;
    int dato,ind=0;
    do
    {
        menu();
        op=valid("FUERA DE RANGO",0,3);
        switch(op)
        {
            case 1:
                if(ind<5)
                {
                    printf("Que dato quiere meter?\n");
                    dato=valid("FUERA DE RANGO",1,1000);
                    ind++;
                    insertar(&head,&last,dato,ind);
                    printf("Lista\n");
                }
                else
                {
                    printf("Cola llena\n");
                }
                system("PAUSE");
                system("CLS");
            break;
            case 2:
                printf("Sacar ultimo\n");
                sacar(&head,&last);
                ind--;
                system("PAUSE");
                system("CLS");
            break;
            case 3:
                pri(&head,&last);
                system("PAUSE");
            break;
            case 0:
            printf("seguro que quiere salir?\n");
            op=valid("FUERA DE RANGO",1,2);
            op--;
        }
    } while (op!=0);
}

void menu (){
    printf("MENU\n");
    printf("1.-insertar\t2.-sacar\t3.-Ver\t0.-Salir\n");
}

struct Cola* create(int dato, int p)
{
    struct Cola* nodo = (struct Cola*)malloc(sizeof(struct Cola));
    nodo->dato=dato;
    nodo->ind=p;
    nodo->next=NULL;
    return nodo;
}

void insertar(struct Cola **head,struct Cola **last,int dato, int p)
{
    struct Cola *nodo=create(dato,p);
    if(*head == NULL)
    {
        *head=nodo;
        *last=nodo;
    }
    else
    {
        struct Cola*temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nodo;
        *last=nodo;
    }
}

void sacar (struct Cola **head,struct Cola **last)
{
    if(*head==NULL)
    {
        printf("Lista vacia\n");
    }
    else
    {
        struct Cola*temp=*head;
        printf("Dato: %d, Ind: %d",temp->dato,temp->ind);
        *head=temp->next;
        free(temp);
    }
    //FAlta una condicion para cuando sea el ultimo elemento de la lista
}

//Sacas todo cada que lo imprimes
void pri(struct Cola **head,struct Cola **last)
{
    if(*head==NULL)
    {
        printf("Lista vacia\n");
    }
    else
    {
        struct Cola*temp=*head;
        while(temp!=NULL)
        {
            temp=*head;
            printf("Dato: %d, Ind: %d \n",temp->dato,temp->ind);
            temp=temp->next;
            *head=temp;
        }
        free(temp);
        *head=NULL;
        *last=NULL;
    }
}

