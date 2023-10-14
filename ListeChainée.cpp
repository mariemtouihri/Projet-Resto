struct maillon{
	int val;
	struct maillon *suiv;
};
//typedef struct maillon listEntier;
typedef struct maillon * listEntier;

//*****1-création d'une liste vide*****
listEntier creer1();

//void creer2(listEntier *l);
//*****2-ajout d'un élément à une liste chainée*****
listEntier ajout1(listEntier l,int x);
//void ajout2(listEntier *l,int x);

//*****3-recherche d'un élément dans une liste chainée*****
int recherche1(listEntier l,int x);
//listEntier recherche2(listEntier l,int x);

//*****4-suppression d'un élément d'une liste chainée*****
listEntier supprimer1(listEntier l,int x);
//void supprimer2(listEntier *l,int x);

//*****5-affichage d'une liste chainée*****
void afficherList(listEntier l);
