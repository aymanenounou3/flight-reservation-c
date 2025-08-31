#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//cette fonction sert a afficher les vols  qui sont enregistrer dans le fichier "list_vols"
void liste_vols()
{
	char dep[50],dest[50];
	
	int id_vol,min_dep,h_dep,jour_dep,mois,annee,min_arriv,h_arriv,jour_arriv;
	
	FILE *p_fichier;
	
	p_fichier = fopen("Files/list_vols.txt","r");
		
	while(!feof(p_fichier))
	{
		fscanf(p_fichier,"%d\t\t\t%s\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%s\t\t\t%d\t\t\t%d\t\t\t%d\n",&id_vol,dep,&h_dep,&min_dep,&jour_dep,&mois,&annee,dest,&min_arriv,&h_arriv,&jour_arriv);	
		printf("ID Vol : %d\n",id_vol);
		printf("Depart : %s\n",dep);
		printf("Heure : %d:%d\n",h_dep,min_dep);
		printf("Date : %d/%d/%d\n",jour_dep,mois,annee);
		printf("Destination : %s\n",dest);
		printf("Heure : %d:%d\n",min_arriv,h_arriv);
		printf("Date : %d/%d/%d\n",jour_arriv,mois,annee);
		printf("----------------------------------------\n");
	}
	
	printf("\n");
	
	fclose(p_fichier);

}

//reserver un des vols qui sont dans le fichier"list_vols" et le vol enregistrer sur le nom de voyageur
void reserver(char email_input[50])
{
	char email[50],dep[50],dest[50];
	
	int id_vol_input,id_vol,min_dep,h_dep,jour_dep,mois,annee,min_arriv,h_arriv,jour_arriv,id_exist=0,id_reserver=0;
	
	FILE *f_lres,*f_lvols;
	
	f_lvols=fopen("Files/list_vols.txt","r");
	
	f_lres=fopen("Files/list_reservation.txt","a+");
	
	printf("ID du vol : ");
	scanf("%d",&id_vol_input);
	
	fseek(f_lvols,0,SEEK_SET);
	
	while(!feof(f_lvols))
	{
		fscanf(f_lvols,"%d %s %d %d %d %d %d %s %d %d %d\n",&id_vol,dep,&h_dep,&min_dep,&jour_dep,&mois,&annee,dest,&min_arriv,&h_arriv,&jour_arriv);
		if(id_vol==id_vol_input)
		{
			id_exist=1;
			break;
		}
	}
	if(id_exist==1)
	{
		while(!feof(f_lres))
		{
			fscanf(f_lres,"%s %d",email,&id_vol);
			if(strcmp(email_input,email)==0 && id_vol==id_vol_input)
			{
				printf("Vous avez deja reserve ce vol !!\n");
				id_reserver=1;
				break;
			}
		}
		if(id_reserver==0)
		{
			fprintf(f_lres,"%s %d\n",email_input,id_vol_input);
			printf("Le vol est reservee avec succes!!\n");
		}
	}
	else
		printf("Ce vol n'existe pas !!\n");
	fclose(f_lres);
	fclose(f_lvols);

}

//cette fonction affiche les reservations d'un voyageur a partir de son email
void liste_reservation(char email_input[30])
{
	char email[50],dep[50],dest[50];
	
	int id_vol_search,id_vol,min_dep,h_dep,jour_dep,mois,annee,min_arriv,h_arriv,jour_arriv;
	
	FILE *f_lres,*f_lvols;
	
	f_lres = fopen("Files/list_reservation.txt","r");
	
	f_lvols = fopen("Files/list_vols.txt","r");
	
	while(!feof(f_lres))
	{
		fscanf(f_lres,"%s %d\n",email,&id_vol);
		if(strcmp(email_input,email)==0)
		{
			fseek(f_lvols,0,SEEK_SET);
			while(!feof(f_lvols))
			{
				fscanf(f_lvols,"%d %s %d %d %d %d %d %s %d %d %d\n",&id_vol_search,dep,&h_dep,&min_dep,&jour_dep,&mois,&annee,dest,&min_arriv,&h_arriv,&jour_arriv);
				if(id_vol == id_vol_search)
				{
					printf("ID Vol : %d\n",id_vol);
					printf("Depart : %s\n",dep);
					printf("Heure : %d:%d\n",h_dep,min_dep);
					printf("Date : %d/%d/%d\n",jour_dep,mois,annee);
					printf("Destination : %s\n",dest);
					printf("Heure : %d:%d\n",min_arriv,h_arriv);
					printf("Date : %d/%d/%d\n",jour_arriv,mois,annee);
					printf("----------------------------------------\n");
				}
			}
		}
	}
	
	printf("\n");
	
	fclose(f_lvols);
	
	fclose(f_lres);
}
