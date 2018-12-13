
#ifndef MENUNAV_H
#define MENUNAV_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

int navegador1x1(int* x,int* y,int navegador[],int* escolha){
    int z;
    z=getch();
        switch(z){
            case 13:{
                return 0;
                break;
            }
            case 27:{
                return 1;
                break;
            }
            case 'a':{
                if(*x==1){
                    navegador[*escolha]=0;
                    *escolha-=1;
                    navegador[*escolha]=1;
                    *x=*x-1;
                }
                return 3;
                break;
            }
            case 'd':{
                if(*x==0){
                    navegador[*escolha]=0;
                    *escolha+=1;
                    navegador[*escolha]=1;
                    *x=*x+1;
                }
                return 3;
                break;
            }
            default: {
                return 3;
                break;
            }
        }
}

int navegador2x1(int* x,int* y,int navegador[],int* escolha){
    int z;
    z=getch();
        switch(z){
            case 13:{
                return 0;
                break;
            }
            case 27:{
                return 1;
                break;
            }
            case 's':{
                if(*y==0 && *x==0){
                    navegador[*escolha]=0;
                    *escolha+=2;
                    navegador[*escolha]=1;
                    *y=*y+1;
                }
                return 3;
                break;
            }
            case 'w':{
                if(*y==1 && *x==0){
                    navegador[*escolha]=0;
                    *escolha-=2;
                    navegador[*escolha]=1;
                    *y=*y-1;
                }
                return 3;
                break;
            }
            case 'a':{
                if(*x==1){
                    navegador[*escolha]=0;
                    *escolha-=1;
                    navegador[*escolha]=1;
                    *x=*x-1;
                }
                return 3;
                break;
            }
            case 'd':{
                if(*x==0 && *y==0){
                    navegador[*escolha]=0;
                    *escolha+=1;
                    navegador[*escolha]=1;
                    *x=*x+1;
                }
                return 3;
                break;
            }
            default: {
                return 3;
                break;
            }
        }
}

int navegador2x2(int* x,int* y,int navegador[],int* escolha){
    int z;
    z=getch();
        switch(z){
            case 13:{
                return 0;
                break;
            }
            case 27:{
                return 1;
                break;
            }
            case 's':{
                if(*y==0){
                    navegador[*escolha]=0;
                    *escolha+=2;
                    navegador[*escolha]=1;
                    *y=*y+1;
                }
                return 3;
                break;
            }
            case 'w':{
                if(*y==1){
                    navegador[*escolha]=0;
                    *escolha-=2;
                    navegador[*escolha]=1;
                    *y=*y-1;
                }
                return 3;
                break;
            }
            case 'a':{
                if(*x==1){
                    navegador[*escolha]=0;
                    *escolha-=1;
                    navegador[*escolha]=1;
                    *x=*x-1;
                }
                return 3;
                break;
            }
            case 'd':{
                if(*x==0){
                    navegador[*escolha]=0;
                    *escolha+=1;
                    navegador[*escolha]=1;
                    *x=*x+1;
                }
                return 3;
                break;
            }
            default: {
                return 3;
                break;
            }
        }
}

int navegador3x2(int* x,int* y,int navegador[],int* escolha){
    int z;
    z=getch();
        switch(z){
            case 13:{
                return 0;
                break;
            }
            case 27:{
                return 1;
                break;
            }
            case 's':{
                if( (*x==00 && *y<2 )|| (*x==1 && *y<1) ){
                    navegador[*escolha]=0;
                    *escolha+=2;
                    navegador[*escolha]=1;
                    *y=*y+1;
                }
                return 3;
                break;
            }
            case 'w':{
                if(*y>0){
                    navegador[*escolha]=0;
                    *escolha-=2;
                    navegador[*escolha]=1;
                    *y=*y-1;
                }
                return 3;
                break;
            }
            case 'a':{
                if(*x==1){
                    navegador[*escolha]=0;
                    *escolha-=1;
                    navegador[*escolha]=1;
                    *x=*x-1;
                }
                return 3;
                break;
            }
            case 'd':{
                if(*x==0 && *y!=2){
                    navegador[*escolha]=0;
                    *escolha+=1;
                    navegador[*escolha]=1;
                    *x=*x+1;
                }
                return 3;
                break;
            }
            default: {
                return 3;
                break;
            }
        }
}

int navegador3x3(int* x,int* y,int navegador[],int* escolha){
    int z;
    z=getch();
        switch(z){
            case 13:{
                return 0;
                break;
            }
            case 27:{
                return 1;
                break;
            }
            case 's':{
                if(*y<2){
                    navegador[*escolha]=0;
                    *escolha+=2;
                    navegador[*escolha]=1;
                    *y=*y+1;
                }
                return 3;
                break;
            }
            case 'w':{
                if(*y>0){
                    navegador[*escolha]=0;
                    *escolha-=2;
                    navegador[*escolha]=1;
                    *y=*y-1;
                }
                return 3;
                break;
            }
            case 'a':{
                if(*x==1){
                    navegador[*escolha]=0;
                    *escolha-=1;
                    navegador[*escolha]=1;
                    *x=*x-1;
                }
                return 3;
                break;
            }
            case 'd':{
                if(*x==0){
                    navegador[*escolha]=0;
                    *escolha+=1;
                    navegador[*escolha]=1;
                    *x=*x+1;
                }
                return 3;
                break;
            }
            default: {
                return 3;
                break;
            }
        }
}

int navegador4x3(int* x,int* y,int navegador[],int* escolha){
    int z;
    z=getch();
        switch(z){
            case 13:{
                return 0;
                break;
            }
            case 27:{
                return 1;
                break;
            }
            case 's':{
                if( (*x==00 && *y<3 )|| (*x==1 && *y<2) ){
                    navegador[*escolha]=0;
                    *escolha+=2;
                    navegador[*escolha]=1;
                    *y=*y+1;
                }
                return 3;
                break;
            }
            case 'w':{
                if(*y>0){
                    navegador[*escolha]=0;
                    *escolha-=2;
                    navegador[*escolha]=1;
                    *y=*y-1;
                }
                return 3;
                break;
            }
            case 'a':{
                if(*x==1){
                    navegador[*escolha]=0;
                    *escolha-=1;
                    navegador[*escolha]=1;
                    *x=*x-1;
                }
                return 3;
                break;
            }
            case 'd':{
                if(*x==0 && *y!=3){
                    navegador[*escolha]=0;
                    *escolha+=1;
                    navegador[*escolha]=1;
                    *x=*x+1;
                }
                return 3;
                break;
            }
            default: {
                return 3;
                break;
            }
        }
}

int navegador4x4(int* x,int* y,int navegador[],int* escolha){
    int z;
    z=getch();
        switch(z){
            case 13:{
                return 0;
                break;
            }
            case 27:{
                return 1;
                break;
            }
            case 's':{
                if(*y<3){
                    navegador[*escolha]=0;
                    *escolha+=2;
                    navegador[*escolha]=1;
                    *y=*y+1;
                }
                return 3;
                break;
            }
            case 'w':{
                if(*y>0){
                    navegador[*escolha]=0;
                    *escolha-=2;
                    navegador[*escolha]=1;
                    *y=*y-1;
                }
                return 3;
                break;
            }
            case 'a':{
                if(*x==1){
                    navegador[*escolha]=0;
                    *escolha-=1;
                    navegador[*escolha]=1;
                    *x=*x-1;
                }
                return 3;
                break;
            }
            case 'd':{
                if(*x==0){
                    navegador[*escolha]=0;
                    *escolha+=1;
                    navegador[*escolha]=1;
                    *x=*x+1;
                }
                return 3;
                break;
            }
            default: {
                return 3;
                break;
            }
        }
}

int navegador5x4(int* x,int* y,int navegador[],int* escolha){
    int z;
    z=getch();
        switch(z){
            case 13:{
                return 0;
                break;
            }
            case 27:{
                return 1;
                break;
            }
            case 's':{
                if( (*x==00 && *y<4 )|| (*x==1 && *y<3) ){
                    navegador[*escolha]=0;
                    *escolha+=2;
                    navegador[*escolha]=1;
                    *y=*y+1;
                }
                return 3;
                break;
            }
            case 'w':{
                if(*y>0){
                    navegador[*escolha]=0;
                    *escolha-=2;
                    navegador[*escolha]=1;
                    *y=*y-1;
                }
                return 3;
                break;
            }
            case 'a':{
                if(*x==1){
                    navegador[*escolha]=0;
                    *escolha-=1;
                    navegador[*escolha]=1;
                    *x=*x-1;
                }
                return 3;
                break;
            }
            case 'd':{
                if(*x==0 && *y!=4){
                    navegador[*escolha]=0;
                    *escolha+=1;
                    navegador[*escolha]=1;
                    *x=*x+1;
                }
                return 3;
                break;
            }
            default: {
                return 3;
                break;
            }
        }
}

int menu1x1(char op1[],char op2[],char cursor[][2],int navegador[],int* x, int* y,int* escolha){
    printf("***************************************\n");
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[0]][0],cursor[navegador[0]][1],op1,cursor[navegador[1]][0],cursor[navegador[1]][1],op2);
    printf("***************************************\n");
    int l=3;
    l=navegador1x1(x,y,navegador,escolha);
    if(l==3){
        return 0;
    }
    else if(l==1){
        return 1;
    }
    else return 2;
}

int menu2x1(char op1[],char op2[],char op3[],char cursor[][2],int navegador[],int* x, int* y,int* escolha){
    printf("***************************************\n");
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[0]][0],cursor[navegador[0]][1],op1,cursor[navegador[1]][0],cursor[navegador[1]][1],op2);
    printf("*%c%c %s \n",cursor[navegador[2]][0],cursor[navegador[2]][1],op3);
    printf("***************************************\n");
    int l=3;
    l=navegador2x1(x,y,navegador,escolha);
    if(l==3){
        return 0;
    }
    else if(l==1){
        return 1;
    }
    else return 2;
}

int menu2x2(char op1[],char op2[],char op3[],char op4[],char cursor[][2],int navegador[],int* x, int* y,int* escolha){
    printf("***************************************");
    printf("\n*%c%c %s \t %c%c %s",cursor[navegador[0]][0],cursor[navegador[0]][1],op1,cursor[navegador[1]][0],cursor[navegador[1]][1],op2);
    printf("\n*%c%c %s \t %c%c %s\n",cursor[navegador[2]][0],cursor[navegador[2]][1],op3,cursor[navegador[3]][0],cursor[navegador[3]][1],op4);
    printf("***************************************");
    int l=3;
    l=navegador2x2(x,y,navegador,escolha);
    if(l==3){
        return 0;
    }
    else if(l==1){
        return 1;
    }
    else return 2;
}

int menu3x2(char op1[],char op2[],char op3[],char op4[],char op5[],char cursor[][2],int navegador[],int* x, int* y,int* escolha){
    printf("***************************************\n");
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[0]][0],cursor[navegador[0]][1],op1,cursor[navegador[1]][0],cursor[navegador[1]][1],op2);
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[2]][0],cursor[navegador[2]][1],op3,cursor[navegador[3]][0],cursor[navegador[3]][1],op4);
    printf("*%c%c %s \n",cursor[navegador[4]][0],cursor[navegador[4]][1],op5);
    printf("***************************************\n");
    int l=3;
    l=navegador3x2(x,y,navegador,escolha);
    if(l==3){
        return 0;
    }
    else if(l==1){
        return 1;
    }
    else return 2;
}

int menu3x3(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],char cursor[][2],int navegador[],int* x, int* y,int* escolha){
    printf("***************************************\n");
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[0]][0],cursor[navegador[0]][1],op1,cursor[navegador[1]][0],cursor[navegador[1]][1],op2);
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[2]][0],cursor[navegador[2]][1],op3,cursor[navegador[3]][0],cursor[navegador[3]][1],op4);
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[4]][0],cursor[navegador[4]][1],op5,cursor[navegador[5]][0],cursor[navegador[5]][1],op6);
    printf("***************************************\n");
    int l=3;
    l=navegador3x3(x,y,navegador,escolha);
    if(l==3){
        return 0;
    }
    else if(l==1){
        return 1;
    }
    else return 2;
}

int menu4x3(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],char op7[],char cursor[][2],int navegador[],int* x, int* y,int* escolha){
    printf("***************************************\n");
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[0]][0],cursor[navegador[0]][1],op1,cursor[navegador[1]][0],cursor[navegador[1]][1],op2);
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[2]][0],cursor[navegador[2]][1],op3,cursor[navegador[3]][0],cursor[navegador[3]][1],op4);
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[4]][0],cursor[navegador[4]][1],op5,cursor[navegador[5]][0],cursor[navegador[5]][1],op6);
    printf("*%c%c %s \n",cursor[navegador[6]][0],cursor[navegador[6]][1],op7);
    printf("***************************************\n");
    int l=3;
    l=navegador4x3(x,y,navegador,escolha);
    if(l==3){
        return 0;
    }
    else if(l==1){
        return 1;
    }
    else return 2;
}

int menu4x4(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],char op7[],char op8[],char cursor[][2],int navegador[],int* x, int* y,int* escolha){
    printf("***************************************\n");
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[0]][0],cursor[navegador[0]][1],op1,cursor[navegador[1]][0],cursor[navegador[1]][1],op2);
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[2]][0],cursor[navegador[2]][1],op3,cursor[navegador[3]][0],cursor[navegador[3]][1],op4);
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[4]][0],cursor[navegador[4]][1],op5,cursor[navegador[5]][0],cursor[navegador[5]][1],op6);
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[6]][0],cursor[navegador[6]][1],op7,cursor[navegador[7]][0],cursor[navegador[7]][1],op8);
    printf("***************************************\n");
    int l=3;
    l=navegador4x4(x,y,navegador,escolha);
    if(l==3){
        return 0;
    }
    else if(l==1){
        return 1;
    }
    else return 2;
}

int menu5x4(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],char op7[],char op8[],char op9[],char cursor[][2],int navegador[],int* x, int* y,int* escolha){
   
   
    printf("***************************************\n");
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[0]][0],cursor[navegador[0]][1],op1,cursor[navegador[1]][0],cursor[navegador[1]][1],op2);
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[2]][0],cursor[navegador[2]][1],op3,cursor[navegador[3]][0],cursor[navegador[3]][1],op4);
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[4]][0],cursor[navegador[4]][1],op5,cursor[navegador[5]][0],cursor[navegador[5]][1],op6);
    printf("*%c%c %s \t %c%c %s\n",cursor[navegador[6]][0],cursor[navegador[6]][1],op7,cursor[navegador[7]][0],cursor[navegador[7]][1],op8);
    printf("*%c%c %s \n",cursor[navegador[8]][0],cursor[navegador[8]][1],op9);
    printf("***************************************\n");
    int l=3;
    l=navegador5x4(x,y,navegador,escolha);
    if(l==3){
        return 0;
    }
    else if(l==1){
        return 1;
    }
    else return 2;
}

int layout1x1(char op1[],char op2[],int* escolha){
    int x,y,navegador[2],loop;
    char cursor[2][2];
    for(x=0;x<2;x++){
            navegador[x]=0;
    }
    x=y=0;
    navegador[0]=1;
    cursor[0][0]=' ';cursor[0][1] =' ';
    cursor[1][0]='-';cursor[1][1] ='>';
    loop=0;
    *escolha=0;
    while(loop==0){
        system("cls");
        loop=menu1x1(op1,op2,cursor,navegador,&x,&y,escolha);
    }
    if(loop==2)return 1;
    else return 0;
}

int layout2x1(char op1[],char op2[],char op3[],int* escolha){
    int x,y,navegador[3],loop;
    char cursor[2][2];
    for(x=0;x<3;x++){
            navegador[x]=0;
    }
    x=y=0;
    navegador[0]=1;
    cursor[0][0]=' ';cursor[0][1] =' ';
    cursor[1][0]='-';cursor[1][1] ='>';
    loop=0;
    *escolha=0;
    while(loop==0){
        system("cls");
        loop=menu2x1(op1,op2,op3,cursor,navegador,&x,&y,escolha);
    }
    if(loop==2)return 1;
    else return 0;
}

int layout2x2(char op1[],char op2[],char op3[],char op4[],int* escolha){
    int x,y,navegador[4],loop;
    char cursor[2][2];
    for(x=0;x<4;x++){
            navegador[x]=0;
    }
    x=y=0;
    navegador[0]=1;
    cursor[0][0]=' ';cursor[0][1] =' ';
    cursor[1][0]='-';cursor[1][1] ='>';
    loop=0;
    *escolha=0;
    while(loop==0){
        system("cls");
        loop=menu2x2(op1,op2,op3,op4,cursor,navegador,&x,&y,escolha);
    }
    if(loop==2)return 1;
    else return 0;
}

/*int layout_batalha(Atributos_parciais* heroi,Atributos_parciais* inimigo){
    int x,y,navegador[4],loop;
    char cursor[2][2];
    for(x=0;x<4;x++){
            navegador[x]=0;
    }
    x=y=0;
    navegador[0]=1;
    cursor[0][0]=' ';cursor[0][1] =' ';
    cursor[1][0]='-';cursor[1][1] ='>';
    loop=0;
    *escolha=0;
    while(loop==0){
        system("cls");
        printar_interface(heroi,inimigo);
        loop=menu2x1("atacar","abrir inventario","fugir",cursor,navegador,&x,&y,escolha);
    }
    if(loop==2)return 1;
    else return 0;
}*/

int layout3x2(char op1[],char op2[],char op3[],char op4[],char op5[],int* escolha){
    int x,y,navegador[5],loop;
    char cursor[2][2];
    for(x=0;x<5;x++){
            navegador[x]=0;
    }
    x=y=0;
    navegador[0]=1;
    cursor[0][0]=' ';cursor[0][1] =' ';
    cursor[1][0]='-';cursor[1][1] ='>';
    loop=0;
    *escolha=0;
    while(loop==0){
        system("cls");
        loop=menu3x2(op1,op2,op3,op4,op5,cursor,navegador,&x,&y,escolha);
    }
    if(loop==2)return 1;
    else return 0;
}

int layout3x3(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],int* escolha){
    int x,y,navegador[6],loop;
    char cursor[2][2];
    for(x=0;x<6;x++){
            navegador[x]=0;
    }
    x=y=0;
    navegador[0]=1;
    cursor[0][0]=' ';cursor[0][1] =' ';
    cursor[1][0]='-';cursor[1][1] ='>';
    loop=0;
    *escolha=0;
    while(loop==0){
        system("cls");
        loop=menu3x3(op1,op2,op3,op4,op5,op6,cursor,navegador,&x,&y,escolha);
    }
    if(loop==2)return 1;
    else return 0;
}

int layout4x3(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],char op7[],int* escolha){
    int x,y,navegador[7],loop;
    char cursor[2][2];
    for(x=0;x<7;x++){
            navegador[x]=0;
    }
    x=y=0;
    navegador[0]=1;
    cursor[0][0]=' ';cursor[0][1] =' ';
    cursor[1][0]='-';cursor[1][1] ='>';
    loop=0;
    *escolha=0;
    while(loop==0){
        system("cls");
        loop=menu4x3(op1,op2,op3,op4,op5,op6,op7,cursor,navegador,&x,&y,escolha);
    }
    if(loop==2)return 1;
    else return 0;
}

int layout4x4(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],char op7[],char op8[],int* escolha){
    int x,y,navegador[8],loop;
    char cursor[2][2];
    for(x=0;x<8;x++){
            navegador[x]=0;
    }
    x=y=0;
    navegador[0]=1;
    cursor[0][0]=' ';cursor[0][1] =' ';
    cursor[1][0]='-';cursor[1][1] ='>';
    loop=0;
    *escolha=0;
    while(loop==0){
        system("cls");
        loop=menu4x4(op1,op2,op3,op4,op5,op6,op7,op8,cursor,navegador,&x,&y,escolha);
    }
    if(loop==2)return 1;
    else return 0;
}

int layout5x4(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],char op7[],char op8[],char op9[],int* escolha){
    int x,y,navegador[9],loop;
    char cursor[2][2];
    for(x=0;x<9;x++){
            navegador[x]=0;
    }
    x=y=0;
    navegador[0]=1;
    cursor[0][0]=' ';cursor[0][1] =' ';
    cursor[1][0]='-';cursor[1][1] ='>';
    loop=0;
    *escolha=0;
    while(loop==0){
        system("cls");
        loop=menu5x4(op1,op2,op3,op4,op5,op6,op7,op8,op9,cursor,navegador,&x,&y,escolha);
    }
    if(loop==2)return 1;
    else return 0;
}


int typeLayout(char tags[][60],int* respota,int verificacao){
    int loop=0;
   
    switch(verificacao){
        case 2:{
            verificacao+=layout1x1(tags[1],tags[2],respota);
            break;
        }
        case 3:{
            loop=layout2x1(tags[1],tags[2],tags[3],respota);
            if(loop==0)verificacao--;
            else verificacao++;
            break;
        }
        case 4:{
            loop=layout2x2(tags[1],tags[2],tags[3],tags[4],respota);
            if(loop==0)verificacao--;
            else verificacao++;
            break;
        }
        case 5:{
            loop=layout3x2(tags[1],tags[2],tags[3],tags[4],tags[5],respota);
            if(loop==0)verificacao--;
            else verificacao++;
            break;
        }
        case 6:{
            loop=layout3x3(tags[1],tags[2],tags[3],tags[4],tags[5],tags[6],respota);
            if(loop==0)verificacao--;
            else verificacao++;
            break;
        }
        case 7:{
            loop=layout4x3(tags[1],tags[2],tags[3],tags[4],tags[5],tags[6],tags[7],respota);
            if(loop==0)verificacao--;
            else verificacao++;
            break;
        }
        case 8:{
            loop=layout4x4(tags[1],tags[2],tags[3],tags[4],tags[5],tags[6],tags[7],tags[8],respota);
            if(loop==0)verificacao--;
            else verificacao++;
            break;
        }
        case 9:{
            loop=layout5x4(tags[1],tags[2],tags[3],tags[4],tags[5],tags[6],tags[7],tags[8],tags[9],respota);
            if(loop==0)verificacao--;
            else verificacao++;
            break;
        }

    }
    if(verificacao==2 && *respota==1); //break;
    
   *respota += 1;
}
#endif
