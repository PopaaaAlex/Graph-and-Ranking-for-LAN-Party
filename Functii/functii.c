 #include "../main.h"

void citire(FILE *fisier, Echipa *echipa){
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
void citire_coada(Echipa *echipe, Coada **coada){
    
    for(int i = 0; i < 32; i++)
        enQueue((*coada), &echipe[i]);
}

void meciuri(Coada *queue, Graph **g, Coada *castigatori, Coada *pierzatori, int *nr_echipe){
    Echipa *echipa_1 = NULL,  *echipa_2 = NULL;
    for(int i = 0; i < *nr_echipe ; i += 2){
       
        
        echipa_1 = deQueue(queue);
        echipa_2 = deQueue(queue);
        //printf("%f %f\n", echipa_1->punctaj_e, echipa_2->punctaj_e);
        if(echipa_1->punctaj_e > echipa_2->punctaj_e){
                enQueue(castigatori, echipa_1);
                enQueue(pierzatori, echipa_2);
                (*g)->a[echipa_2->poz][echipa_1->poz] = 1;
            }
            else if(echipa_2->punctaj_e > echipa_1->punctaj_e){
                enQueue(castigatori, echipa_2);
                enQueue(pierzatori, echipa_1);
                (*g)->a[echipa_1->poz][echipa_2->poz] = 1;    
            }
                else if(echipa_1->punctaj_e ==  echipa_2->punctaj_e &&( strcmp(echipa_1->nume_echipa, echipa_2->nume_echipa)) > 0){
                    enQueue(castigatori,echipa_1);
                    enQueue(pierzatori, echipa_2);
                    (*g)->a[echipa_2->poz][echipa_1->poz] = 1;
                }
                    else if(echipa_1->punctaj_e ==  echipa_2->punctaj_e &&( strcmp(echipa_1->nume_echipa, echipa_2->nume_echipa)) < 0){
                        enQueue(castigatori, echipa_2);
                        enQueue(pierzatori, echipa_1);
                        (*g)->a[echipa_1->poz][echipa_2->poz] = 1; 
                    }
    }
}


void final(Coada *coada, char *argv, Graph **g){
    Coada* castigatori = createQueue(), *pierzatori = createQueue();
    FILE *fisier = fopen(argv, "rt");
    int nr_victorii = 1, nr_echipe = 32;
    while( nr_echipe != 1){
        meciuri(coada, g, castigatori, pierzatori, &nr_echipe);
        //functia de calcul puncraj + afisare la final
        
        coada = castigatori;
        nr_echipe /= 2;
        nr_victorii++;
    }
}

void afisare_graph(char *argv, Graph *g){
    FILE *fisier = fopen(argv, "at");
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++)
            fprintf(fisier,"%d ", g->a[i][j]);
    fprintf(fisier, "\n");
    }

    fclose(fisier);
}

void calcul_punctaj(Coada *pierzatori, int nr_victorii,     )