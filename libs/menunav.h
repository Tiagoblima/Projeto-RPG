#ifndef MENUNAV_H_INCLUDED
#define MENUNAV_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

typedef struct{
    float ataque,defesa,vida,mana;
    char nome[30];
    int lv;
}Atributos_parciais;


void pegar_tamanho1x1(char op1[],int *Top1,char op2[],int *Top2){
    *Top1=strlen(op1);
    *Top2=strlen(op2);
}

void pegar_tamanho2x1(char op1[],int *Top1,char op2[],int *Top2,char op3[],int* Top3 ){
    *Top1=strlen(op1);
    *Top2=strlen(op2);
    *Top3=strlen(op3);
}

void pegar_tamanho2x2(char op1[],int *Top1,char op2[],int *Top2,char op3[],int* Top3,char op4[],int*Top4 ){
    *Top1=strlen(op1);
    *Top2=strlen(op2);
    *Top3=strlen(op3);
    *Top4=strlen(op4);
}

void pegar_tamanho3x2(char op1[],int *Top1,char op2[],int *Top2,char op3[],int* Top3,char op4[],int*Top4,char op5[],int* Top5 ){
    *Top1=strlen(op1);
    *Top2=strlen(op2);
    *Top3=strlen(op3);
    *Top4=strlen(op4);
    *Top5=strlen(op5);
}

void pegar_tamanho3x3(char op1[],int *Top1,char op2[],int *Top2,char op3[],int* Top3,char op4[],int*Top4,char op5[],int* Top5,char op6[],int*Top6 ){
    *Top1=strlen(op1);
    *Top2=strlen(op2);
    *Top3=strlen(op3);
    *Top4=strlen(op4);
    *Top5=strlen(op5);
    *Top6=strlen(op6);
}

void pegar_tamanho4x3(char op1[],int *Top1,char op2[],int *Top2,char op3[],int* Top3,char op4[],int*Top4,char op5[],int* Top5,char op6[],int*Top6,char op7[],int* Top7 ){
    *Top1=strlen(op1);
    *Top2=strlen(op2);
    *Top3=strlen(op3);
    *Top4=strlen(op4);
    *Top5=strlen(op5);
    *Top6=strlen(op6);
    *Top7=strlen(op7);
}

void pegar_tamanho4x4(char op1[],int *Top1,char op2[],int *Top2,char op3[],int* Top3,char op4[],int*Top4,char op5[],int* Top5,char op6[],int*Top6,char op7[],int* Top7,char op8[],int* Top8){
    *Top1=strlen(op1);
    *Top2=strlen(op2);
    *Top3=strlen(op3);
    *Top4=strlen(op4);
    *Top5=strlen(op5);
    *Top6=strlen(op6);
    *Top7=strlen(op7);
    *Top8=strlen(op8);
}

void pegar_tamanho5x4(char op1[],int *Top1,char op2[],int *Top2,char op3[],int* Top3,char op4[],int*Top4,char op5[],int* Top5,char op6[],int*Top6,char op7[],int* Top7,char op8[],int* Top8,char op9[],int* Top9 ){
    *Top1=strlen(op1);
    *Top2=strlen(op2);
    *Top3=strlen(op3);
    *Top4=strlen(op4);
    *Top5=strlen(op5);
    *Top6=strlen(op6);
    *Top7=strlen(op7);
    *Top8=strlen(op8);
    *Top9=strlen(op9);
}

int checar_tamanho_2(int x, int y){
    if(x>y)return x;
    else return y;
}

int checar_tamanho_3(int x,int y,int z){
    if(x>y){
        if(x>z)return x;
        else return z;
    }
    else{
        if(y>z)return y;
        else return z;
    }
}

int checar_tamanho_4(int x,int y, int z,int w){
    if(x>y){
        if(w>z){
            if(x>w)return x;
            else return w;
        }
        else{
            if(x>z)return x;
            else return z;
        }
    }
    else{
        if(w>z){
            if(y>w)return y;
            else return w;
        }
        else{
            if(y>z)return y;
            else return z;
        }
    }
}

int checar_tamanho_5(int x,int y,int z,int w,int u){
    if(x>y){
        if(z>w){
            if(x>z){
                if(x>u)return x;
                else return u;
            }
            else{
                if(z>u)return z;
                else return u;
            }
        }
        else{
            if(x>w){
                if(x>u)return x;
                else return u;
            }
            else{
                if(w>u)return w;
                else return u;
            }
        }
    }
    else{
        if(z>w){
            if(y>z){
                if(y>u)return y;
                else return u;
            }
            else{
                if(z>u)return z;
                else return u;
            }
        }
        else{
            if(y>w){
                if(y>u)return y;
                else return u;
            }
            else{
                if(w>u)return w;
                else return u;
            }
        }
    }
}



void interface_linha_superior(){
    int x;
    printf("   %c",201);
    for(x=0;x<70;x++){
        printf("%c",205);
    }
    printf("%c\n",187);
}

void interface_lateral_simplis(char op1[],char cursor[][2],int navegador[],int posisao,int Tes){
    int x=64,y;
    x-=Tes;
    printf("   %c",186);
    printf("    %c%c%s",cursor[navegador[posisao]][0],cursor[navegador[posisao]][1],op1);
    for(y=0;y<x;y++){
        putchar(' ');
    }
    printf("%c\n",186);
}



void interface_lateral_dupla(char op1[],char op2[],char cursor[][2],int navegador[],int posisao,int Tes,int Tdi,int Tmax){
    int x=54,y,a;
    a=Tmax-Tes+8;
    x=66-Tmax-12-Tdi;
    printf("   %c",186);
    printf("    %c%c%s",cursor[navegador[posisao]][0],cursor[navegador[posisao]][1],op1);
    for(y=0;y<a;y++)putchar(' ');
    printf("%c%c%-s",cursor[navegador[posisao+1]][0],cursor[navegador[posisao+1]][1],op2);
    for(y=0;y<x;y++)putchar(' ');
    printf("%c\n",186);
}

void interface_linha_horizontais(){
    int x;
    printf("   %c",204);
    for(x=0;x<70;x++){
        printf("%c",205);
    }
    printf("%c\n",185);
}


void interface_linha_inferior(){
    int x;
    printf("   %c",200);
    for(x=0;x<70;x++){
        printf("%c",205);
    }
    printf("%c",188);
}

int navegador1x0(){
    int z;
    z=getch();
    if(z==13)return 0;
    else if(z==27)return 1;
    else return 3;
}

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
int menu1x0(char op1[],char cursor[][2],int navegador[],int Top1){
    interface_linha_superior();
    interface_lateral_simplis(op1,cursor,navegador,0,Top1);
    interface_linha_inferior();
    int l=3;
    l=navegador1x0();
    if(l==3){
        return 0;
    }
    else if(l==1){
        return 1;
    }
    else return 2;

}

int menu1x1(char op1[],char op2[],char cursor[][2],int navegador[],int* x, int* y,int* escolha,int Top1,int Top2){
    interface_linha_superior();
    interface_lateral_dupla(op1,op2,cursor,navegador,0,Top1,Top2,Top1);
    interface_linha_inferior();
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

int menu2x1(char op1[],char op2[],char op3[],char cursor[][2],int navegador[],int* x, int* y,int* escolha,int Top1,int Top2,int Top3,int Tmax){
    interface_linha_superior();
    interface_lateral_dupla(op1,op2,cursor,navegador,0,Top1,Top2,Tmax);
    interface_lateral_simplis(op3,cursor,navegador,2,Top3);
    interface_linha_inferior();
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

int menu2x2(char op1[],char op2[],char op3[],char op4[],char cursor[][2],int navegador[],int* x, int* y,int* escolha,int Top1,int Top2,int Top3,int Top4,int Tmax){
    interface_linha_superior();
    interface_lateral_dupla(op1,op2,cursor,navegador,0,Top1,Top2,Tmax);
    interface_lateral_dupla(op3,op4,cursor,navegador,2,Top3,Top4,Tmax);
    interface_linha_inferior();
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

int menu3x2(char op1[],char op2[],char op3[],char op4[],char op5[],char cursor[][2],int navegador[],int* x, int* y,int* escolha,int Top1,int Top2,int Top3,int Top4,int Top5,int Tmax){
    interface_linha_superior();
    interface_lateral_dupla(op1,op2,cursor,navegador,0,Top1,Top2,Tmax);
    interface_lateral_dupla(op3,op4,cursor,navegador,2,Top3,Top4,Tmax);
    interface_lateral_simplis(op5,cursor,navegador,4,Top5);
    interface_linha_inferior();
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

int menu3x3(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],char cursor[][2],int navegador[],int* x, int* y,int* escolha,int Top1,int Top2,int Top3,int Top4,int Top5,int Top6,int Tmax){
    interface_linha_superior();
    interface_lateral_dupla(op1,op2,cursor,navegador,0,Top1,Top2,Tmax);
    interface_lateral_dupla(op3,op4,cursor,navegador,2,Top3,Top4,Tmax);
    interface_lateral_dupla(op5,op6,cursor,navegador,4,Top5,Top6,Tmax);
    interface_linha_inferior();
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

int menu4x3(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],char op7[],char cursor[][2],int navegador[],int* x, int* y,int* escolha,int Top1,int Top2,int Top3,int Top4,int Top5,int Top6,int Top7,int Tmax){
    interface_linha_superior();
    interface_lateral_dupla(op1,op2,cursor,navegador,0,Top1,Top2,Tmax);
    interface_lateral_dupla(op3,op4,cursor,navegador,2,Top3,Top4,Tmax);
    interface_lateral_dupla(op5,op6,cursor,navegador,4,Top5,Top6,Tmax);
    interface_lateral_simplis(op7,cursor,navegador,6,Top7);
    interface_linha_inferior();
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

int menu4x4(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],char op7[],char op8[],char cursor[][2],int navegador[],int* x, int* y,int* escolha,int Top1,int Top2,int Top3,int Top4,int Top5,int Top6,int Top7,int Top8,int Tmax){
    interface_linha_superior();
    interface_lateral_dupla(op1,op2,cursor,navegador,0,Top1,Top2,Tmax);
    interface_lateral_dupla(op3,op4,cursor,navegador,2,Top3,Top4,Tmax);
    interface_lateral_dupla(op5,op6,cursor,navegador,4,Top5,Top6,Tmax);
    interface_lateral_dupla(op7,op8,cursor,navegador,6,Top7,Top8,Tmax);
    interface_linha_inferior();
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

int menu5x4(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],char op7[],char op8[],char op9[],char cursor[][2],int navegador[],int* x, int* y,int* escolha,int Top1,int Top2,int Top3,int Top4,int Top5,int Top6,int Top7,int Top8,int Top9,int Tmax){
    interface_linha_superior();
    interface_lateral_dupla(op1,op2,cursor,navegador,0,Top1,Top2,Tmax);
    interface_lateral_dupla(op3,op4,cursor,navegador,2,Top3,Top4,Tmax);
    interface_lateral_dupla(op5,op6,cursor,navegador,4,Top5,Top6,Tmax);
    interface_lateral_dupla(op7,op8,cursor,navegador,6,Top7,Top8,Tmax);
    interface_lateral_simplis(op9,cursor,navegador,8,Top9);
    interface_linha_inferior();
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

int layout1x0(char op1[],int* escolha){
   int Top1;
    Top1=strlen(op1);
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
        printf("\n");
        loop=menu1x0(op1,cursor,navegador,Top1);
    }
    if(loop==2)return 1;
    else return 0;
}

int layout1x1(char op1[],char op2[],int* escolha){
    int Top1,Top2;
    pegar_tamanho1x1(op1,&Top1,op2,&Top2);
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
        printf("\n");
        loop=menu1x1(op1,op2,cursor,navegador,&x,&y,escolha,Top1,Top2);
    }
    if(loop==2)return 1;
    else return 0;
}

int layout2x1(char op1[],char op2[],char op3[],int* escolha){
    int Top1,Top2,Top3,Tmax;
    pegar_tamanho2x1(op1,&Top1,op2,&Top2,op3,&Top3);
    Tmax=checar_tamanho_2(Top1,Top3);
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
        printf("\n");
        loop=menu2x1(op1,op2,op3,cursor,navegador,&x,&y,escolha,Top1,Top2,Top3,Tmax);
    }
    if(loop==2)return 1;
    else return 0;
}

int layout2x2(char op1[],char op2[],char op3[],char op4[],int* escolha){
    int Top1,Top2,Top3,Top4,T;
    pegar_tamanho2x2(op1,&Top1,op2,&Top2,op3,&Top3,op4,&Top4);
    T=checar_tamanho_2(Top1,Top3);
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
        printf("\n");
        loop=menu2x2(op1,op2,op3,op4,cursor,navegador,&x,&y,escolha,Top1,Top2,Top3,Top4,T);
    }
    if(loop==2)return 1;
    else return 0;
}


int layout3x2(char op1[],char op2[],char op3[],char op4[],char op5[],int* escolha){
    int Top1,Top2,Top3,Top4,Top5,T;
    pegar_tamanho3x2(op1,&Top1,op2,&Top2,op3,&Top3,op4,&Top4,op5,&Top5);
    T=checar_tamanho_3(Top1,Top3,Top5);
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
        printf("\n");
        loop=menu3x2(op1,op2,op3,op4,op5,cursor,navegador,&x,&y,escolha,Top1,Top2,Top3,Top4,Top5,T);
    }
    if(loop==2)return 1;
    else return 0;
}

int layout3x3(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],int* escolha){
    int Top1,Top2,Top3,Top4,Top5,Top6,T;
    pegar_tamanho3x3(op1,&Top1,op2,&Top2,op3,&Top3,op4,&Top4,op5,&Top5,op6,&Top6);
    T=checar_tamanho_3(Top1,Top3,Top5);
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
        printf("\n");
        loop=menu3x3(op1,op2,op3,op4,op5,op6,cursor,navegador,&x,&y,escolha,Top1,Top2,Top3,Top4,Top5,Top6,T);
    }
    if(loop==2)return 1;
    else return 0;
}

int layout4x3(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],char op7[],int* escolha){
    int Top1,Top2,Top3,Top4,Top5,Top6,Top7,T;
    pegar_tamanho4x3(op1,&Top1,op2,&Top2,op3,&Top3,op4,&Top4,op5,&Top5,op6,&Top6,op7,&Top7);
    T=checar_tamanho_4(Top1,Top3,Top5,Top7);
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
        printf("\n");
        loop=menu4x3(op1,op2,op3,op4,op5,op6,op7,cursor,navegador,&x,&y,escolha,Top1,Top2,Top3,Top4,Top5,Top6,Top7,T);
    }
    if(loop==2)return 1;
    else return 0;
}

int layout4x4(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],char op7[],char op8[],int* escolha){
    int Top1,Top2,Top3,Top4,Top5,Top6,Top7,Top8,T;
    pegar_tamanho4x4(op1,&Top1,op2,&Top2,op3,&Top3,op4,&Top4,op5,&Top5,op6,&Top6,op7,&Top7,op8,&Top8);
    T=checar_tamanho_4(Top1,Top3,Top5,Top7);
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
        printf("\n");
        loop=menu4x4(op1,op2,op3,op4,op5,op6,op7,op8,cursor,navegador,&x,&y,escolha,Top1,Top2,Top3,Top4,Top5,Top6,Top7,Top8,T);
    }
    if(loop==2)return 1;
    else return 0;
}

int layout5x4(char op1[],char op2[],char op3[],char op4[],char op5[],char op6[],char op7[],char op8[],char op9[],int* escolha){
    int Top1,Top2,Top3,Top4,Top5,Top6,Top7,Top8,Top9,T;
    pegar_tamanho5x4(op1,&Top1,op2,&Top2,op3,&Top3,op4,&Top4,op5,&Top5,op6,&Top6,op7,&Top7,op8,&Top8,op9,&Top9);
    T=checar_tamanho_5(Top1,Top3,Top5,Top7,Top9);
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
        printf("\n/*");
        loop=menu5x4(op1,op2,op3,op4,op5,op6,op7,op8,op9,cursor,navegador,&x,&y,escolha,Top1,Top2,Top3,Top4,Top5,Top6,Top7,Top8,Top9,T);
    }
    if(loop==2)return 1;
    else return 0;
}
int typeLayout(char tags[][60],int* respota,int verificacao){
    int loop=0;

    switch(verificacao){
    	case 1:
		{
			verificacao+=layout1x0(tags[1],respota);
		}
    	
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



#endif // MENUNAV_H_INCLUDED
