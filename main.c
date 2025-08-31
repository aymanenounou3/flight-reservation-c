#include<stdio.h>
#include<stdlib.h>
#include"User/munu_user.h"
#include"Emplye/munu_emplye.h"
#include"Admin/munu_admin.h"
#include<windows.h>


void Color(int couleurDuTexte,int couleurDeFond)                // procedure d'affichage des couleurs
{                                                               //le num 16 signifi qu'il y a 16 couleurs disponibles !!
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);                      //cette fonction des couleurs peut colorer le texte et le fond !!!
SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
munu()
{
	int choice, j;
	Color(12,15);
	char d[56] = "=>=>=>=>=>=>=>=>=>=>Client Aeroport<=<=<=<=<=<=<=<=<=<=";

	for(j=0;j<56;j++)
	{
		Sleep(50);
		printf("%c",d[j]);
	}
	
	Color(0,15);
	printf("\n\nBienvenue dans notre client, choisissez un des options disponibles pour continuer: \n\n");
	do{
		Color(3,15);
		printf("1 - Espace Voyageur:\n");
		printf("2 - Espace Employe:\n");
		printf("3 - Espace Administrateur:\n");
		printf("0 - Fermer le programme.\n\n");
		Color(0,15);
		printf("Votre choix : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				Color(4,15);
				printf("\n\n------------------------Espace voyageur------------------------\n\n");
				Color(3,15);
				login_menu();
				break;
			case 2:
				Color(4,15);
				printf("\n\n--------------------------Espace employe--------------------------\n\n");
				Color(3,15);
				menu_emp();
				break;
			case 3:
				Color(4,15);
				printf("\n\n--------------------------Espace admin--------------------------\n\n");				
				Color(3,15);
				menu_admin();
				break;
			case 0:
				break;
		}
	}while(choice!=0);
}


main(){
	munu();
}

