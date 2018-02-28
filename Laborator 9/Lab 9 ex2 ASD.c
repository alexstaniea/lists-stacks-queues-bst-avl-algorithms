#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int *v;
}heap;

int left(int i)
{
    return 2*i+1;
}

int right(int i)
{
    return 2*i+2;
}

int parent(int i)
{
    return (i-1)/2;
}

void maxHeapify(heap maxheap, int i)
{
    if(maxheap.size<=1)
        return;

    int largest;

    if(right(i)>=maxheap.size){
        if(maxheap.v[i]>=maxheap.v[left(i)])
            largest=i;
        else
            largest=left(i);
    }else{
        if(maxheap.v[i]>=maxheap.v[left(i)] && maxheap.v[i]>=maxheap.v[right(i)])
            largest=i;
        else if(maxheap.v[right(i)]>=maxheap.v[left(i)] && maxheap.v[i]<=maxheap.v[right(i)])
            largest=right(i);
        else
            largest=left(i);

    }

    if(largest!=i){
        int aux=maxheap.v[largest];
        maxheap.v[largest]=maxheap.v[i];
        maxheap.v[i]=aux;

        //maxheapify if largest is not a leaf
        if(largest<maxheap.size/2)
            maxHeapify(maxheap, largest);
    }
}

void buildMaxHeap(heap maxheap)
{
    int i;
    for(i=maxheap.size/2-1;i>=0;i--)
        maxHeapify(maxheap, i);
}

int extractMax(heap *maxheap)
{
    int aux=maxheap->v[0];
    maxheap->v[0]=maxheap->v[maxheap->size-1];
    maxheap->v[maxheap->size-1]=aux;
    maxheap->size-=1;

    maxHeapify(*maxheap, 0);

    return maxheap->v[maxheap->size+1];
}

void heapSort(int *v, int n)
{
    heap maxheap;
    maxheap.v=v;
    maxheap.size=n;

    buildMaxHeap(maxheap);

    int i;

    for(i=n-1;i>=1;i--)
        extractMax(&maxheap);
}

int main()
{
    int n, i;
    FILE *fin=fopen("date.txt", "r");
    fscanf(fin, "%d", &n);

    int *v=(int*)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
        fscanf(fin, "%d", &v[i]);

    heapSort(v, n);

    for(i=0;i<n;i++)
        fprintf(stdout, "%d ", v[i]);

    return 0;
}
