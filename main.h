#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


struct echipa{
    int poz;
    char *nume_echipa;
    double punctaj_e;
    struct echipa *next;
};
typedef struct echipa Echipa;

struct Graph
{
    int **a;
};
typedef struct Graph Graph;


struct Coada
{
    Echipa *fata, *spate;
};
typedef struct Coada Coada;

void citire(FILE *, Echipa *);
Echipa *deQueue(Coada *q);
void enQueue (Coada *q, Echipa *v);
Coada* createQueue();
int isEmpty(Coada *);
void citire_coada(Echipa *, Coada **);
Graph* alocare();
void meciuri(Coada *, Graph **,Coada *, Coada *, int *);
void final(Coada *, char *, Graph**);
void enQueue_q(Coada *, Coada *);
void afisare_graph(char *, Graph *);