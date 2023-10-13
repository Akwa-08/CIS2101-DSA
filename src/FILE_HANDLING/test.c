#include<stdio.h>

int main(){

    FILE *fp;
    float x;
    
    if(fp = fopen("test.dat", "rb")){
        while( fread(&x, sizeof(float), 1, fp) != 0){

        }
        fclose(fp);
    } else {
        printf("Can't Open File");
    }

}


