#include "main.h"

int main(int argc, char* argv[])
{
    FILE *fisier = fopen(argv[1], "rt");
    Echipa *echipa = (Echipa*)calloc(32, sizeof(Echipa));
    Coada *coada = createQueue();

    citire(fisier, echipa);
    citire_coada(echipa, &coada);
    for( int i = 0; i < 32; i++)
    {
        printf("%f ", echipa[i].punctaj_e);
    }

    return 0;
}