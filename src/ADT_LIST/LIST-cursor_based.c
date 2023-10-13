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
void deallocSpace(VirtualHeap *VH, int ndx);
void insertElem(LIST *head, char data, int pos);
void deleteElem(LIST *head, char data);
int locateElem(LIST head, char data);
void displayList(LIST head);


VirtualHeap VH;

int main(){
    LIST head = -1;
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

void deallocSpace(VirtualHeap *VH, int ndx){
    if ( ndx > -1 && ndx < SIZE){
        VH->Nodes[ndx].link = VH->avail;
        VH->avail = ndx;
    }
}

void insertElem(LIST *head, char data, int pos){
    LIST *trav = head;
    int ndx = 0;

    while(*trav != -1 && ndx < pos){
        trav = &VH.Nodes[*trav].link;
        ndx++;
    }

    LIST node = allocSpace(&VH);

    if (node != -1){
        VH.Nodes[node].elem = data;
        VH.Nodes[node].link = *trav;
        *trav = node;
    }
}

void deleteElem(LIST *head, char data){
    LIST *trav = head;

    while (*trav != -1 && VH.Nodes[*trav].elem != data){
        trav = VH.Nodes[*trav].link;
    }

    if(*trav != -1){
        LIST temp = *trav;
        *trav = VH.Nodes[temp].link;
        deallocSpace(&VH, temp);

    }
}

int locateElem(LIST head, char data){
    int pos = -1;
    LIST trav = head;
    int ndx;

    for (ndx = 0; trav != -1 && pos == -1; ndx++, trav = VH.Nodes[trav].link){
        if (VH.Nodes[trav].elem == data){
            pos = ndx;
        }

    }
    
}

void displayList(LIST head){
    LIST trav = head;

    while (trav != -1){
        printf("\t%d [ %c | %d ]\n", trav, VH.Nodes[trav].elem, VH.Nodes[trav].link);
        trav = VH.Nodes[trav].link;
    }

    printf("\n");
}