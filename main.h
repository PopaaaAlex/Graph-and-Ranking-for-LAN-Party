#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>


struct echipa{
    int poz;
    char *nume_echipa;
    double punctaj_e;
    int nr_victorii;
    float prestigiu;
    struct echipa *next;
};
typedef struct echipa Echipa;

struct Graph
{
    Echipa *varf;
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
void final(Coada *, Graph**, Coada*, Coada*);
void enQueue_q(Coada *, Coada *);
void afisare_graph(char *, Graph *);
void punctaj_final(Coada* castigatori, Coada* pierzatori);
float calcul_punctaj(Echipa *);