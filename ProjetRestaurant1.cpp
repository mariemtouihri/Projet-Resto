#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	float c1=9;
	char *d_c1= "Salade de chevre chaud   ********* 9DT\n";
	float c2=6;
	char *d_c2= "Toasts de foie gras   ********* 6DT\n";
	float c3=7;
	char *d_c3= "Magret fume au foin   ********* 7DT\n";

}ENTREES;

typedef struct{
	float c1=15;
	char *d_c1= "Supions basques   ********* 15DT\n";
	float c2=18;
	char *d_c2= "Entrecote 300gr   ********* 18DT\n";
	float c3=12;
	char *d_c3= "Steak haché 180gr   ********* 12DT\n";
	float c4=14;
	char *d_c4= "Aiguillette de poulet, sauce caramel   *** 9DT\n";

}PLATS;

typedef struct{
	float c1=5.5;
	char *d_c1= "Café Gourmand   ********* 5.5DT\n";
	float c2=4;
	char *d_c2= "Glace Maison   ********* 4DT\n";
	float c3=4.5;
	char *d_c3= "Dessert du jour   ********* 4.5DT\n";

}DESSERTS;

typedef struct{
     ENTREES e;
     PLATS p;
     DESSERTS d;
}MENU;

typedef struct{
	int num;
	char * det_fact_e;
	char * det_fact_p;
	char * det_fact_d;
	float facture_e=0;
	float facture_p=0;
	float facture_d=0;
}COMMANDE;

struct CLIENT{
	COMMANDE val;
	struct CLIENT *suiv;
};
typedef struct CLIENT * client;

typedef struct{
	int num;
	int nbc;
	float facture_totale;
	client Client;
}TABLE;

struct RESTAURANT{
	TABLE val;
    struct RESTAURANT *suiv;
};
typedef struct RESTAURANT * restaurant;

void creer_resto(restaurant *resto)
{
    resto=NULL;
}

void ajout_table(restaurant *resto,TABLE tab)
{
    restaurant nouv;
    nouv=(restaurant)malloc(sizeof(restaurant));
    nouv->val=tab;
    nouv->suiv=*resto;
    *resto=nouv;
}

TABLE ajout_tab(TABLE x)
{
    int nbc,num;
    printf("Vous allez ajouter une nouvelle table ^_^ :\n");
    printf("Entez un numéro : ");
    scanf("%d",&x.num);
    printf("Entrez le nombre de client maximum: ");
    scanf("%d",&x.nbc);
    return x;
}


restaurant rechercher_table(restaurant resto,int x)
{
    restaurant courant=resto ;
        while(courant->val.num!=x && courant!=NULL)
        courant=courant->suiv;
    return courant;
}

void creer_client(restaurant *resto,int num)
{
    rechercher_table(*resto,num)->val.Client=NULL;
}


COMMANDE ajout_commande(restaurant *resto,COMMANDE com,int num)
{
    client nouv;
    nouv=(client)malloc(sizeof(client));
    nouv->val=com;
    nouv->suiv=(rechercher_table(*resto,num))->val.Client;
    (rechercher_table(*resto,num))->val.Client=nouv;
    return (rechercher_table(*resto,num))->val.Client->val;
}


/*void ajout_commande(restaurant *resto,int num)
{
    client nouv;
    nouv=(client)malloc(sizeof(client));
    nouv->suiv=(rechercher_table(*resto,num))->val.Client;
    (rechercher_table(*resto,num))->val.Client=nouv;
}

restaurant creer_resto()
{
    restaurant resto;
    resto=NULL;
    return resto;
}

client creer_client(restaurant resto)
{
    resto->val.Client=NULL;
    return resto->val.Client;
}

void ajout_tab(TABLE tab)
{
    printf("Vous allez ajouter une nouvelle table ^_^ :\n");
    printf("Entez un numéro : ");
    scanf("%d",&tab.num);
    printf("Entrez le nombre de client maximum: ");
    scanf("%d",&tab.nbc);
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

client ajout_commande(restaurant resto)
{
    client nouv;
    nouv=(client)malloc(sizeof(client));
    nouv->val=resto->val.Client->val;
    nouv->suiv=resto->val.Client;
    resto->val.Client=nouv;
    return resto->val.Client;
}

restaurant rechercher_table(restaurant resto,int x)
{
    restaurant courant=resto ;
        while(courant->val.num!=x && courant!=NULL)
        courant=courant->suiv;
    return courant;
}*/

client rechercher_commande(client cl,int x)
{
    client courant=cl;
        while(courant->val.num!=x && courant!=NULL)
        courant=courant->suiv;
    return courant;
}

void afficher_facture(COMMANDE com)
{
    float fact_total;
    printf("Vous avez demandé :\n");
    printf(com.det_fact_e,com.det_fact_p,com.det_fact_d);
    printf("\nLe prix total :\n");
    fact_total=com.facture_e + com.facture_p + com.facture_d;
    printf("",fact_total);
}


void supprimer_commande_e(restaurant resto,int x)
{
    restaurant ts,p;
    ts=rechercher_table(resto,x);
    if(ts==NULL) printf("rien à supprimer");
    else if (ts==resto)
    {
        resto=resto->suiv;
        free(ts);
    }else
    {
        p=resto;
        while(p->suiv!=ts) p=p->suiv;
        p->suiv=ts->suiv;
        free(ts);
    }
}

/*int recherche1(listEntier l,int x)
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
        printf("4 : CONFIRMER\n");
        printf("5 : QUITTER\n");
        printf("Votre choix ? ");
        scanf("%d", &choix);
        if(choix < 1 || choix > 4) printf("Vous n'avez pas entrer un nombre correct. Vous ne mangerez rien du tout !");
    }

    return choix;
}

int entrees()
{
    int choix ;



        printf("*************Nos ENTREES*************\n");
        printf("1 : Salade de chevre chaud   ********* 9DT\n");
        printf("2 : Toasts de foie gras   ********* 6DT\n");
        printf("3 : Magret fume au foin   ********* 7DT\n");
        printf("4 : CONFIRMER\n");
        printf("5 : ANNULER\n");
        do
          {
            printf("Votre choix ? ");
            scanf("%d", &choix);
            if(choix < 1 || choix > 5) printf("Choix invalide !\n");

          } while(choix!=4 && choix!=5);

    return choix;
}

int plats()
{
    int choix ;

        printf("*************Nos PLATS*************\n");
        printf("1 : Supions basques   ********* 15DT\n");
        printf("2 : Entrecote 300gr   ********* 18DT\n");
        printf("3 : Steak haché 180gr   ********* 12DT\n");
        printf("4 : Aiguillette de poulet, sauce caramel   *** 9DT\n");
        printf("5 : CONFIRMER\n");
        printf("6 : ANNULER\n");


            do
          {
            printf("Votre choix ? ");
            scanf("%d", &choix);
            if(choix < 1 || choix > 6) printf("Choix invalide !\n");

          } while(choix!=5 && choix!=6);





    return choix;
}

int desserts()
{
    int choix ;

        printf("*************Nos DESSERTS*************\n");
        printf("1 : Café Gourmand   ********* 5.5DT\n");
        printf("2 : Glace Maison   ********* 4DT\n");
        printf("3 : Dessert du jour   ********* 4.5DT\n");
        printf("4 : CONFIRMER\n");
        printf("5 : ANNULER\n");
       do
          {
            printf("Votre choix ? ");
            scanf("%d", &choix);
            if(choix < 1 || choix > 5) printf("Choix invalide !\n");

          } while(choix!=4 && choix!=5);

    return choix;
}

main()
{
    /*restaurant resto;
    client cl;
    int Menu=0;
    MENU m;

    printf("Vous êtes le bienvenue ! \n\n");
    resto=creer_resto();
    ajout_tab(resto->val);
    resto=ajout_table(resto,resto->val);
    cl=creer_client(resto);*/

    int Menu=0;
    MENU m;
    restaurant resto;
    int n;
    printf("Vous êtes le bienvenue ! \n\n");
    creer_resto(&resto);
    ajout_table(&resto,ajout_tab(resto->val));
    printf("Donnez le num de table : ");
    scanf("%d",&n);
    //x=rechercher_table(resto,m);
    creer_client(&resto,n);
//    ajout_commande(&resto,m);


    do{
        switch(menu())
        {
            case 1:switch(entrees())
                {
                     case 1:resto->val.Client->val.facture_e=+m.d.c1;resto->val.Client->val.det_fact_e=m.d.d_c1 ;break;
                     case 2:resto->val.Client->val.facture_e=+m.d.c2;resto->val.Client->val.det_fact_e=m.d.d_c2 ;break;
                     case 3:resto->val.Client->val.facture_e=+m.d.c3;resto->val.Client->val.det_fact_e=m.d.d_c3 ;break;
                     case 4:printf("Bon appétit :)\n") ;break;
                     case 5:resto->val.Client->val.facture_e=0;resto->val.Client->val.det_fact_e="" ;
                };break;
            case 2:switch(plats())
                 {
                     case 1:resto->val.Client->val.facture_p=+m.p.c1;resto->val.Client->val.det_fact_p=m.p.d_c1 ;break;
                     case 2:resto->val.Client->val.facture_p=+m.p.c2;resto->val.Client->val.det_fact_p=m.p.d_c2 ;break;
                     case 3:resto->val.Client->val.facture_p=+m.p.c3;resto->val.Client->val.det_fact_p=m.p.d_c3 ;break;
                     case 4:resto->val.Client->val.facture_p=+m.p.c4;resto->val.Client->val.det_fact_p=m.p.d_c4 ;break;
                     case 5:printf("Bon appétit :)\n") ;break;
                     case 6:resto->val.Client->val.facture_p=0;resto->val.Client->val.det_fact_p="" ;

                };break;

           case 3:switch(desserts())
                {
                     case 1:resto->val.Client->val.facture_d=+m.d.c1;resto->val.Client->val.det_fact_d=m.d.d_c1 ;break;
                     case 2:resto->val.Client->val.facture_d=+m.d.c2;resto->val.Client->val.det_fact_d=m.d.d_c2 ;break;
                     case 3:resto->val.Client->val.facture_d=+m.d.c3;resto->val.Client->val.det_fact_d=m.d.d_c3 ;break;
                     case 4:printf("Bon appétit :)\n") ;break;
                     case 5:resto->val.Client->val.facture_d=0;resto->val.Client->val.det_fact_d="" ;

                };break;

          // case 4:printf("\nC'est un bon choix :*\nMerci pour votre visite :) \n");afficher_facture(resto,resto->val.Client->val) ;break;

           case 5:printf("\nMerci pour votre visite :) \n");return 0 ;

        }

           printf("\nRevenir au menu?\n");
           printf("1-Oui\n");
           printf("2-Non\n");
           scanf("%d",&Menu);
           printf("\n");

     }while(Menu != 2);

}
