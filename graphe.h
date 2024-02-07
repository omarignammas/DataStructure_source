#ifndef GRAPHE_H
#define GRAPHE_H
/* graphemat.h */
#include <stdio.h>
#define faux 0
#define vrai 1
#define INFINI 90000
// Declaration des structures -----------------------------------------
typedef int booleen;
typedef char NomSom[20]; // nom d'un sommet
typedef int *Matrice;

typedef struct
{
    int n;           // nombre de sommets
    int nMax;        // nombre max de sommets
    booleen value;   // graphe value ou non
    NomSom *nomS;    // noms des sommets
    Matrice element; // existence d'un arc (i, j)
    Matrice valeur;  // cout de l'arc (i, j)
    booleen *marque; // sommet marque (visite) ou non
} GrapheMat;
// Declaration des fonctions ----------------------------------------------

//        creer un graphe
GrapheMat *creerGrapheMat(int nMax, int value);

//        detruire le graphe
void detruireGraphe(GrapheMat *graphe);

//        ajouter un sommet
void ajouterUnSommet(GrapheMat *graphe, NomSom nom);

//        ajouter un arc
void ajouterUnArc(GrapheMat *graphe, NomSom somD, NomSom somA, int cout);

//        afficher le graphe
void ecrireGraphe(GrapheMat *graphe);

//        affichage suivant un parcours en profondeur
void parcoursProfond(GrapheMat *graphe);
#endif
