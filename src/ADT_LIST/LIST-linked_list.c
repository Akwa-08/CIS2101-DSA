#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char data;
    struct node *link;
} *LIST;

void initList(LIST *L);
void insertAt(LIST *L, char elem, int pos);
void deleteElem(LIST *L, char elem);
void deleteAll(LIST *L, char elem);
int locElem(LIST L, char elem);
char retElem(LIST L, int pos);
void displayList(LIST L);

int main(){
    LIST L;
    int retInt;
    char retChar;

    initList(&L);

    insertAt(&L, 'A', 1);
    insertAt(&L, 'C', 2);
    insertAt(&L, 'B', 2);
    insertAt(&L, 'D', 4);
    insertAt(&L, 'A', 5);
    insertAt(&L, 'B', 3);
    displayList(L);

    deleteElem(&L, 'B');
    displayList(L);

    deleteAll(&L, 'A');
    displayList(L);

    retInt = locElem(L, 'B');
    printf("\n%d", retInt);
    retInt = locElem(L, 'A');
    printf("\n%d", retInt);

    retChar = retElem(L, 3);
    printf("\n%c ", retChar);
    retChar = retElem(L, 1);
    printf("\n%c ", retChar);
    retChar = retElem(L, 2);
    printf("\n%c ", retChar);
}

void initList(LIST *L){
    *L = NULL;
}

void displayList(LIST L){
    printf("\n");
    while(L!=NULL){
        printf("%c ", L->data);
        L = L->link;
    }
}

void insertAt(LIST *L, char elem, int pos){
    LIST *trav = L;
    int ndx = 1;

    while(*trav != NULL && ndx < pos){
        trav = &(*trav)->link;
        ndx++;
    }

    LIST newNode = (LIST)malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->data = elem;
        newNode->link = *trav;
        *trav = newNode;
    }
    

}

void deleteElem(LIST *L, char elem){
    if(*L != NULL){
        LIST *trav;
        for(trav = L; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}
        if(*trav != NULL){
            LIST temp = *trav;
            *trav = temp->link;
            free(temp);
        }else{
            printf("Element could not be Found");
        }
    }
}

void deleteAll(LIST *L, char elem){
    
    if(*L != NULL){
        LIST *trav = L;
        while(*trav != NULL){
            if((*trav)->data == elem){
                LIST temp = *trav;
                *trav = temp->link;
                free(temp);
            }else{
                trav = &(*trav)->link;
            }
        }
    }
}

int locElem(LIST L, char elem){
    LIST trav = L;
    int ndx;
    int pos = -8;

    for(ndx = 0; trav != NULL && pos == -8; ndx++, trav = trav->link){
        if(trav->data == elem){
            pos = ndx;
        }
    }

    return pos;
}

char retElem(LIST L, int pos){
    LIST trav = L;
    int ndx;
    int retElem = '\0';

    for (ndx = 1; trav != NULL && retElem == '\0'; ndx++, trav = trav->link){
        if (ndx == pos){
            retElem = trav->data;
        }
    }

    return retElem;
}
