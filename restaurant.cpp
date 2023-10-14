#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float c1=9;
	float c2=6;
	float c3=7;

}ENTREES;

typedef struct{
	float c1=15;
	float c2=18;
	float c3=12;
	float c4=14;

}PLATS;

typedef struct{
	float c1=5.5;
	float c2=4;
	float c3=4.5;

}DESSERTS;
// I'll change it because of the new menu
typedef struct{
     ENTREES e;
     PLATS p;
     DESSERTS d;
}MENU;

typedef struct{
	int num;
	float prix_e=0;
	float prix_p=0;
	float prix_d=0;
	float prix_total=0;
}COMMANDE;

struct CLIENT{
	COMMANDE val;
	struct CLIENT *suiv;
};
typedef struct CLIENT * client;

typedef struct{
	int num;
	int r=0;
	client Client;
}TABLE;

struct RESTAURANT{
	TABLE val;
    struct RESTAURANT *suiv;
};
typedef struct RESTAURANT * restaurant;

restaurant creer_resto()
{
    restaurant resto;
    resto=NULL;
    return resto;
}

client creer_client()
{
    client cl;
    cl=NULL;
    return cl;
}


restaurant ajout_table(restaurant resto,TABLE tab)
{
    restaurant nouv;
    nouv=(restaurant)malloc(sizeof(restaurant));
    nouv->val=tab;
    nouv->suiv=resto;
    resto=nouv;
    return resto;
}

/*client ajout_commande(client cl ,COMMMANDE com)
{
    client nouv;
    nouv=(client)malloc(sizeof(client));
    nouv->val=com;
    nouv->suiv=cl;
    cl=nouv;
    return cl;
}

restaurant rechercher_table(restaurant resto,TABLE tab)
{
    restaurant courant=l;
        while(courant->val!=x&&courant!=NULL)
        courant=courant->suiv;
    return courant;
}

client rechercher_client(client cl,CLIENT cl)
{
    client courant=l;
        while(courant->val!=x&&courant!=NULL)
        courant=courant->suiv;
    return courant;
}

void supprimer_table(restaurant*resto,TABLE tab)
{
    restaurant e,p;
    e=rechercher_table(*l,tab);
    if(e==NULL) printf("rien a supprimer");
    else if (e==resto)
    {
        resto=resto->suiv;
        free(e);
    }else
    {
        p=resto;
        while(p->suiv!=e) p=p->suiv;
        p->suiv=e->suiv;
        free(e);
    }
}

int recherche1(listEntier l,int x)
{
     listEntier courant;
     while(x!=l->val || l->suiv!=NULL)
     {
         if (l->val=x)
     }
}*/


int menu()
{
    int choix = 0;

    while (choix < 1 || choix > 4)
    {
        printf("*************MENU*************\n");
        printf("1 : Nos ENTREES\n");
        printf("2 : Nos PLATS\n");
        printf("3 : Nos DESSERTS\n");
        printf("4 : QUITTER\n");
        printf("Votre choix ? ");
        scanf("%d", &choix);
    }

    return choix;
}

int entrees()
{
    int choix = 0;

    while (choix < 1 || choix > 4)
    {
        printf("*************Nos ENTREES*************\n");
        printf("1 : Salade de chevre chaud   ********* 9DT\n");
        printf("2 : Toasts de foie gras   ********* 6DT\n");
        printf("3 : Magret fume au foin   ********* 7DT\n");
        printf("4 : ANNULER\n");
        printf("Votre choix ? ");
        scanf("%d", &choix);
    }

    return choix;
}

int plats()
{
    int choix = 0;

    while (choix < 1 || choix > 6)
    {
        printf("*************Nos PLATS*************\n");
        printf("1 : Supions basques   ********* 15DT\n");
        printf("2 : Entrecote 300gr   ********* 18DT\n");
        printf("3 : Steak hache 180gr   ********* 12DT\n");
        printf("4 : Aiguillette de poulet, sauce caramel   *** 9DT\n");
        printf("5 : CONFIRMER\n");
        printf("6 : ANNULER\n");
        while (1)
        {
            printf("Votre choix ? ");
            scanf("%d", &choix);
        }

    }

    return choix;
}

int desserts()
{
    int choix = 0;

    while (choix < 1 || choix > 4)
    {
        printf("*************Nos DESSERTS*************\n");
        printf("1 : Cafe Gourmand   ********* 5.5DT\n");
        printf("2 : Glace Maison   ********* 4DT\n");
        printf("3 : Dessert du jour   ********* 4.5DT\n");
        printf("4 : ANNULER\n");
        printf("Votre choix ? ");
        scanf("%d", &choix);
    }

    return choix;
}

void Menu()
{
	MENU choix;
	COMMANDE com;
	switch(menu())
        {
            case 1:switch(entrees())
                    {

                    };break;
            case 2:switch(plats())
                    {
                      case 1:com.prix_p+=choix.p.c1;break;
                      case 2:com.prix_p+=choix.p.c2;break;
                      case 3:com.prix_p+=choix.p.c3;break;
                      case 4:com.prix_p+=choix.p.c4;break;
                      case 5:com.prix_p=choix.p.c1;break;
                      case 6:(com.prix_p=0 && Menu());break;
                    };break;
           case 3:switch(desserts())
                    {

                    };break;
           case 4:return 0 ;break;

           default:printf("Vous n'avez pas entrer un nombre correct. Vous ne mangerez rien du tout !");

        }

}

main()
{
    COMMANDE com;
    int choix=-1;

    printf("Vous etes le bienvenue ! \n\n");
    /*while(c!='F'&&c!='M')
    {
        printf("Entrez F ou M pour indiquer votre genre : ")
        if(c='F')printf("Entrez votre nom madame :")
    }
     while(1)
    {
        printf("*************MENU*************\n");
        printf("-----Nos ENTREES-----\n1.1-Salade de chevre chaud   ********* 9DT\n1.2-Toasts de foie gras   ********* 6DT\n1.3-Magret fume au foin   ********* 7DT\n",
               "-----Nos PLATS-----\n2.1-Supions basques   ********* 15DT\n2.2-Entrecote 300gr   ********* 18DT\n2.3-Steak hache 180gr   ********* 12DT\n2.4-Aiguillette de poulet, sauce caramel   ********* 9DT\n",
               "-----Nos DESSERTS-----\n3.1-Cafe Gourmand   ********* 5.5DT\n3.2-Glace Maison   ********* 4DT\n3.3-Dessert du jour   ********* 4.5DT\n");
        scanf("%d",&choix);
    }*/
       /* switch(menu())
        {
            case 1:switch(entrees())
                    {

                    };break;
            case 2:switch(plats())
                    {
                      case 1:com.prix_p+=choix.p.c1;break;
                      case 2:com.prix_p+=choix.p.c2;break;
                      case 3:com.prix_p+=choix.p.c3;break;
                      case 4:com.prix_p+=choix.p.c4;break;
                      case 5:com.prix_p=choix.p.c1;break;
                      case 6:(com.prix_p=0 && Menu());break;
                    };break;
           case 3:switch(desserts())
                    {

                    };break;
           case 4:return 0 ;break;

           default:printf("Vous n'avez pas entrer un nombre correct. Vous ne mangerez rien du tout !");

        }*/
        Menu();

}
