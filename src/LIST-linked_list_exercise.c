#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ID;
    char LN[16], FN[24], MI;  // Lastname, Firstname, Middle Initial
    char course[8];
    int yearLevel;
} Studrec;

typedef struct node {
    Studrec stud;
    struct node* link;
} *StudList;   // Definition of the List

void insertFirst(StudList* students, Studrec new);
Studrec deleteRecord(StudList* students, int studID);
void display(StudList students);

int main() {
    StudList students = NULL;
    Studrec retval;

    Studrec student1 = {21104450, "Vinceade", "Doe", 'M', "Computer", 2};
    Studrec student2 = {21104451, "Alice", "Smith", 'F', "Math", 1};
    Studrec student3 = {21104450, "Vince", "Doe", 'M', "Computer", 2};

    insertFirst(&students, student1);
    display(students);
    insertFirst(&students, student2);
    display(students);
    insertFirst(&students, student3);
    display(students);

    retval = deleteRecord(&students, 21104458);
    if (retval.ID == 0) {
        printf("Student Record not found\n");
    } else {
        printf("ID: %d\n", retval.ID);
        printf("Name: %s %s %c\n", retval.FN, retval.LN, retval.MI);
        printf("Course: %s\n", retval.course);
        printf("Year Level: %d\n", retval.yearLevel);
    }
    printf("\n");

    retval = deleteRecord(&students, 21104450);
    if (retval.ID == 0) {
        printf("Student Record not found\n");
    } else {
        printf("ID: %d\n", retval.ID);
        printf("Name: %s %s %c\n", retval.FN, retval.LN, retval.MI);
        printf("Course: %s\n", retval.course);
        printf("Year Level: %d\n", retval.yearLevel);
    }
    printf("\n");

    display(students);

    return 0;
}

void insertFirst(StudList* students, Studrec new) {
    StudList* trav;

    for (trav = students; *trav != NULL && (*trav)->stud.ID != new.ID; trav = &(*trav)->link) {}

    if (*students == NULL) {
        StudList newNode = (StudList)malloc(sizeof(struct node));
        if (newNode != NULL) {
            newNode->stud = new;
            newNode->link = *students;
            *students = newNode;
        } else {
            printf("Memory allocation failed\n");
        }
    } else {
        printf("Student Record Already Exists\n");
    }
}

Studrec deleteRecord(StudList* students, int studID) {
    StudList* trav;
    Studrec dummy = {0, "", "", ' ', "", 0};

    for (trav = students; *trav != NULL && (*trav)->stud.ID != studID; trav = &(*trav)->link) {}

    if (*trav != NULL) {
        StudList temp = *trav;
        dummy = temp->stud;
        *trav = temp->link;
        free(temp);
    } else {
        printf("Student Record not found\n");
    }

    return dummy;
}

void display(StudList students) {
    StudList current = students;

    if (current != NULL) {
        printf("Student Records:\n");
        while (current != NULL) {
            printf("ID: %d\n", current->stud.ID);
            printf("Name: %s %s %c\n", current->stud.FN, current->stud.LN, current->stud.MI);
            printf("Course: %s\n", current->stud.course);
            printf("Year Level: %d\n", current->stud.yearLevel);
            printf("\n");
            current = current->link;
        }
    }
}
