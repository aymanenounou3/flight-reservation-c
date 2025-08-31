#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"modif_voyageur.h"
#include"modif_vol.h"
#include"modif_employe.h"


void menu_admin()
{
	char email_input[50];
	int i,choice;
	printf("\tEmail : ");
	scanf("%s",email_input);
	i=logIn(email_input,"Files/admin_log.txt");
	if(i==1)
	{
		do{
			printf("1 - Acceder a la liste des voyageurs\n");
			printf("2 - Acceder a la liste des vols\n");
			printf("3 - Acceder a la liste des employes\n");
			printf("0 - Return\n");
			printf("votre choix : ");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					menu_voyageur();
					break;
				case 2:
					menu_vol();
					break;
				case 3:
					menu_employe();
					break;
				case 0:
					break;
			}
		}while(choice!=0);
	}
}

