#include <stdio.h>
#include <stdlib.h>

struct maillon{
	int val;
	struct maillon *suiv;
};
typedef struct maillon * listEntier;

listEntier creer1(){
	listEntier l;
	l=NULL;
	return l;
}

listEntier ajouterEnFin(listEntier liste, int valeur)
{
	listEntier 
    nouvelElement =(listEntier)malloc(sizeof(listEntier));
    nouvelElement->val = valeur;
    nouvelElement->suiv = NULL;
 
    if(liste == NULL)
    {
        /* Si la liste est vide� il suffit de renvoyer l'�l�ment cr�� */
        return nouvelElement;
    }
    else
    {
        /* Sinon, on parcourt la liste � l'aide d'un pointeur temporaire et on
        indique que le dernier �l�ment de la liste est reli� au nouvel �l�ment */
        listEntier temp=liste;
        while(temp->suiv != NULL)
        {
            temp = temp->suiv;
        }
        temp->suiv = nouvelElement;
        return liste;
    }   
}


void afficher(listEntier l){
	listEntier courant;
	courant=l;
	while(courant!=NULL){
		printf("%d  ",courant->val);
		courant=courant->suiv;	}
}

main(){
listEntier l;int i,n,y,x;
l=creer1();
printf("saisir nbre d'elements: ");
scanf("%d",&n);
for(i=0;i<n;i++){
	printf("saisir une valeur: ");
    scanf("%d",&x);
l= ajouterEnFin(l,x);
}
afficher(l);
}
