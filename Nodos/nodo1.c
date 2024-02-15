#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libad.h"
#include "list.h"

struct datos{
    char name[30];
    char app[30];
    int id;

    struct datos *siguiete;
    struct datos *anterior;
};



int main()
{
    struct datos *list = NULL;

}

void create_bin(struct datos *nodo)
