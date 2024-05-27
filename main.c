#include "main.h"

int main(int argc, char* argv[])
{
    FILE *fisier = fopen(argv[1], "rt");
    Echipa *echipa = (Echipa*)calloc(32, sizeof(Echipa));
    Coada *coada = createQueue(); //*pierzatori = createQueue(), *castigatori = createQueue();
    Graph *graph = alocare();
    

    citire(fisier, echipa);
    citire_coada(echipa, &coada);
    final(coada, argv[2], &graph);
    afisare_graph(argv[2], graph);

    return 0;
}