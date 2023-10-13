#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    char elements[SIZE];
    int count;
} LIST;

void initList1(LIST *L);
void displayList(LIST L);
int findElem(LIST L, char elem);
void insertElem(LIST *L, char elem, int pos);
void deleteElem(LIST *L, char elem);
LIST initList2();

int main() {
    LIST L;
    int retval;

    initList1(&L);
    L = initList2();

    insertElem(&L, 'A', 0);
    insertElem(&L, 'C', 1);
    insertElem(&L, 'B', 1);
    insertElem(&L, 'D', 3);
    displayList(L);

    retval = findElem(L, 'C');
    printf("%d\n", retval);
    retval = findElem(L, 'E');
    printf("%d\n", retval);
    displayList(L);

    deleteElem(&L, 'C');
    displayList(L);

    return 0;
}

void initList1(LIST *L) {
    L->count = 0;
}

LIST initList2() {
    LIST L;
    L.count = 0;
    return L;
}

void displayList(LIST L) {
	int ndx;
    for ( ndx = 0; ndx < L.count; ndx++) {
        printf("%c ", L.elements[ndx]);
    }
    printf("\n");
}

int findElem(LIST L, char elem) {
    int pos = -1;
    int ndx;
    for (ndx = 0; ndx < L.count; ndx++) {
        if (L.elements[ndx] == elem) {
            pos = ndx;
            break;
        }
    }
    return pos;
}

void insertElem(LIST *L, char elem, int pos) {
    if (L->count < SIZE) {
        if (L->count > pos) {
            int ndx;

            for (ndx = L->count; ndx >= pos; ndx--) {
                L->elements[ndx + 1] = L->elements[ndx];
            }

        	L->elements[pos] = elem;
            L->count++;
        } else {
            L->elements[L->count++] = elem;
        }
    }
}

void deleteElem(LIST *L, char elem) {
    int ndx = findElem(*L, elem);

    if (ndx != -1) {
    	int i;
        for (i = ndx; i < L->count - 1; i++) {
            L->elements[i] = L->elements[i + 1];
        }
        L->count--;
    }
}

