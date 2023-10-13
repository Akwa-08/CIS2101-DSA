#include<stdio.h>
#include<stdlib.h>

#define SIZE 8

typedef struct{
    struct{
        char elem;
        int link; 
    }Nodes[SIZE];
    int avail;
}VirtualHeap;

typedef int LIST;

void initVH(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace();

int main(){
    LIST head = -1;
    VirtualHeap VH;
    char elem;

}

void initVH(VirtualHeap *VH){
    int ndx;

    for(ndx = 0; ndx < SIZE; ndx++){
        VH->Nodes[ndx].link = ndx - 1;
    }

    VH->avail = SIZE - 1;
}

int allocSpace(VirtualHeap *VH){
    int ndx = VH->avail;

    if(ndx != -1){
        VH->avail = VH->Nodes[ndx].link;
    } 

    return ndx;
}

void deallocSpace(VirtualHeap *VH, int index){
    if ( ndx > -1 && ndx < SIZE){
        VH->Nodes[ndx].link = VH->avail;
        VH->avail = ndx;
    }
}