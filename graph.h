
#include "main.h"


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


Echipa *deQueue(Coada *q);
void enQueue ( Coada *q, Echipa v);
Coada* createQueue();