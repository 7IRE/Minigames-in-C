#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
void check(char *string , char *input , int *win);

int main (){
    FILE *ptr;
    FILE *stats;
    int number,attempt=0,win=0;
    ptr=fopen("Data.txt","r");

    char string[6]="empty";
    srand(time(0));
    number=rand()%2309+1;
    for(int loop=1;loop<=number;loop++){
        fscanf(ptr,"%s",string);
    }   
    fclose(ptr);
    printf("Enter a 5 digit word , remember you have 6 attempts.");
    while(attempt!=6&&win==0){
        fflush(stdin);
        char input[6];
        scanf("%s",input);
        check(string,input,&win);
        printf("%d attempts left.\n",5-attempt);
        attempt++;
    }
    printf("The correct ans is %s\n ",string);
    if(win!=0){
        printf("YOU WIN ");
    }
    else{
        printf("YOU LOSE");
    }
    sleep(5);
    return 0;
}

void check(char string[6], char input[6], int *win){
    for(int loop=0;loop<5;loop++){
        int a=0;
        if(string[loop]==input[loop]){
            printf("\033[102m%c\033[0m",string[loop]);
        }
        else {
            for(int hloop=0;hloop<5;hloop++){
                if(string[hloop]==input[loop]){
                    printf("\033[103m \033[0m");
                    a=1;
                }
            }
            if(a==0){
                    printf("\033[101m \033[0m");
            }

        }


    }
    printf("\n");
    if(string[0]==input[0]&&string[1]==input[1]&&string[2]==input[2]&&string[3]==input[3]&&string[4]==input[4]){
        *win=1;
    }
}