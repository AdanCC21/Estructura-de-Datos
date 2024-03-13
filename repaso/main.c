#include <stdio.h>
#include <stdlib.h>
#include "libad.h"

#define TRUE 1
#define FALSE 0

struct Pila{
    int dato;
    struct Pila *next;
};
struct Pila *crear(int dato);
void push (struct Pila**head,int dato);
void pop (struct Pila **head);
void peek (struct Pila **head);
int isEmpty (struct Pila **head);

int main()
{
    struct Pila *stack=NULL;
    int op,dato,vacio;
    do
    {
        printf("1.-Push,2.-Pop,3.-Top/Peek,4.-IsEmpty,5.-Size\n");
        op=valid("",0,5);
        switch(op)
        {
            case 1:
                printf("ingrese un dato\n");
                dato=valid("",0,1000);
                push(&stack,dato);
            break;
            case 2:
                pop(&stack);
            break;
            case 3:
                peek(&stack);
            break;
            case 4:
                vacio=isEmpty(&stack);
                if(vacio==1)
                {
                    printf("Esta vacio\n");

                }
                else
                {
                    printf("esta lleno\n");
                }
            break;
        }
    } while (op!=0);
}

struct Pila *crear(int dato)
{
    struct Pila *nodo = (struct Pila*)malloc(sizeof(struct Pila));
    nodo->dato=dato;
    nodo->next = NULL;
    return nodo;
}

void push (struct Pila**head,int dato)
{
    struct Pila *nodo=crear(dato);
    if(*head==NULL)
    {
        *head=nodo;
    }
    else
    {
        struct Pila *temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nodo;
    }
}

void pop (struct Pila **head)
{
    if(*head==NULL)
    {
        printf("Vacia\n");
    }
    else
    {
        struct Pila *temp=*head, *prev=NULL;
        
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        
        if(prev==NULL)
        {
            printf("Dato : %d\n",temp->dato);
            free(temp);
            *head=NULL;
        }
        else
        {
            printf("Dato : %d\n",temp->dato);
            prev->next=NULL;
            free(temp);
        }
        
    }
}

void peek (struct Pila **head)
{
    if(*head==NULL)
    {
        printf("Vacia\n");
    }
    else
    {
        struct Pila *temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        printf("Dato : %d\n",temp->dato);
    }
}

int isEmpty (struct Pila **head)
{
    if(*head==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

