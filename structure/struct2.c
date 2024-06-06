#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char nom[20];
	char prenom[20];
	double Note[3];
	double moyenne;
}Etudiant;

main() {

	Etudiant etu;
	int i;
	double somme =0.0;

	printf("donnez le nom :");
	scanf("%s\n",etu.nom);
	printf("donnez le prenom :");
	scanf("%s\n",etu.prenom);
	printf("donnez les notes:\n");
	for(i = 0;i<3;i++){
		printf("Note num %lf:",i+1);
		scanf("%lf",&etu.Note[i]);
		somme += etu.Note[i];
	}
	etu.moyenne = somme / 3.0;


	printf("la moyenne de l'étudiant %s %s est: %.2lf\n",etu.nom,etu.prenom,etu.moyenne);

 return 0;
}