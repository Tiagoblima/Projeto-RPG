
#include <cadastro.h>
#include <loja.h>
#include <batalha.h>
#include <tagsmenu.h>

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

void nome(Inimigo* Inimigos)
{
	strcpy(Inimigos[0].nome, "Javali");
	Inimigos[0].tipo=0;
	strcpy(Inimigos[1].nome, "Carangueijo gigante");
	Inimigos[1].tipo=2;
	strcpy(Inimigos[2].nome, "Slime");
	Inimigos[2].tipo=0;
	strcpy(Inimigos[3].nome, "Cobra pesonhenta");
	Inimigos[3].tipo=6;
	strcpy(Inimigos[4].nome, "Goblin");
	Inimigos[4].tipo=0;
	strcpy(Inimigos[5].nome, "Rato gigante");
	Inimigos[5].tipo=0;
	strcpy(Inimigos[6].nome, "Kobolg");
	Inimigos[6].tipo=0;
	strcpy(Inimigos[7].nome, "Guerreiro tribal");
	Inimigos[7].tipo=0;
	strcpy(Inimigos[8].nome, "Povo do mar");
	Inimigos[8].tipo=2;
	strcpy(Inimigos[9].nome, "Treant");
	Inimigos[9].tipo=3;
	strcpy(Inimigos[10].nome, "Esqueleto");
	Inimigos[10].tipo=0;
	strcpy(Inimigos[11].nome, "Pixie");
	Inimigos[11].tipo=4;
	strcpy(Inimigos[12].nome, "Treant infectado");
	Inimigos[12].tipo=3;
	strcpy(Inimigos[13].nome, "Sprite");
	Inimigos[13].tipo=2;
	strcpy(Inimigos[14].nome, "Drow");
	Inimigos[14].tipo=7;
	strcpy(Inimigos[15].nome, "Zumbi");
	Inimigos[15].tipo=0;
	strcpy(Inimigos[16].nome, "Bidrone");
	Inimigos[16].tipo=5;
	strcpy(Inimigos[17].nome, "Pantera");
	Inimigos[17].tipo=0;
	strcpy(Inimigos[18].nome, "Espada voadora");//Andar 10 Boss2
	Inimigos[18].tipo=7;
	strcpy(Inimigos[19].nome, "Aranha-Lobo gigante");//Andar 10 Boss1
	Inimigos[19].tipo=6;
	strcpy(Inimigos[20].nome, "Kobolg alado");
	Inimigos[20].tipo=4;
	strcpy(Inimigos[21].nome, "Monstro da ferrugem");
	Inimigos[21].tipo=3;
	strcpy(Inimigos[22].nome, "Pseudo dragão");
	Inimigos[22].tipo=1;
	strcpy(Inimigos[23].nome, "Orc");
	Inimigos[23].tipo=0;
	strcpy(Inimigos[24].nome, "Troglodita");
	Inimigos[24].tipo=0;
	strcpy(Inimigos[25].nome, "Lizard man");
	Inimigos[25].tipo=0;
	strcpy(Inimigos[26].nome, "Gnoll");
	Inimigos[26].tipo=0;
	strcpy(Inimigos[27].nome, "Satiro");
	Inimigos[27].tipo=3;
	strcpy(Inimigos[28].nome, "Gnomo");
	Inimigos[28].tipo=3;
	strcpy(Inimigos[29].nome, "Vespa gigante");
	Inimigos[29].tipo=4;
	strcpy(Inimigos[30].nome, "Hobgoblin");
	Inimigos[30].tipo=0;
	strcpy(Inimigos[31].nome, "Espectro");
	Inimigos[31].tipo=7;
	strcpy(Inimigos[32].nome, "Tridrone");
	Inimigos[32].tipo=5;
	strcpy(Inimigos[33].nome, "Harpia");
	Inimigos[33].tipo=4;
	strcpy(Inimigos[34].nome, "Carniçal");
	Inimigos[34].tipo=0;
	strcpy(Inimigos[35].nome, "Dríade");
	Inimigos[35].tipo=4;
	strcpy(Inimigos[36].nome, "Diabrete");
	Inimigos[36].tipo=0;
	strcpy(Inimigos[37].nome, "Serpete de fogo");
	Inimigos[37].tipo=1;
	strcpy(Inimigos[38].nome, "Armadura animada");//Andar 20 Boss1
	Inimigos[38].tipo=7;
	strcpy(Inimigos[39].nome, "Cão da morte");//Andar 20 Boss2
	Inimigos[39].tipo=1;
	strcpy(Inimigos[40].nome, "Chefe golem");
	Inimigos[40].tipo=3;
	strcpy(Inimigos[41].nome, "Esqueleto de minotauro");
	Inimigos[41].tipo=0;
	strcpy(Inimigos[42].nome, "Hipogrifo");
	Inimigos[42].tipo=4;
	strcpy(Inimigos[43].nome, "Gargula");
	Inimigos[43].tipo=3;
	strcpy(Inimigos[44].nome, "Bruxa do mar");
	Inimigos[44].tipo=2;
	strcpy(Inimigos[45].nome, "Gnoll lider");
	Inimigos[45].tipo=0;
	strcpy(Inimigos[46].nome, "Centauro");
	Inimigos[46].tipo=0;
	strcpy(Inimigos[47].nome, "Slime de gelo");
	Inimigos[47].tipo=2;
	strcpy(Inimigos[48].nome, "Alossauro");
	Inimigos[48].tipo=0;
	strcpy(Inimigos[49].nome, "Ogro");
	Inimigos[49].tipo=0;
	strcpy(Inimigos[50].nome, "Uganda Knuckles");
	Inimigos[50].tipo=8;
	strcpy(Inimigos[51].nome, "Quadrone");
	Inimigos[51].tipo=5;
	strcpy(Inimigos[52].nome, "Lobisobem");
	Inimigos[52].tipo=0;
	strcpy(Inimigos[53].nome, "Escorpião gigante");
	Inimigos[53].tipo=6;
	strcpy(Inimigos[54].nome, "Múmia");
	Inimigos[54].tipo=0;
	strcpy(Inimigos[55].nome, "Cão infernal");
	Inimigos[55].tipo=1;
	strcpy(Inimigos[56].nome, "Pesadelo");
	Inimigos[56].tipo=7;
	strcpy(Inimigos[57].nome, "Yeti");
	Inimigos[57].tipo=2;
	strcpy(Inimigos[58].nome, "Manticora");//Andar 30 Boss1
	Inimigos[58].tipo=1;
	strcpy(Inimigos[59].nome, "Basilisco");//Andar 30 Boss2
	Inimigos[54].tipo=6;
	strcpy(Inimigos[60].nome, "Minotauro");
	Inimigos[60].tipo=0;
	strcpy(Inimigos[61].nome, "Guardião reanimado");
	Inimigos[61].tipo=7;
	strcpy(Inimigos[62].nome, "Banshee");
	Inimigos[62].tipo=0;
	strcpy(Inimigos[63].nome, "Lâmia");
	Inimigos[63].tipo=6;
	strcpy(Inimigos[64].nome, "Demonio das sobras");
	Inimigos[64].tipo=7;
	strcpy(Inimigos[65].nome, "Homem-javali");
	Inimigos[65].tipo=0;
	strcpy(Inimigos[66].nome, "Dragão filhote");
	Inimigos[66].tipo=1;
	strcpy(Inimigos[67].nome, "Naga dos ossos");
	Inimigos[67].tipo=6;
	strcpy(Inimigos[68].nome, "Comadante orc");
	Inimigos[68].tipo=0;
	strcpy(Inimigos[69].nome, "Rei lizardman");
	Inimigos[69].tipo=0;
	strcpy(Inimigos[70].nome, "Pentadrone");
	Inimigos[70].tipo=5;
	strcpy(Inimigos[71].nome, "Elemental do fogo");
	Inimigos[71].tipo=1;
	strcpy(Inimigos[72].nome, "Arbusto errante");
	Inimigos[72].tipo=3;
	strcpy(Inimigos[73].nome, "Elemental do ar");
	Inimigos[73].tipo=4;
	strcpy(Inimigos[74].nome, "Tricerátopo");
	Inimigos[74].tipo=0;
	strcpy(Inimigos[75].nome, "Drow de elite");
	Inimigos[75].tipo=7;
	strcpy(Inimigos[76].nome, "Elemental da agua");
	Inimigos[76].tipo=2;
	strcpy(Inimigos[77].nome, "Elemental da terra");
	Inimigos[77].tipo=3;
	strcpy(Inimigos[78].nome, "Gigante da colina");//Andar 40 Boss1
	Inimigos[78].tipo=3;
	strcpy(Inimigos[79].nome, "Golem de carne");//Andar 40 Boss2
	Inimigos[79].tipo=3;
	strcpy(Inimigos[80].nome, "Caçador invisivel");
	Inimigos[80].tipo=6;
	strcpy(Inimigos[81].nome, "Quimera");
	Inimigos[81].tipo=1;
	strcpy(Inimigos[82].nome, "Ciclópe");
	Inimigos[82].tipo=0;
	strcpy(Inimigos[83].nome, "Resssurgido");
	Inimigos[83].tipo=0;
	strcpy(Inimigos[84].nome, "Dragão jovem");
	Inimigos[84].tipo=1;
	strcpy(Inimigos[85].nome, "Wyvern");
	Inimigos[85].tipo=1;
	strcpy(Inimigos[86].nome, "Hobgoblin senhor da guerra");
	Inimigos[86].tipo=0;
	strcpy(Inimigos[87].nome, "Devorador de mentes");
	Inimigos[87].tipo=7;
	strcpy(Inimigos[88].nome, "Medusa");
	Inimigos[88].tipo=0;
	strcpy(Inimigos[89].nome, "Drow arcano");
	Inimigos[89].tipo=7;
	strcpy(Inimigos[90].nome, "Gigante de pedra");
	Inimigos[90].tipo=3;
	strcpy(Inimigos[91].nome, "Yeti abominavel");
	Inimigos[91].tipo=2;
	strcpy(Inimigos[92].nome, "Guardião do escudo");
	Inimigos[92].tipo=0;
	strcpy(Inimigos[93].nome, "Efreeti");
	Inimigos[93].tipo=1;
	strcpy(Inimigos[94].nome, "Oni");
	Inimigos[94].tipo=0;
	strcpy(Inimigos[95].nome, "Hidra");
	Inimigos[95].tipo=2;
	strcpy(Inimigos[96].nome, "Dragão Adulto");
	Inimigos[96].tipo=1;
	strcpy(Inimigos[97].nome, "Tirano da morte");
	Inimigos[97].tipo=7;
	strcpy(Inimigos[98].nome, "Cavaleiro da morte");
	Inimigos[98].tipo=0;
	strcpy(Inimigos[99].nome, "Kraken");
	Inimigos[99].tipo=2;
	strcpy(Inimigos[100].nome, "Uganda Knukles");
	Inimigos[100].tipo=8;
}
////////////////////////////

int menuGame(Cadastro* user,int cur_heroi)
{


}
int game(Cadastro* user,int cur_heroi){
srand(time(NULL));
  int a=0,play=1,decisao,rng,rng2,combate_fim=0,turno,andar;
  int andar_check[50];
  char escolha;
  int choice;
  Inimigo monstros[100],inimigo_atual[3];
  struct Status_Atual status;
  float dano;
	//setlocale(LC_ALL,"");
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
		


	
	do
	{
		printf("Escolha o andar que deseja lutar\n");
		scanf("%i",&andar);
		if(andar_check[andar-1]==0)
		{
			printf("Voce ainda nao liberou esse andar.\n");
        	getch();
		}
	}while(andar_check[andar-1]==0);
	
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
	int subclasse_on = 0; 
	int i,ok;
	for(i=0;i<3;i++)
	{
		if(user->heroi[cur_heroi].subclasse[i].on==1)
		{
			subclasse_on = i;
	
		}	
	}
	int subclasse_game;

	char subclasse[3][60];
	char subclasse_name[2][60];
	int classe = user->heroi[cur_heroi].classe;
	if(subclasse_on)
	{
		
		printf("\n\nDefina sua subclasse a seguir\n\n");
	 	getch();
	 	if(subclasse_on==1)
	 	{
	 		typeLayout(subclasse,&subclasse_game,1);
		}
		else
		{
			typeLayout(subclasse,&subclasse_game,2);
		}
	    imprimirStatusSubClass(*user,cur_heroi,classe,subclasse_game);
	    getch();	
	    int new_ataque = user->heroi[cur_heroi].subclasse[subclasse_game].ataque_base;
	    int new_defesa = user->heroi[cur_heroi].subclasse[subclasse_game].defesa_base;
		int new_mana = user->heroi[cur_heroi].subclasse[subclasse_game].mana_base;
		int new_vida = user->heroi[cur_heroi].subclasse[subclasse_game].vida_base;

		user->heroi[cur_heroi].ataque_base = new_ataque;
		user->heroi[cur_heroi].defesa_base = new_defesa;
		user->heroi[cur_heroi].mana_base = new_mana;
		user->heroi[cur_heroi].vida_base = new_vida;
	}
	

	nome(monstros);
	user->heroi[cur_heroi].ataque_base +=user->heroi[cur_heroi].ataque; 
	user->heroi[cur_heroi].defesa_base +=user->heroi[cur_heroi].defesa; 	

	system("cls");
	printf("Status do adversario:\n\n");
	if(rng2!=99){
			
        printf("INIMIGO:%s\n",monstros[rng2].nome);
        printf("vida:%.1f\nataque:%.2f\ndefesa:%.2f\n",monstros[rng2].vida,monstros[rng2].ataque,monstros[rng2].defesa);
	}
	else{
        printf("INIMIGO:\n");
        printf("vida:???\nataque:???\ndefesa:???\n");
	}
	getch();
	
	
	int status = batalha(user,&monstros[rng2],&cur_heroi);
	system("cls");
	printf("Status Final da batalha: ");
	if(status)
	{
		printf("Voce venceu!\n\n\n");
		
		
		(*user).heroi[cur_heroi].moeda += 5*andar;
		if(andar==(*user).heroi[cur_heroi].andar)
		{
			(*user).heroi[cur_heroi].andar++;
			printf("Voce subiu de andar!\n\nNovo andar desbloqueado: %i\n\n",(*user).heroi[cur_heroi].andar);
		}
		printf("Voce ganhou %i moedas pela vitoria!",5*andar);
		
		printf("\n\nParabens pela vitoria!!!\n");
		user->heroi[cur_heroi].vitoria_seguida += 1;
		user->heroi[cur_heroi].tot_vitoria += 1;

		printf("\n\nVoce esta a %i lutas sem perder!!!\n",user->heroi[cur_heroi].vitoria_seguida);

	}
	else
	{
		printf("Voce perdeu!\n\n");
		user->heroi[cur_heroi].vitoria_seguida = 0;
		user->heroi[cur_heroi].derrota += 1;
	}
	getch();
	imprimirStatusHeroi(*user,cur_heroi);
	getch();
	user->heroi[cur_heroi].ataque_base -=user->heroi[cur_heroi].ataque; 
	user->heroi[cur_heroi].defesa_base -=user->heroi[cur_heroi].defesa; 	
	
	char tags[4][60];	
	tagsGame(tags);

	typeLayout(tags,&choice,3);
				
	switch(choice){
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
		default:
			printf("Comando invalido.\n");
			system("cls");
			break;

	}
	

}

}
#endif
