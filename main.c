#include <stdio.h>
#include <stdlib.h>
#include "arbre2.h"
#include "liste2.h"

int menu()
{
	printf("\n\n GESTION D'ARBRES \n\n");
	printf("\n\n ARBRES BINAIRES \n\n");
	printf(" 0 - Fin du programme\n");
	printf("\n");
	printf(" 1 - Creation de l'arbre genealogique\n");
	printf(" 2 - Creation de l'arbre de l'expression arithmetique\n");
	printf("\n");
	printf(" 3 - Parcours prefixe\n");
	printf(" 4 - Parcours infixe\n");
	printf(" 5 - Parcours postfixe\n");
	printf(" 6 - Trouver Noeud \n");
	printf(" 7 - Taille \n");
	printf(" 8 - Hauteur \n");
	printf(" 9 - Parcours en Largeur \n");
	printf("\n");
	printf("Votre choix ? ");
	int cod;
	scanf("%d", &cod);
	getchar();
	printf("\n");
	return cod;
}

int main()
{
	Arbre *A2;
	Arbre *A1;
	int stop = 1;
	Noeud *racinegen = cNd((char *)"omar",
	cNd((char *)"simo", 
	cNd((char *)"jalil",
	NULL, 
	cNd((char *)"hmouda", NULL, 
	cF((char *)"manal"))),
	cNd((char *)"Sarah",
	cF((char *)"anas"),
	NULL)), 
	NULL);
	Noeud *racinearth = cNd((char *)"-", cNd((char *)"", cNd((char *)"+", cF((char *)"a"), cF((char *)"b")), cNd((char *)"-", cF((char *)"c"), cF((char *)"d"))), cF((char *)"e"));
	while (stop)
	{
		int cod = menu();
		switch (cod)
		{
		case 0:
			stop = 0;
			break;
		case 1:

			A1 = creerArbre(racinegen, afficherChar, comparer);
			break;
		case 2:

			A2 = creerArbre(racinearth, afficherChar, comparer);
			break;
		case 3:
			printf(" parcour prefixe d'arbre genealogique : ");
			prefixe(racinegen, afficherChar);
			printf("\nparcour prefixe d'arbre arithmetique : ");
			prefixe(racinearth, afficherChar);
			break;
		case 4:
			printf(" parcour infixe d'arbre genealogique :");
			infixe(racinegen, afficherChar);
			printf("\n parcour infixe d'arbre arithmetique : ");
			infixe(racinearth, afficherChar);
			break;
		case 5:
			printf(" parcour postfixe d'arbre genealogique : ");
			postfixe(racinegen, afficherChar);
			printf("\n parcour postfixe d'arbre arithmetique : ");
			postfixe(racinearth, afficherChar);
			break;
		case 6:
		{
			printf("entrer le Noeud chercher dans l'arbre genealogique:");
			char trouve[20];
			scanf("%s", trouve);
			if (trouverNoeud(racinegen, trouve, comparer) != NULL)
			{
				printf("Le Noeud %s existe", afficher(trouverNoeud(racinegen, trouve, comparer)->reference));
			}
			else
			{
				printf("Le Noeud n'existe pas'");
			}
			printf("\nentrer le Noeud chercher dans l'arbre arithmetique:");
			char trouve1[20];
			scanf("%s", trouve1);

			if (trouverNoeud(racinearth, trouve1, comparer) != NULL)
			{
				printf("Le Noeud %s existe.", afficher(trouverNoeud(racinearth, trouve1, comparer)->reference));
			}
			else
			{
				printf("Le Noeud est introuvable.");
			}
			break;
		}
		case 7:
			printf(" la Taille Arbre genealogique : ");
			printf("%d", taille(racinegen));
			printf("\nla Taille Arbre arithmetique : ");
			printf("%d", taille(racinearth));
			break;
		case 8:
			printf("Hauteur Arbre genealogique : ");
			printf("%d", hauteur(racinegen));
			printf("\nHauteur Arbre arithmetique : ");
			printf("%d", hauteur(racinearth));
			break;
		case 9:
			printf("parcour en largeur d'arbre genealogique : ");
			enLargeur(racinegen, afficherChar);
			printf("\nparcour en largeur d'arbre arithmetique : ");
			enLargeur(racinearth, afficherChar);
			break;
		}
	}
	return 0;
}
