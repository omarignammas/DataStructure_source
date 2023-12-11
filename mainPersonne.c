#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define faux 0
#define vrai 1
#include "personne.h"
#include "liste.h"

int menu()
{
	printf("\n\nGESTION D'UNE LISTE DE PERSONNES\n\n");
	printf("0 - Fin\n");
	printf("1 - Insertion en tete de liste\n");
	printf("2 - Insertion en fin de liste\n");
	printf("3 - Retrait en tete de liste\n");
	printf("4 - Retrait en fin de liste\n");
	printf("5 - Retrait d'un element a partir de son nom\n");
	printf("6 - Parcours de la liste\n");
	printf("7 - Recherche d'un element a partir de son nom\n");
	printf("8 - Destruction de la liste\n");
	printf("\n");
	printf("Votre choix ? ");
	int cod;
	scanf("%d", &cod);
	printf("\n");
	return cod;
}

int main()
{
	ch15 nom, prenom;
	Personne *nouveau;
	Personne *extrait;
	Personne *cherche;
	Personne *Pexiste;
	Personne *personne_cherche;
	Liste *lp = creerListe(0, ecrirePersonne, comparerPersonne);
	booleen fini = faux;
	while (!fini)
	{
		switch (menu())
		{
		case 0:
			fini = vrai;
			break;
		case 1:
			printf("\\ENTRER LE NOM ET LE PRENOM DE LA PERSONNE A INSERER EN TETE\n");
			printf("NOM DE LA PERSONNE :");
			scanf("%s", nom);
			printf("PRENOM DE LA PERSONNE :");
			scanf("%s", prenom);
			nouveau = creerPersonne(nom, prenom);
			insererEnTeteDeListe(lp, nouveau);
			break;
		case 2:
			printf("\\ENTRER LE NOM ET LE PRENOM DE LA PERSONNE A INSERER EN FIN \n");
			printf("NOM DE LA PERSONNE :");
			scanf("%s", nom);
			printf("PRENOM DE LA PERSONNE :");
			scanf("%s", prenom);
			nouveau = creerPersonne(nom, prenom);
			insererEnFinDeliste(lp, nouveau);
			break;
		case 3:
			extrait = (Personne *)extraireEnTeteDeListe(lp);
			if (extrait != NULL)
			{
				printf("LA PERSONNE %s %s EXTRAIT EN TETE DE LA LISTE", extrait->nom, extrait->prenom);
			}
			else
			{
				printf("LA LISTE EST VIDE");
			}
			break;
		case 4:
			extrait = (Personne *)extraireEnFinDeListe(lp);
			if (extrait != NULL)
			{
				printf("LA PERSONNE %s %s EXTRAIT EN FIN DE LA  LISTE", extrait->nom, extrait->prenom);
			}
			else
			{
				printf("LA LISTE EST VIDE");
			}
			break;
		case 5:
			printf("NOM DE LA PERSONNE VEULEZ RETIRER? ");
			scanf("%s", nom);
			cherche = creerPersonne(nom, "?");
			Personne*Pexiste = (Personne*)chercherUnObjet(lp, cherche);
			if (extraireUnObjet(lp, Pexiste))
			{
				printf("LA PERSONNE %s %s EXTRAIT DE LA LISTE", Pexiste->nom, Pexiste->prenom);
			}
			break;
		case 6:
			listerListe(lp);

			break;
		case 7:
			printf("ENTRER LE NOM VOUS CHERCHEZ : ");
			scanf("%s", nom);
			cherche = creerPersonne(nom, "?");
		    Pexiste = (Personne *)chercherUnObjet(lp, cherche);
			if (Pexiste != NULL)
			{
				printf("%s  EXISTE DANS LA LISTE", nom);
			}
			else
			{
				printf("%s N'EXISTE PAS", nom);
			}
			break;
		case 8:
			detruireListe(lp);
			break;
		}
	}
	return 0;
}
