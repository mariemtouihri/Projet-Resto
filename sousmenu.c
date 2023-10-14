#include <stdio.h>
#include <stdlib.h>

int menu()
{

  int choix = 0;

while (choix < 1 || choix > 4)
{
    printf("Operation :\n\n");
    printf("1. Addition\n");
    printf("2. Soustraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n\n");
    printf("Votre choix ?\n");
    scanf("%d", &choix);
    printf("\n\n");
}
return choix;
}
int main ( int argc, char** argv )
{


int operation;
int resultat = 0, nombre1 = 0, nombre2 = 0;
int Menu = 1;

do
{

switch (operation = menu())

{
case 1:
printf("Addition :\n\n");
printf("Nombre 1 : ");
scanf("%d", &nombre1);
printf("Nombre 2 : ");
scanf("%d", &nombre2);
resultat = nombre1 + nombre2;
printf("%d + %d = %d\n", nombre1, nombre2, resultat);
break;

case 2:
printf("Soustraction :\n\n");
printf("Nombre 1 : ");
scanf("%d", &nombre1);
printf("Nombre 2 : ");
scanf("%d", &nombre2);
resultat = nombre1 - nombre2;
printf("%d - %d = %d\n", nombre1, nombre2, resultat);
break;

case 3:
printf("Multiplication :\n\n");
printf("Nombre 1 : ");
scanf("%d", &nombre1);
printf("Nombre 2 : ");
scanf("%d", &nombre2);
resultat = nombre1 * nombre2;
printf("%d * %d = %d\n", nombre1, nombre2, resultat);
break;

case 4:
printf("Division :\n\n");
printf("Nombre 1 : ");
scanf("%d", &nombre1);
printf("Nombre 2 : ");
scanf("%d", &nombre2);
resultat = nombre1 / nombre2;
printf("%d / %d = %d\n", nombre1, nombre2, resultat);
break;

default:
printf("Vous n'avez pas rentre un nombre correct.");
break;
}

printf("\n\n");


system("PAUSE");
printf("Revenir au menu?\n");
printf("1-Oui\n");
printf("2-Non\n");
scanf("%d",&Menu);

}while(Menu != 2);

return 0;
}
