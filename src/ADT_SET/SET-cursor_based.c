#include<stdio.h>
#include<stdlib.h>

#define SIZE 16

typedef struct{
    struct{
        int data;
        int link; 
    }Nodes[SIZE];
    int avail;
}VirtualHeap;

typedef int SET;

void initVH(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int ndx);
void insertElem(SET *set, int elem);
SET Union(SET A, SET B);
SET Intersection(SET A, SET B);
SET Difference(SET A, SET B);
void displaySet(SET set);

VirtualHeap VH;

int main(void){
    SET A = -1;
    SET B = -1;

    initVirutalHeap(&VH);
    insertElem(&A, 7);
    insertElem(&A, 5);
    insertElem(&A, 2);
    insertElem(&A, 7);
    insertElem(&A, 4);
    insertElem(&A, 1);
    insertElem(&A, 0);

    SET C = Union(A, B);
    SET D = Intersection(A, B);
    SET E = Difference(A, B);

    displaySet(A);
    displaySet(B);
    displaySet(C);
    displaySet(D);
    displaySet(E);
    return 0;
}

void insertElem(SET *set, int elem){
    int node = allocSpace(&VH);

    if(node != -1){
        VH.Nodes[node].data = elem;
        VH.Nodes[node].link = *set;
        *set = node;

    }
}
SET Union(SET A, SET B){
    SET C = -1;
    SET *cptr = &C;

    while (A != -1 && B != -1){
        *cptr = allocSpace(&VH);

        if (*cptr != -1){
            if(VH.Nodes[A].data < VH.Nodes[B].data){
                VH.Nodes[*cptr].data = VH.Nodes[A].data;
                A = VH.Nodes[A].link;
            } else if (VH.Nodes[A].data > VH.Nodes[B].data){
                VH.Nodes[*cptr].data = VH.Nodes[B].data;
                A = VH.Nodes[B].link;
            } else {
                VH.Nodes[*cptr].data = VH.Nodes[A].data;
                A = VH.Nodes[A].link;
                B = VH.Nodes[B].link;
            }
        }
    } 
}

SET Intersection(SET A, SET B){

}

SET Difference(SET A, SET B){

}

void displaySet(SET set){
    SET trav = -1;

    for(trav = set; trav != -1; trav = VH.Nodes[trav].link ){
        printf("%-3d [ %d | %-3d ]\n", trav, VH.Nodes[trav].data, VH.Nodes[trav].link);
    }

    printf("\n");
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

void deallocSpace(VirtualHeap *VH, int ndx){
    if ( ndx > -1 && ndx < SIZE){
        VH->Nodes[ndx].link = VH->avail;
        VH->avail = ndx;
    }
}