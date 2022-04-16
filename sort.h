#ifndef _SORT_
#define _SORT_

typedef struct node
{
    int value;
    struct node* link;
} NODE;

typedef struct queue
{
    NODE* head;
    NODE* tail;
} QUEUE;

void exchange_sort(int *a, int size);

void merge_sort(int *a, int first, int last);
void merge(int *a, int first, int mid, int last);

void quick_sort(int *a, int L, int R);

void heap_sort(int *a, int size);
void makeheap(int *a, int size);
void siftdown(int *a, int size, int i);
void removekeys(int *a, int size);

void radix_sort(int *a, int size);
int maxx(int *a, int size);
void init(QUEUE* q);
int empty(QUEUE* q);
void enqueue(QUEUE* q, int value);
int dequeue(QUEUE* q);

#endif