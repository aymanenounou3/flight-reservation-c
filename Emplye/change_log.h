#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct l_info
{
	char email[50],mdp[50];
	struct l_info *suivant;
}l_info;

//telecharger les informations du connexion un par un 
l_info *telecharger_un_par_un(l_info *p , FILE *f)
{
	l_info *nouveau = (l_info*)malloc(sizeof(l_info)) ;
	l_info *temp = p ;
	fscanf(f,"%s %s\n",nouveau->email,nouveau->mdp);
	nouveau->suivant=NULL;
	
	if(p==NULL)
		return nouveau;
	else
	{
		while(temp->suivant!=NULL)
			temp=temp->suivant;
		temp->suivant=nouveau;
		return p;
	}
}

//telecharger les informations de connexion 
l_info *telecharger_connexion_emp(l_info *p)
{
	FILE *f;
	f = fopen("Files/connexion_emp.txt","r");
	while(!feof(f))
	{
		p=telecharger_un_par_un(p,f);
	}
	fclose(f);
	return p;
}

//cette fonction sert a enregistrer les informations de connexion
void sauvgarder_empl_connexion(l_info *p)
{
	FILE *p_fichier;
	p_fichier = fopen("Files/connexion_emp.txt","w");
	l_info *aide=p;
	while(aide!=NULL)
	{
		fprintf(p_fichier,"%s %s\n",aide->email,aide->mdp);
		aide = aide->suivant;
	}
	fclose(p_fichier);
}

//cette fonction sert a chaner le mot de passe d'un employe
l_info *modifier_mdp(l_info *l, char email[50])
{
	char mdp_actuel[50], mdp_nouveau[50], mdp_nouveau2[50];
	l_info *temp = l;
	while(temp!=NULL)
	{
		if(strcmp(email,temp->email)==0)
		{
			printf("Entrer votre mot de passe actuel : ");
			scanf("%s", mdp_actuel);
			if (strcmp(mdp_actuel,temp->mdp)!=0)
			{
				printf("Le mot de passe est incorrecte !!\n");
				return l;
			}
		A:	printf("Entrer un nouveau mot de passe : ");
			scanf("%s", mdp_nouveau);
			printf("Reentrez le nouveau mot de passe : ");
			scanf("%s",mdp_nouveau2);
			if (strcmp(mdp_nouveau,mdp_nouveau2)!=0)
			{
				printf("Les nouveaux mot de passes ne sont pas identiques!!\n");
				goto A ;
			}
			strcpy(temp->mdp, mdp_nouveau2);
		}
		temp=temp->suivant;
	}
	return l;
}


void change_connexion(char email[50])
{
	l_info *l;
	l = NULL;
	l = telecharger_connexion_emp(l);
	l = modifier_mdp(l,email);
	sauvgarder_empl_connexion(l);
}

