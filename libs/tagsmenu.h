
#ifndef TAGSMENU_H
#define TAGSMENU_H

#include <stdio.h>
#include <string.h>
#include <cadastro.h>
tagsMainMenu(char tags[][60])
{
	strcpy(tags[0],"NULL\0");
	strcpy(tags[1],"Ir a Loja");
	strcpy(tags[2],"Jogar");
	strcpy(tags[3],"Status");
	strcpy(tags[4],"Cadastrar novo Heroi");
	strcpy(tags[5],"Mudar Heroi");
	strcpy(tags[6],"Configuracoes");
	strcpy(tags[7],"Sair");
}
tagsStartMenu(char tags[][60])
{
	strcpy(tags[0],"NULL\0");
	strcpy(tags[1],"Novo Usuario");
	strcpy(tags[2],"Acessar o Login");
}
tagsLojaMenu(char tags[][60])
{
	strcpy(tags[0],"NULL\0");
	strcpy(tags[1],"Adquirir Equipamento");
	strcpy(tags[2],"Adicionar Consumiveis");
	strcpy(tags[3],"Menu Principal");
}
tagsStatusMenu(char tags[][60])
{
	strcpy(tags[0],"Null");
	strcpy(tags[1],"Equipamentos");
	strcpy(tags[2],"Classe");
	strcpy(tags[3],"Heroi");
	strcpy(tags[4],"Subclasse");
	strcpy(tags[5],"Consumiveis");
	strcpy(tags[6],"Menu Principal");

}
void tagsClasses(char classe[][60])
{

	strcpy(classe[0],"NULL\0");
	strcpy(classe[1],"Guerreiro\0");
	strcpy(classe[2],"Mago\0");
	strcpy(classe[3],"Lutador\0");
	strcpy(classe[4],"Assassino\0");

}
void tagsSubClass(char subclasse[][60],int classe)
{

	///Módulo em desenvolvimento
	switch(classe)
	{
    case 1:
        {
            strcpy(subclasse[1],"Duelista");
            strcpy(subclasse[2],"Berseker");
        }break;
       case 2:
        {
            strcpy(subclasse[1],"Mago de Sangue");
            strcpy(subclasse[2],"Mago Elemental");
        }break;
          case 3:
        {
            strcpy(subclasse[1],"Monge");
            strcpy(subclasse[2],"Campeao");
        }break;
          case 4:
        {
            strcpy(subclasse[1],"Gangster");
            strcpy(subclasse[2],"Sniper");
        }break;
	}
	strcpy(subclasse[0],"NULL");
}
void tagsConfigMenu(char tags[][60])
{

	strcpy(tags[0],"NULL\0");
	strcpy(tags[1],"Mudar Nome do Heroi\0");
	strcpy(tags[2],"Adicionar subclasse\0");
	strcpy(tags[3],"Mudar Classe\0");
	strcpy(tags[4],"Menu Principal\0");

}
void tagsHerois(Cadastro user,char tags[][60],int qtd_herois)
{
	int i;
	for(i=0;i<=qtd_herois;i++)
	{
		strcpy(tags[i+1],user.heroi[i].nome);
	}

}
void tagsEquipamentos(char Equipamentos[][60])
{
	strcpy(Equipamentos[1],"Bota\0");
	strcpy(Equipamentos[2],"Calca\0");
	strcpy(Equipamentos[3],"Elmo\0");
	strcpy(Equipamentos[4],"Escudo\0");
	strcpy(Equipamentos[5],"Espada\0");
	strcpy(Equipamentos[6],"Luva\0");
	strcpy(Equipamentos[7],"Ombro\0");
	strcpy(Equipamentos[8],"Couraca\0");

}
void tagsStartGame(char tags[4][60])
{
	strcpy(tags[0],"Null");
	strcpy(tags[1],"Selecionar Heroi");
	strcpy(tags[2],"Sair");
}
void tagsConsumeveis(char cons[][60])
{
	strcpy(cons[0],"Null");
	strcpy(cons[1],"HP-Porcao de vida");
	strcpy(cons[2],"MANA-Porcao de Mana");
	strcpy(cons[3],"DEBUFF-Contra Efeitos Negativos");
}
void tagsGame(char tags[][60])
{

	strcpy(tags[0],"NULL\0");
	strcpy(tags[1],"Continuar jogando\0");
	strcpy(tags[2],"Menu Principal\0");
	strcpy(tags[3],"Sair e Salvar Status\0");

}
void imprimirTags(char tags[][60],int number_tags)
{
	int i;
	for(i=1;i<number_tags;i++)
	{
		printf("%i.%s\n",i,tags[i]);
	}
}
#endif
