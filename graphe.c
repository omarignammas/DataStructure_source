#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"
#define faux 0
#define vrai 1
#define INFINI 90000

// creer un graphe--------------------------------------------
GrapheMat *creerGrapheMat(int nMax, int value)
{
	// allocation de graphe
	GrapheMat *graphe = (GrapheMat *)malloc(sizeof(GrapheMat));
	graphe->n = 0;
	graphe->nMax = nMax;
	graphe->value = value;
	graphe->nomS = (NomSom *)malloc(sizeof(NomSom) * nMax);
	graphe->marque = (booleen *)malloc(sizeof(booleen) * nMax);
	graphe->element = (int *)malloc(sizeof(int) * nMax * nMax);
	graphe->valeur = (int *)malloc(sizeof(int) * nMax * nMax);

	// initialisation par defaut
	for (int i = 0; i < nMax; i++)
	{
		for (int j = 0; j < nMax; j++)
		{
			graphe->element[i * nMax + j] = faux;
			graphe->valeur[i * nMax + j] = INFINI;
		}
	}
	for (int i = 0; i < graphe->n; i++)
		graphe->marque[i] = faux;
	return graphe;
}

static void razMarque(GrapheMat *graphe)
{
	for (int i = 0; i < graphe->n; i++)
		graphe->marque[i] = faux;
}

// detruire le graphe-------------------------------------------------
void detruireGraphe(GrapheMat *graphe)
{
	free(graphe->nomS);
	free(graphe->marque);
	free(graphe->element);
	free(graphe->valeur);
	free(graphe);
}

static int rang(GrapheMat *graphe, NomSom nom)
{
	int i = 0;
	booleen trouve = faux;
	while ((i < graphe->n) && !trouve)
	{
		trouve = strcmp(graphe->nomS[i], nom) == 0;
		if (!trouve)
			i++;
	}
	return trouve ? i : -1;
}

// ajouter un sommet-------------------------------------------------
void ajouterUnSommet(GrapheMat *graphe, NomSom nom)
{
	if (rang(graphe, nom) == -1)
	{
		if (graphe->n < graphe->nMax)
		{
			strcpy(graphe->nomS[graphe->n++], nom);
		}
		else
		{
			printf("\nNombre de sommets > %d\n", graphe->nMax);
		}
	}
	else
	{
		printf("\n%s deja defini\n", nom);
	}
}

// ajouter un arc-------------------------------------------------
void ajouterUnArc(GrapheMat *graphe, NomSom somD, NomSom somA, int cout)
{
	int nMax = graphe->nMax;
	int rd = rang(graphe, somD);
	int rg = rang(graphe, somA);
	graphe->element[rd * nMax + rg] = vrai;
	graphe->valeur[rd * nMax + rg] = cout;
}

// afficher le graphe-------------------------------------------------
void ecrireGraphe(GrapheMat *graphe)
{
	int nMax = graphe->nMax;
	for (int i = 0; i < graphe->n; i++)
		printf("%s ", graphe->nomS[i]);
	printf(";\n");

	for (int i = 0; i < graphe->n; i++)
	{
		printf("\n%s : ", graphe->nomS[i]);
		for (int j = 0; j < graphe->n; j++)
		{
			if (graphe->element[i * nMax + j] == vrai)
			{
				printf("%s ", graphe->nomS[j]);
				if (graphe->value)
				{
					printf(" (%d) ", graphe->valeur[i * nMax + j]);
				}
			}
		}
		printf(";");
	}
}

static void profondeur(GrapheMat *graphe, int numSommet)
{
	int nMax = graphe->nMax;
	graphe->marque[numSommet] = vrai;
	printf("%s\n", graphe->nomS[numSommet]);
	for (int i = 0; i < graphe->n; i++)
	{
		if ((graphe->element[numSommet * nMax + i] == vrai) && !graphe->marque[i])
		{
			profondeur(graphe, i);
		}
	}
}

// affichage suivant un parcours en profondeur-------------------------------------------------
void parcoursProfond(GrapheMat *graphe)
{
	for (int i = 0; i < graphe->n; i++)
		graphe->marque[i] = faux;
	for (int i = 0; i < graphe->n; i++)
	{
		if (!graphe->marque[i])
			profondeur(graphe, i);
	}
}
