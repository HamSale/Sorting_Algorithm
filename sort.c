#include <stdlib.h>
#include "sort.h"

void exchange_sort(int *a, int size)
{
    for(int i=0; i<=size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(a[j] < a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}

void merge_sort(int *a, int first, int last)
{
    int mid;

    if(first < last)
    {
        mid = (first + last) / 2;

        merge_sort(a, first, mid);
        merge_sort(a, mid + 1, last);
        merge(a, first, mid, last);
    }
}

void merge(int *a, int first, int mid, int last)
{
    int i = first;
    int j = mid + 1;
    int k = last;

    int *temp = (int*)malloc(sizeof(int) * (last + 1));
    int alloc = first;

    while (i <= mid && j <= last)
    {
        if(a[i] <= a[j])
        {
            temp[alloc] = a[i];
            i++;
        }
        else
        {
            temp[alloc] = a[j];
            j++;
        }

        alloc++;
    }

    if(i > mid)
    {
        for(int h=j; h<=last; h++)
            temp[alloc++] = a[h];
    }
    else
    {
        for(int h=i; h<= mid; h++)
            temp[alloc++] = a[h];
    }

    for(int h=first; h<=last; h++)
        a[h] = temp[h];
    
    free(temp);
}

void quick_sort(int *a, int L, int R)
{
    int left = L;
    int right = R;
    int pivot = a[(L + R) / 2];
    int temp;

    do {
        while (a[left] < pivot)
            left++;
        while (a[right] > pivot)
            right--;
        
        if(left <= right)
        {
            temp = a[left];
            a[left] = a[right];
            a[right] = temp;

            left++;
            right--;
        }
    } while (left <= right);

    if(L < right)
        quick_sort(a, L, right);
    
    if(R > left)
        quick_sort(a, left, R);
}

void heap_sort(int *a, int size)
{
    makeheap(a, size);
    removekeys(a, size);
}

void makeheap(int *a, int size)
{
    for(int i=size/2; i>=1; i--)
    {
        siftdown(a, size, i);
    }
}

void siftdown(int *a, int size, int i)
{
    int parent = i;
    int left_child = 2 * parent;
    int right_child = 2 * parent + 1;

    if(left_child <= size && a[parent] < a[left_child])
    {
        parent = left_child;
    }
    
    if(right_child <= size && a[parent] < a[right_child])
    {
        parent = right_child;
    }

    if(parent != i)
    {
        int temp = a[parent];
        a[parent] = a[i];
        a[i] = temp;

        siftdown(a, size, parent);
    }
}

void removekeys(int *a, int size)
{
    for(int i=size; i>=1; i--)
    {
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;

        siftdown(a, i - 1, 1);
    }
}

void radix_sort(int *a, int size)
{
    QUEUE list[10];
    int i, j, k, radix;
    int division = 1;
    int max = maxx(a, size);

    for(i=0; i<10; i++)
    {
        init(&list[i]);
    }

    for(i=0; i<max; i++)
    {
        for(j=0; j<size; j++)
        {
            radix = (a[j] / division) % 10;
            enqueue(&list[radix], a[j]);
        }
        k = 0;

        for(j=0; j<10; j++)
        {
            while (!empty(&list[j]))
            {
                a[k++] = dequeue(&list[j]);
            }
        }
        division *= 10;
    }
}

int maxx(int *a, int size)
{
    int i;
    int max = a[0];
    int cnt = 1;

    for(i=1; i<size; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }

    while (max / 10 != 0)
    {
        max /= 10;
        cnt++;
    }

    return cnt;
}

void init(QUEUE* q)
{
    q->head = NULL;
    q->tail = NULL;
}

int empty(QUEUE* q)
{
    if(q->head == NULL)
        return 1;
    else
        return 0;
}

void enqueue(QUEUE* q, int value)
{
    NODE* new_NODE = (NODE*)malloc(sizeof(NODE));
    new_NODE->link = NULL;
    new_NODE->value = value;

    if(empty(q))
    {
        q->head = new_NODE;
        q->tail = new_NODE;
    }
    else
    {
        q->tail->link = new_NODE;
        q->tail = new_NODE;
    }
}

int dequeue(QUEUE* q)
{
    NODE* xNODE;
    int val;

    xNODE = q->head;
    val = xNODE->value;
    q->head = q->head->link;

    free(xNODE);

    return val;
}