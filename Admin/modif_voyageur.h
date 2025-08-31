#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct list_info
{
	int num_passport;
	char email[50],nom[30],prenom[30],CIN[10];
	struct list_info *suivant;
}list_info;

typedef struct list_connexion
{
	char email[50],mdp[30];
	struct list_connexion *suivant;
}list_connexion;

//telecharger les informations d'un voyageur
list_info *telecharger_info_1(list_info *l_info,FILE *p_fichier)
{
	list_info *nouveau=(list_info*)malloc(sizeof(list_info)),*temp=l_info;
	
	fscanf(p_fichier,"%s %s %s %s %d\n",nouveau->email,nouveau->nom,nouveau->prenom,nouveau->CIN,&nouveau->num_passport);
	nouveau->suivant=NULL;
	if(l_info==NULL)
		return nouveau;
	
	else
	{
		while(temp->suivant!=NULL)
			temp=temp->suivant;
		temp->suivant=nouveau;
		return l_info;
	}
}
//telecharger les informations des voyageurs
list_info *telecharger_info(list_info *l_info)
{
	l_info=NULL;
	FILE *p_fichier;
	p_fichier = fopen("Files/information_utilisateur.txt","r");
	while(!feof(p_fichier))
	{
		l_info=telecharger_info_1(l_info,p_fichier);
	}
	fclose(p_fichier);
	return l_info;
}

 
list_connexion *telecharger_connexion_1(list_connexion *l_connexion,FILE *f)
{
	list_connexion *nouveau=(list_connexion*)malloc(sizeof(list_connexion));
	list_connexion *temp=l_connexion;
	fscanf(f,"%s %s\n",nouveau->email,nouveau->mdp);
	nouveau->suivant=NULL;
	if(l_connexion==NULL)
		return nouveau;
	else
	{
		while(temp->suivant!=NULL)
			temp=temp->suivant;
		
		temp->suivant=nouveau;
		return l_connexion;
	}
}


list_connexion *telecharger_connexion(list_connexion *l_connexion)
{
	l_connexion=NULL;
	FILE *f;
	f=fopen("Files/connexion_utilisateur.txt","r");
	while(!feof(f))
	{
		l_connexion = telecharger_connexion_1(l_connexion,f);
	}
	fclose(f);
	return l_connexion;
}

//modifier les informations des voyageurs;
list_info *modifier(list_info *l_info)
{
	if(l_info==NULL)
	{
		printf("La liste est vide !\n");
		return l_info;
	}
	list_info *temp=l_info;
	char email_input[50];
	printf("\nEntrez l'email pour modifier les informations : ");
	scanf("%s",email_input);
	while(temp!=NULL)
	{
		if(strcmp(temp->email,email_input)==0)
		{
			printf("Email : %s\tNom : %s\tPrenom : %s\tCIN : %s\tNumero de passport : %d\n",temp->email,temp->nom,temp->prenom,temp->CIN,temp->num_passport);
			printf("Modification\n");
			printf("Nouveau nom : ");
			scanf("%s",temp->nom);
			printf("Nouveau prenom : ");
			scanf("%s",temp->prenom);
			printf("Nouveau CIN : ");
			scanf("%s",temp->CIN);
			printf("Nouveau numero de passeport : ");
			scanf("%d",&temp->num_passport);
			return l_info;
		}
		temp=temp->suivant;
	}
	printf("Cet email n'existe pas !\n");
	return l_info;
}

//cette fonciton sert a afficher les informations des voyageurs
void afficher(list_info *l_info)
{
	if(l_info==NULL)
		printf("La liste est vide !\n");
	else
	{
		list_info *temp=l_info;
		while(temp!=NULL)
		{
			printf("Email : %s\nNom : %s\nPrenom : %s\nCIN : %s\nNumero de passport : %d\n",temp->email,temp->nom,temp->prenom,temp->CIN,temp->num_passport);
			printf("---------------------------------------------------------------\n");
			temp=temp->suivant;
		}
	}
}

//cette fonction sert a enregistrer tous les informations stockees dans la memoire;
void sauvgarder(list_info *l_info,list_connexion *l_connexion)
{
	FILE *f_info,*f_connexion;
	f_info=fopen("Files/information_utilisateur.txt","w");
	f_connexion=fopen("Files/connexion_utilisateur.txt","w");
	list_info *temp=l_info;
	list_connexion *temp2=l_connexion;
	while(temp!=NULL)
	{
		fprintf(f_info,"%s\t\t%s\t\t%s\t\t%s\t\t%d\n",temp->email,temp->nom,temp->prenom,temp->CIN,temp->num_passport);
		temp=temp->suivant;
	}
	while(temp2!=NULL)
	{
		fprintf(f_connexion,"%s\t%s\n",temp2->email,temp2->mdp);
		temp2=temp2->suivant;
	}
	printf("Modification avec succes!!\n");
	fclose(f_connexion);
	fclose(f_info);
}


void menu_voyageur()
{
	list_info *l_info;
	list_connexion *l_connexion;
	l_info=telecharger_info(l_info);
	l_connexion=telecharger_connexion(l_connexion);
	int choix;
	do{
		printf("1 - Afficher les informations des utilisateurs\n");
		printf("2 - modifier les informations un utilisateur\n");
		printf("3 - Enregistrez les modifierications\n");
		printf("4 - Retour\n");
		printf("votre choix : ");
		scanf("%d",&choix);
		switch(choix)
		{
			case 1:
				afficher(l_info);
				printf("\n");
				break;
			case 2:
				l_info=modifier(l_info);
				printf("\n");
				break;
			case 3:
				sauvgarder(l_info,l_connexion);
				printf("\n");
				break;
			case 4:
				break;
		}
	}while(choix!=4);
}

