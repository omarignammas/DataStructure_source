#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personne.h"

//La creation d'une personne
Personne *creerPersonne(char *nom, char *prenom)
{
	Personne *p = (Personne *)malloc(sizeof(Personne));
	strcpy(p->nom, nom);
	strcpy(p->prenom, prenom);
	return p;
}

//Ecrire une personne
char *ecrirePersonne(Objet *objet)
{
	Personne *p = (Personne *)objet; 
	char *Persn = (char *)malloc(sizeof(Personne));
	snprintf(Persn, sizeof(Personne), "%s %s\n", p->nom, p->prenom);
	return Persn;													  
}

//Comparaison de deux personnes
int comparerPersonne(Objet *objet1, Objet *objet2)
{
	Personne *p1 = (Personne *)objet1;
	Personne *p2 = (Personne *)objet2;
	return strcmp(p1->nom, p2->nom);
}
