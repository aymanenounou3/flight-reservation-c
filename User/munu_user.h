#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"login.h"
#include"reservation.h"

//fonction qui affiche le menu dans l'espace voyageur:
void reservation_menu(char email_input[50])
{
	int choix;
	do{
		printf("1 - Afficher la liste des vols:\n");
		printf("2 - Reserver un vol:\n");
		printf("3 - Mes resevations:\n");
		printf("4 - Se deconnecter.\n");
		printf("votre choix : ");
		scanf("%d",&choix);
		switch(choix)
		{
			case 1:
				liste_vols();
				break;
			case 2:
				reserver(email_input);
				printf("\n");
				break;
			case 3:
				liste_reservation(email_input);
				break;
			case 4:
				break;
		}
	}while(choix!=4);
}

//quand l'utilisateur se deconnecte, la fonction ci-dessous revient en arriere et affiche le debut du page (login).
void login_menu()
{
	char email_input[50];
	int choix,i;
	do{
		printf("1 - Se connecter. \n");
		printf("2 - Creer un nouveau compte.\n");
		printf("3 - Se deconnecter.\n");
		printf("votre choix : ");
		scanf("%d",&choix);
		switch(choix)
		{
			case 1:
				printf("\tEntrer votre email : ");
				scanf("%s",email_input);
				i = logIn(email_input,"Files/connexion_utilisateur.txt");
				printf("\n");
				if(i==1)
					reservation_menu(email_input);
				break;
			case 2:
				nv_compte();
				break;
			case 3:munu();
				break;
		}
	}while(choix!=0);
}

