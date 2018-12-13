#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <cadastro.h>
#include <loja.h>
typedef struct{
    int existencia,itensidade,duracao;
    float efeito;
}Buff;

typedef struct{
    Buff hemorragia,queimadura,veneno,atordoar,silencio,medo,enfraquecer,cura,armagedon;
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
    numero->mana=boneco->mana;
    strcpy((*numero).nome,(*boneco).nome);
}

void receber_valores_inimigo(Atributos_parciais *numero,Personagem* espelho,Inimigo *boneco){
    numero->ataque=espelho->ataque=boneco->ataque;
    numero->defesa=espelho->defesa=boneco->defesa;
    numero->vida=espelho->vida=boneco->vida;
    espelho->mana=99999999;
    strcpy((*numero).nome,(*boneco).nome);
    strcpy((*espelho).nome,(*boneco).nome);
}

void printar_interface(Atributos_parciais* heroi,Atributos_parciais* inimigo){
    system("cls");
    printf("\n%s\t %s\n vida:%.2f\t vida:%.2f\n mana:%.2f\t mana:infinita\n ataque:%.1f\t ataque:%.1f\n defesa:%.1f\t defesa:%.1f",heroi->nome,inimigo->nome,(*heroi).vida,(*inimigo).vida,(*heroi).mana,(*heroi).ataque,(*inimigo).ataque,(*heroi).defesa,(*inimigo).defesa);
    printf("\n faça seu movimento\n");
    printf("\n1-atacar\t 2-abrir inventario\n 3-se render\n");
}

void zerando_um_buff(Buff* viajado){
    viajado->efeito=viajado->duracao=viajado->existencia=viajado->itensidade=0;
}

void zerando_maldicoes(Buff_Debuff* viagem){
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
}

void efeito_hemorragia(Buff_Debuff* maldicao,Atributos_parciais* bruxo,Personagem* amaldicoado,float* dano){
    if((*maldicao).hemorragia.itensidade>5){
        (*maldicao).hemorragia.efeito=2*(*bruxo).ataque+0.05*(5-(*maldicao).hemorragia.itensidade)*(*amaldicoado).vida;
        *dano+=(*maldicao).hemorragia.efeito;
    }
    else{
        (*maldicao).hemorragia.efeito=0.15*(*bruxo).ataque*(*maldicao).hemorragia.itensidade;
        *dano+=(*maldicao).hemorragia.efeito;
    }
    printf("\n\n\n hemorragia de itensidade %i causou %.2f de dano, com %i turnos resttantes",(*maldicao).hemorragia.itensidade,(*maldicao).hemorragia.efeito,(*maldicao).hemorragia.duracao);
    (*maldicao).hemorragia.duracao--;
    if((*maldicao).hemorragia.duracao==0){
        (*maldicao).hemorragia.itensidade=0;
        (*maldicao).hemorragia.existencia=0;
    }
}

void efeito_veneno(Buff_Debuff* maldicao,Personagem* amaldicoado,float* dano){
    (*maldicao).veneno.efeito=(*maldicao).veneno.itensidade*0.08*(*amaldicoado).vida;
    *dano-=(*maldicao).veneno.efeito;
    printf("\n\n\n veneno de itensidade %i causou %.2f de dano, com %i turnos resttantes",(*maldicao).veneno.itensidade,(*maldicao).veneno.efeito,(*maldicao).veneno.duracao);
    (*maldicao).veneno.duracao--;
    if((*maldicao).veneno.duracao==0){
        (*maldicao).veneno.existencia=0;
        (*maldicao).veneno.itensidade=0;
    }
}

void efeito_queimadura(Buff_Debuff* maldicao,Atributos_parciais* bruxo,float* dano){
    (*maldicao).queimadura.efeito=0.14*(*bruxo).ataque*(*maldicao).queimadura.itensidade;
    *dano-=(*maldicao).queimadura.efeito;
    printf("\n\n\n queimadura de itensidade %i causou %.2f de dano, com %i turnos restantes",(*maldicao).queimadura.itensidade,(*maldicao).queimadura.efeito,(*maldicao).queimadura.duracao);
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

void efeito_cura(Buff_Debuff* maldicao,Personagem* bruxo,float* cura){
    (*maldicao).cura.efeito=(*maldicao).cura.itensidade*0.1*(*bruxo).vida;
    *cura+=(*maldicao).cura.efeito;
    printf("\n\n\n cura de itensidade %i causou %.2f de cura, com %i turnos restantes",(*maldicao).cura.itensidade,(*maldicao).cura.efeito,(*maldicao).cura.duracao);
    (*maldicao).cura.duracao--;
    if((*maldicao).cura.duracao==0){
        (*maldicao).cura.existencia=0;
        (*maldicao).cura.itensidade=0;
    }
}

void efeito_medo(Buff_Debuff* maldicao,Personagem* amaldicoado,int* rng){
    if((*maldicao).medo.existencia==1){
        if((*maldicao).medo.itensidade==1){
            printf("\n\n\n %s está com medo",amaldicoado->nome);
            *rng-=1;
        }
        else if((*maldicao).medo.itensidade==2){
            printf("\n\n\n %s está com muito medo",amaldicoado->nome);
            *rng-=2;
        }
        else if((*maldicao).medo.itensidade>=3){
            printf("\n\n\n %s está totalmente apavorado",amaldicoado->nome);
            *rng-=3;
        }
        (*maldicao).medo.duracao--;
        if((*maldicao).medo.duracao==0){
            (*maldicao).medo.existencia=0;
            printf("\n\n\n %s está com medo",amaldicoado->nome);
        }
    }
}

void efeito_atordoar(Buff_Debuff* maldicao,Personagem* amaldicoado,int* escolha){
    if((*maldicao).atordoar.existencia==1){
        printf("\n\n\n %s está atordoado e por isso não pode atacar, %i turnos restantes\n",amaldicoado->nome,(*maldicao).atordoar.duracao);
        if(*escolha!=2)(*escolha)=15;
        (*maldicao).atordoar.duracao--;
        if((*maldicao).atordoar.duracao==0)(*maldicao).atordoar.existencia=0;
    }
}

void efeito_silencio(Buff_Debuff* maldicao,Personagem* amaldicoado,int* escolha){
    if((*maldicao).silencio.existencia==1){
        printf("\n %s está silenciado e por isso não usar habilidades, %i turnos restantes\n",amaldicoado->nome,(*maldicao).silencio.duracao);
        if(*escolha!=1)*escolha=15;
        (*maldicao).silencio.duracao--;
        if((*maldicao).silencio.duracao==0)(*maldicao).silencio.existencia=0;
    }
}

void efeito_enfraquecer(Buff_Debuff* maldicao,Personagem* boneco,Atributos_parciais* amaldicoado){
    char potcento='%';
    if((*maldicao).enfraquecer.existencia==1){
        (*amaldicoado).ataque=(1-(0.1*(*maldicao).enfraquecer.itensidade))*(*boneco).ataque;
        (*maldicao).medo.duracao--;
        printf("\n\n\n efeito debilitante enfraquecer de grau %i ,diminuiu seu ataque em %i %c com %i turnos restantes",(*maldicao).enfraquecer.itensidade,(*maldicao).enfraquecer.itensidade*10,potcento,(*maldicao).enfraquecer.duracao);
        if((*maldicao).medo.duracao==0){
            (*maldicao).medo.existencia=0;
            (*maldicao).medo.itensidade=0;
        }
    }
    else receber_valores(amaldicoado,boneco);
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
    if((*amaldicoado).hemorragia.itensidade==1)printf("\n\n\n e causou um sangramento");
    else if((*amaldicoado).hemorragia.itensidade>5)printf("\n\n\n a sede se tornou insasiavel");
    else printf("\n\n\n a sede de sangue está aumentando");
}

void aplicar_atordoar(Buff_Debuff* amaldicoado){
    (*amaldicoado).atordoar.existencia=1;
    (*amaldicoado).atordoar.duracao=3;
    printf("\n\n\n e foi atordoado");
}

void aplicar_atordoar_passivo(Buff_Debuff* amaldicoado){
    int rng=D6();
    if(rng==6){
        (*amaldicoado).atordoar.existencia=1;
        (*amaldicoado).atordoar.duracao=1;
        printf("\n\n\n stun passivo ativado");
    }
    else printf("\n\n\n passivo não ativada");
}

void aplicar_armagedon(Buff_Debuff* s_amaldicoado,Buff_Debuff* s_bruxo){
    (*s_bruxo).cura.existencia=1;
    (*s_bruxo).cura.itensidade+=3;
    (*s_bruxo).cura.duracao=5;
    (*s_amaldicoado).armagedon.duracao=2;
    (*s_amaldicoado).armagedon.existencia=1;
    (*s_amaldicoado).armagedon.itensidade=1;
    printf("\n\n\n AAAMAGEDON!");
}

void aplicar_curar(Buff_Debuff* amaldicoado){
     (*amaldicoado).cura.existencia=1;
     (*amaldicoado).cura.itensidade++;
     (*amaldicoado).cura.duracao=3;
     printf("\n\n\n cura foi realizada no alvo");
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
            printf("\n\n\n o veneno ficou mais potente");
            (*amaldicoado).veneno.duracao=3;
        }
        else printf("\n\n\n mas o ataque falou");
    }
    else{
        rng=D4();
        if(rng>2){
            (*amaldicoado).veneno.existencia=1;
            (*amaldicoado).veneno.duracao=3;
            (*amaldicoado).veneno.itensidade=1;
            printf("\n\n\n o veneno começa a fazer efeito");
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
            printf("\n\n\n o medo está cada vez maior");
        }
    }
    else{
        (*amaldicoado).medo.existencia=1;
        (*amaldicoado).medo.itensidade=1;
        printf("\n\n\n e começa a ficar com medo");
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

float dano_por_turnos(Buff_Debuff* maldicao,Atributos_parciais* bruxo, Atributos_parciais* amaldicoado,Personagem* corpo_amaldicoado,Personagem* corpo_bruxo){
    float dps=0;
    if((*maldicao).hemorragia.existencia==1)efeito_hemorragia(maldicao,bruxo,corpo_amaldicoado,&dps);
    if((*maldicao).veneno.existencia==1)efeito_veneno(maldicao,corpo_amaldicoado,&dps);
    if((*maldicao).queimadura.existencia==1)efeito_queimadura(maldicao,bruxo,&dps);
    if((*maldicao).armagedon.existencia==1)efeito_armagedon(maldicao,corpo_bruxo,&dps);
    if((*maldicao).cura.existencia==1)efeito_cura(maldicao,corpo_bruxo,&dps);
    return dps;
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
    dano=(-1)*(*dps)+(*rng)*ataque1*(1-reducao)*(-1);
    dano=dano/10;

    return dano;
}

void ataque_basico(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou um ataque basico em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D20();
    if(*rng==20){
        printf("\n\n\no golpe causou sangramento");
        aplicar_hemorragia_passiva(s_amaldicoado);
    }
    *rng=D4();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_normal(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou um ataque normal em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D20();
    if(*rng==20){
        printf("\n\n\no golpe causou sangramento");
        aplicar_hemorragia_passiva(s_amaldicoado);
    }
    *rng=D6();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_forte(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou um ataque forte em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D20();
    if(*rng==20){
        printf("\n\n\no golpe causou sangramento");
        aplicar_hemorragia_passiva(s_amaldicoado);
    }
    *rng=D8();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_muito_forte(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou um ataque muito forte em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D20();
    if(*rng==20){
        printf("\n\n\no golpe causou sangramento");
        aplicar_hemorragia_passiva(s_amaldicoado);
    }
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_venenoso(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou um ataque venenoso em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_veneno(s_amaldicoado);
    *rng=D4();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_veneno_de_cobra(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou um veneno de cobra em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_veneno(s_amaldicoado);
    *rng=D8();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_veneno_anti_dragao(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou um veneno anti-dragão em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_veneno(s_amaldicoado);
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_ventania(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou ventania em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D10();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_rajada_de_vento(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s atacou com uma rajada de vento em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_furacao(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s atacou com um furacão %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_eletrico(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou um ataque eletrico em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D4();
    if(*rng==4){
        aplicar_atordoar(s_bruxo);
        printf("\n\n\n o ataque eletricou foi suficiente para paralizar");
    }
    *rng=D10();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_eletrico_forte(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou um ataque eletrico forte em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D4();
    if(*rng==4){
        aplicar_atordoar(s_amaldicoado);
        printf("\n\n\n o ataque eletricou foi suficiente para paralizar");
    }
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_eletrico_divino(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou um ataque eletrico divino em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D4();
    if(*rng==4){
        aplicar_atordoar(s_amaldicoado);
        printf("\n\n\n o ataque eletricou foi suficiente para paralizar");
    }
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_bola_de_fogo(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou uma bola de fogo em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D4();
    if(*rng==1){
        printf("\n\n\n a bola de fogo infligiu queimaduras");
        aplicar_queimadura(s_amaldicoado);
    }
    *rng=D10();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
    printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_rajada_de_fogo(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou uma rajada de fogo em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D4();
    if(*rng==4){
        printf("\n\n\n a rajada de fogo infligiu queimaduras");
        aplicar_queimadura(s_amaldicoado);
    }
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_incendio(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou incendiar em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D4();
    if(*rng==4){
        printf("\n\n\n o incendio infligiu queimaduras");
        aplicar_queimadura(s_amaldicoado);
    }
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_pedregulho(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou pedregulho em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D4();
    if(*rng==4){
        aplicar_atordoar(s_amaldicoado);
        printf("\n\n\n o ataque de pedregulho foi suficiente para paralizar");
    }
    *rng=D10();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_desmoronamento(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou demoronamento em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D4();
    if(*rng==4){
        aplicar_atordoar(s_amaldicoado);
        printf("\n\n\n o ataque de demoronamento foi suficiente para paralizar");
    }
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_terremoto(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou terremoto em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);    *rng=D4();
    if(*rng==4){
        aplicar_atordoar(s_amaldicoado);
        printf("\n\n\n o ataque de terremoto foi suficiente para paralizar");
    }
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_bolhas(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou um ataque de bolha em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D10();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_rajada_de_agua(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou rajada de agua em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_tsunami(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou tsunami em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_silenciar(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou um silenciar em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_silencio(s_amaldicoado);
    *rng=D4();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,0,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_olhar_amendrontador(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou olhar amedrontador em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_medo(s_amaldicoado);
    *rng=D4();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,0,dps,(*amaldicoado).defesa);
     printf("\n\n\n  %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

/////////////////////////////////////////

void ataque_em_cruz(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou ataque em cruz em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_hemorragia(s_amaldicoado);
    aplicar_atordoar_passivo(s_amaldicoado);
    *rng=D6();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_estocada(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou estocada em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_hemorragia(s_amaldicoado);
    aplicar_atordoar_passivo(s_amaldicoado);
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_corte_profundo(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou corte profundo em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_hemorragia(s_amaldicoado);
    aplicar_atordoar_passivo(s_amaldicoado);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_basico_tank(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou ataque basico em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    (*bruxo).mana-=3;
    aplicar_hemorragia(s_amaldicoado);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo)+0.15*(*bruxo).vida;
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_golpe_de_escudo(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou golpe de escudo em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_atordoar(s_amaldicoado);
    *rng=D4();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo)+0.15*(*bruxo).vida;
    *dano=Dano_Total(rng,1,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_provocar(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou provocar em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_medo(s_amaldicoado);
    *rng=1;
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo)+0.15*(*bruxo).vida;
    *dano=Dano_Total(rng,1,dps,(*amaldicoado).defesa);
     printf("\n\n\n%s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_armagedon(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou armagedon em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_armagedon(s_amaldicoado,s_bruxo);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo)+0.15*(*bruxo).vida;
    *dano=Dano_Total(rng,1,dps,(*amaldicoado).defesa);
     printf("\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    (*amaldicoado).vida+=*dano;
    getch();
}

void ataque_basico_assassino(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou ataque basico em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_hemorragia(s_amaldicoado);
    *rng=D4();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    getch();
}

void ataque_apunhalar(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou apunhalar em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_hemorragia(s_amaldicoado);
    *rng=D8();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    getch();
}

void ataque_dilacerar(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou dilacerar em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_hemorragia(s_amaldicoado);
    *rng=D12();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    getch();
}

void ataque_golpe_na_garganta(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s usou golper na garganta' em em %s",corpo_bruxo->nome,corpo_amaldicoado->nome);
    aplicar_hemorragia(s_amaldicoado);
    aplicar_hemorragia(s_amaldicoado);
    *rng=D20();
    *dps=dano_por_turnos(s_amaldicoado,bruxo,amaldicoado,corpo_amaldicoado,corpo_bruxo);
    *dano=Dano_Total(rng,(*bruxo).ataque,dps,(*amaldicoado).defesa);
     printf("\n\n\n %s causou um total de %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    getch();
}

void ataque_falho(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    printf("\n\n\n%s não pode atacar",corpo_bruxo->nome);
    float ataque_0=(*bruxo).ataque;
    (*bruxo).ataque=0;
    *rng=1;

    (*bruxo).ataque=ataque_0;
     printf("\n\n\n %s mesmo assim causou %.2f de dano a %s",bruxo->nome,(*dano)*-1,corpo_amaldicoado->nome);
    getch();
}


void elemental_normal(Inimigo* alvo,Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng){
    int ataque=D4();
    efeito_silencio(s_bruxo,corpo_bruxo,&ataque);
    switch(ataque){
        case 1:{
            if(*rng>4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>4){
                ataque_normal(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>4){
                ataque_forte(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>4){
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
            if(*rng>4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>4){
                ataque_bola_de_fogo(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>4){
                ataque_rajada_de_fogo(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>4){
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
            if(*rng>4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>4){
                ataque_bolhas(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>4){
                ataque_rajada_de_agua(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>4){
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
            if(*rng>4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>4){
                ataque_pedregulho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>4){
                ataque_desmoronamento(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>4){
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
            if(*rng>4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>4){
                ataque_ventania(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>4){
                ataque_rajada_de_vento(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>4){
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
            if(*rng>4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>4){
                ataque_eletrico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>4){
                ataque_eletrico_forte(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>4){
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
            if(*rng>4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>4){
                ataque_venenoso(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>4){
                ataque_veneno_de_cobra(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>4){
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
            if(*rng>4){
                ataque_venenoso(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 2:{
            if(*rng>4){
                ataque_pedregulho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 3:{
            if(*rng>4){
                ataque_bolhas(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
            else{
                ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                break;
            }
        }
        case 4:{
            if(*rng>4){
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
    printf("\n1-ataque basico\t 2- ataque em cruz('3')\n 3-estocada('10')\t 4-corte profundo('20')");
    scanf("%i",escolha);
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>4){
                ataque_basico(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\n\n\n ataque falhou");
            break;
        }
        case 2:{
            if((*bruxo).mana>=3){
                bruxo->mana-=3;
                if(*rng>=2){
                ataque_em_cruz(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
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
                    ataque_estocada(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 4:{
            if(bruxo->mana>=20){
                bruxo->mana-=20;
                if(*rng>=2){
                    ataque_corte_profundo(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("mana insuficiente\n\n\n");
            }
            else printf("mana insuficiente\n\n\n");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

 void tank_ataque(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    float custo;
    custo=0.2*bruxo->vida;
    printf("\n1-ataque basico\t 2-golpe de escudo('3')\n 3-provocar('10'\t 4-armagedon(*%.1f*)",custo);
    scanf("%i",escolha);
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>4){
                ataque_basico_tank(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
            }
            else printf("\n\n\n ataque falhou");
            break;
        }
        case 2:{
            if((*bruxo).mana>=3){
                bruxo->mana-=3;
                if(*rng>=2){
                ataque_golpe_de_escudo(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
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
                    ataque_provocar(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 4:{
            if(bruxo->vida>=custo){
                bruxo->vida-=custo;
                if(*rng>=2){
                    ataque_armagedon(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("vida insuficiente\n\n\n");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

void mago_ataque(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    printf("\n1-ataque basico\t 2-bola de fogo('3')\n 3-veneno('10')\t 4-terremoto('20')");
    scanf("%i",escolha);
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>4){
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
            if(bruxo->mana>10){
                bruxo->mana-=10;
                if(*rng>=2){
                    ataque_venenoso(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 4:{
            if(bruxo->mana>=20){
                bruxo->mana-=20;
                if(*rng>=2){
                    ataque_terremoto(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("mana insuficiente\n\n\n");
            }
            else printf("mana insuficiente\n\n\n");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

void assasino_ataque(Atributos_parciais* bruxo,Buff_Debuff* s_bruxo,Personagem* corpo_bruxo,Atributos_parciais* amaldicoado,Buff_Debuff* s_amaldicoado,Personagem* corpo_amaldicoado,float* dps, float* dano,int* rng,int* escolha){
    printf("\n1-ataque basico\t 2-apunhalar('3')\n 3-dilacerar('10')\t 4-golpe na garganta('20')");
    scanf("%i",escolha);
    efeito_silencio(s_bruxo,corpo_bruxo,escolha);
    *rng=D10();
    switch(*escolha){
        case 1:{
            if(*rng>4){
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
                    ataque_dilacerar(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("\n\n\n a habilidade falhou");
            }
            else printf("\n\n\n mana insuficiente");
            break;
        }
        case 4:{
            if(bruxo->mana>=20){
                bruxo->mana-=20;
                if(*rng>=2){
                    ataque_golpe_na_garganta(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng);
                }
                else printf("mana insuficiente\n\n\n");
            }
            else printf("mana insuficiente\n\n\n");
            break;
        }
        default:{
            ataque_falho(bruxo,s_bruxo,corpo_bruxo,amaldicoado,s_amaldicoado,corpo_amaldicoado,dps,dano,rng );
            break;
        }
    }
}

void receber_informacoes(Inimigo* alvo,Personagem* corpo_heroi,Personagem* corpo_inimigo,Atributos_parciais* atributo_heroi,Atributos_parciais* atributo_inimigo,Buff_Debuff* s_heroi,Buff_Debuff* s_inimigo){
    receber_valores_heroi(atributo_heroi,corpo_heroi);
    receber_valores_inimigo(atributo_inimigo,corpo_inimigo,alvo);
    zerando_maldicoes(s_heroi);
    zerando_maldicoes(s_inimigo);
}


int batalha(Cadastro *conta,Inimigo *alvo,int* personagem_atual){
    Personagem personagem_alvo,*corpo_heroi=&(*conta).heroi[*personagem_atual],*corpo_inimigo=&personagem_alvo;
    Atributos_parciais status_heroi,status_inimigo,*atributo_heroi=&status_heroi,*atributo_inimigo=&status_inimigo;
    Buff_Debuff efeitos_heroi,efeitos_inimigo,*s_heroi=&efeitos_heroi,*s_inimigo=&efeitos_inimigo;
    int rng,escolha;
    float dano_primario=0,full_dano=0;
    receber_informacoes(alvo,corpo_heroi,corpo_inimigo,atributo_heroi,atributo_inimigo,s_heroi,s_inimigo);
	  
    while(1){
        system("cls");
        printar_interface(atributo_heroi,atributo_inimigo);
        scanf("%i",&escolha);
        int opcao;
        if(escolha==2)
        {
        	system("cls");
        	imprimirStatusConsumiveis(*conta,*personagem_atual);
        	getch();
        	system("cls");
			utilizarConsumiveis(conta,*personagem_atual,atributo_heroi);
		}
		getch();
		system("cls");
        printar_interface(atributo_heroi,atributo_inimigo);
        efeito_atordoar(s_heroi,corpo_heroi,&escolha);
        rng=D10();
        efeito_medo(s_heroi,corpo_heroi,&rng);
        switch(escolha){
            case 1:{
                    switch(corpo_heroi->classe){
                            case 1://lutador
                                lutador_ataque(atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,&dano_primario,&full_dano,&rng,&escolha);
                                break;

                            case 2: //tank
                                tank_ataque(atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,&dano_primario,&full_dano,&rng,&escolha);
                                break;

                            case 3: //mago
                                mago_ataque(atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,&dano_primario,&full_dano,&rng,&escolha);
                                break;

                            case 4: //assassino
                                assasino_ataque(atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,&dano_primario,&full_dano,&rng,&escolha);
                                break;

                    }
            }
            case 3:{
                printf("\n\n\n não se pode fugir de uma batalha");
                ataque_falho(atributo_heroi,s_heroi,corpo_heroi,atributo_inimigo,s_inimigo,corpo_inimigo,&dano_primario,&full_dano,&rng);
                break;
            }
        }
        status_inimigo.vida+=full_dano;
        if(status_inimigo.vida<=0){
            return 1;
            break;
        }
        rng=0;
        efeito_atordoar(s_inimigo,corpo_inimigo,&rng);
        if(rng==0){
            contra_ataque(alvo,atributo_inimigo,s_inimigo,corpo_inimigo,atributo_heroi,s_heroi,corpo_heroi,&dano_primario,&full_dano,&rng);
        }
        else{
            ataque_falho(atributo_inimigo,s_inimigo,corpo_inimigo,atributo_heroi,   s_heroi,corpo_heroi,&dano_primario,&full_dano,&rng);

        }
        status_heroi.vida+=full_dano;
        if(status_heroi.vida<=0){
            return 0;
            break;
        }
    }
}

