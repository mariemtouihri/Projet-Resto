struct maillon{
	int val;
	struct maillon *suiv;
};
//typedef struct maillon listEntier;
typedef struct maillon * listEntier;

//*****1-cr�ation d'une liste vide*****
listEntier creer1();

//void creer2(listEntier *l);
//*****2-ajout d'un �l�ment � une liste chain�e*****
listEntier ajout1(listEntier l,int x);
//void ajout2(listEntier *l,int x);

//*****3-recherche d'un �l�ment dans une liste chain�e*****
int recherche1(listEntier l,int x);
//listEntier recherche2(listEntier l,int x);

//*****4-suppression d'un �l�ment d'une liste chain�e*****
listEntier supprimer1(listEntier l,int x);
//void supprimer2(listEntier *l,int x);

//*****5-affichage d'une liste chain�e*****
void afficherList(listEntier l);
