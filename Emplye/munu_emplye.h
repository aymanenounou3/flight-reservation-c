#include"change_log.h"
#include"affich_info.h"

//cette fonction s'affiche lorsque l'utilisateur choisit l'espace employee.
void menu_emp()
{
	char email_input[50];
	int i,choix;
	printf("\tEmail : ");
	scanf("%s",email_input);
	
	i=logIn(email_input,"Files/connexion_emp.txt");
	
	if(i==1)
	{
		do{
			printf("1 - Afficher mes informations\n");
			printf("2 - Changer votre mot de passe\n");
			printf("3 - Retour\n");
			printf("votre choix : ");
			scanf("%d",&choix);
			switch(choix)
			{
				case 1:
					affichage_info(email_input);
					break;
				case 2:
					change_connexion(email_input);
					break;
				case 3:munu(); 
				       break;
					
			}
		}while(choix!=0);
	}
}

