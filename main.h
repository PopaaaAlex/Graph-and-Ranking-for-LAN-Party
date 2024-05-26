#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct echipa{
    int poz;
    char *nume_echipa;
    double punctaj_e;
};

typedef struct echipa Echipa;

void citire(FILE *, Echipa *);