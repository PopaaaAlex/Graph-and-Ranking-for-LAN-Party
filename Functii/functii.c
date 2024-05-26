#include "../main.h"

void citire(FILE *fisier, Echipa *echipa)
{
    char nume[40];
    for(int i = 0; i < 32; i++)
    {
        echipa[i].poz = i;
        fscanf(fisier, "%lf ", &echipa[i].punctaj_e);
        fgets(nume, sizeof(nume), fisier);
        echipa[i].nume_echipa = (char*)calloc(strlen(nume) + 1, sizeof(char));
        strcpy(echipa[i].nume_echipa, nume);
    }
}