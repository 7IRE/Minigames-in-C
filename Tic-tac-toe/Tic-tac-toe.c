#include <stdio.h>
#include <stdlib.h>

void display(char data[3][3]){
    printf("TIC-TAC_TOE\n\n");
    printf("%c |%c | %c\n",data[0][0],data[1][0],data[2][0]);  
    printf("--+--+--\n");    
    printf("%c |%c | %c\n",data[0][1],data[1][1],data[2][1]);  
    printf("--+--+--\n");    
    printf("%c |%c | %c\n\n\n",data[0][2],data[1][2],data[2][2]);  
}

void clear(char data[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            data[i][j]=' ';
        }
    }
}

int menu(){
    printf("---------------------------------------------------------------------------------------------------\nEnter the respective number to chose the option for the menu:\n 1-pass&play\n 2-Rules \n 3-Exit\n------------------------------------------------------------\n");
    int choice;
    int buff;
    scanf("  %d",&choice);
    if(choice==1){
        return 1;
    }
    else if(choice==2){
        printf("\n The Rules of the game are as follows :\n Choose your respective square by typing a single no.(1-9) and pressing enter and each no. specify a specific position on the grid \n 1| 2| 3 \n 4| 5| 6\n 7| 8| 9\n\nFirst move is always played by X. \n if 3 X comes in any row or column or diagonal X wins and vice versa \n\n\n\n Enter anything to go back... \n");
        scanf(" %d",&buff);
        return menu();
    }
    else if(choice==3){
        return 0;
    }
    else{
        printf("INVALID CHOICE,TRY AGAIN");
        return menu();
    }
}
int move(char data[3][3],char *move){

    if((data[0][0]=='X'&&data[0][1]=='X'&&data[0][2]=='X')||(data[1][0]=='X'&&data[1][1]=='X'&&data[1][2]=='X')||(data[2][0]=='X'&&data[2][1]=='X'&&data[2][2]=='X')||(data[0][0]=='X'&&data[1][0]=='X'&&data[2][0]=='X')||(data[0][1]=='X'&&data[1][1]=='X'&&data[2][1]=='X')||(data[0][2]=='X'&&data[1][2]=='X'&&data[2][2]=='X')||(data[0][0]=='X'&&data[1][1]=='X'&&data[2][2]=='X')||(data[0][2]=='X'&&data[1][1]=='X'&&data[2][0]=='X')){
        printf("X WINS");
        return 100;
    }
    else if((data[0][0]=='O'&&data[0][1]=='O'&&data[0][2]=='O')||(data[1][0]=='O'&&data[1][1]=='O'&&data[1][2]=='O')||(data[2][0]=='O'&&data[2][1]=='O'&&data[2][2]=='O')||(data[0][0]=='O'&&data[1][0]=='O'&&data[2][0]=='O')||(data[0][1]=='O'&&data[1][1]=='O'&&data[2][1]=='O')||(data[0][2]=='O'&&data[1][2]=='O'&&data[2][2]=='O')||(data[0][0]=='O'&&data[1][1]=='O'&&data[2][2]=='O')||(data[0][2]=='O'&&data[1][1]=='O'&&data[2][0]=='O')){
        printf("O WINS");
        return 100;
    }
    else if(data[0][0]!=' '&&data[0][1]!=' '&&data[0][2]!=' '&&data[1][0]!=' '&&data[1][2]!=' '&&data[2][0]!=' '&&data[2][1]!=' '&&data[2][2]!=' '){
        printf("ITS a DRAW..");
        return 100;
    }

    int input;
    printf("\n----ENTER YOUR MOVE (1-9)----\n");
    scanf("%d",&input);
    switch (input){
    case 1:  
        if(data[0][0]==' '){
            data[0][0]=*move;
            break;
        }
        else{
            return 0;
        }
    case 2: 
        if(data[1][0]==' '){
            data[1][0]=*move;
            break;
        }
        else{
            return 0;
        }
    case 3:  
        if(data[2][0]==' '){
            data[2][0]=*move;
            break;
        }
        else{
            return 0;
        }
    case 4:  
        if(data[0][1]==' '){
            data[0][1]=*move;
            break;
        }
        else{
            return 0;
        }
    case 5:  
        if(data[1][1]==' '){
            data[1][1]=*move;
            break;
        }
        else{
            return 0;
        }
    case 6:  
        if(data[2][1]==' '){
            data[2][1]=*move;
            break;
        }
        else{
            return 0;
        }
    case 7:  
        if(data[0][2]==' '){
            data[0][2]=*move;
            break;
        }
        else{
            return 0;
        }
    case 8: 
        if(data[1][2]==' '){
            data[1][2]=*move;
            break;
        }
        else{
            return 0;
        }
    case 9:  
        if(data[2][2]==' '){
            data[2][2]=*move;
            break;
        }
        else{
            return 0;
        }
    default:
        return 0;
    }   
    

    if(*move=='X'){
        *move='O';
        printf("\n---O turn---\n");
    }
    else if(*move=='O'){
        *move='X';
        printf("\n---X turn---\n");
    }
}


int main (){
    char data[3][3];
    clear(data);
    char mve='X';
    int buff=0;
    int me=menu();
    if(me==1){
        while(buff!=100){
            display(data);
            buff=move(data,&mve);
        }
    }
    printf("\nEnter anything to close the software...\n");
    scanf("%d",&mve);
    return 0;
}