#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int annee;
	int mois;
	int jour;
} Datenais;


typedef struct {
	char nom[20];
	char prenom[20];
	Datenais Date;
}Stagaire;
main (){

Stagaire stage1;
printf("donnez les informations du stagaire.\n");
printf("donnez le nom : ");
scanf("%s", stage1.nom);
printf("donnez le prenom:");
scanf("%s", stage1.prenom);
printf("donnez la Datenais:");
printf("donnez le jour:");
scanf("%d",&stage1.Date.jour);
printf("donnez le mois:");
scanf("%d",&stage1.Date.mois);
printf("donnez le annee:");
scanf("%d",&stage1.Date.annee);

printf("les informations du stagaire.\n");
printf("le nom :%s\n ",stage1.nom);
printf("le prenom:%s\n",stage1.prenom);
printf("la Datenais:\n");
printf("le jour:%d\n",stage1.Date.jour);
printf("le mois:%d\n",stage1.Date.mois);
printf("l'annee:%d\n",stage1.Date.annee);


}


