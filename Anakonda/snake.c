#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define g 25


//==========================================================================================================================================

//==========================================================================================================================================

void init(char data[g][g][3]){
    
    for(int i=0;i<g;i++){
        for(int j=0;j<g;j++){
            for(int k=0;k<3;k++){
                data[i][j][k]=' ';
            }
        }
    }
    for(int i=0;i<4;i++){
        data[i][0][0]='d';
    }
    data[0][0][1]='t';
    data[3][0][1]='h';
}
//==========================================================================================================================================

void move(char data[g][g][3],char direction,int* game,int* score){

    //Apple Generator
    int a=0;
    while(a==0){
        for(int i=0;i<g;i++){
            for(int j=0;j<g;j++){
                if(data[i][j][0]=='A'){
                    a=1;
                }
            }
        }
        if(a==0){
            srand(time(NULL));
            int i = rand()%g+1;
            srand(time(NULL));
            int j = rand()%g+1;
            if(data[i][j][0]==' '){
                data[i][j][0]='A';
                a=1;
            }
        }   
    }

    //Locate head and tail and then save in a array
    int ht[4];
    for(int i=0;i<g;i++){
        for(int j=0;j<g;j++){
            if(data[i][j][1]=='h'){
                ht[0]=i;
                ht[1]=j;
            }
            else if(data[i][j][1]=='t'){
                ht[2]=i;
                ht[3]=j;
            }
        }
    }
    //move 
    int mv=0,apple=0;
    switch (direction){
        case 'a':
            if(data[ht[0]-1][ht[1]][0]==' '||data[ht[0]-1][ht[1]][0]=='A'){
                if(data[ht[0]-1][ht[1]][0]=='A'){
                    apple=1;
                }
                data[ht[0]][ht[1]][0]=direction;
                data[ht[0]-1][ht[1]][0]=direction;
                data[ht[0]][ht[1]][1]=' ';
                data[ht[0]-1][ht[1]][1]='h';
                
                mv=1;
            }
            break;
        case 'd':
            if(data[ht[0]+1][ht[1]][0]==' '||data[ht[0]+1][ht[1]][0]=='A'){
                if(data[ht[0]+1][ht[1]][0]=='A'){
                    apple=1;
                    
                }
                data[ht[0]][ht[1]][0]=direction;
                data[ht[0]+1][ht[1]][0]=direction;
                data[ht[0]][ht[1]][1]=' ';
                data[ht[0]+1][ht[1]][1]='h';
                
                mv=1;
            }
            break;
        case 'w':
            if(data[ht[0]][ht[1]-1][0]==' '||data[ht[0]][ht[1]-1][0]=='A'){
                if(data[ht[0]][ht[1]-1][0]=='A'){
                    apple=1;
                    
                }
                data[ht[0]][ht[1]][0]=direction;
                data[ht[0]][ht[1]-1][0]=direction;
                data[ht[0]][ht[1]][1]=' ';
                data[ht[0]][ht[1]-1][1]='h';
                
                mv=1;
            }
            break;
        case 's':
            if(data[ht[0]][ht[1]+1][0]==' '||data[ht[0]][ht[1]+1][0]=='A'){
                if(data[ht[0]][ht[1]+1][0]=='A'){
                    apple=1;
                
                }
                data[ht[0]][ht[1]][0]=direction;
                data[ht[0]][ht[1]+1][0]=direction;
                data[ht[0]][ht[1]][1]=' ';
                data[ht[0]][ht[1]+1][1]='h';
                
                mv=1;
            }
            break;
    }
    if((ht[1]==0&&direction=='w')||(ht[1]==g-1&&direction=='s')){
        mv=0;
    }
    if(mv==1&&apple==0){
        if(data[ht[2]][ht[3]][0]=='a'){
            data[ht[2]-1][ht[3]][1]='t';
            data[ht[2]][ht[3]][1]=' ';
            data[ht[2]][ht[3]][0]=' ';
        }
        else if(data[ht[2]][ht[3]][0]=='d'){
            data[ht[2]+1][ht[3]][1]='t';
            data[ht[2]][ht[3]][1]=' ';
            data[ht[2]][ht[3]][0]=' ';
        }
        else if(data[ht[2]][ht[3]][0]=='s'){
            data[ht[2]][ht[3]+1][1]='t';
            data[ht[2]][ht[3]][1]=' ';
            data[ht[2]][ht[3]][0]=' ';
        }
        else if(data[ht[2]][ht[3]][0]=='w'){
            data[ht[2]][ht[3]-1][1]='t';
            data[ht[2]][ht[3]][1]=' ';
            data[ht[2]][ht[3]][0]=' ';
        }
    }
    else if(mv==0){
        *game=1;
        
    }
}

void display(char data[g][g][3],int* score,int* tme){
    system("cls");
    printf("SCORE: %d                                  TIME: %d\n",*score,*tme);
    printf("+");
    for(int i=0;i<g;i++){
        printf("==");
    }
    printf("+\n");
    for(int j=0;j<g;j++){
        printf("|");
        for(int i=0;i<g;i++){
            if((data[i][j][0]=='a')||(data[i][j][0]=='d')||(data[i][j][0]=='s')||(data[i][j][0]=='w')){
                printf("o ");
            }
            else{
                printf("%c ",data[i][j][0]);
            }
        }
        printf("|\n");
    }
    printf("+");
    for(int i=0;i<g;i++){
        printf("==");
    }
    printf("+\n");
}

//==========================================================================================================================================
int main (){
    char direction='d';
    char data[g][g][3];
    int score=0,tme=0;
    init(data);
    sleep(3);
    int game=0;
    while(game==0){
        display(data,&score,&tme);
        if (kbhit()) {
            direction = getch();
        }
        tme++;
        move(data,direction,&game,&score);
        score=0;
        for(int i=0;i<g;i++){
            for(int j=0;j<g;j++){
                if((data[i][j][0]=='a')||(data[i][j][0]=='d')||(data[i][j][0]=='s')||(data[i][j][0]=='w')){
                    score++;
                }
            }
        }
        
    }
    printf("---THE END---");
    scanf("%d",&game);

    return 0;
}
