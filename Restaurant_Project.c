#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Restaurant_Project.h"

struct ENTREES{
	double c1;
	char *d_c1;
	double c2;
	char *d_c2;
	double c3;
	char *d_c3;
};
struct ENTREES e ={9,"Salade de chevre chaud   ********* 9DT\n",6,"Toasts de foie gras   ********* 6DT\n",7,"Magret fume au foin   ********* 7DT\n"};
typedef struct ENTREES ENTREES;

struct PLATS{
	double c1;
	char *d_c1;
	double c2;
	char *d_c2;
	float c3;
	char *d_c3;
	double c4;
	char *d_c4;
};
struct PLATS p ={15,"Supions basques   ********* 15DT\n",18,"Entrecote 300gr   ********* 18DT\n",12,"Steak haché 180gr   ********* 12DT\n",14,"Aiguillette de poulet, sauce caramel   *** 9DT\n"};
typedef struct PLATS PLATS;

typedef struct{
	double c1;
	char *d_c1;
	double c2;
	char *d_c2;
	double c3;
	char *d_c3;

}DESSERTS;
DESSERTS d ={5.5,"Café Gourmand   ********* 5.5DT\n",4,"Glace Maison   ********* 4DT\n",4.5,"Dessert du jour   ********* 4.5DT\n"};


typedef struct{
     ENTREES e;
     PLATS p;
     DESSERTS d;
}MENU;

struct COMMANDE{
	float facture_e;
	float facture_p;
	float facture_d;
	float fact_total;
	int num;
	char  *det_fact_e;
	char  *det_fact_p;
	char  *det_fact_d;
};
typedef struct COMMANDE COMMANDE;

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


void creer_resto(restaurant resto)
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


/*void creer_client(restaurant *resto,int num)
{
    rechercher_table(*resto,num)->val.Client=NULL;
}*/


TABLE ajout_tab(TABLE x)
{
    printf("Vous allez ajouter une nouvelle table ^_^ :\n");
    printf("Entez un numéro : ");
    scanf("%d",&x.num);
    printf("Entrez le nombre de client maximum: ");
    scanf("%d",&x.nbc);
    x.Client=NULL;
    return x;
}


restaurant rechercher_table(restaurant resto,int x)
{
    restaurant courant=resto ;
        while(courant->val.num!=x && courant!=NULL)
        courant=courant->suiv;
    return courant;
}


void ajout_commande(restaurant *resto,COMMANDE com,int num)
{
    client nouv;
    nouv=(client)malloc(sizeof(client));
    nouv->val=com;
    nouv->suiv=(rechercher_table(*resto,num))->val.Client;
    (rechercher_table(*resto,num))->val.Client=nouv;
    (rechercher_table(*resto,num))->val.Client->val;
}

int menu()
{
    int choix = 0;

    while (choix < 1 || choix > 5)
    {
        printf("\n*************MENU*************\n\n");
        printf("1 : Nos ENTREES\n");
        printf("2 : Nos PLATS\n");
        printf("3 : Nos DESSERTS\n");
        printf("4 : CONFIRMER\n");
        printf("5 : QUITTER\n");
        printf("\nVotre choix ? ");
        scanf("%d", &choix);
        if(choix < 1 || choix > 5) printf("Vous n'avez pas entrer un nombre correct.Vous ne mangerez rien du tout !\n");
    }

    return choix;
}

int entrees()
{
    int choix ;



        printf("\n*************Nos ENTREES*************\n\n");
        printf("1 : Salade de chevre chaud   ********* 9DT\n");
        printf("2 : Toasts de foie gras   ********* 6DT\n");
        printf("3 : Magret fume au foin   ********* 7DT\n");
        printf("4 : CONFIRMER\n");
        printf("5 : ANNULER\n");
        //do
         // {
            printf("\nVotre choix ? ");
            scanf("%d", &choix);
            if(choix < 1 || choix > 5) printf("Choix invalide !\n");

          //} while(choix!=4 && choix!=5);

    return choix;
}

int plats()
{
    int choix ;

        printf("\n*************Nos PLATS*************\n\n");
        printf("1 : Supions basques   ********* 15DT\n");
        printf("2 : Entrecote 300gr   ********* 18DT\n");
        printf("3 : Steak haché 180gr   ********* 12DT\n");
        printf("4 : Aiguillette de poulet, sauce caramel   *** 9DT\n");
        printf("5 : CONFIRMER\n");
        printf("6 : ANNULER\n");


          //  do
         // {
            printf("\nVotre choix ? ");
            scanf("%d", &choix);
            if(choix < 1 || choix > 6) printf("Choix invalide !\n");

         // } while(choix!=5 && choix!=6);


    return choix;
}

int desserts()
{
    int choix ;

        printf("\n*************Nos DESSERTS*************\n\n");
        printf("1 : Café Gourmand   ********* 5.5DT\n");
        printf("2 : Glace Maison   ********* 4DT\n");
        printf("3 : Dessert du jour   ********* 4.5DT\n");
        printf("4 : CONFIRMER\n");
        printf("5 : ANNULER\n");
      // do
      //    {
            printf("\nVotre choix ? ");
            scanf("%d", &choix);
            if(choix < 1 || choix > 5) printf("Choix invalide !\n");

       //   } while(choix!=4 && choix!=5);

    return choix;
}

void afficher_facture(COMMANDE com)
{
    printf("Vous avez demandé :\n");
    printf("%s%s%s",com.det_fact_e,com.det_fact_p,com.det_fact_d);
    printf("\nLe prix total :\n");
    com.fact_total=com.facture_e + com.facture_p + com.facture_d;
    printf("%2.2f\n",com.fact_total);
}

COMMANDE ajout_com(COMMANDE com)
{
    int Menu=0,off=0;
    MENU m;
    COMMANDE c;
    com.det_fact_e=(char*)malloc(sizeof(char)*100);
    com.det_fact_p=(char*)malloc(sizeof(char)*100);
    com.det_fact_d=(char*)malloc(sizeof(char)*100);
    com.facture_e=0;
    com.facture_p=0;
    com.facture_d=0;
    int i=1;


    do{
        switch(menu())
        {
            case 1:switch(entrees())
                   { case 1:  com.facture_e = +e.c1 ;   com.det_fact_e = e.d_c1 ;break;
				     case 2:  com.facture_e = +e.c2 ;   com.det_fact_e = e.d_c2 ;break;
                     case 3:  com.facture_e = +e.c3 ;   com.det_fact_e = e.d_c3 ;break;
					 case 4:  printf ("\nbon appétit :) \n") ; break ;
					 case 5:  com.facture_e =0 ;  com.det_fact_e ="" ;

                    };break;
            case 2:switch(plats())
                 {   case 1:  com.facture_p = +p.c1 ;    com.det_fact_p = p.d_c1 ;break;
				     case 2:  com.facture_p = +m.p.c2 ;  com.det_fact_p = p.d_c2 ;break;
                     case 3:  com.facture_p = +p.c3 ;    com.det_fact_p = p.d_c3 ;break;
					 case 4:  com.facture_p = +p.c4 ;    com.det_fact_p = p.d_c4 ;break;
					 case 5:  printf ("bon appétit :) \n") ; break ;
					 case 6:  com.facture_p =0 ;  com.det_fact_p = "" ;

                    };break;

           case 3:switch(desserts())
                    {case 1:  com.facture_d = +d.c1 ;  com.det_fact_d = d.d_c1 ;break;
				     case 2:  com.facture_d = +d.c2 ;  com.det_fact_d = d.d_c2 ;break;
                     case 3:  com.facture_d = +d.c3 ;  com.det_fact_d = d.d_c3 ;break;
					 case 4:  printf ("bon appétit :) \n") ; break ;
					 case 5:  com.facture_d =0 ;  com.det_fact_d = "" ;

                    };break;

           case 4:printf("\nBon appétit :* \nCOMMANDE num= %d\n",i++);
                  afficher_facture(com);


           case 5:printf("\nMerci pour votre visite :)\n");




        }

            printf("\nRevenir au menu?\n");
            printf("1-Oui\n");
            printf("2-Non\n");
            scanf("%d",&Menu);
            printf("\n");

     }while(Menu != 2);
     return com;
}

/*void ajout_client(restaurant *resto,COMMANDE com)
{
    client nouv;
    nouv=(client)malloc(sizeof(client));
    nouv->val=com;
    nouv->suiv=(*resto)->val.Client;
    (*resto)->val.Client=nouv;
}*/


int menu_principal()
{
    int choix = 0;

    while (choix < 1 || choix > 5)
    {
        printf("\n==========MENU PRINCIPAL==========\n\n");
        printf("1 : AJOUTER UNE TABLE\n");
        printf("2 : AJOUTER UNE COMMANDE\n");
        printf("3 : SUPPRIMER UNE TABLE\n");
        printf("4 : SUPPRIMER UNE COMMANDE\n");
        printf("5 : QUITTER\n");
        printf("\nVotre choix ? ");
        scanf("%d", &choix);
        if(choix < 1 || choix > 5) printf("Vous n'avez pas entrer un nombre correct !\n");
    }

    return choix;
}

void afficher_tab(TABLE x)
{
    printf("les informations sur cette table ^_^ :\n");
    printf("son numéro : %d\n",x.num);
    printf("le nombre de client maximum: %d\n",x.nbc);
}

void afficher_table(restaurant resto,int num)
{
    restaurant courant;
    courant=resto;
   // while(courant!=NULL)
    {
        afficher_tab(rechercher_table(courant,num)->val);
        courant=courant->suiv;
    }
}


int main()
{
    restaurant resto,x;
    COMMANDE com;
    int m=1;
    int m_p=0;
    creer_resto(&resto);


    //for(int i=0;i<2;i++)

    /*ajout_table(&resto,ajout_tab(resto->val));


    afficher_table(resto,m);

    //ajout_commande(&resto,ajout_com(com),m);

    x=rechercher_table(resto,m);
    creer_client(&resto,m);
    ajout_client(&x,com);
    resto==NULL;*/

   do
   {
       switch(menu_principal())
       {
           case 1:ajout_table(&resto,ajout_tab(resto->val));break;
           case 2:printf("Donnez le num de table : ");scanf("%d",&m);ajout_commande(&resto,ajout_com(com),m);  break;
           case 3:afficher_table(resto,m); break;
          // case 4:
           case 5:printf("\nGOOD BYE\n"); return 0;
       }

        printf("\nRevenir au menu principal?\n");
            printf("1-Oui\n");
            printf("2-Non\n");
            scanf("%d",&m_p);
            printf("\n");
   }while(m_p!=2);

}
