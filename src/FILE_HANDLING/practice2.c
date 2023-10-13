#include<stdio.h>

typedef struct {
    char FN[24]; //firstname
    char MI; //middle initial
    char LN[16]; //lastname
}Nametype;

typedef struct {
    Nametype name;
    int ID;
    char course[8]; //BSCS, BSIS, BSIT
    int yrLevel;
}Studtype;

void writeFile();
void readFile();
void displayHeader();
void displayStudent();


int main(){

    readFile();

    writeFile();

    readFile();
}

void writeFile(){
    char fileName[20];

    printf("Enter a file name: ");

    if (fgets(fileName, sizeof(fileName), stdin) != NULL){
        fileName[strcspn(fileName, "\n")] = 0;
    }

    FILE *fp = fopen(fileName, "wb");

    if (fp != NULL){

    }
}

void readFile(){
    char fileName[20];

    printf("Enter a file name: ");

    if(fgets(fileName,sizeof(fileName),stdin) != NULL){
        fileName[strcspn(fileName, "\n")] = 0;
    }

    FILE *fp = fopen(fileName, "rb");

    if (fp != NULL){
        Studtype student;
        int count = 1;
        
        displayHeader();
        while(fread(&student, sizeof(student), 1, fp) != 0){
            displayStudent(student);

            if(count == 30){
                printf("\nPress a key to continue");
                fflush(stdout);

                // while(getchar() != '\n'){

                //}
                count = 1;
            }
            count++;
        }
        fclose(fp);
    }
}

void displayHeader(){

    printf("\n\n");
    printf("%-10s", "ID No.");
    printf("%-16s", "Lastname");
    printf("%-24s", "Firstname");
    printf("%-3s", "MI");
    printf("%-8s", "Course");
    printf("%5s", "Year");
    printf("\n");
    printf("%-10s", "======");
    printf("%-16s", "========");
    printf("%-24s", "=========");
    printf("%-3s", "==");
    printf("%-8s", "======");
    printf("%5s", "====");
}


void displayStudent(Studtype S){

    printf("\n\n");
    printf("%-10d", S.ID);
    printf("%-16s", S.name.LN);
    printf("%-24s", S.name.FN);
    printf("%-3c", S.name.MI);
    printf("%-8s", S.course);
    printf("%-5d", S.yrLevel);
}

