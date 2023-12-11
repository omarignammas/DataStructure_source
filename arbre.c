#include <stdio.h>
#include <stdlib.h>
#include "arbre2.h"
#include "liste2.h"

//creation d'un noeud
Noeud *cNd(Objet *objet, Noeud *gauche, Noeud *droite)
{
	Noeud *nouveau = (Noeud *)malloc(sizeof(Noeud));
	nouveau->reference = objet;
	nouveau->gauche = gauche;
	nouveau->droite = droite;
	return nouveau;
}

//creation d'une feuille
Noeud *cF(Objet *objet)
{
	return cNd(objet, NULL, NULL);
}

//initialisation d'un arbre
void initArbre(Arbre *arbre, Noeud *racine, char *(*afficher)(Objet *), int (*comparer)(Objet *, Objet *))
{
	arbre->racine = racine;
	arbre->afficher = afficher;
	arbre->comparer = comparer;
}

//creation d'un arbre
Arbre *creerArbre(Noeud *racine,
				  char *(*afficher)(Objet *), int (*comparer)(Objet *, Objet *))
{
	Arbre *arbre = (Arbre *)malloc(sizeof(Arbre));
	initArbre(arbre, racine, afficher, comparer);
	return arbre;
}

// parcours en profondeur prefixe de l'arbre
void prefixe(Noeud *racine, char *(*afficher)(Objet *))
{
	if (racine != NULL)
	{
		printf("%s\t", afficher(racine->reference));
		prefixe(racine->gauche, afficher);
		prefixe(racine->droite, afficher);
	}
}

// parcours en profondeur infixe de l'arbre
void infixe(Noeud *racine, char *(*afficher)(Objet *))
{
	if (racine != NULL)
	{
		infixe(racine->gauche, afficher);
		printf("%s\t", afficher(racine->reference));
		infixe(racine->droite, afficher);
	}
}

//parcours en profondeur postfixe de l'arbre
void postfixe(Noeud *racine, char *(*afficher)(Objet *))
{
	if (racine != NULL)
	{
		postfixe(racine->gauche, afficher);
		postfixe(racine->droite, afficher);
		printf("%s\t", afficher(racine->reference));
	}
}

//chercher un noeud
Noeud *trouverNoeud(Noeud *racine, Objet *objet, int (*comparer)(Objet *, Objet *))
{
	Noeud *pNom;
	if (racine == NULL)
	{
		pNom = NULL;
	}
	else if (comparer(racine->reference, objet) == 0)
	{
		pNom = racine;
	}
	else
	{
		pNom = trouverNoeud(racine->gauche, objet, comparer);
		if (pNom == NULL)
			pNom = trouverNoeud(racine->droite , objet, comparer);
	}
	return pNom;
}

// retourner la hauteur de l'arbre
int hauteur(Noeud *racine)
{
	if (racine == NULL)
		return 0;
	else
	{
		return 1 + max(hauteur(racine->gauche), hauteur(racine->droite));
	}
}

//retourner la taille de l'arbre
int taille(Noeud *racine)
{
	if (racine == NULL)
		return 0;
	else
		return 1 + taille(racine->gauche) + taille(racine->droite);
}

// parcours en largeur de l'arbre
void enLargeur(Noeud *racine, char *(*afficher)(Objet *))
{
	Liste *li = creerListe(0, afficher, comparer);
	insererEnTeteDeListe(li, racine);
	while (!listeVide(li))
	{
		Noeud *extrait = (Noeud *)extraireEnTeteDeListe(li);
		printf("%s\t", afficher(extrait->reference));
		if (extrait->gauche != NULL)
			insererEnTeteDeListe(li, extrait->gauche);
		if (extrait->droite != NULL)
			insererEnTeteDeListe(li, extrait->droite);
	}
}

//le maximum 
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//l'affichage des chaines de caracteres
char *afficherChar(Objet *objet)
{
	return (char *)objet;
}
