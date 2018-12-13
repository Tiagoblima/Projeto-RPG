
#include <cadastro.h>
#include <loja.h>
#include <batalha.h>
#ifndef GAME_H
#define GAME_H

typedef struct Status_Atual{
	float vida_atual,defesa_atual,ataque_atual;
};
///////////////////////////////////ficha monstros

float Dano(int rng, float ataque1, float defesa1){//////////calculo de dano atualizado

	int a;
    float ataque,defesa,dano,reducao[6];
	ataque=ataque1;
	defesa=defesa1;

      for( a=0;a<6;a++){
        reducao[a]=0;
      }

    if(defesa<=100){
        reducao[0]=defesa/2;
    }


    if(defesa<=200 &&defesa>100){
        reducao[1]=(defesa+100)/4;
    }

    if(defesa<=300 &&defesa>200){
        reducao[2]=(defesa+400)/8;
    }

    if(defesa<=400&&defesa>300){
        reducao[3]=(defesa+1100)/16;
    }

    if(defesa<=500&&defesa>400){
        reducao[4]=(defesa+2600)/32;
    }

    if(defesa<=600&&defesa>500){
        reducao[5]=(defesa+5700)/64;
    }

    reducao[6]=0;
    reducao[6]=reducao[0]+reducao[1]+reducao[2]+reducao[3]+reducao[4]+reducao[5];
    reducao[6]=reducao[6]/100;


    dano=rng*ataque*(1-reducao[6]);
    dano=dano/10;
}

float Vida_inimigo(int tier){
	float vida_in;
	int *tier_in;
	tier_in=&tier;

	switch(*tier_in){
		case 1:
			vida_in=10+rand()%16;
			break;

		case 2:
			vida_in=15+rand()%21;
			break;

		case 3:
			vida_in=25+rand()%26;
			break;

		case 4:
			vida_in=30+rand()%31;
			break;

		case 5:
			vida_in=60+rand()%36;
			break;

		case 6:
			vida_in=75+rand()%41;
			break;

		case 7:
			vida_in=110+rand()%51;
			break;

		case 8:
			vida_in=145+rand()%71;
			break;

		case 9:
			vida_in=200+rand()%91;
			break;

		case 10:
			vida_in=300+rand()%131;
			break;

		case 11:
			vida_in=500+rand()%201;
			break;
		case 12:
			vida_in=1000;
			break;

		default:
			break;

	}
	return(vida_in);
}

float Ataque_inimigo(int tier){
	float ataque_in;
	int *tier_in;
	tier_in=&tier;

	switch(*tier_in){
		case 1:
			ataque_in=2+rand()%4;
			break;

		case 2:
			ataque_in=5+rand()%6;
			break;

		case 3:
			ataque_in=10+rand()%16;
			break;

		case 4:
			ataque_in=15+rand()%21;
			break;

		case 5:
			ataque_in=25+rand()%26;
			break;

		case 6:
			ataque_in=35+rand()%31;
			break;

		case 7:
			ataque_in=50+rand()%36;
			break;

		case 8:
			ataque_in=60+rand()%46;
			break;

		case 9:
			ataque_in=90+rand()%66;
			break;

		case 10:
			ataque_in=120+rand()%91;
			break;

		case 11:
			ataque_in=180+rand()%121;
			break;
		case 12:
			ataque_in=500;
			break;

		default:
			break;

	}
	return(ataque_in);
}

float Defesa_inimigo(int tier){
	float defesa_in;
	int *tier_in;
	tier_in=&tier;

	switch(*tier_in){
		case 1:
			defesa_in=2+rand()%4;
			break;

		case 2:
			defesa_in=5+rand()%6;
			break;

		case 3:
			defesa_in=10+rand()%16;
			break;

		case 4:
			defesa_in=15+rand()%21;
			break;

		case 5:
			defesa_in=25+rand()%26;
			break;

		case 6:
			defesa_in=35+rand()%31;
			break;

		case 7:
			defesa_in=50+rand()%36;
			break;

		case 8:
			defesa_in=60+rand()%46;
			break;

		case 9:
			defesa_in=90+rand()%66;
			break;

		case 10:
			defesa_in=120+rand()%91;
			break;

		case 11:
			defesa_in=180+rand()%121;
			break;
		case 12:
			defesa_in=500;
			break;

		default:
			break;

	}
	return(defesa_in);
}

void nome(Inimigo* inimigos)
{
	strcpy(inimigos->nome, "Javali");
	strcpy(inimigos[1].nome, "Carangueijo gigante");
	strcpy(inimigos[2].nome, "Slime");
	strcpy(inimigos[3].nome, "Cobra pesonhenta");
	strcpy(inimigos[4].nome, "Goblin");
	strcpy(inimigos[5].nome, "Rato gigante");
	strcpy(inimigos[6].nome, "Kobolg");
	strcpy(inimigos[7].nome, "Guerreiro tribal");
	strcpy(inimigos[8].nome, "Povo do mar");
	strcpy(inimigos[9].nome, "Treant");
	strcpy(inimigos[10].nome, "Esqueleto");
	strcpy(inimigos[11].nome, "Pixie");
	strcpy(inimigos[12].nome, "Treant infectado");
	strcpy(inimigos[13].nome, "Sprite");
	strcpy(inimigos[14].nome, "Drow");
	strcpy(inimigos[15].nome, "Zumbi");
	strcpy(inimigos[16].nome, "Bidrone");
	strcpy(inimigos[17].nome, "Aranha-Lobo gigante");//Andar 10 Boss1
	strcpy(inimigos[18].nome, "Espada voadora");//Andar 10 Boss2
	strcpy(inimigos[19].nome, "Pantera");
	strcpy(inimigos[20].nome, "Kobolg alado");
	strcpy(inimigos[21].nome, "Monstro da ferrugem");
	strcpy(inimigos[22].nome, "Pseudo dragão");
	strcpy(inimigos[23].nome, "Orc");
	strcpy(inimigos[24].nome, "Troglodita");
	strcpy(inimigos[25].nome, "Lizard man");
	strcpy(inimigos[26].nome, "Gnoll");
	strcpy(inimigos[27].nome, "Satiro");
	strcpy(inimigos[28].nome, "Gnomo");
	strcpy(inimigos[29].nome, "Vespa gigante");
	strcpy(inimigos[30].nome, "Hobgoblin");
	strcpy(inimigos[31].nome, "Espectro");
	strcpy(inimigos[32].nome, "Tridrone");
	strcpy(inimigos[33].nome, "Harpia");
	strcpy(inimigos[34].nome, "Carniçal");
	strcpy(inimigos[35].nome, "Armadura animada");//Andar 20 Boss1
	strcpy(inimigos[36].nome, "Diabrete");
	strcpy(inimigos[37].nome, "Serpete de fogo");
	strcpy(inimigos[38].nome, "Dríade");
	strcpy(inimigos[39].nome, "Cão da morte");//Andar 20 Boss2
	strcpy(inimigos[40].nome, "Chefe golem");
	strcpy(inimigos[41].nome, "Esqueleto de minotauro");
	strcpy(inimigos[42].nome, "Hipogrifo");
	strcpy(inimigos[43].nome, "Gargula");
	strcpy(inimigos[44].nome, "Bruxa do mar");
	strcpy(inimigos[45].nome, "Gnoll lider");
	strcpy(inimigos[46].nome, "Centauro");
	strcpy(inimigos[47].nome, "Slime de gelo");
	strcpy(inimigos[48].nome, "Alossauro");
	strcpy(inimigos[49].nome, "Ogro");
	strcpy(inimigos[50].nome, "Uganda Knuckles");
	strcpy(inimigos[51].nome, "Manticora");//Andar 30 Boss1
	strcpy(inimigos[52].nome, "Basilisco");//Andar 30 Boss2
	strcpy(inimigos[53].nome, "Múmia");
	strcpy(inimigos[54].nome, "Cão infernal");
	strcpy(inimigos[55].nome, "Pesadelo");
	strcpy(inimigos[56].nome, "Quadrone");//
	strcpy(inimigos[57].nome, "Yeti");
	strcpy(inimigos[58].nome, "Lobisobem");
	strcpy(inimigos[59].nome, "Escorpião gigante");
	strcpy(inimigos[60].nome, "Minotauro");
	strcpy(inimigos[61].nome, "Guardião reanimado");
	strcpy(inimigos[62].nome, "Banshee");
	strcpy(inimigos[63].nome, "Lâmia");
	strcpy(inimigos[64].nome, "Demonio das sobras");
	strcpy(inimigos[65].nome, "Homem-javali");
	strcpy(inimigos[66].nome, "Dragão filhote");
	strcpy(inimigos[67].nome, "Naga dos ossos");
	strcpy(inimigos[68].nome, "Comadante orc");
	strcpy(inimigos[69].nome, "Rei lizardman");
	strcpy(inimigos[70].nome, "Pentadrone");
	strcpy(inimigos[71].nome, "Elemental do fogo");
	strcpy(inimigos[72].nome, "Arbusto errante");
	strcpy(inimigos[73].nome, "Elemental do ar");
	strcpy(inimigos[74].nome, "Tricerátopo");
	strcpy(inimigos[75].nome, "Drow de elite");
	strcpy(inimigos[76].nome, "Elemental da agua");
	strcpy(inimigos[77].nome, "Gigante da colina");//Andar 40 Boss1
	strcpy(inimigos[78].nome, "Elemental da terra");
	strcpy(inimigos[79].nome, "Golem de carne");//Andar 40 Boss2
	strcpy(inimigos[80].nome, "Caçador invisivel");
	strcpy(inimigos[81].nome, "Quimera");
	strcpy(inimigos[82].nome, "Ciclópe");
	strcpy(inimigos[83].nome, "Resssurgido");
	strcpy(inimigos[84].nome, "Dragão jovem");
	strcpy(inimigos[85].nome, "Wyvern");
	strcpy(inimigos[86].nome, "Hobgoblin senhor da guerra");
	strcpy(inimigos[87].nome, "Devorador de mentes");
	strcpy(inimigos[88].nome, "Medusa");
	strcpy(inimigos[89].nome, "Drow");
	strcpy(inimigos[90].nome, "Gigante de pedra");
	strcpy(inimigos[91].nome, "Yeti abominavel");
	strcpy(inimigos[92].nome, "Guardião do escudo");
	strcpy(inimigos[93].nome, "Efreeti");
	strcpy(inimigos[94].nome, "Oni");
	strcpy(inimigos[95].nome, "Hidra");
	strcpy(inimigos[96].nome, "Dragão Adulto");
	strcpy(inimigos[97].nome, "Tirano da morte");
	strcpy(inimigos[98].nome, "Cavaleiro da morte");
	strcpy(inimigos[99].nome, "Kraken");
	strcpy(inimigos[100].nome, "Uganda Knukles");
}

////////////////////////////


int game(Cadastro* user,int cur_heroi){
srand(time(NULL));
  int a=0,play=1,decisao,rng,rng2,combate_fim=0,turno,andar;
  int andar_check[50];
  char escolha;
  Inimigo monstros[100],inimigo_atual[3];
  struct Status_Atual status;
  float dano;
	setlocale(LC_ALL,"");
  system("cls");
  

		
	for(a=0;a<101;a++){///////tier e atributos dos montros
		 nome(monstros);
		 
		if(a<5||(a>=50 && a<55)){
			monstros[a].tier=1;
			monstros[a].vida=Vida_inimigo(monstros[a].tier);
			monstros[a].ataque=Ataque_inimigo(monstros[a].tier);
			monstros[a].defesa=Defesa_inimigo(monstros[a].tier);
		}
		else if((a>=5 && a<10)||(a>=55 && a<60)){
			monstros[a].tier=2;
			monstros[a].vida=Vida_inimigo(monstros[a].tier);
			monstros[a].ataque=Ataque_inimigo(monstros[a].tier);
			monstros[a].defesa=Defesa_inimigo(monstros[a].tier);
		}
		else if((a>=10 && a<15)||(a>=60 && a<65)){
			monstros[a].tier=3;
			monstros[a].vida=Vida_inimigo(monstros[a].tier);
			monstros[a].ataque=Ataque_inimigo(monstros[a].tier);
			monstros[a].defesa=Defesa_inimigo(monstros[a].tier);
		}
		else if((a>=15 && a<20)||(a>=65 && a<70)){
			monstros[a].tier=4;
			monstros[a].vida=Vida_inimigo(monstros[a].tier);
			monstros[a].ataque=Ataque_inimigo(monstros[a].tier);
			monstros[a].defesa=Defesa_inimigo(monstros[a].tier);
		}
		else if((a>=20 && a<25)||(a>=70 && a<75)){
			monstros[a].tier=5;
			monstros[a].vida=Vida_inimigo(monstros[a].tier);
			monstros[a].ataque=Ataque_inimigo(monstros[a].tier);
			monstros[a].defesa=Defesa_inimigo(monstros[a].tier);
		}
		else if((a>=25 && a<30)||(a>=75 && a<80)){
			monstros[a].tier=6;
			monstros[a].vida=Vida_inimigo(monstros[a].tier);
			monstros[a].ataque=Ataque_inimigo(monstros[a].tier);
			monstros[a].defesa=Defesa_inimigo(monstros[a].tier);
		}
		else if((a>=30 && a<35)||(a>=80 && a<85)){
			monstros[a].tier=7;
			monstros[a].vida=Vida_inimigo(monstros[a].tier);
			monstros[a].ataque=Ataque_inimigo(monstros[a].tier);
			monstros[a].defesa=Defesa_inimigo(monstros[a].tier);
		}
		else if((a>=35 && a<40)||(a>=85 && a<90)){
			monstros[a].tier=8;
			monstros[a].vida=Vida_inimigo(monstros[a].tier);
			monstros[a].ataque=Ataque_inimigo(monstros[a].tier);
			monstros[a].defesa=Defesa_inimigo(monstros[a].tier);
		}
		else if((a>=40 && a<45)||(a>=90 && a<95)){
			monstros[a].tier=9;
			monstros[a].vida=Vida_inimigo(monstros[a].tier);
			monstros[a].ataque=Ataque_inimigo(monstros[a].tier);
			monstros[a].defesa=Defesa_inimigo(monstros[a].tier);
		}
		else if((a>=45 && a<47)||(a>=95 && a<97)){
			monstros[a].tier=10;
			monstros[a].vida=Vida_inimigo(monstros[a].tier);
			monstros[a].ataque=Ataque_inimigo(monstros[a].tier);
			monstros[a].defesa=Defesa_inimigo(monstros[a].tier);
		}
		else if((a>=47 && a<49)||(a>=97 && a<99)){
			monstros[a].tier=11;
			monstros[a].vida=Vida_inimigo(monstros[a].tier);
			monstros[a].ataque=Ataque_inimigo(monstros[a].tier);
			monstros[a].defesa=Defesa_inimigo(monstros[a].tier);
		}
		else if(a==49||a==99){
			monstros[a].tier=12;
			monstros[a].vida=Vida_inimigo(monstros[a].tier);
			monstros[a].ataque=Ataque_inimigo(monstros[a].tier);
			monstros[a].defesa=Defesa_inimigo(monstros[a].tier);
		}

		if(a%10==0){
			monstros[a].vida*=1.5;
			monstros[a].ataque*=1.5;
			monstros[a].defesa*=1.5;
		}
	}

		

	while(play==1){
		
		
	int andarDesbloc = (*user).heroi[cur_heroi].andar;		
		for(a=0;a<50;a++)
		{
			
			if(a<andarDesbloc)
			{
				andar_check[a]=1;
			}
			else
			{
				andar_check[a]=0;
			}
			
		}
		
		system("cls");
		printf("Voce esta no lobby andar\n");
		printf("Derrote os inimigos para subir e derrotar o chefe da torre.\n");
		printf("O que deseja fazer?\n1-lutar\n2-Menu Principal\n3-Sair e salvar progresso\n4-Sair sem salvar\n");///HUD
		decisao=getch();

		switch(decisao){
			case 49:
				printf("Escolha o andar que deseja lutar\n");
				scanf("%i",&andar);
				
				if(andar_check[andar-1]==0){
					printf("Voce ainda nao liberou esse andar.\n");
                    getch();
					system("cls");
				}
				else{
                    switch(andar){

                        case 49:
                            rng2=98;
                            break;

                        case 50:
                            rng2=99;
                            break;
                    }

                    if(andar<49){
                        rng2=andar+50;
                    }
          
          			
					
			
					nome(monstros);
					
					system("cls");
					printf("Status do adversário:\n\n");
					if(rng2!=99){
							
                        printf("INIMIGO:%s\n",monstros[rng2].nome);
                        printf("vida:%.1f\nataque:%.2f\ndefesa:%.2f\n",monstros[rng2].vida,monstros[rng2].ataque,monstros[rng2].defesa);
					}
					else{
                        printf("INIMIGO:\n");
                        printf("vida:???\nataque:???\ndefesa:???\n");
					}
					getch();
					(*user).heroi[cur_heroi].mana =(*user).heroi[cur_heroi].mana_base;
					int status = batalha(user,&monstros[rng2],&cur_heroi);
					system("cls");
					printf("Status Final da batalha: ");
					if(status==1)
					{
						printf("Você venceu!\n\n\n");
						
						
						(*user).heroi[cur_heroi].moeda += 5*andar;
						if(andar==(*user).heroi[cur_heroi].andar)
						{
							(*user).heroi[cur_heroi].andar++;
							printf("Você subiu de andar!\n\nNovo andar desbloqueado: %i\n\n",(*user).heroi[cur_heroi].andar);
						}
						printf("Você ganhou %i moedas pela vitória!",5*andar);
						
						printf("\n\nParabéns pela vitória!!!\n");
						
					}
					else
					{
						printf("Você perdeu!\n\n");
					}
					getch();
					imprimirStatusHeroi(*user,cur_heroi);
					getch();
					
				}
				break;

			case 50:
				return 1;
				break;
			
			case 51:
				return 0;
				break;
			case 52:
				exit(1);
			default:
				printf("Comando invalido.\n");
				system("cls");
				break;

		}

	}


}
#endif
