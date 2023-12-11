#ifndef LISTE_H
#define LISTE_H

//renommer booleen comme un int qui peut prendre la valeur de 0 ou 1
typedef int booleen;

typedef void Objet;

// definit la structure d'un element de la liste
typedef struct element
{
	Objet *reference;
	struct element *suivant;
} Element;

//defini la structure de la Liste
typedef struct
{
	Element *premier; // premier element
	Element *dernier; // dernier
	Element *courant; // en cours
	int nbElt;		  // nombre d'element
	int type;		  // 0 : simple , 1 : croissant , 2 : decroissant
	char *(*afficher)(Objet *);
	int (*comparer)(Objet *, Objet *);
} Liste;

// initialisation de la liste
void initListe(Liste *li, int type, char *(*afficher)(Objet *), int (*comparer)(Objet *, Objet *));

//creation de la liste
Liste *creerListe(int type, char *(*afficher)(Objet *), int (*comparer)(Objet *, Objet *));

//inserersion d'un element en tete de liste
void insererEnTeteDeListe(Liste *li, Objet *objet);


//nombre des elements 
int nbElement(Liste *li);

// ajouter en tete de la liste
static Element *creerElement();

// inserer apres un element
static void insererApres(Liste *li, Element *precedent, Objet *objet);

//ajouter en fin de la liste
void insererEnFinDeliste(Liste *li, Objet *objet);

// positionner en tete de  liste
void ouvrirListe(Liste *li);

// si on atteint la fin de liste
booleen finListe(Liste *li);

//verification si la liste est vide
booleen listeVide(Liste *li);

// pointer sur l'element courant
static Element *elementCourant(Liste *li);

// retrait un element en tete de liste
Objet *extraireEnTeteDeListe(Liste *li);

// retrait un element a partir l'element suivant
static Objet *extraireApres(Liste *li, Element *precedent);

//retrait lelement du fin de liste
Objet *extraireEnFinDeListe(Liste *li);

// retrait a partir de la reference(objet)
booleen exrtaireUnObjet(Liste *li, Objet *objet);

//detruire la liste
void detruireListe(Liste *li);

//fonction de comparaison de deux elements
int comparer(Objet *objet1, Objet *objet2);

//fonction d'affichage de elements
char *afficher(Objet *objet);

#endif
