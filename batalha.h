#ifndef BATALHA_H_INCLUDED
#define BATALHA_H_INCLUDED



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <menunav.h>
#include <math.h>
#include <cadastro.h>

typedef struct{
    int existencia,itensidade,duracao;
    float efeito;
}Buff;

typedef struct{
    Buff hemorragia,queimadura,veneno,atordoar,silencio,medo,fortalecer,enfraquecer,cura,armagedon,pocao_HP,pocao_MP,pocao_ZD;
    float efeito;
}Buff_Debuff;


int D4(){
    int valor=1+rand()%4;
    return valor;
}

int D6(){
    int valor=1+rand()%6;
    return valor;
}

int D8(){
    int valor=1+rand()%8;
    return valor;
}

int D10(){
    int valor=1+rand()%10;
    return valor;
}

int D12(){
    int valor=1+rand()%12;
    return valor;
}

int D20(){
     int valor=1+rand()%20;
    return valor;
}

float critico(){
    float critico=1;
    int chance=D4();
    if(chance==4){
        critico=1.25;
        chance=D4();
        if(chance>=3){
            critico=1.5;
            chance=D4();
            if(chance==4){
                critico=1.75;
                chance=D4();
                if(chance>=2){
                    critico=2;
                    chance=D20();
                    if(chance==20){
                        critico=4;
                        printf("\n critico supremo de de 3x ");
                    }
                    else printf("\n critico de 2x");
                }
                else printf("critico de 75%c",'%');
            }
            else printf("\n critico de 50%c",'%');
        }
        else printf("\n critico de 25%c",'%');
    }
    return critico;
}

float critico_ult(){
    float critico=1;
    int chance=4;
    if(chance==4){
        critico=1.25;
        chance=4;
        if(chance>=3){
            critico=1.5;
            chance=D4();
            if(chance>=2){
                critico=1.75;
                chance=D4();
                if(chance>=2){
                    critico=2;
                    chance=D4();
                    if(chance==4){
                        critico=4;
                        chance=D4();
                        if(chance==4){
                            critico=5;
                            chance=D10();
                            if(chance==10){
                                critico=6;
                                printf("\n critico supremo de 5x");
                            }
                            else printf("\n critco de 4x");
                        }
                        printf("\n critico supremo de de 3x ");
                    }
                    else printf("\n critico de 100%c",'%');
                }
                else printf("\n critico de 75%c",'%');
            }
            else printf("\n critico de 50%c",'%');
        }
        else printf("\n critico de 25%c",'%');
    }
    return critico;
}

void printar_interface(Atributos_parciais* heroi,Atributos_parciais* inimigo){
    system("cls");
    printf("\n%s\t %s\n vida:%.2f\t vida:%.2f\n mana:%.2f\t mana:infinita\n ataque:%.1f\t ataque:%.1f\n defesa:%.1f\t defesa:%.1f",heroi->nome,inimigo->nome,(*heroi).vida,(*inimigo).vida,(*heroi).mana,(*heroi).ataque,(*inimigo).ataque,(*heroi).defesa,(*inimigo).defesa);
    printf("\n faca seu movimento\n\n");
}
void receber_valores(Atributos_parciais *numero,Personagem *boneco){
    numero->ataque=boneco->ataque;
    numero->defesa=boneco->defesa;
    numero->vida=boneco->vida;
    numero->mana=boneco->mana;
    strcpy((*numero).nome,(*boneco).nome);
}

void receber_valores_heroi(Atributos_parciais *numero,Personagem *boneco){
    numero->ataque=boneco->ataque_base;
    numero->defesa=boneco->defesa_base;
    numero->vida=boneco->vida_base;
    numero->mana=boneco->mana_base;
    strcpy((*numero).nome,(*boneco).nome);
}

void receber_valores_inimigo(Atributos_parciais *numero,Personagem* espelho,Inimigo *boneco){
    numero->ataque=espelho->ataque=espelho->ataque_base=boneco->ataque;
    numero->defesa=espelho->defesa=espelho->defesa_base=boneco->defesa;
    numero->vida=espelho->vida=espelho->vida_base=boneco->vida;
    espelho->mana=99999999;
    strcpy((*numero).nome,(*boneco).nome);
    strcpy((*espelho).nome,(*boneco).nome);
}

void zerando_um_buff(Buff* viajado){
    viajado->efeito=viajado->duracao=viajado->existencia=viajado->itensidade=0;
}

void zerando_tudo(Buff_Debuff* viagem){
    zerando_um_buff(&viagem->atordoar);
    zerando_um_buff(&viagem->armagedon);
    zerando_um_buff(&viagem->atordoar);
    zerando_um_buff(&viagem->cura);
    zerando_um_buff(&viagem->enfraquecer);
    zerando_um_buff(&viagem->hemorragia);
    zerando_um_buff(&viagem->medo);
    zerando_um_buff(&viagem->queimadura);
    zerando_um_buff(&viagem->silencio);
    zerando_um_buff(&viagem->veneno);
    zerando_um_buff(&viagem->pocao_HP);
    zerando_um_buff(&viagem->pocao_MP);
    zerando_um_buff(&viagem->pocao_ZD);
    zerando_um_buff(&viagem->fortalecer);
}

void zerando_maldicoes(Buff_Debuff* viagem){
    zerando_um_buff(&viagem->atordoar);
    zerando_um_buff(&viagem->atordoar);
    zerando_um_buff(&viagem->enfraquecer);
    zerando_um_buff(&viagem->hemorragia);
    zerando_um_buff(&viagem->medo);
    zerando_um_buff(&viagem->queimadura);
    zerando_um_buff(&viagem->silencio);
    zerando_um_buff(&viagem->veneno);
}

void receber_informacoes(Inimigo* alvo,Personagem* corpo_heroi,Personagem* corpo_inimigo,Atributos_parciais* atributo_heroi,Atributos_parciais* atributo_inimigo,Buff_Debuff* s_heroi,Buff_Debuff* s_inimigo){
    receber_valores_heroi(atributo_heroi,corpo_heroi);
    receber_valores_inimigo(atributo_inimigo,corpo_inimigo,alvo);
    zerando_tudo(s_heroi);
    zerando_tudo(s_inimigo);
}


void efeito_hemorragia(Buff_Debuff* maldicao,Atributos_parciais* bruxo,Personagem* amaldicoado,float* dano){
    if((*maldicao).hemorragia.itensidade>5){
        (*maldicao).hemorragia.efeito=2*(*bruxo).ataque+0.05*(5-(*maldicao).hemorragia.itensidade)*(*amaldicoado).vida;
        *dano-=(*maldicao).hemorragia.efeito;
    }
    else{
        (*maldicao).hemorragia.efeito=0.15*(*bruxo).ataque*(*maldicao).hemorragia.itensidade;
        *dano-=(*maldicao).hemorragia.efeito;
    }
    printf("\n hemorragia de itensidade %i causou %.2f de dano, com %i turnos restantes",(*maldicao).hemorragia.itensidade,(*maldicao).hemorragia.efeito/10,(*maldicao).hemorragia.duracao);
    (*maldicao).hemorragia.duracao--;
    if((*maldicao).hemorragia.duracao==0){
        (*maldicao).hemorragia.itensidade=0;
        (*maldicao).hemorragia.existencia=0;
    }
}

void efeito_veneno(Buff_Debuff* maldicao,Personagem* amaldicoado,float* dano){
    (*maldicao).veneno.efeito=(*maldicao).veneno.itensidade*0.08*(*amaldicoado).vida;
    *dano-=(*maldicao).veneno.efeito;
    printf("\n veneno de itensidade %i causou %.2f de dano, com %i turnos restantes",(*maldicao).veneno.itensidade,(*maldicao).veneno.efeito/10,(*maldicao).veneno.duracao);
    (*maldicao).veneno.duracao--;
    if((*maldicao).veneno.duracao==0){
        (*maldicao).veneno.existencia=0;
        (*maldicao).veneno.itensidade=0;
    }
}

void efeito_queimadura(Buff_Debuff* maldicao,Atributos_parciais* bruxo,float* dano){
    (*maldicao).queimadura.efeito=0.14*(*bruxo).ataque*(*maldicao).queimadura.itensidade;
    *dano-=(*maldicao).queimadura.efeito;
    printf("\n queimadura de itensidade %i causou %.2f de dano, com %i turnos restantes",(*maldicao).queimadura.itensidade,(*maldicao).queimadura.efeito/10,(*maldicao).queimadura.duracao);
    (*maldicao).queimadura.duracao--;
    if((*maldicao).queimadura.duracao==0){
        (*maldicao).queimadura.existencia=0;
        (*maldicao).queimadura.itensidade=0;
    }
}

void efeito_armagedon(Buff_Debuff* maldicao,Personagem* bruxo,float* dano){
    (*maldicao).armagedon.efeito=(*maldicao).armagedon.itensidade*1.2*(*bruxo).vida;
    *dano-=(*maldicao).armagedon.efeito;
    (*maldicao).armagedon.duracao--;
    if((*maldicao).armagedon.duracao==0){
        (*maldicao).armagedon.existencia=0;
        (*maldicao).armagedon.itensidade=0;
    }
}

void efeito_medo(Buff_Debuff* maldicao,Personagem* amaldicoado,int* rng){
    if((*maldicao).medo.existencia==1){
        if((*maldicao).medo.itensidade==1){
            printf("\n %s esta com medo",amaldicoado->nome);
            *rng-=1;
        }
        else if((*maldicao).medo.itensidade==2){
            printf("\n %s esta com muito medo",amaldicoado->nome);
            *rng-=2;
        }
        else if((*maldicao).medo.itensidade>=3){
            printf("\n %s esta totalmente apavorado",amaldicoado->nome);
            *rng-=3;
        }
        (*maldicao).medo.duracao--;
        if((*maldicao).medo.duracao==0){
            (*maldicao).medo.existencia=0;
            printf("\n %s esta com medo",amaldicoado->nome);
        }
    }
}

void efeito_atordoar(Buff_Debuff* maldicao,Personagem* amaldicoado,int* escolha){
    if((*maldicao).atordoar.existencia==1){
        printf("\n %s esta atordoado e por isso nao pode atacar, %i turnos restantes\n",amaldicoado->nome,(*maldicao).atordoar.duracao);
        if(*escolha!=2)(*escolha)=15;
        (*maldicao).atordoar.duracao--;
        if((*maldicao).atordoar.duracao==0)(*maldicao).atordoar.existencia=0;
    }
}

void efeito_silencio(Buff_Debuff* maldicao,Personagem* amaldicoado,int* escolha){
    if((*maldicao).silencio.existencia==1){
        printf("\n %s esta silenciado e por isso nao usar habilidades, %i turnos restantes\n",amaldicoado->nome,(*maldicao).silencio.duracao);
        if(*escolha!=1)*escolha=15;
        (*maldicao).silencio.duracao--;
        if((*maldicao).silencio.duracao==0)(*maldicao).silencio.existencia=0;
    }
}

void efeito_enfraquecer(Buff_Debuff* maldicao,Personagem* boneco,Atributos_parciais* amaldicoado){
    char potcento='%';
    if((*maldicao).enfraquecer.existencia==1){
        printf("\nativado\n");
        (*amaldicoado).ataque=(1-(0.1*(*maldicao).enfraquecer.itensidade))*(*amaldicoado).ataque;
        (*amaldicoado).vida=(1-(0.1*(*maldicao).enfraquecer.itensidade))*(*amaldicoado).vida;
        (*amaldicoado).defesa=(1-(0.1*(*maldicao).enfraquecer.itensidade))*(*amaldicoado).defesa;
        (*maldicao).enfraquecer.duracao--;
        (*maldicao).fortalecer.existencia=-1;
        printf("\n\n efeito debilitante enfraquecer de grau %i ,diminuiu seus atributos em %i %c com %i turnos restantes",(*maldicao).enfraquecer.itensidade,(*maldicao).enfraquecer.itensidade*10,potcento,(*maldicao).enfraquecer.duracao);
        if((*maldicao).enfraquecer.duracao==0){
            (*maldicao).enfraquecer.existencia=0;
            (*maldicao).enfraquecer.itensidade=0;
            receber_valores(amaldicoado,boneco);
        }
    }
    else if((*maldicao).enfraquecer.existencia==-1){
        (*maldicao).enfraquecer.duracao--;
        (*maldicao).fortalecer.existencia=-1;
        printf("\n\n efeito debilitante enfraquecer de grau %i ,diminuiu seus atributos em %i %c com %i turnos restantes",(*maldicao).enfraquecer.itensidade,(*maldicao).enfraquecer.itensidade*10,potcento,(*maldicao).enfraquecer.duracao);
        if((*maldicao).enfraquecer.duracao==0){
            (*maldicao).enfraquecer.existencia=0;
            (*maldicao).enfraquecer.itensidade=0;
            receber_valores_heroi(amaldicoado,boneco);
        }
    }
}

void efeito_fortalecer(Buff_Debuff* maldicao,Personagem* boneco,Atributos_parciais* amaldicoado){
    char potcento='%';
    if((*maldicao).fortalecer.existencia==1){
        printf("\nativado\n");
        (*amaldicoado).ataque=(1+(0.2*(*maldicao).fortalecer.itensidade))*(*amaldicoado).ataque;
        (*amaldicoado).vida=(1+(0.2*(*maldicao).fortalecer.itensidade))*(*amaldicoado).vida;
        (*amaldicoado).defesa=(1+(0.2*(*maldicao).fortalecer.itensidade))*(*amaldicoado).defesa;
        (*maldicao).fortalecer.duracao--;
        (*maldicao).fortalecer.existencia=-1;

        printf("\n\n efeito amplificador fortalecer de grau %i ,aumentou seus atributos em %i %c com %i turnos restantes",(*maldicao).fortalecer.itensidade,(*maldicao).fortalecer.itensidade*20,potcento,(*maldicao).fortalecer.duracao);
        getch();
    }
    else if((*maldicao).fortalecer.existencia==-1){
        (*maldicao).fortalecer.duracao--;
        printf("\n\n efeito amplificador fortalecer de grau %i ,aumentou seus atributos em %i %c com %i turnos restantes",(*maldicao).fortalecer.itensidade,(*maldicao).fortalecer.itensidade*20,potcento,(*maldicao).fortalecer.duracao);
        getch();
        if((*maldicao).fortalecer.duracao==0){
                (*maldicao).fortalecer.existencia=0;
                (*maldicao).fortalecer.itensidade=0;
                receber_valores_heroi(amaldicoado,boneco);
            }
    }
}

void efeito_cura(Buff_Debuff* maldicao,Personagem* bruxo,Atributos_parciais* atributo_bruxo){
    float cura=0;
    (*maldicao).cura.efeito=(*maldicao).cura.itensidade*0.01*(*bruxo).vida;
    cura+=(*maldicao).cura.efeito;
    printf("\n cura de itensidade %i causou %.2f de cura, com %i turnos restantes",(*maldicao).cura.itensidade,(*maldicao).cura.efeito/10,(*maldicao).cura.duracao);
    (*atributo_bruxo).vida+=cura;    (*maldicao).cura.duracao--;
    if((*maldicao).cura.duracao==0){
        (*maldicao).cura.existencia=0;
        (*maldicao).cura.itensidade=0;
    }
}

void efeito_PHP(Buff_Debuff* maldicao,Personagem* bruxo,Atributos_parciais* atributo_bruxo){
    float cura;
    (*maldicao).pocao_HP.efeito=0.1*(*atributo_bruxo).vida;
    cura=(*maldicao).pocao_HP.efeito;
    printf("\n pocao de cura restaurou %.2f de vida, com %i turnos restantes",(*maldicao).pocao_HP.efeito,(*maldicao).pocao_HP.duracao);
    (*atributo_bruxo).vida+=cura;
    (*maldicao).pocao_HP.duracao--;
    if((*maldicao).pocao_HP.duracao==0){
        (*maldicao).pocao_HP.existencia=0;
    }
}

void efeito_PMP(Buff_Debuff* maldicao,Personagem* bruxo,Atributos_parciais* atributo_bruxo){
    float cura;
    (*maldicao).pocao_MP.efeito=0.1*(*bruxo).mana;
    cura=(*maldicao).pocao_MP.efeito;
    printf("\n pocao de mana restaurou %.2f de mana, com %i turnos restantes",(*maldicao).pocao_MP.efeito,(*maldicao).pocao_MP.duracao);
    (*atributo_bruxo).mana+=cura;
    (*maldicao).pocao_MP.duracao--;
    if((*maldicao).pocao_MP.duracao==0){
        (*maldicao).pocao_MP.existencia=0;
    }
}

void efeito_PZD(Buff_Debuff* maldicao){
    if((*maldicao).pocao_ZD.existencia!=0){
        int efeitosNegativos=(*maldicao).hemorragia.existencia+(*maldicao).veneno.existencia+(*maldicao).queimadura.existencia+(*maldicao).armagedon.existencia+(*maldicao).atordoar.existencia+(*maldicao).silencio.existencia+(*maldicao).enfraquecer.existencia;
        if(efeitosNegativos!=0){
            if((*maldicao).pocao_ZD.existencia==1)printf("\n pocao de remover efeitos negativos ativado");
            else printf("\n chefes de andar sao imunes a efeitos negativos");
            zerando_maldicoes(maldicao);
        }
        (*maldicao).pocao_ZD.duracao--;
        if((*maldicao).pocao_ZD.duracao==0){
            (*maldicao).pocao_ZD.existencia=0;
        }
      }
}

int aplicar_PHP(Buff_Debuff* amaldicoado,int* PHP){
    if(PHP>0){
        *PHP-=1;
        (*amaldicoado).pocao_HP.existencia=1;
        (*amaldicoado).pocao_HP.duracao=3;
        return 1;
    }
    else return 0;
}

int aplicar_PMP(Buff_Debuff* amaldicoado,int* PHP){
    if(PHP>0){
        *PHP-=1;
        (*amaldicoado).pocao_MP.existencia=1;
        (*amaldicoado).pocao_MP.duracao=3;
        return 1;
    }
    else return 0;
}

int aplicar_PZD(Buff_Debuff* amaldicoado,int* PHP){
    if(PHP>0){
        *PHP-=1;
        (*amaldicoado).pocao_ZD.existencia=1;
        (*amaldicoado).pocao_ZD.duracao=3;
        return 1;
    }
    else return 0;
}

void aplicar_hemorragia_passiva(Buff_Debuff* amaldicoado){
    (*amaldicoado).hemorragia.duracao=1;
    (*amaldicoado).hemorragia.itensidade=1;
    (*amaldicoado).hemorragia.duracao=3;
}

void aplicar_hemorragia(Buff_Debuff* amaldicoado){
    (*amaldicoado).hemorragia.existencia=1;
    (*amaldicoado).hemorragia.itensidade++;
    (*amaldicoado).hemorragia.duracao=3;
    if((*amaldicoado).hemorragia.itensidade==1)printf("\n e causou um sangramento");
    else if((*amaldicoado).hemorragia.itensidade>5)printf("\n a sede se tornou insasiavel");
    else printf("\n a sede de sangue esta aumentando");
}

void aplicar_atordoar(Buff_Debuff* amaldicoado){
    (*amaldicoado).atordoar.existencia=1;
    (*amaldicoado).atordoar.duracao=3;
    printf("\n e foi atordoado");
}

void aplicar_atordoar_passivo(Buff_Debuff* amaldicoado){
    int rng=D6();
    if(rng==6){
        (*amaldicoado).atordoar.existencia=1;
        (*amaldicoado).atordoar.duracao=1;
        printf("\n stun passivo ativado");
    }
    else printf("\n passivo nao ativada");
}

void aplicar_armagedon(Atributos_parciais* bruxo,Buff_Debuff* amaldicoado){
    int custo=0.2*bruxo->vida;
    bruxo->vida-=custo;
    (*amaldicoado).armagedon.duracao+=2;
    (*amaldicoado).armagedon.existencia=1;
    (*amaldicoado).armagedon.itensidade++;
    printf("\n AAAMAGEDON!");
}

void aplicar_curar(Buff_Debuff* amaldicoado){
     (*amaldicoado).cura.existencia=1;
     (*amaldicoado).cura.itensidade++;
     (*amaldicoado).cura.duracao=3;
     printf("\n cura foi realizada no alvo");
 }

void aplicar_queimadura(Buff_Debuff* amaldicoado){
    if((*amaldicoado).queimadura.existencia==1){
        int rng,chance;
        chance=3*(*amaldicoado).queimadura.itensidade;
        rng=D20();
        if(rng%chance==0)(*amaldicoado).queimadura.itensidade++;
    }
    else{
        (*amaldicoado).queimadura.existencia=1;
        (*amaldicoado).queimadura.itensidade=1;
    }
    (*amaldicoado).queimadura.duracao=3;
}

void aplicar_veneno(Buff_Debuff* amaldicoado){
    int rng,chance;
    if((*amaldicoado).veneno.existencia==1){
        chance=6*(*amaldicoado).veneno.itensidade;
        rng=D20();
        if(rng%chance==0){
            (*amaldicoado).veneno.itensidade++;
            printf("\n o veneno ficou mais potente");
            (*amaldicoado).veneno.duracao=3;
        }
        else printf("\n mas o ataque falou");
    }
    else{
        rng=D4();
        if(rng>2){
            (*amaldicoado).veneno.existencia=1;
            (*amaldicoado).veneno.duracao=3;
            (*amaldicoado).veneno.itensidade=1;
            printf("\n o veneno comeca a fazer efeito");
        }
    }
}

void aplicar_medo(Buff_Debuff* amaldicoado){
    if((*amaldicoado).medo.existencia==1){
        int rng,chance;
        chance=3*(*amaldicoado).medo.itensidade;
        rng=D20();
        if(rng%chance==0){
            (*amaldicoado).medo.itensidade++;
            printf("\n o medo esta cada vez maior");
        }
    }
    else{
        (*amaldicoado).medo.existencia=1;
        (*amaldicoado).medo.itensidade=1;
        printf("\n e comeca a ficar com medo");
    }
    (*amaldicoado).medo.duracao=3;
}

void aplicar_silencio(Buff_Debuff* amaldicoado){
    if((*amaldicoado).silencio.existencia==1){
        int rng,chance;
        chance=3*(*amaldicoado).silencio.itensidade;
        rng=D20();
        if(rng%chance==0)(*amaldicoado).silencio.itensidade++;
    }
    else{
        (*amaldicoado).silencio.existencia=1;
        (*amaldicoado).silencio.itensidade=1;
    }
    (*amaldicoado).silencio.duracao=3;
}

void aplicar_enfraquecer(Buff_Debuff* amaldicoado){
    if((*amaldicoado).enfraquecer.existencia==1){
        int rng,chance;
        chance=3*(*amaldicoado).enfraquecer.itensidade;
        rng=D20();
        if(rng%chance==0)(*amaldicoado).enfraquecer.itensidade++;
    }
    else{
        (*amaldicoado).enfraquecer.existencia=1;
        (*amaldicoado).enfraquecer.itensidade=1;
    }
    (*amaldicoado).enfraquecer.duracao=3;
}

void aplicar_fortalecer(Buff_Debuff* amaldicoado){
    if((*amaldicoado).fortalecer.existencia==1){
        int rng,chance;
        chance=3*(*amaldicoado).fortalecer.itensidade;
        rng=D20();
        if(rng%chance==0)(*amaldicoado).fortalecer.itensidade++;
    }
    else{
        (*amaldicoado).fortalecer.existencia=1;
        (*amaldicoado).fortalecer.itensidade=1;
    }
    (*amaldicoado).fortalecer.duracao=3;
}

void aplicar_fortalecer_ult(Buff_Debuff* amaldicoado){
    (*amaldicoado).fortalecer.existencia=1;
    (*amaldicoado).fortalecer.itensidade=7;
    (*amaldicoado).fortalecer.duracao=7;
}

void aplicar_queimadura_ult(Buff_Debuff* amaldicoado){
    (*amaldicoado).queimadura.existencia=1;
    (*amaldicoado).queimadura.itensidade=7;
    (*amaldicoado).queimadura.duracao=7;
}

void aplicar_enfraquecer_ult(Buff_Debuff* amaldicoado){
    (*amaldicoado).enfraquecer.existencia=1;
    (*amaldicoado).enfraquecer.itensidade=3;
    (*amaldicoado).enfraquecer.duracao=7;
}

float dano_por_turnos(Buff_Debuff* maldicao,Atributos_parciais* bruxo, Atributos_parciais* amaldicoado,Personagem* corpo_amaldicoado,Personagem* corpo_bruxo){
    float dps=0;
    if((*maldicao).hemorragia.existencia==1)efeito_hemorragia(maldicao,bruxo,corpo_amaldicoado,&dps);
    if((*maldicao).veneno.existencia==1)efeito_veneno(maldicao,corpo_amaldicoado,&dps);
    if((*maldicao).queimadura.existencia==1)efeito_queimadura(maldicao,bruxo,&dps);
    if((*maldicao).armagedon.existencia==1)efeito_armagedon(maldicao,corpo_bruxo,&dps);
    return dps;
}

void cura_por_turno(Personagem* corpo_heroi,Buff_Debuff* s_heroi,Atributos_parciais* atributo_heroi){
    if((*s_heroi).cura.existencia==1)efeito_cura(s_heroi,corpo_heroi,atributo_heroi);
    if((*s_heroi).pocao_HP.existencia==1)efeito_PHP(s_heroi,corpo_heroi,atributo_heroi);
    if((*s_heroi).pocao_MP.existencia==1)efeito_PMP(s_heroi,corpo_heroi,atributo_heroi);
}

float Dano_Total(int* rng, float ataque1,float* dps, float defesa){//////////calculo de dano atualizado
    float dano,reducao;
    if(defesa<=0)defesa=0.001;
    else if(defesa>=0 && defesa<100)defesa=defesa/2;
    else if(defesa>=100 && defesa<200)defesa=(100+defesa)/4;
    else if(defesa>=200 && defesa<300)defesa=(400+defesa)/8;
    else if(defesa>=300 && defesa<400)defesa=(1100+defesa)/16;
    else if(defesa>=400 && defesa<500)defesa=(2600+defesa)/32;
    else if(defesa>=500 && defesa<600)defesa=(5700+defesa)/64;
    else defesa=99;
    reducao=defesa/100;
    printf("\n\n rng de ataque %i\n",*rng);
    dano=(*dps)+(*rng)*ataque1*(1-reducao)*(-1);
    dano=dano/10;

    return dano;
}

void ataque_basico(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou um ataque basico em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D20();
    if(*rng==20){
        printf(" o golpe causou sangramento");
        aplicar_hemorragia_passiva(s_amaldicoado);
    }
    *rng=D4();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_normal(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s ataque normal em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D20();
    if(*rng==20){
        printf(" o golpe causou sangramento");
        aplicar_hemorragia_passiva(s_amaldicoado);
    }
    *rng=D6();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void corte_preciso(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou corte preciso em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D20();
    if(*rng==20){
        printf(" o golpe causou sangramento");
        aplicar_hemorragia_passiva(s_amaldicoado);
    }
    *rng=D6();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_forte(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou um ataque forte em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D20();
    if(*rng==20){
        printf(" o golpe causou sangramento");
        aplicar_hemorragia_passiva(s_amaldicoado);
    }
    *rng=D8();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_muito_forte(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou um ataque muito forte em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D20();
    if(*rng==20){
        printf(" o golpe causou sangramento");
        aplicar_hemorragia_passiva(s_amaldicoado);
    }
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_venenoso(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou um ataque venenoso em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_veneno(s_amaldicoado);
    *rng=D4();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_veneno_de_cobra(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou um veneno de cobra em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_veneno(s_amaldicoado);
    *rng=D8();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_veneno_anti_dragao(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou um veneno anti-dragao em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_veneno(s_amaldicoado);
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_ventania(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou ventania em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D10();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_rajada_de_vento(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s atacou com uma rajada de vento em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_furacao(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s atacou com um furacao %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_eletrico(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou um ataque eletrico em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D4();
    if(*rng==4){
        aplicar_atordoar(s_bruxo);
        printf(" o ataque eletricou foi suficiente para paralizar");
    }
    *rng=D10();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_eletrico_forte(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou um ataque eletrico forte em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D4();
    if(*rng==4){
        aplicar_atordoar(s_amaldicoado);
        printf(" o ataque eletricou foi suficiente para paralizar");
    }
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_eletrico_divino(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou um ataque eletrico divino em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D4();
    if(*rng==4){
        aplicar_atordoar(s_amaldicoado);
        printf(" o ataque eletricou foi suficiente para paralizar");
    }
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_bola_de_fogo(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou uma bola de fogo em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D4();
    if(*rng==1){
        printf(" a bola de fogo infligiu queimaduras");
        aplicar_queimadura(s_amaldicoado);
    }
    *rng=D10();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_rajada_de_fogo(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou uma rajada de fogo em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D10();
    if(*rng==4){
        printf(" a rajada de fogo infligiu queimaduras");
        aplicar_queimadura(s_amaldicoado);
    }
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_incendio(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou incendiar em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D12();
    if(*rng==4){
        printf("  o incendio infligiu queimaduras");
        aplicar_queimadura(s_amaldicoado);
    }
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_pedregulho(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou pedregulho em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D4();
    if(*rng==4){
        aplicar_atordoar(s_amaldicoado);
        printf(" o ataque de pedregulho foi suficiente para paralizar");
    }
    *rng=D10();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_desmoronamento(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou demoronamento em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D4();
    if(*rng==4){
        aplicar_atordoar(s_amaldicoado);
        printf(" o ataque de demoronamento foi suficiente para paralizar");
    }
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_terremoto(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou terremoto em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);    *rng=D4();
    if(*rng==4){
        aplicar_atordoar(s_amaldicoado);
        printf(" o ataque de terremoto foi suficiente para paralizar");
    }
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_bolhas(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou um ataque de bolha em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D10();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_rajada_de_agua(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou rajada de agua em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_tsunami(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou tsunami em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_silenciar(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou um silenciar em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_silencio(s_amaldicoado);
    *rng=D4();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,0,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_olhar_amendrontador(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou olhar amedrontador em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_medo(s_amaldicoado);
    *rng=D4();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,0,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n  %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

/////////////////////////////////////////

void ataque_em_cruz(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou ataque em cruz em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_hemorragia(s_amaldicoado);
    aplicar_atordoar_passivo(s_amaldicoado);
    *rng=D6();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_estocada(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou estocada em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_hemorragia(s_amaldicoado);
    aplicar_atordoar_passivo(s_amaldicoado);
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_corte_profundo(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou corte profundo em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_hemorragia(s_amaldicoado);
    aplicar_atordoar_passivo(s_amaldicoado);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ultimate_punho_supremo_de_azura(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    float mana;
    printf("\n\n\n\n%s usou seu ultimate em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    printf("\nPUNHO SUPREMO DE AZURA!!!!!!!!!!!");
    aplicar_atordoar(s_amaldicoado);
    aplicar_hemorragia(s_amaldicoado);
    *rng=D20();
    mana=bruxo->mana;
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dps+=(mana/10)*bruxo->ataque;
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ultimate_ira_dos_dragoes(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou seu ultimate em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    printf("\nIRA DOS DRAGOES!!!!!!!!!!!");
    aplicar_fortalecer(s_bruxo);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ultimate_fortalcer(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou seu ultimate em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    printf("\nFORTALECER!!!!!!!!!!!");
    aplicar_fortalecer_ult(s_bruxo);
    *rng=1;
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ultimate_armagedon(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou seu ultimate em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);    aplicar_armagedon(bruxo,s_amaldicoado);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo)+0.15*(*bruxo).vida;
    *dano=Dano_Total(rng,bruxo->ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ultimate_transfusao(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    float cura;
    printf("\n\n\n\n%s usou seu ultimate em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    printf("\nTRANSFUSAO!!!!!!!!!!!");
    aplicar_curar(s_bruxo);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    cura=*dano*0.6;
    printf("\n e roubando um total de %2f de vida",cura*-1);
    bruxo->vida-=cura;
    (*amaldicoado).vida+=*dano;
    getch();
}

void ultimate_golpe_infernal(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou seu ultimate em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    printf("\nATAQUE INFERNAL!!!!!!!!!!!");
    aplicar_queimadura_ult(s_amaldicoado);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ultimate_duplo_critico(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou seu ultimate em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    printf("\nDUPLO CRITICO!!!!!!!!!!!");
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico_ult();
    *dano*=critico_ult();
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ultimate_presas_duplas(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou seu ultimate em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    printf("\nPRESAS DUPLAS!!!!!!!!!!!");
    aplicar_enfraquecer_ult(s_amaldicoado);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico_ult();
    (*amaldicoado).vida+=*dano;
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,2*(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_basico_tank(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou ataque basico em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    (*bruxo).mana-=3;
    aplicar_hemorragia(s_amaldicoado);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo)+0.15*(*bruxo).vida;
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_golpe_de_escudo(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou golpe de escudo em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_atordoar(s_amaldicoado);
    *rng=D4();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo)+0.15*(*bruxo).vida;
    *dano=Dano_Total(rng,1,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_provocar(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou provocar em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_medo(s_amaldicoado);
    *rng=1;
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo)+0.15*(*bruxo).vida;
    *dano=Dano_Total(rng,1,dps,(*amaldicoado).defesa);
    *dano*=critico();
     printf("\n%s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}



void ataque_basico_assassino(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou ataque basico em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_hemorragia(s_amaldicoado);
    *rng=D4();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    amaldicoado->vida+=*dano;
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    getch();
}

void ataque_apunhalar(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou apunhalar em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_hemorragia(s_amaldicoado);
    *rng=D8();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    amaldicoado->vida+=*dano;
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    getch();
}

void ataque_dilacerar(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou dilacerar em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_hemorragia(s_amaldicoado);
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    amaldicoado->vida+=*dano;
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    getch();
}

void ataque_golpe_na_garganta(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s usou golper na garganta' em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_hemorragia(s_amaldicoado);
    aplicar_hemorragia(s_amaldicoado);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    *dano*=critico();
    amaldicoado->vida+=*dano;
    printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    getch();
}

void ataque_falho(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n\n%s nao conseguiu",corpo_bruxo->nome);
    float ataque_0=(*bruxo).ataque;
    (*bruxo).ataque=0;
    *rng=0;
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);(*bruxo).ataque=ataque_0;
    *dano*=critico();
    amaldicoado->vida+=*dano;
    printf("\n %s mesmo assim causou %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    getch();
}

void elemental_normal(Inimigo* alvo,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    int ataque=D4();
    efeito_silencio(s_bruxo,corpo_bruxo,&ataque);

    switch(ataque){
        case 1:{
            if(*rng>=4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>=4){
                ataque_normal(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>=4){
                ataque_forte(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>=4){
                ataque_muito_forte(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
        }
    }
}

void elemental_fogo(Inimigo* alvo,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    int ataque=D4();
    efeito_silencio(s_bruxo,corpo_bruxo,&ataque);
    switch(ataque){
        case 1:{
            if(*rng>=4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>=4){
                ataque_bola_de_fogo(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>=4){
                ataque_rajada_de_fogo(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>=4){
                ataque_incendio(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
        }
    }
}

void elemental_agua(Inimigo* alvo,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    int ataque=D4();
    efeito_silencio(s_bruxo,corpo_bruxo,&ataque);
    switch(ataque){
        case 1:{
            if(*rng>=4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>=4){
                ataque_bolhas(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>=4){
                ataque_rajada_de_agua(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>=4){
                ataque_tsunami(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
        }
    }
}

void elemental_terra(Inimigo* alvo,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    int ataque=D4();
    efeito_silencio(s_bruxo,corpo_bruxo,&ataque);
    switch(ataque){
        case 1:{
            if(*rng>=4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>=4){
                ataque_pedregulho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>=4){
                ataque_desmoronamento(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>=4){
                ataque_terremoto(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
        }
    }
}

void elemental_vento(Inimigo* alvo,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    int ataque=D4();
    efeito_silencio(s_bruxo,corpo_bruxo,&ataque);
    switch(ataque){
        case 1:{
            if(*rng>=4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>=4){
                ataque_ventania(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>=4){
                ataque_rajada_de_vento(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>=4){
                ataque_furacao(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
        }
    }
}

void elemental_eletrico(Inimigo* alvo,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    int ataque=D4();
    efeito_silencio(s_bruxo,corpo_bruxo,&ataque);
    switch(ataque){
        case 1:{
            if(*rng>=4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>=4){
                ataque_eletrico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>=4){
                ataque_eletrico_forte(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>=4){
                ataque_eletrico_divino(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
        }
    }
}

void elemental_venenoso(Inimigo* alvo,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    int ataque=D4();
    efeito_silencio(s_bruxo,corpo_bruxo,&ataque);
    switch(ataque){
        case 1:{
            if(*rng>=4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>=4){
                ataque_venenoso(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>=4){
                ataque_veneno_de_cobra(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>=4){
                ataque_veneno_anti_dragao(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
        }
    }
}

void elemental_magico(Inimigo* alvo,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    int ataque=D4();
    efeito_silencio(s_bruxo,corpo_bruxo,&ataque);
    switch(ataque){
        case 1:{
            if(*rng>=4){
                ataque_venenoso(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>=4){
                ataque_pedregulho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>=4){
                ataque_bolhas(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>=4){
                ataque_eletrico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
        }
    }
}

void elemental_uganda(Inimigo* alvo,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    int ataque=D4();
    switch(ataque){
        case 1:{
                ataque_tsunami(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
        }
        case 2:{
                ataque_incendio(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                 break;

        }
        case 3:{
                ataque_veneno_anti_dragao(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
        }
        case 4:{
                ataque_terremoto(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
        }
    }
}

void contra_ataque(Inimigo* alvo,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    int tipo=alvo->tipo;
    switch(tipo){
        case 0:{
            elemental_normal(alvo,bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps, dano,rng);
            break;
        }
        case 1:{
            elemental_fogo(alvo,bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps, dano,rng);
            break;
        }
        case 2:{
            elemental_agua(alvo,bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps, dano,rng);
            break;
        }
        case 3:{
            elemental_terra(alvo,bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps, dano,rng);
            break;
        }
        case 4:{
            elemental_vento(alvo,bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps, dano,rng);
            break;
        }
        case 5:{
            elemental_eletrico(alvo,bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps, dano,rng);
            break;
        }
        case 6:{
            elemental_venenoso(alvo,bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps, dano,rng);
            break;
        }
        case 7:{
            elemental_magico(alvo,bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps, dano,rng);
            break;
        }
        case 8:{
            elemental_uganda(alvo,bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps, dano,rng);
            break;
        }
    }

 }

 void lutador_ataque(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>=4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\n\n\n ataque falhou");
            break;
        }
        case 2:{
            if((*bruxo).mana>=3){
                bruxo->mana-=3;
                if(*rng>=2){
                corte_preciso(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

void monge_ataque(int* ult,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>=4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\n\n\n ataque falhou");
            break;
        }
        case 2:{
            if((*bruxo).mana>=3){
                bruxo->mana-=3;
                if(*rng>=2){
                corte_preciso(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 3:{
            if(bruxo->mana>10){
                bruxo->mana-=10;
                if(*rng>=2){
                    ataque_em_cruz(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 4:{
            if(*ult==1){
                *ult=0;
                    ultimate_ira_dos_dragoes(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\nso e possivel usa a ultimate uma vez\n\n\n");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

void campeao_ataque(int* ult,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>=4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\n\n\n ataque falhou");
            break;
        }
        case 2:{
            if((*bruxo).mana>=3){
                bruxo->mana-=3;
                if(*rng>=2){
                corte_preciso(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 3:{
            if(bruxo->mana>12){
                bruxo->mana-=12;
                if(*rng>=2){
                    ataque_estocada(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 4:{
            if(*ult==1){
                *ult=0;
                    ultimate_punho_supremo_de_azura(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\nso e possivel usa a ultimate uma vez\n\n\n");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

void tank_ataque(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>=4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\n\n\n ataque falhou");
            break;
        }
        case 2:{
            if((*bruxo).mana>=4){
                bruxo->mana-=4;
                if(*rng>=2){
                ataque_golpe_de_escudo(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

void duelista_ataque(int* ult,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>=4){
                ataque_golpe_de_escudo(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\n\n\n ataque falhou");
            break;
        }
        case 2:{
            if((*bruxo).mana>=4){
                bruxo->mana-=4;
                if(*rng>=2){
                corte_preciso(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 3:{
            if(bruxo->mana>12){
                bruxo->mana-=12;
                if(*rng>=2){
                    ataque_estocada(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 4:{
            if(*ult==1){
               *ult=0;
                   ultimate_fortalcer(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\nso e possivel usa a ultimate uma vez\n\n\n");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

void berserker_ataque(int* ult,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>=4){
                ataque_basico_tank(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\n\n\n ataque falhou");
            break;
        }
        case 2:{
            if((*bruxo).mana>=3){
                bruxo->mana-=3;
                if(*rng>=2){
                corte_preciso(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 3:{
            if(bruxo->mana>8){
                bruxo->mana-=8;
                if(*rng>=2){
                    ataque_estocada(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 4:{
            if(*ult==1){
                *ult=0;
                   ultimate_armagedon(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\nso e possivel usa a ultimate uma vez\n\n\n");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

void mago_ataque(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>+4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\n\n\n ataque falhou");
            break;
        }
        case 2:{
            if((*bruxo).mana>=3){
                bruxo->mana-=3;
                if(*rng>=2){
                ataque_bola_de_fogo(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

void vampiro_ataque(int* ult,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>=4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\n\n\n ataque falhou");
            break;
        }
        case 2:{
            if((*bruxo).mana>=3){
                bruxo->mana-=3;
                if(*rng>=2){
                ataque_bola_de_fogo(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 3:{
            if(bruxo->mana>15){
                bruxo->mana-=15;
                if(*rng>=2){
                    ataque_veneno_anti_dragao(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 4:{
            if(*ult==1){
                *ult=0;
                   ultimate_transfusao(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);

            }
            else printf("\nso e possivel usa a ultimate uma vez\n\n\n");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

void elementarista_ataque(int* ult,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>+4){
                ataque_bola_de_fogo(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\n\n\n ataque falhou");
            break;
        }
        case 2:{
            if((*bruxo).mana>=3){
                bruxo->mana-=3;
                if(*rng>=2){
                ataque_bolhas(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 3:{
            if(bruxo->mana>14){
                bruxo->mana-=14;
                if(*rng>=2){
                    ataque_desmoronamento(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 4:{
            if(*ult==1){
                *ult=0;
                   ultimate_golpe_infernal(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\nso e possivel usa a ultimate uma vez\n\n\n");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

void assasino_ataque(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>=4){
                ataque_basico_assassino(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\n\n\n ataque falhou");
            break;
        }
        case 2:{
            if((*bruxo).mana>=3){
                bruxo->mana-=3;
                if(*rng>=2){
                ataque_apunhalar(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

void sniper_ataque(int* ult,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>=4){
                ataque_basico_assassino(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\n\n\n ataque falhou");
            break;
        }
        case 2:{
            if((*bruxo).mana>=3){
                bruxo->mana-=3;
                if(*rng>=2){
                ataque_apunhalar(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 3:{
            if(bruxo->mana>6){
                bruxo->mana-=6;
                if(*rng>=2){
                    ataque_dilacerar(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 4:{
            if(*ult==1){
                *ult=0;
                   ultimate_duplo_critico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\nso e possivel usa a ultimate uma vez\n\n\n");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

void striker_ataque(int* ult,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>=4){
                ataque_basico_assassino(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\n\n\n ataque falhou");
            break;
        }
        case 2:{
            if((*bruxo).mana>=3){
                bruxo->mana-=3;
                if(*rng>=2){
                ataque_apunhalar(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 3:{
            if(bruxo->mana>10){
                bruxo->mana-=10;
                if(*rng>=2){
                    ataque_golpe_na_garganta(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 4:{
            if(*ult==1){
                *ult=0;
                ultimate_presas_duplas(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\nso e possivel usa a ultimate uma vez\n\n\n");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

 void heroi_ataque(int* ult,Atributos_parciais* atributo_heroi,Buff_Debuff* s_heroi,Personagem* corpo_heroi,Atributos_parciais* atributo_inimigo,Buff_Debuff* s_inimigo,Personagem* corpo_inimigo,float* dps, float* dano,int* rng,int* escolha2){
        switch(corpo_heroi->classe){
                            case 1://lutador
                                lutador_ataque(atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,dps,dano,rng,escolha2);
                                break;
                            case 2:
                                monge_ataque(ult,atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,dps,dano,rng,escolha2);
                                break;
                             case 3:
                                campeao_ataque(ult,atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,dps,dano,rng,escolha2);
                                break;
                            case 4://tank
                                tank_ataque(atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,dps,dano,rng,escolha2);
                                break;
                            case 5:
                                duelista_ataque(ult,atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,dps,dano,rng,escolha2);
                                break;
                            case 6:
                                berserker_ataque(ult,atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,dps,dano,rng,escolha2);
                                break;
                            case 7: //mago
                                mago_ataque(atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,dps,dano,rng,escolha2);
                                break;
                            case 8:
                                elementarista_ataque(ult,atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,dps,dano,rng,escolha2);
                                break;
                            case 9:
                                vampiro_ataque(ult,atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,dps,dano,rng,escolha2);
                                break;
                            case 10: //assassino
                                assasino_ataque(atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,dps,dano,rng,escolha2);
                                break;
                            case 11:
                                sniper_ataque(ult,atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,dps,dano,rng,escolha2);
                                break;
                            case 12:
                                striker_ataque(ult,atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,dps,dano,rng,escolha2);
                                break;
                    }
}


int mostrar_ataques(int classe,int* escolha){
    switch(classe){
        case 1:return layout1x1("ataque basico","corte preciso('3')",escolha);break;
        case 2:return layout2x2("ataque basico","corte preciso('3')","ataque em cruz('10')","ira dos dragoes(''ultimate'')",escolha);break;
        case 3:return layout2x2("ataque basico","corte preciso('3)","estocada('12')","punho supremo de azura(ultimate)",escolha);break;
        case 4:return layout1x1("ataque basico","golpe de escudo('4')",escolha);break;
        case 5:return layout2x2("golpe de escudo","corte preciso('3')","estocada('12'),","fortalecer(''ultimate'')",escolha);break;
        case 6:return layout2x2("ataque basico","golpe de escudo('3')","corte preciso(8')","armagedon(''ultimate'')",escolha);break;
        case 7:return layout1x1("ataque basico","bola de fogo('3')",escolha);break;
        case 9:return layout2x2("ataque basico","bola de fogo('3')","envenenar('15')","transfusao de sangue(''ultimate'')",escolha);break;
        case 8:return layout2x2("bola de fogo","bolhas('3')","demoronamento('14')","ataque infernal(''ultimate'')",escolha);break;
        case 10:return layout1x1("ataque basico","apunhalar('3')",escolha);break;
        case 11:return layout2x2("ataque basico","apunhalar('3')","golpe na garganta('6')","presas duplas(''ultimate'')",escolha);break;
        case 12:return layout2x2("ataque basico","apunhalar('3')","dilacerar('10')","duplo critico(''ultimate'')",escolha);break;
        }
}

int mostrar_inventario(int* escolha2,int PHP,int PMP,int PZD){
    int verificacao2,botao=0;
    verificacao2=layout2x1("pocao de vida","pocao de mana","pocao de remover efeitos negativos",escolha2);
    if(verificacao2==1){
        switch(*escolha2){
            case 0:{
                if(PHP>0){
                    printf("\n %i pocoes de cura restantes. enter para confirmar esc para cancelar",PHP);
                    while(botao!=13 && botao!=27){
                        botao=getch();
                    }
                    if(botao==13)return 1;
                    else return 0;
                }
                else{
                    printf("\n voce nao possui mais pocoes de cura");
                    *escolha2=5;
                    return 1;
                }
            }
            case 1:{
                if(PMP>0){
                    printf("\n %i pocoes de mana restantes. enter para confirmar esc para cancelar",PMP);
                    while(botao!=13 && botao!=27){
                        botao=getch();
                    }
                    if(botao==13)return 1;
                    else return 0;
                }
                else{
                    printf("\n voce nao possui mais pocoes de mana");
                    *escolha2=5;
                    return 1;
                }
            }
            case 2:{
                if(PZD>0){
                    printf("\n %i pocoes de purificacoes restantes. enter para confirmar esc para cancelar",PZD);
                    while(botao!=13 && botao!=27){
                        botao=getch();
                    }
                    if(botao==13)return 1;
                    else return 0;
                }
                else{
                    printf("\n voce nao possui mais pocoes de purificacao");
                    *escolha2=5;

                    return 1;
                }
            }
        }
    }
    else return 0;
}
int layout_batalha(Atributos_parciais* heroi,Atributos_parciais* inimigo,int* escolha){
    int Top1,Top2,Top3,T;
    pegar_tamanho2x1("atacar",&Top1,"abrir inventario",&Top2,"fugir",&Top3);
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
        printar_interface(heroi,inimigo);
        loop=menu2x1("atacar","abrir inventario","fugir",cursor,navegador,&x,&y,escolha,Top1,Top2,Top3,T);
    }
    if(loop==2)return 1;
    else return 0;
}

void fazer_escolha(int* escolha,int* escolha2,Atributos_parciais* atributo_heroi,Atributos_parciais* atributo_inimigo,Personagem* corpo_heroi,Personagem* corpo_inimigo,int PHP,int PMP,int PZD){
    int verificacao=0;
    while(verificacao==0){
        system("cls");
        verificacao=layout_batalha(atributo_heroi,atributo_inimigo,escolha);
        if(verificacao==1 && *escolha==0){
            verificacao=mostrar_ataques(corpo_heroi->classe,escolha2);
        }
        else if(verificacao==1 && *escolha==1){
            verificacao=mostrar_inventario(escolha2,PHP,PMP,PZD);
        }
    }
    *escolha+=1;
    *escolha2+=1;
}

void usar_pocao(int* escolha2,int* PHP,int* PMP,int* PZD,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    switch(*escolha2){
            case 1:{
                aplicar_PHP(s_bruxo,PHP);
                break;
            }
            case 2:{
                aplicar_PMP(s_bruxo,PMP);
                break;
            }
            case 3:{
                aplicar_PZD(s_bruxo,PZD);
                break;
            }
            case 5:{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }

    }
}

void efeitos_gerais(Personagem* corpo_amaldicoado,Buff_Debuff* s_amaldicoado,Atributos_parciais* amaldicoado){
    if((*s_amaldicoado).enfraquecer.existencia!=0)efeito_enfraquecer(s_amaldicoado,corpo_amaldicoado,amaldicoado);
    if((*s_amaldicoado).fortalecer.existencia!=0)efeito_fortalecer(s_amaldicoado,corpo_amaldicoado,amaldicoado);
}

int batalha(Cadastro *conta,Inimigo *alvo,int* personagem_atual){
    Personagem personagem_alvo,*corpo_heroi=&(*conta).heroi[*personagem_atual],*corpo_inimigo=&personagem_alvo;
    Atributos_parciais status_heroi,status_inimigo,*atributo_heroi=&status_heroi,*atributo_inimigo=&status_inimigo;
    Buff_Debuff efeitos_heroi,efeitos_inimigo,*s_heroi=&efeitos_heroi,*s_inimigo=&efeitos_inimigo;
    int ult=1,rng,escolha,escolha2,PHP,PMP,PZD;
    float dano_primario=0,full_dano=0;
    PHP=(*corpo_heroi).set.hp;
    PMP=(*corpo_heroi).set.mana;
    PZD=(*corpo_heroi).set.debuff;
    receber_informacoes(alvo,corpo_heroi,corpo_inimigo,atributo_heroi,atributo_inimigo,s_heroi,s_inimigo);
    while(1){
        efeitos_gerais(corpo_heroi,s_heroi,atributo_heroi);
        fazer_escolha(&escolha,&escolha2,atributo_heroi,atributo_inimigo,corpo_heroi,corpo_inimigo,PHP,PMP,PZD);
        efeito_atordoar(s_heroi,corpo_heroi,&escolha);
        rng=D10();
        efeito_medo(s_heroi,corpo_heroi,&rng);
        switch(escolha){
            case 1:{
                    heroi_ataque(&ult,atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,&dano_primario,&full_dano,&rng,&escolha2);
                    break;
            }
            case 2:{
                usar_pocao(&escolha2,&PHP,&PMP,&PZD,atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,&dano_primario,&full_dano,&rng);
                break;
            }
            case 3:{
                printf("\n\n\n nao se pode fugir de uma batalha");
                ataque_falho(atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,&dano_primario,&full_dano,&rng);
                break;
            }
        }
        cura_por_turno(corpo_heroi,s_heroi,atributo_heroi);
        if(status_inimigo.vida<=0){
            return 1;
            break;
        }
        efeitos_gerais(corpo_inimigo,s_inimigo,atributo_inimigo);
        rng=0;
        efeito_atordoar(s_inimigo,corpo_inimigo,&rng);
        if(rng==0){
            rng=D10();
            contra_ataque(alvo,atributo_inimigo,s_inimigo,corpo_inimigo,atributo_heroi,s_heroi,corpo_heroi,&dano_primario,&full_dano,&rng);
        }
        else{
            ataque_falho(atributo_inimigo,s_inimigo,corpo_inimigo,atributo_heroi,s_heroi,corpo_heroi,&dano_primario,&full_dano,&rng);

        }
        if(status_heroi.vida<=0){
            return 0;
            break;
        }
    }
}







#endif // BATALHA_H_INCLUDED
