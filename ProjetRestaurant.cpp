#include <stdio.h>

typedef struct{
	;
	int annee;
}client;

struct table{
	client tbl;
	struct table *suiv;
};
typedef struct table * Resto;

struct Resto{
	table tbl;
	struct Resto *suiv;
};
typedef struct maillon * listEntier;


