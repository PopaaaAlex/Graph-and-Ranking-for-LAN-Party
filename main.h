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

void citire(FILE *, Echipa *);