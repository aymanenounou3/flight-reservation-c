#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct emp
{
	char email[50],prenom[50],nom[50],metier[30];
	struct emp *suivant;
}emp;


typedef struct connexion
{
	char email[50],mdp[50];
	struct connexion *suivant;
}connexion;

//telecharger un employee deja enregistrees;
emp *telecharger_1(emp *l , FILE *p_fichier)
{
	emp *nouveau=(emp*)malloc(sizeof(emp));
	emp *temp=l;
	fscanf(p_fichier,"%s %s %s %s\n",nouveau->email,nouveau->nom,nouveau->prenom,nouveau->metier);
	nouveau->suivant=NULL;
	if(l==NULL)
		return nouveau;
	else
	{
		while(temp->suivant!=NULL)
			temp=temp->suivant;
		
		temp->suivant=nouveau;
		return l;
	}
}

//telecharger les infos des employes qui sont dans le fichier "donnees_emp.txt" ;
emp *telecharger_emp(emp *l)
{
	FILE *p_fichier;
	p_fichier = fopen("Files/donnees_emp.txt","r");
	while(!feof(p_fichier))
	{
		l=telecharger_1(l,p_fichier);
	}
	fclose(p_fichier);
	return l;
}

//cette fonction sert a lire un email et mdp qui sont deja dans un fichier
connexion *connexion_1(connexion *l , FILE *p_fichier)
{
	connexion *nouveau=(connexion*)malloc(sizeof(connexion)) ;
	connexion *temp=l;
	fscanf(p_fichier,"%s %s\n",nouveau->email,nouveau->mdp);
	nouveau->suivant=NULL;
	if(l==NULL)
		return nouveau;
	else
	{
		while(temp->suivant!=NULL)
			temp=temp->suivant;
		
		temp->suivant=nouveau;
		return l;
	}
}

//cette fonction sert a telecharger la connexion des employes;
connexion *connexion_emp(connexion *l)
{
	FILE *p_fichier;
	p_fichier = fopen("Files/connexion_emp.txt","r");
	while(!feof(p_fichier))
	{
		l=connexion_1(l,p_fichier);
	}
	fclose(p_fichier);
	return l;
}

//cette fonction sert a ajouter un nouveau mot de passe 
connexion *ajouter_connexion(connexion *l,char email[50])
{
	connexion *nouveau=(connexion*)malloc(sizeof(connexion)) ;
	connexion *temp=l;
	strcpy(nouveau->email,email);
	printf("Mot de passe : ");
	scanf("%s",nouveau->mdp);
	nouveau->suivant=NULL;
	if(l==NULL)
		return nouveau;
	else
	{
		while(temp->suivant!=NULL)
			temp=temp->suivant;
		
		temp->suivant=nouveau;
		return l;
	}
}

//cette fonction sert a ajouter un nouveau employee
emp *ajouter_emp(emp *l,connexion *p)
{
	emp *nouveau=(emp*)malloc(sizeof(emp));
	emp *temp=l,*temp2=l;
	printf("Email : ");
	scanf("%s",nouveau->email);
	while(temp2!=NULL)
	{
		if(strcmp(nouveau->email,temp2->email)==0)
		{
			printf("L'email existe deja!!\n");
			return l;
		}
		temp2=temp2->suivant;
	}
	p = ajouter_connexion(p,nouveau->email);
	printf("Votre nom : ");
	scanf("%s",nouveau->nom);
	printf("Votre prenom : ");
	scanf("%s",nouveau->prenom);
	printf("Votre metier : ");
	scanf("%s",nouveau->metier);
	nouveau->suivant=NULL;
	if(l==NULL)
		return nouveau;
	else
	{
		while(temp->suivant!=NULL)
			temp=temp->suivant;
		
		temp->suivant=nouveau;
		return l;
	}

}

//modifier les informations d'un employee;
emp *modifier_emp(emp *l)
{
	char email_input[50];
	if(l==NULL)
	{
		printf("La liste est vide !!\n");
		return l;
	}
	emp *temp=l;
	printf("Entrez l'email d'employee qui vous voudriez modifier : ");
	scanf("%s",email_input);
	while(temp!=NULL)
	{
		if(strcmp(temp->email,email_input)==0)
		{
			printf("Les informations : \n");
			printf("Email : %s\t\tNom : %s\t\tPrenom : %s\t\tMetier : %s\n",temp->email,temp->nom,temp->prenom,temp->metier);
			printf("Modification : \n");
			printf("Nouveau Email : ");
			scanf("%s",temp->email);
			printf("Nouveau Nom : ");
			scanf("%s",temp->nom);
			printf("Nouveau Prenom : ");
			scanf("%s",temp->prenom);
			printf("Nouveau Metier : ");
			scanf("%s",temp->metier);
			return l;
		}
		temp=temp->suivant;
	}
	printf("Cet email n'existe pas !!\n");
	return l;
}

//afficher tous les employee 
void afficher_emp(emp *l)
{
	if(l==NULL)
		printf("la liste est vide !!\n");
	else
	{
		emp *temp=l;
		while(temp!=NULL)
		{
			printf("Email : %s\nNom : %s\nPrenom : %s\nMetier : %s\n",temp->email,temp->nom,temp->prenom,temp->metier);
			printf("---------------------------------------------------------------\n");
			temp=temp->suivant;
		}
	}
}

//cette fonction sert a sauvegarder les modifications
void sauvgarder_emp(emp *l,connexion *p)
{
	FILE *p_info,*p_connexion;
	p_info = fopen("Files/donnees_emp.txt","w");
	p_connexion = fopen("Files/connexion_emp.txt","w");
	
	emp *temp=l;
	connexion *temp2=p;
	
	while(temp!=NULL)
	{
		fprintf(p_info,"%s %s %s %s\n",temp->email,temp->nom,temp->prenom,temp->metier);
		temp=temp->suivant;
	}
	while(temp2!=NULL)
	{
		fprintf(p_connexion,"%s %s\n",temp2->email,temp2->mdp);
		temp2=temp2->suivant;
	}
	printf("Modificaton Enregistree avec succes!!\n");
	fclose(p_connexion);
	fclose(p_info);
}

void menu_employe()
{
	emp *l;
	connexion *p;
	l=NULL ; 
	p=NULL;
	l = telecharger_emp(l);
	p = connexion_emp(p);
	int choix;
	do{
		printf("1 - Afficher la liste des employes\n");
		printf("2 - Ajouter un employe\n");
		printf("3 - Modifier un employe\n");
		printf("4 - Enregistrer les modifications\n");
		printf("5 - Retour\n");
		printf("votre choix : ");
		scanf("%d",&choix);
		switch(choix)
		{
			case 1:
				afficher_emp(l);
				printf("\n");
				break;
			case 2:
				l = ajouter_emp(l,p);
				printf("\n");
				break;
			case 3:
				l = modifier_emp(l);
				printf("\n");
				break;
			case 4:
				sauvgarder_emp(l,p);
				printf("\n");
				break;
			case 5:
				break;
		}
	}while(choix!=5);
}

