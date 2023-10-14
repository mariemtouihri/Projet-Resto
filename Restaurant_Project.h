void creer_resto(restaurant *resto);
void ajout_table(restaurant *resto,TABLE tab)
TABLE ajout_tab(TABLE x);
restaurant rechercher_table(restaurant resto,int x);
COMMANDE ajout_commande(restaurant *resto,COMMANDE com,int num);
int menu();
int entrees();
int plats();
int desserts();
void afficher_facture(COMMANDE com);
COMMANDE ajout_com(COMMANDE com);
int menu_principal();
void afficher_tab(TABLE x);
void afficher_table(restaurant resto,int num);



