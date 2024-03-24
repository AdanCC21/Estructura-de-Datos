#include <stdio.h>
#include <stdlib.h>
#include "libad.h"




int main()
{
    double time;
    time=10;
    printf("%f\n",time);
    modificar(&time);
    printf("%f\n",time);
}

void modificar (double *ptr)
{
    *ptr=15;
}