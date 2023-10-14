#include <stdio.h>
#include <stdlib.h>

struct element {
	int val;
    struct element* nxt;
};
typedef struct element* llist;

llist creer (){
	llist l;
	l=NULL;
	return l;
}
llist ajoutEntete(llist l,int x){
	llist nelement;
	nelement= (llist)malloc(sizeof(llist));
}
