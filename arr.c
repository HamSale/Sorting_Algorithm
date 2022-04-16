#include <stdlib.h>
#include <time.h>
#include "arr.h"

int *vector(int size)
{
    int *vec;
    vec = (int *)malloc(sizeof(int)*size);

    return vec;
}

void freeVector(int *vec)
{
    free(vec);
}

double get_runtime(void)
{
  clock_t start;
  start = clock();

  return ((double)start*100.0/(double)CLOCKS_PER_SEC);
}

void printArray(int *a, int size)
{
    for(int i=0; i<size; i++)
        printf("%d  ", a[i]);

    printf("\n");
}