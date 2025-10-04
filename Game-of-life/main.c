#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define z 40

void display(int board[z][z]){
        system("cls");
        printf("+");
        for(int h=0;h<z;h++){
            printf("==");
        }
        printf("+\n");
        for(int h=0;h<z;h++){
            printf("|");
            for(int i=0;i<z;i++){
                if(board[i][h]==1){
                    printf("[]");
                }
                else{
                    printf("  ");
                }
            }
            printf("|\n");
        }
        printf("+");
        for(int h=0;h<z;h++){
            printf("==");
        }
        printf("+");
    }


int main (){
    printf("INITIALIZING...");
    int board[z][z];
    int buffer[z][z];
    //0=dead , 1=alive 
    for(int a=0;a<z;a++){
        for(int A=0;A<z;A++){
            board[a][A]=0;
            buffer[a][A]=0;
        }
    }

    printf("\nSet Initial Condition \nw,a,s,d-Move Invisible pointer \n t-toggle state (alive or dead) \n r-start the game\n");
    sleep(5);
    char input='z';
    int setup=1;
    int v=1,h=1;
     while(setup==1){
        if (kbhit()) {
            input = getch();
        }


        if(input=='w'){
            v--;
        }
        else if(input=='s'){
            v++;
        }
        else if(input=='d'){
            h++;
        }
        else if(input=='a'){
            h--;
        }

        if(v<1){
            v=z-2;
        }
        else if(h<1){
            h=z-2;
        }
        else if(v>z-2){
            v=1;
        }
        else if(h>z-2){
            h=1;
        }

        if(input=='t'){
            if(board[h][v]==0){
                board[h][v]=1;
            }
            else{
                board[h][v]=0;
            }
        }

        
        display(board);
        if(input=='r'){
            setup=0;
        }
        usleep(10);
        input='z';

    }
    printf("\n STARTING  SIMULATION \n (q to exit and s to slow down simulation & n for normal speed)");
    sleep(1);
    
    while (setup==0){
        for(int h=0;h<z;h++){
            for(int v=0;v<z;v++){
                int count=0;
                if(board[h+1][v]==1){
                    count++;
                }
                if(board[h-1][v]==1){
                    count++;
                }
                if(board[h][v+1]==1){
                    count++;
                }
                if(board[h][v-1]==1){
                    count++;
                }
                if(board[h+1][v+1]==1){
                    count++;
                }
                if(board[h+1][v-1]==1){
                    count++;
                }
                if(board[h-1][v-1]==1){
                    count++;
                }
                if(board[h-1][v+1]==1){
                    count++;
                }

                if((count==2||count==3)&&board[h][v]==1){
                    buffer[h][v]=1;
                }
                else if((count<2||count>3)&&board[h][v]==1){
                    buffer[h][v]=0;
                }
                else if(count==3&&board[h][v]==0){
                    buffer[h][v]=1;
                }
            }
        }
        for(int h=0;h<z;h++){
            buffer[h][0]=0;
            buffer[0][h]=0;
            buffer[h][z-1]=0;
            buffer[z-1][h]=0;
        }
        for(int h=0;h<z;h++){
            for(int v=0;v<z;v++){
                board[h][v]=buffer[h][v];
            }
        }
       
        display(board);

        if (kbhit()) {
        input = getch();
        if (input == 'q') break;
        if (input == 's') sleep(1);
        if (input == 'n') usleep(100);
        }


    }
    
    sleep(1);
    return 0;
    
}

