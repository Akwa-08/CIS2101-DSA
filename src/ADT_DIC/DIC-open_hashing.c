#include<stdbool.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

#define SIZE 26

typedef struct node{
    char elem;
    struct node *link;
} NODE, *LIST;

typedef LIST OpenDic[SIZE];


int getHash( char data);
bool isMember(OpenDic book, char data);
void insertElem(OpenDic book, char data);
void deleteELem(OpenDic book, char data);
void displayDic(OpenDic book);


int main(void){
    OpenDic book = {0};

    displayDic(book);

    return 0;
}

int getHas(char data){

    return (toupper(data) - 'A') % SIZE;

}

bool isMember(OpenDic book, char data){
    int ndx = getHash(data);
    LIST trav = book[ndx];

    while (trav != NULL && trav->elem != data){
        trav = trav->link;
    }

    return (trav != NULL);
}

void insertElem(OpenDic book, char data){
    if (!isMember(book, data)){
        int ndx = getHash(data);
        LIST node = (LIST) malloc(sizeof(NODE));

        if (node != NULL){
            node->elem = data;
            node->link = book[ndx];
            book[ndx] = node;
        }
    }
}

void deleteElem(OpenDic book, char data){
    int ndx = getHash(data);
    LIST *trav = &book[ndx];

    while (*trav != NULL && (*trav)->elem != data){
        trav = &(*trav)->link;
    }

    if (*trav != NULL){
        LIST temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

void displayDic(OpenDic book){
    int ndx;
    LIST trav = NULL;

    for( ndx = 0; ndx < SIZE; ndx++){
        printf("[%02d] =>", ndx);

        for(trav = book[ndx]; trav != NULL; trav->link){
            printf("%c => ", trav->elem);
        }
        printf("NULL\n");
    }
}