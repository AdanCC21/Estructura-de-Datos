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

// void start (struct Nodo**head,char name[],int ind);
void end (struct Nodo **head,char name[],int ind);
// void specific (struct Nodo **head, char name[],int ind,int p);
void pri (struct Nodo *head);
void pri_end (struct Nodo *head);


//Main
int main()
{
    int op=0,p=0,in=0,sp;
    char name[20];
    struct Nodo* Lista=NULL;
    do
    {
        system("CLS");
        menu();
        op=valid("Fuera de rango",0,6);
        switch(op)
        {
            case 1:
                printf("Ingrese su nombre\n");
                gets(name);
                p++;
                in++;
                end(&Lista,name,p);
                system("PAUSE");
                break;
            case 2:
                printf("Verificar vacio\n");
                if(in>0)
                {
                    printf("La pila no esta vacia\n");
                }
                else
                {
                    printf("La pila esta vacia\n");
                }
                system("PAUSE");
                break;
            case 3:
                //cantidad
                if(in>0)
                {
                    printf("La pila tiene %d datos\n",p);
                }
                else
                {
                    printf("La pila esta vacia\n");
                }
                system("PAUSE");
                break;
            case 4:
            if(in==0)
            {
                printf("Lista Vacia\n");
            }
            else
            {
                pri(Lista);
            }
                system("PAUSE");
                break;
            case 5:
                printf("Que posicion desea eliminar\n");
                sp=valid("FUERA DE RANGO",1,in);
                del(&Lista,sp);
                in--;
                system("PAUSE");
                break;
            case 6:
                if(p==0)
                {
                    printf("Pila Vacia\n");
                }
                else
                {
                    pri_end(Lista);
                }
                system("PAUSE");
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
    printf("1.-Inicio\t2.-Verificar vacio\t3.-Cantidad\t4.-Imprimir\t5.-Eliminar\t6.-Imprimir Ultimo\t0.-salir\n");
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

void pri_end (struct Nodo *head)
{
    struct Nodo *temp = head;
    if(temp->next==NULL)
    {
        printf("Nombre %-10s | Id %-10d\n",temp->name,temp->ind);

    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        printf("Nombre %-10s | Id %-10d\n",temp->name,temp->ind);        
    }
}
