#include<ctype.h>
#include<stdbool.h>
#include<stdio.h>

#define SIZE 26
#define EMPTY '?'
#define DELETED '!'

typedef struct{
    char elems[SIZE];
    int size;
} Dictionary;

Dictionary initDic(void);
int getHash(char);
bool isMember(Dictionary *book, char data);
void insertElem(Dictionary *book, char data);
void deleteElem(Dictionary *book, char data);
void displayDic(Dictionary book);

int main(void){
    Dictionary book = initDic();

}

Dictionary initDic(void){
    Dictionary book;
    int ndx;

    for ( ndx = 0; ndx < SIZE; ndx++){
        book.elems[ndx] = EMPTY;
    }

    book.size = 0;
    return book;
}

int getHash(char);
bool isMember(Dictionary *book, char data);
void insertElem(Dictionary *book, char data);
void deleteElem(Dictionary *book, char data);
void displayDic(Dictionary book);