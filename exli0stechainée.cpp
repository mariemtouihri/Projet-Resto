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

void creer2(listEntier *l){
	*l=NULL;
}

listEntier ajoutDebut1(listEntier l,int x){
	listEntier p;
	p=(listEntier)malloc(sizeof(listEntier));
	p->val=x;
	p->suiv=l;
	l=p;
	return l;
}

void ajoutDebut2(listEntier *l,int x){
	listEntier p;
	p=(listEntier)malloc(sizeof(listEntier));
	p->val=x;
	p->suiv=*l;
	*l=p;
}

listEntier ajoutFin1(listEntier l,int x){
	listEntier nouv,cour;
	nouv=(listEntier)malloc(sizeof(listEntier));
    nouv->val=x;
	nouv->suiv=NULL;
	if(l==NULL) {

	l=nouv ;
	return l;}
	else {
	  cour=l;
	  while(cour->suiv!=NULL)
         cour=cour->suiv;
	  cour->suiv=nouv;

	              }

	return l;

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
//creer2(&l);
printf("saisir nbre d'elements: ");
scanf("%d",&n);
for(i=0;i<n;i++){
	printf("saisir une valeur: ");
    scanf("%d",&x);
l=ajoutDebut1(l,x);
//ajoutDebut2(&l,x);
l=ajoutFin1(l,x);
}
afficher(l);
}
