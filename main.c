#include <stdio.h>
#include "sort.h"
#include "arr.h"

int main()
{
    int *a, size, choice;
    double time_a, time_b;

   //배열 크기 입력
    printf("What size of array?");  scanf("%d", &size);

    //***Exchange Sort***
    //배열 크기 동적할당
    a = vector(size);

    //배열에 랜덤값 부여
    for(int i=0; i<size; i++)
        a[i] = rand();
    
    printf("before : ");  printArray(a, size);

    time_a = get_runtime();
    exchange_sort(a, size);
    time_b = get_runtime();
    printf("Exchange Sort execution time : %.100lf\n\n", time_b - time_a);

    //***Merge Sort***
    //배열 크기 동적할당
    a = vector(size);

    //배열에 랜덤값 부여
    for(int i=0; i<size; i++)
        a[i] = rand();
    
    printf("before : ");  printArray(a, size);

    time_a = get_runtime();
    merge_sort(a, 0, size - 1);
    time_b = get_runtime();
    printf("Merge Sort execution time : %.100lf\n\n", time_b - time_a);

    //***Quick Sort***
    //배열 크기 동적할당
    a = vector(size);

    //배열에 랜덤값 부여
    for(int i=0; i<size; i++)
        a[i] = rand();
    
    printf("before : ");  printArray(a, size);

    time_a = get_runtime();
    quick_sort(a, 0, size - 1);
    time_b = get_runtime();
    printf("Quick Sort execution time : %.100lf\n\n", time_b - time_a);

    //***Heap Sort***
    //배열 크기 동적할당
    a = vector(size + 1);
    a[0] = -1;

    //배열에 랜덤값 부여
    for(int i=1; i<=size; i++)
        a[i] = rand();

    printf("before : ");  printArray(a, size);

    time_a = get_runtime();
    heap_sort(a, size);
    time_b = get_runtime();
    printf("Heap Sort execution time : %.100lf\n\n", time_b - time_a);

    //***Radix Sort***
    //배열 크기 동적할당
    a = vector(size);

    //배열에 랜덤값 부여
    for(int i=0; i<size; i++)
        a[i] = rand();
    
    printf("before : ");  printArray(a, size);

    time_a = get_runtime();
    radix_sort(a, size);
    time_b = get_runtime();
    printf("Radix Sort execution time : %.100lf\n\n", time_b - time_a);

    printf("after : "); printArray(a, size);

    freeVector(a);

    return 0;
}