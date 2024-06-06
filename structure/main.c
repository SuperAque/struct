#include <stdio.h>
#include <stdlib.h>

//declaration v1<
struct personne{

	char nom[12];
	int age;
	double taille;
}

//declaration v2
typedef struct{

	char nom[12];
	int age;
	double taille;

}personne;
void main()
{
	//appel de new type () structure v1
	struct personne pers;
	//appel de new type () structure v2
	personne pers;
}
