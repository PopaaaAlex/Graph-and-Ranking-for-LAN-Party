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

void meciuri(Coada *queue){
    Coada *castigatori = createQueue(), *pierzatori = createQueue();
    for(int i = 0; i < 32; i += 2){
        Echipa *echipa_1 = NULL,  *echipa_2 = NULL;
        
        echipa_1 = deQueue(queue);
        echipa_2 = deQueue(queue);

        if(echipa_1->punctaj_e > echipa_2->punctaj_e){
                enQueue(castigatori, echipa_1);
                enQueue(pierzatori, echipa_2);
            }
            else if(echipa_2->punctaj_e > echipa_1->punctaj_e){
                enQueue(castigatori, echipa_2);
                enQueue(pierzatori, echipa_1);    
            }
            else if(echipa_1->punctaj_e ==  echipa_2->punctaj_e &&( strcmp(echipa_1->nume_echipa, echipa_2->nume_echipa)) < 0){
                enQueue(castigatori,echipa_1);
                enQueue(pierzatori, echipa_2);
            }
            else if(echipa_1->punctaj_e ==  echipa_2->punctaj_e &&( strcmp(echipa_1->nume_echipa, echipa_2->nume_echipa)) > 0){
                 enQueue(castigatori, echipa_2);
                enQueue(pierzatori, echipa_1); 
            }
    }
}