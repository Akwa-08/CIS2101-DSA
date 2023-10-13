#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
typedef struct{
    char elements[SIZE];
    int count
} LIST;

typedef enum {TRUE, FALSE} Boolean;

void initList1(LIST *L);
LIST initList2();

int main(){
    LIST L;

    initList1(&L);

    L = initList2();


}

void initList1(LIST *L){
    L->count = 0;
}

LIST initList2(){
    LIST L;
    L.count = 0;
    return L;
}