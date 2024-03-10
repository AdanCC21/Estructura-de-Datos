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
    struct Nodo *next;
};

void menu();
struct Cola* create(int dato, int p);
void insertar(struct Cola **head,struct Cola **last,int dato, int p);
void sacar (struct Cola **head,struct Cola **last);

int main()
{
    struct Cola* head,*last;
    int op;
    int dato,ind=0,del;
    do
    {
        menu();
        op=valid("FUERA DE RANGO",0,3);
        switch(op)
        {
            case 1:
                if(ind<5)
                {
                    printf("Que dato quiere meter?");
                    dato=valid("FUERA DE RANGO",1,1000);
                    ind++;
                    insertar(&head,&last,dato,ind);
                    printf("Lista");
                }
                else
                {
                    printf("Cola llena\n");
                }
                system("PAUSE");
                system("CLS");
            break;
            case 2:
                printf("Sacar ultimo");
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
            print("seguro que quiere salir?\n");
            op=valid("FUERA DE RANGO",1,2);
        }
    } while (op!=0);
}

void menu (){
    print("MENU\n");
    print("1.-insertar\t2.-sacar\t3.-Ver\t0.-Salir\n");
}

struct Cola* create(int dato, int p)
{
    struct Cola* nodo = (struct Cola*)malloc(sizeof(struct Cola));
    nodo->next=NULL;
}

void insertar(struct Cola **head,struct Cola **last,int dato, int p)
{
    struct Cola*nodo=create(dato,p);
    if(*head == NULL)
    {
        *head=nodo;
        *last=nodo;
    }
    else
    {
        struct Cola*temp=*head;
        while(temp!=NULL)
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
        printf("Lista vacia");
    }
    else
    {
        struct Cola*temp=*head;
        printf("Dato: %d, Ind: %d",temp->dato,temp->ind);
        *head=temp->next;
        free(temp);
    }
}

//Sacas todo cada que lo imprimes
void pri(struct Cola **head,struct Cola **last)
{
    if(*head==NULL)
    {
        printf("Lista vacia");
    }
    else
    {
        struct Cola*temp=*head;
        while(temp!=NULL)
        {
            temp=*head;
            printf("Dato: %d, Ind: %d",temp->dato,temp->ind);
            *head=temp->next;
            free(temp);
        }
    }
}

