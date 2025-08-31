#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct employee
{
    char email[50],mdp[50],prenom[50],nom[50], metier[50];
    
	struct employee *suivant;

}employee;

//cette fonction affiche les informations des employees a apartir de leurs email;
void affichage_info(char email[50])
{
	FILE *p_fichier;
	
	struct employee *l_emp;
	
	p_fichier = fopen("Files/donnees_emp.txt","r");
	while(!feof(p_fichier))
	{
		fscanf(p_fichier,"%s %s %s %s",l_emp->email, l_emp->nom, l_emp->prenom, l_emp->metier);
		if(strcmp(email,l_emp->email)==0)
		{
			printf("Nom : %s \nPrenom : %s \nE-mail: %s \nMetier: %s\n",l_emp->nom,l_emp->prenom, l_emp->email, l_emp->metier);
			return;
		}
	}
	printf("Employee non trouvee !!\n");
	fclose(p_fichier);
}

