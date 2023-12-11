#ifndef ARBRE_H
#define ARBRE_H

typedef void Objet;  //une reappelation de void par objet

// la structure d'un noeud
typedef struct noeud
{
	Objet *reference;
	struct noeud *gauche;
	struct noeud *droite;
} Noeud;

//la structure d'un arbre 
typedef struct
{
	Noeud *racine;
	char *(*afficher)(Objet *);
	int (*comparer)(Objet *, Objet *);
} Arbre;

//creation noeud 
Noeud *cNd(Objet *, Noeud *, Noeud *);

//creation feuille
Noeud *cF(Objet *);

//initialisation d'un arbre
void initArbre(Arbre *, Noeud *, char *(*afficher)(Objet *), int (*comparer)(Objet *, Objet *));

Arbre *creerArbre(Noeud *, char *(*afficher)(Objet *), int (*comparer)(Objet *, Objet *));

//parcours préfixé
void prefixe(Noeud *, char *(*afficher)(Objet *));

//parcours infixé
void infixe(Noeud *, char *(*afficher)(Objet *));

//parcours postfixé
void postfixe(Noeud *, char *(*afficher)(Objet *));

//chercher noeud
Noeud *trouverNoeud(Noeud *, Objet *, int (*comparer)(Objet *, Objet *));

//hauteur d'arbre
int hauteur(Noeud *racine);

//la taille de l'arbre
int taille(Noeud *);

//parcours en largeur
void enLargeur(Noeud *, char *(*afficher)(Objet *));

//maximum
int max(int, int);
//affichage des chaines et des entiers
char *afficherChar(Objet *objet);
char *afficherInt(Objet *objet);

#endif
