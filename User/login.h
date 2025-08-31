#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//cette fonction sert a creer un nouveau voyageur avec tous ses donnees en l'enregistrant dans le fichier "user_log.txt"
void nv_compte()
{
	FILE *f_info,*f_log;
	
	char email_input[50],email[50],mdp[30],nom[30],prenom[30],CIN[10];
	
	int num_passport , exist;
	
	f_log = fopen("Files/connexion_utilisateur.txt","a+");
	
	exist = 1 ;
	
		printf("Entrer votre e-mail : ");
		scanf("%s",email_input);
		fseek(f_log,0,SEEK_SET);
		exist=0;
		while(!feof(f_log))
		{
			fscanf(f_log,"%s%s",email,mdp);
			if(strcmp(email_input,email)==0)
			{
				exist=1;
				printf("Cet email est deja enregistree !!\n");
				return;
			}
		}

	printf("\tEntrer votre mot de passe : ");
	scanf("%s",mdp);
	
	fprintf(f_log,"%s\t\t%s\n",email_input,mdp);
	
	fclose(f_log);
	f_info = fopen("Files/information_utilisateur.txt","a+");
	printf("Identification\n");
	printf("\tVotre nom : ");
	scanf("%s",nom);
	printf("\tVotre prenom : ");
	scanf("%s",prenom);
	printf("\tVotre CIN : ");
	scanf("%s",CIN);
	printf("\tVotre Numero de passeport : ");
	scanf("%d",&num_passport);
	fprintf(f_info,"%s\t\t%s\t\t%s\t\t%s\t\t%d\n",email_input,nom,prenom,CIN,num_passport);
	fclose(f_info);
}

//se connecter avec un email deja enregistree
int logIn(char email_input[50],char file_name[20])
{
	char email[50],mdp[30],mdp_input[30];
	
	int success=0;
	
	FILE *p_fichier;
	
	p_fichier = fopen(file_name,"r");
	
	printf("\tMot de passe: ");
	scanf("%s",mdp_input);
	while(!feof(p_fichier))
	{
		fscanf(p_fichier,"%s %s",email,mdp);
		if(strcmp(email_input,email)==0 && strcmp(mdp_input,mdp)==0)
		{
			success=1;
			break;
		}
	}
	fclose(p_fichier);
	if(success==1)
	{
		printf("Entree avec succes.\n");
		return 1;
	}
	printf("Le mot de passe ou l'email entre est incorrect !! \nSVP reesayer.\n");
	return 0;
}

