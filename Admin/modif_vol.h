#include<stdio.h>
#include<stdlib.h>


typedef struct vol
{
	char dep[50],dest[50];
	int id_vol,min_dep,h_dep,jour_dep,mois,annee,min_arriv,h_arriv,jour_arriv;
	struct vol *suivant;
}vol;

typedef struct reserve
{
	char email[50];
	int id_vol;
	struct reserve *suivant;
}reserve;

//telecharger un vol deja enregistrees;
vol *telecharger_vol_1(vol *l_vol,FILE *p_fichier)
{
	vol *nouveau=(vol*)malloc(sizeof(vol)),*temp=l_vol;
	fscanf(p_fichier,"%d %s %d %d %d %d %d %s %d %d %d\n",&nouveau->id_vol,nouveau->dep,&nouveau->h_dep,&nouveau->min_dep,&nouveau->jour_dep,&nouveau->mois,&nouveau->annee,nouveau->dest,&nouveau->min_arriv,&nouveau->h_arriv,&nouveau->jour_arriv);
	nouveau->suivant=NULL;
	if(l_vol==NULL)
		return nouveau;
	else
	{
		while(temp->suivant!=NULL)
			temp=temp->suivant;
		
		temp->suivant=nouveau;
		return l_vol;
	}
}

//cette fonction sert a telecharger les infos des vols
vol *telecharger_vol(vol *l_vol)
{
	l_vol=NULL;
	FILE *p_fichier;
	p_fichier = fopen("Files/list_vols.txt","r");
	while(!feof(p_fichier))
	{
		l_vol=telecharger_vol_1(l_vol,p_fichier);
	}
	fclose(p_fichier);
	return l_vol;
}

//telecharger une reservation
reserve *telecharger_reserv_1(reserve *l_reserve,FILE *p_fichier)
{
	reserve *nouveau=(reserve*)malloc(sizeof(reserve));
	reserve *temp=l_reserve;
	fscanf(p_fichier,"%s %d\n",nouveau->email,&nouveau->id_vol);
	nouveau->suivant=NULL;
	if(l_reserve==NULL)
		return nouveau;
	else
	{
		while(temp->suivant!=NULL)
			temp=temp->suivant;
		temp->suivant=nouveau;
		return l_reserve;
	}

}

int i;
//telecharger tous les reservations
reserve *telecharger_reserv(reserve *l_reserve)
{
	l_reserve=NULL;
	FILE *p_fichier;
	p_fichier = fopen("Files/list_reservation.txt","r");
	while(!feof(p_fichier))
	{
		l_reserve=telecharger_reserv_1(l_reserve,p_fichier);
		i++;
	}
	fclose(p_fichier);
	return l_reserve;
}

//cette fonction sert a afficher tous les vols 
void afficher_vol(vol *l_vol)
{
	if(l_vol==NULL)
		printf("La liste est vide !!\n");
	else
	{
		vol *temp = l_vol;
		while(temp!=NULL)
		{
			printf("ID Vol : %d\nDepart : %s\nHeure : %d:%d\nDate : %d/%d/%d\nDestination : %s\nHeur : %d:%d\nDate : %d/%d/%d\n",temp->id_vol,temp->dep,temp->h_dep,temp->min_dep,temp->jour_dep,temp->mois,temp->annee,temp->dest,temp->min_arriv,temp->h_arriv,temp->jour_arriv,temp->mois,temp->annee);
			printf("---------------------------------------------------------------\n");
			temp=temp->suivant;
		}
	}
}

//cette fonction sert a creer un nouveau vol;
vol *ajouter_vol(vol *l_vol)
{
	vol *nouveau=(vol*)malloc(sizeof(vol));
	vol *temp = l_vol;
	printf("ID Vol : ");
	scanf("%d",&nouveau->id_vol);
	printf("Insertion des infos: \n");
	printf("Depart");
	printf("Lieu : ");
	scanf("%s",nouveau->dep);
	printf("Heure : ");
	scanf("%d",&nouveau->h_dep);
	printf("Minute : ");
	scanf("%d",&nouveau->min_dep);
	printf("Jour : ");
	scanf("%d",&nouveau->jour_dep);
	printf("Mois : ");
	scanf("%d",&nouveau->mois);
	printf("Annee : ");
	scanf("%d",&nouveau->annee);
	
	printf("Destination : ");
	printf("Lieu : ");
	scanf("%s",nouveau->dest);
	printf("Heure : ");
	scanf("%d",&nouveau->h_arriv);
	printf("Minute : ");
	scanf("%d",&nouveau->min_arriv);
	printf("Jour : ");
	scanf("%d",&nouveau->jour_arriv);

	nouveau->suivant=NULL;
	if(l_vol==NULL)
		return nouveau;
	else
	{
		while(temp->suivant!=NULL)
			temp=temp->suivant;
		
		temp->suivant=nouveau;
		return l_vol;
	}
}

//cette fonction sert a enregistrer tous les modifications
void sauvgarder_tous(vol *l_vol,reserve *l_reserve)
{
	FILE *f_vol,*f_reserve;
	f_vol = fopen("Files/list_vols.txt","w");
	f_reserve = fopen("Files/list_reservation.txt","w");
	vol *temp=l_vol;
	reserve *temp2=l_reserve;
	while(temp!=NULL)
	{
		fprintf(f_vol,"%d %s %d %d %d %d %d %s %d %d %d\n",temp->id_vol,temp->dep,temp->h_dep,temp->min_dep,temp->jour_dep,temp->mois,temp->annee,temp->dest,temp->min_arriv,temp->h_arriv,temp->jour_arriv,temp->mois,temp->annee);
		temp=temp->suivant;
	}
	while(temp2!=NULL)
	{
		fprintf(f_reserve,"%s %d\n",temp2->email,temp2->id_vol);
		temp2=temp2->suivant;
	}
	printf("Modificaton Enregistre avec succes!!\n");
	fclose(f_reserve);
	fclose(f_vol);
}


void menu_vol()
{
	vol *l_vol;
	reserve *l_reserve;
	l_vol = telecharger_vol(l_vol);
	l_reserve = telecharger_reserv(l_reserve);
	int choix ;
	do{
		printf("1 - Afficher la liste des vols\n");
		printf("2 - Ajouter un vol\n");
		printf("3 - Enregistrez les modifications\n");
		printf("4 - Retour\n");
		printf("votre choix : ");
		scanf("%d",&choix);
		switch(choix)
		{
			case 1:
				afficher_vol(l_vol);
				printf("\n");
				break;
			case 2:
				l_vol = ajouter_vol(l_vol);
				printf("\n");
				break;
			case 3:
				sauvgarder_tous(l_vol,l_reserve);
				printf("\n");
				break;
			case 4:
				break;
		}
	}while(choix!=4);
}
 
