#include <stdio.h>
void line(){
    printf("\n-------------------------------------------------- \n :");
}

void display(char data[8][8]){
    //DISPLAY BOARD
    printf("\n------CHESS------\n");
    printf("+-+-+-+-+-+-+-+-+ \n");
    for (int hloop=0;hloop<8;hloop++){
        for(int loop=0;loop<8;loop++){
        printf("|%c",data[hloop][loop]);
        }
        printf("| \n");
        
    }
    printf("+-+-+-+-+-+-+-+-+ \n");
}

void init(char data[8][8]){
    //RESET BOARD
    for(int hloop=0;hloop<8;hloop++){
        for(int loop=0;loop<8;loop++){
            data[loop][hloop]=' ';
        }
    }
    data[0][0]='r',data[0][1]='n',data[0][2]='b',data[0][3]='q',data[0][4]='k',data[0][5]='b',data[0][6]='n',data[0][7]='r';
    data[7][0]='R',data[7][1]='N',data[7][2]='B',data[7][3]='Q',data[7][4]='K',data[7][5]='B',data[7][6]='N',data[7][7]='R';

    for(int loop=0;loop<8;loop++){
        data[1][loop]='p';
        data[6][loop]='P';
    }
}

int start(){
    int a;
    printf("Enter a number to choose respective option. \n -------------------------------------------------- ");
    printf("\n 1.) Pass and play ");
    line();
    scanf("%d",&a);
    return a;
}

void board(){
    char data[8][8];
        printf("If you want to play white your pieces are in capital letters while black has its pieces in small letter \n ");
    line();
    printf("WHITE \n Pawns=P \n Queen=Q \n Rook=R \n King=K \n Bishop=B \n Knight=N");
    line();
    printf("BLACK \n Pawns=p \n Queen=q \n Rook=r \n King=k \n Bishop=b \n Knight=n");
    line();
    printf("\nSetting up board...\n");
    init(data);
    display(data);
}

void logic(int a){
    if(a==1){
        board();
    }
}

