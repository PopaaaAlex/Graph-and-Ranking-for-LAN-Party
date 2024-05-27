#include "../main.h"

void citire(FILE *fisier, Echipa *echipa) {
    char nume[40];
    for (int i = 0; i < 32; i++) {
        echipa[i].poz = i;
        fscanf(fisier, "%lf ", &echipa[i].punctaj_e);
        fgets(nume, sizeof(nume), fisier);
        echipa[i].nume_echipa = (char *)calloc(strlen(nume) + 1, sizeof(char));
        strcpy(echipa[i].nume_echipa, nume);
    }
}

void citire_coada(Echipa *echipe, Coada **coada) {

    for (int i = 0; i < 32; i++)
        enQueue((*coada), &echipe[i]);
}

void meciuri(Coada *queue, Graph **g, Coada *castigatori, Coada *pierzatori, int *nr_echipe) {
    Echipa *echipa_1 = NULL, *echipa_2 = NULL;
    for (int i = 0; i < *nr_echipe; i += 2) {

        echipa_1 = deQueue(queue);
        echipa_2 = deQueue(queue);
        if (echipa_1->punctaj_e > echipa_2->punctaj_e) {
            enQueue(castigatori, echipa_1);
            enQueue(pierzatori, echipa_2);
            (*g)->a[echipa_2->poz][echipa_1->poz] = 1;
        }
        else if (echipa_2->punctaj_e > echipa_1->punctaj_e) {
            enQueue(castigatori, echipa_2);
            enQueue(pierzatori, echipa_1);
            (*g)->a[echipa_1->poz][echipa_2->poz] = 1;
        }
        else if (echipa_1->punctaj_e == echipa_2->punctaj_e && (strcmp(echipa_1->nume_echipa, echipa_2->nume_echipa)) > 0) {
            enQueue(castigatori, echipa_1);
            enQueue(pierzatori, echipa_2);
            (*g)->a[echipa_2->poz][echipa_1->poz] = 1;
        }
        else if (echipa_1->punctaj_e == echipa_2->punctaj_e && (strcmp(echipa_1->nume_echipa, echipa_2->nume_echipa)) < 0) {
            enQueue(castigatori, echipa_2);
            enQueue(pierzatori, echipa_1);
            (*g)->a[echipa_1->poz][echipa_2->poz] = 1;
        }
    }
}

void final(Coada *coada, Graph **g, Coada *castigatori, Coada *pierzatori) {
    int nr_victorii = 0, nr_echipe = 32, contor = 0;
    
    while (nr_echipe != 1) {
        meciuri(coada, g, castigatori, pierzatori, &nr_echipe);
        Echipa *aux = pierzatori->fata;
    contor = 0;
    while (aux != NULL && contor < 16) {
        aux->nr_victorii = 0;
        aux = aux->next;
        contor++;
    }
        while(aux != NULL) {   
            if(aux->nr_victorii == 0 && contor >= 16)
                aux->nr_victorii = nr_victorii;   
            contor++;
            aux = aux->next;
        }

        coada = castigatori;
        nr_echipe /= 2;
        nr_victorii++;
    }
    castigatori->fata->nr_victorii = nr_victorii;
    
}

void afisare_graph(char *argv, Graph *g) {
    FILE *fisier = fopen(argv, "wt");
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++)
            fprintf(fisier,"%d ", g->a[i][j]);
        fprintf(fisier,"\n");
    }

    fclose(fisier);
}

float calcul_punctaj(Echipa *echipa) {
    float q = 0.15, Pr, l = 6, r;
    r = (float)echipa->nr_victorii;

    Pr = (q * pow((2 - q), r)) / (pow(2, l)+(pow((2 - q), l) * (q - 1)));
    return Pr;
}

void punctaj_final(Coada* castigatori, Coada* pierzatori) {
    Echipa *aux = pierzatori->fata;
    while(aux != NULL) {
        aux->prestigiu = calcul_punctaj(aux);
        aux = aux->next;
    }
    castigatori->fata->prestigiu = calcul_punctaj(castigatori->fata);
}

void afisare_scor(Coada* castigatori, Coada *pierzatori, char* argv) {
    FILE *fisier = fopen(argv, "wt");
    Coada* aux = pierzatori;
    
    while(aux->fata != NULL) {
        fprintf(fisier, "%.4f %s", aux->fata->prestigiu, aux->fata->nume_echipa);
        aux->fata = aux->fata->next;
    }
    
    fprintf(fisier, "%.4f %s", castigatori->fata->prestigiu, castigatori->fata->nume_echipa);
    fclose(fisier);
}
