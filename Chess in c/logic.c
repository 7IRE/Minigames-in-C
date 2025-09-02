#include <stdio.h>
#include <stdlib.h>
//----------------------------------------------------------------------------------------------------------------
//KNIGHT

int wknight(char data[8][8],int pos[4]){
    if(((abs(pos[3]-pos[1])==2)&&(abs(pos[2]-pos[0])==1))||(abs(pos[3]-pos[1])==1)&&(abs(pos[2]-pos[0])==2)){
        if(data[pos[2]][pos[3]]==' '||data[pos[2]][pos[3]]=='p'||data[pos[2]][pos[3]]=='q'||data[pos[2]][pos[3]]=='r'||data[pos[2]][pos[3]]=='b'||data[pos[2]][pos[3]]=='k'||data[pos[2]][pos[3]]=='n'){
            data[pos[2]][pos[3]]='N';
            data[pos[0]][pos[1]]=' ';
            return 1;
        }
    }
    return 0;
}
int bknight(char data[8][8],int pos[4]){
    if(((abs(pos[3]-pos[1])==2)&&(abs(pos[2]-pos[0])==1))||(abs(pos[3]-pos[1])==1)&&(abs(pos[2]-pos[0])==2)){
        if(data[pos[2]][pos[3]]==' '||data[pos[2]][pos[3]]=='P'||data[pos[2]][pos[3]]=='Q'||data[pos[2]][pos[3]]=='R'||data[pos[2]][pos[3]]=='B'||data[pos[2]][pos[3]]=='K'||data[pos[2]][pos[3]]=='N'){
            data[pos[2]][pos[3]]='n';
            data[pos[0]][pos[1]]=' ';
            return 0;
        }
    }
    return 1;
}

//----------------------------------------------------------------------------------------------------------------
//BISHOP

int bpath(char data[8][8],int pos[4]){
/*
4               3
    .       .
        .
    .   -   .
1               2
  4 directions*/
    //PATH = 0-No,1-Yes
    if(abs(pos[0]-pos[2])!=abs(pos[1]-pos[3])){
        return 0;
    }
    //-------------
    if((pos[0]<pos[2])&&(pos[1]>pos[3])){
        for(int loop=1;loop<abs(pos[0]-pos[2]);loop++){
            if(data[pos[0]+loop][pos[1]-loop]!=' '){
                return 0;
            }
        }
        return 1;
    }
    else if((pos[0]<pos[2])&&(pos[1]<pos[3])){
        for(int loop=1;loop<abs(pos[0]-pos[2]);loop++){
            if(data[pos[0]+loop][pos[1]+loop]!=' '){
                return 0;
            }
        }
        return 1;
    }
    else if((pos[0]>pos[2])&&(pos[1]<pos[3])){
        for(int loop=1;loop<abs(pos[0]-pos[2]);loop++){
            if(data[pos[0]-loop][pos[1]+loop]!=' '){
                return 0;
            }
        }
        return 1;
    }
    else if((pos[0]>pos[2])&&(pos[1]>pos[3])){
        for(int loop=1;loop<abs(pos[0]-pos[2]);loop++){
            if(data[pos[0]-loop][pos[1]-loop]!=' '){
                return 0;
            }
        }
        return 1;
    }
}
int wbishoop(char data[8][8],int pos[4]){
    int path=bpath(data,pos);
    if((path==1)&&(data[pos[2]][pos[3]]==' '||data[pos[2]][pos[3]]=='p'||data[pos[2]][pos[3]]=='q'||data[pos[2]][pos[3]]=='r'||data[pos[2]][pos[3]]=='b'||data[pos[2]][pos[3]]=='k'||data[pos[2]][pos[3]]=='n')){
        data[pos[2]][pos[3]]='B';
        data[pos[0]][pos[1]]=' ';
        return 1;
    }
    return 0;
}

int bbishoop(char data[8][8] ,int pos[4]){
    int path=bpath(data,pos);
    if((path==1)&&(data[pos[2]][pos[3]]==' '||data[pos[2]][pos[3]]=='P'||data[pos[2]][pos[3]]=='Q'||data[pos[2]][pos[3]]=='R'||data[pos[2]][pos[3]]=='B'||data[pos[2]][pos[3]]=='K'||data[pos[2]][pos[3]]=='N')){
        data[pos[2]][pos[3]]='b';
        data[pos[0]][pos[1]]=' ';
        return 0;
    }
    return 1;
}
//----------------------------------------------------------------------------------------------------------------
//KING
int wking(char data[8][8],int pos[4]){
    // -1 0 , -1 -1 , -1 1 , 0 -1 , 0 1 , 1 0 , 1 -1 , 1 1
    if(((data[pos[0]][pos[1]]==data[pos[2]-1][pos[3]]) || (data[pos[0]][pos[1]]==data[pos[2]-1][pos[3]-1]) || (data[pos[0]][pos[1]]==data[pos[2]-1][pos[3]+1]) || (data[pos[0]][pos[1]]==data[pos[2]][pos[3]-1]) || (data[pos[0]][pos[1]]==data[pos[2]][pos[3]+1]) || (data[pos[0]][pos[1]]==data[pos[2]+1][pos[3]]) || (data[pos[0]][pos[1]]==data[pos[2]+1][pos[3]-1]) || (data[pos[0]][pos[1]]==data[pos[2]+1][pos[3]+1])) && ((data[pos[2]][pos[3]]==' ')||(data[pos[2]][pos[3]]=='k')||(data[pos[2]][pos[3]]=='q')||(data[pos[2]][pos[3]]=='p')||(data[pos[2]][pos[3]]=='r')||(data[pos[2]][pos[3]]=='b')||(data[pos[2]][pos[3]]=='n'))){
        data[pos[2]][pos[3]]='K';
        data[pos[0]][pos[1]]=' ';
        return 1;
    }
    else
    return 0;
}

int bking(char data[8][8],int pos[4]){
    // -1 0 , -1 -1 , -1 1 , 0 -1 , 0 1 , 1 0 , 1 -1 , 1 1
    if(((data[pos[0]][pos[1]]==data[pos[2]-1][pos[3]]) || (data[pos[0]][pos[1]]==data[pos[2]-1][pos[3]-1]) || (data[pos[0]][pos[1]]==data[pos[2]-1][pos[3]+1]) || (data[pos[0]][pos[1]]==data[pos[2]][pos[3]-1]) || (data[pos[0]][pos[1]]==data[pos[2]][pos[3]+1]) || (data[pos[0]][pos[1]]==data[pos[2]+1][pos[3]]) || (data[pos[0]][pos[1]]==data[pos[2]+1][pos[3]-1]) || (data[pos[0]][pos[1]]==data[pos[2]+1][pos[3]+1])) && ((data[pos[2]][pos[3]]==' ')||(data[pos[2]][pos[3]]=='K')||(data[pos[2]][pos[3]]=='Q')||(data[pos[2]][pos[3]]=='P')||(data[pos[2]][pos[3]]=='R')||(data[pos[2]][pos[3]]=='B')||(data[pos[2]][pos[3]]=='N'))){
        data[pos[2]][pos[3]]='k';
        data[pos[0]][pos[1]]=' ';
        return 0;
    }
    else
    return 1;
}
//----------------------------------------------------------------------------------------------------------------
//PAWN
int wpawn(char data[8][8],int pos[4]){
    if(pos[1]==pos[3]){
        if(pos[0]==pos[2]+1){
            if(data[pos[2]][pos[3]]==' '){
                data[pos[2]][pos[3]]='P';
                data[pos[0]][pos[1]]=' ';
                return 1;
            }
        }
        else if(pos[0]==pos[2]+2){
            if((data[pos[0]-1][pos[1]]==' ') && (data[pos[2]][pos[3]]==' ')){
                data[pos[2]][pos[3]]='P';
                data[pos[0]][pos[1]]=' ';
                return 1;
            }
        }        
    }
    else if((pos[1]==pos[3]+1)&&(pos[0]==pos[2]+1)&&(data[pos[2]][pos[3]]=='p'||data[pos[2]][pos[3]]=='q'||data[pos[2]][pos[3]]=='r'||data[pos[2]][pos[3]]=='b'||data[pos[2]][pos[3]]=='k'||data[pos[2]][pos[3]]=='n')){
                data[pos[2]][pos[3]]='P';
                data[pos[0]][pos[1]]=' ';
                return 1;
    }
    else if((pos[1]==pos[3]-1)&&(pos[0]==pos[2]+1)&&(data[pos[2]][pos[3]]=='p'||data[pos[2]][pos[3]]=='q'||data[pos[2]][pos[3]]=='r'||data[pos[2]][pos[3]]=='b'||data[pos[2]][pos[3]]=='k'||data[pos[2]][pos[3]]=='n')){
        data[pos[2]][pos[3]]='P';
        data[pos[0]][pos[1]]=' ';
        return 1;
    }
    return 0;
}
int bpawn(char data[8][8],int pos[4]){
    if(pos[1]==pos[3]){
        if(pos[0]==pos[2]-1){
            if(data[pos[2]][pos[3]]==' '){
                data[pos[2]][pos[3]]='p';
                data[pos[0]][pos[1]]=' ';
                return 0;
            }
        }
        else if(pos[0]==pos[2]-2){
            if((data[pos[0]+1][pos[1]]==' ') && (data[pos[2]][pos[3]]==' ')){
                data[pos[2]][pos[3]]='p';
                data[pos[0]][pos[1]]=' ';
                return 0;
            }
        }
    }
    else if((pos[1]==pos[3]+1)&&(pos[0]==pos[2]-1)&&(data[pos[2]][pos[3]]=='P'||data[pos[2]][pos[3]]=='Q'||data[pos[2]][pos[3]]=='R'||data[pos[2]][pos[3]]=='B'||data[pos[2]][pos[3]]=='K'||data[pos[2]][pos[3]]=='N')){
                data[pos[2]][pos[3]]='p';
                data[pos[0]][pos[1]]=' ';
                return 0;
    }
    else if((pos[1]==pos[3]-1)&&(pos[0]==pos[2]-1)&&(data[pos[2]][pos[3]]=='P'||data[pos[2]][pos[3]]=='Q'||data[pos[2]][pos[3]]=='R'||data[pos[2]][pos[3]]=='B'||data[pos[2]][pos[3]]=='K'||data[pos[2]][pos[3]]=='N')){
        data[pos[2]][pos[3]]='p';
        data[pos[0]][pos[1]]=' ';
        return 0;
    }
    return 1; 
}
//--------------------------------------------------------------------------------------------------------------
//ROOK
int rpath(char data[8][8],int pos[4]){
    int a=0;
    // vertical movement
    if((pos[0]<pos[2])&&(pos[1]==pos[3])){
        for(int loop=1;pos[2]>(pos[0]+loop);loop++){
            if(data[pos[0]+loop][pos[1]]!=' '){
                a=1;
                break;
            }
        }
        if(a==1){
            return 0;
        }
        else{
            return 1;
        }
    }
    if((pos[0]>pos[2])&&(pos[1]==pos[3])){
       for(int loop=1;pos[0]>(pos[2]+loop);loop++){
            if(data[pos[2]+loop][pos[1]]!=' '){
                a=1;
                break;
            }
        }
        if(a==1){
            return 0;
        }
        else{
            return 1;
        } 
    
        
    }
    //horizontal movement
    if((pos[1]<pos[3])&&(pos[0]==pos[2])){
        for(int loop=1;pos[3]>(pos[1]+loop);loop++){
            if(data[pos[0]][pos[1]+loop]!=' '){
                a=1;
                break;
            }
        }
        if(a==1){
            return 0;
        }
        else{
            return 1;
        } 
    }
    if((pos[1]>pos[3])&&(pos[0]==pos[2])){
        for(int loop=1;pos[1]>(pos[3]+loop);loop++){
            if(data[pos[0]][pos[3]+loop]!=' '){
                a=1;
                break;
            }
        }
        if(a==1){
            return 0;
        }
        else{
            return 1;
        } 
    }
    return 0;
}

int wrook(char data[8][8],int pos[4]){
    int path=rpath(data,pos);
    if(path==0){
        return 0;
    }
    else if(path==1){
        if(data[pos[2]][pos[3]]==' '||data[pos[2]][pos[3]]=='r'||data[pos[2]][pos[3]]=='q'||data[pos[2]][pos[3]]=='p'||data[pos[2]][pos[3]]=='n'||data[pos[2]][pos[3]]=='b'||data[pos[2]][pos[3]]=='k'){
            data[pos[2]][pos[3]]='R';
            data[pos[0]][pos[1]]=' ';
        }
        return 1;
    }
}
int brook(char data[8][8],int pos[4]){
    int path=rpath(data,pos);
    if(path==0){
        return 1;
    }
    else if(path==1){
        if(data[pos[2]][pos[3]]==' '||data[pos[2]][pos[3]]=='R'||data[pos[2]][pos[3]]=='Q'||data[pos[2]][pos[3]]=='P'||data[pos[2]][pos[3]]=='N'||data[pos[2]][pos[3]]=='B'||data[pos[2]][pos[3]]=='K'){
            data[pos[2]][pos[3]]='r';
            data[pos[0]][pos[1]]=' ';
        }
        return 0;
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------
//QUEEN
int rqueen(char data[8][8],int pos[4]){
    int b;
    if(abs(pos[0]-pos[2])!=abs(pos[1]-pos[3])){
        b = rpath(data,pos);
    }
    else{
        b = bpath(data,pos);
    }
    return b;
} 

int wqueen(char data[8][8],int pos[4]){
    int path=rqueen(data,pos);
    if((path==1)&&(data[pos[2]][pos[3]]==' '||data[pos[2]][pos[3]]=='p'||data[pos[2]][pos[3]]=='q'||data[pos[2]][pos[3]]=='r'||data[pos[2]][pos[3]]=='b'||data[pos[2]][pos[3]]=='k'||data[pos[2]][pos[3]]=='n')){
        data[pos[2]][pos[3]]='Q';
        data[pos[0]][pos[1]]=' ';
        return 1;
    }
    printf("path=%d",path);
    return 0;
}

int bqueen(char data[8][8],int pos[4]){
    int path=rqueen(data,pos);
    if((path==1)&&(data[pos[2]][pos[3]]==' '||data[pos[2]][pos[3]]=='P'||data[pos[2]][pos[3]]=='Q'||data[pos[2]][pos[3]]=='R'||data[pos[2]][pos[3]]=='B'||data[pos[2]][pos[3]]=='K'||data[pos[2]][pos[3]]=='N')){
        data[pos[2]][pos[3]]='q';
        data[pos[0]][pos[1]]=' ';
        return 0;
    }
    printf("path=%d",path);
    return 1;
}
//----------------------------------------------------------------------------------------------------------------
int wturn(int pos[4],char piece ,char data[8][8]){
    if((piece=='R')  &&  (data[pos[0]][pos[1]]=='R')){
        return wrook(data,pos);
    }
    else if((piece=='N')  &&  (data[pos[0]][pos[1]]=='N')){
        return wknight(data,pos);
    }
    else if((piece=='B')  &&  (data[pos[0]][pos[1]]=='B')){
        return wbishoop(data,pos);
    }
    else if((piece=='K')  &&  (data[pos[0]][pos[1]]=='K')){
        return wking(data,pos);
    }
    else if((piece=='Q')  &&  (data[pos[0]][pos[1]]=='Q')){
        return wqueen(data,pos);
    }
    else if((piece=='P')  &&  (data[pos[0]][pos[1]]=='P')){
        return wpawn(data,pos);
    }
    else{
        return 0;
    }

}
int bturn(int pos[4],char piece ,char data[8][8]){
    if((piece=='r')  &&  (data[pos[0]][pos[1]]=='r')){
        return brook(data,pos);
    }
    else if((piece=='n')  &&  (data[pos[0]][pos[1]]=='n')){
        return bknight(data,pos);
    }
    else if((piece=='b')  &&  (data[pos[0]][pos[1]]=='b')){
        return bbishoop(data,pos);
    }
    else if((piece=='k')  &&  (data[pos[0]][pos[1]]=='k')){
        return bking(data,pos);
    }
    else if((piece=='q')  &&  (data[pos[0]][pos[1]]=='q')){
        return bqueen(data,pos);
    }
    else if((piece=='p')  &&  (data[pos[0]][pos[1]]=='p')){
        return bpawn(data,pos);
    }
    else{
        return 1;
    }
    
}

//----------------------------------------------------------------------------------------------------------------------------------------


int logic(char data[8][8] ,int *turn ,int *enp){
    // TURN 0 - WHITE , 1 - BLACK
    if(*turn==0){
        printf("---WHITE TURN---");
        char piece;
        int pos[4];
        scanf(" %c%d%d%d%d",&piece,&pos[0],&pos[1],&pos[2],&pos[3]);
        *turn=wturn(pos,piece,data);
    }
    else if(*turn==1){
        printf("---BLACK TURN---");
        char piece;
        int pos[4];
        scanf(" %c%d%d%d%d",&piece,&pos[0],&pos[1],&pos[2],&pos[3]);
        *turn=bturn(pos,piece,data);
    }
}

