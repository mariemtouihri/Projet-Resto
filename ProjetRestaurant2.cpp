#include <stdio.h>

struct maillon{
	int val;
	struct maillon *suiv;
};
typedef struct maillon listEntier;

listEntier creer1()
{
    listEntier l;
    l.suiv=NULL;
    return l;
}
