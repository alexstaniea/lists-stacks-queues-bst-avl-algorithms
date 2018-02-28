#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int info;
    int pr;
}elem;

typedef struct
{
    int size;
    elem *v;
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

void minHeapify(heap minheap, int i)
{
    if(minheap.size<=1)
        return;

    int smallest;

    if(right(i)>=minheap.size){
        if(minheap.v[i].pr<=minheap.v[left(i)].pr)
            smallest=i;
        else
            smallest=left(i);
    }else{
        if(minheap.v[i].pr<=minheap.v[left(i)].pr && minheap.v[i].pr<=minheap.v[right(i)].pr)
            smallest=i;
        else if(minheap.v[right(i)].pr<=minheap.v[left(i)].pr && minheap.v[i].pr>=minheap.v[right(i)].pr)
            smallest=right(i);
        else
            smallest=left(i);
    }

    if(smallest!=i){
        elem aux=minheap.v[smallest];
        minheap.v[smallest]=minheap.v[i];
        minheap.v[i]=aux;

        //minheapify if smallest is not a leaf
        if(smallest<minheap.size/2)
            minHeapify(minheap, smallest);
    }
}

elem extractMin(heap *minheap)
{
    elem temp=minheap->v[0];
    minheap->v[0]=minheap->v[minheap->size-1];
    minheap->size-=1;

    minHeapify(*minheap, 0);

    return temp;
}

void insert(heap *minheap, int pr, int info)
{
    (minheap->v[minheap->size]).pr=pr;
    (minheap->v[minheap->size]).info=info;
    minheap->size+=1;

    elem aux;
    int i=minheap->size-1;

    while(parent(i)>=0 && minheap->v[i].pr<minheap->v[parent(i)].pr){
        aux=minheap->v[i];
        minheap->v[i]=minheap->v[parent(i)];
        minheap->v[parent(i)]=aux;

        i=parent(i);
    }
}

elem minimum(heap minheap)
{
    return minheap.v[0];
}

int main()
{
    int n, i;
    FILE *fin=fopen("date.txt", "r");
    fscanf(fin, "%d", &n);

    heap minheap;
    minheap.v=(elem*)malloc(sizeof(elem)*n);
    minheap.size=0;

    for(i=0;i<n;i++){
        int pr, info;
        fscanf(fin, "%d %d", &pr, &info);
        insert(&minheap, pr, info);
    }

    for(i=0;i<n;i++){
        elem temp=extractMin(&minheap);
        printf("%d -> %d\n", temp.pr, temp.info);
    }

    return 0;
}
