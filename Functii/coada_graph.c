#include "../main.h"

Coada* createQueue(){
    Coada *q;
    q = (Coada*)calloc(1, sizeof(Coada));
    if(q == NULL) return NULL;
    q->fata = q->spate = NULL;
    return q;
}

void enQueue ( Coada *q, Echipa *v){
    Echipa * newNode =(Echipa*)malloc(sizeof(Echipa));
    
    newNode->nume_echipa = (char*)calloc(strlen(v->nume_echipa) + 1, sizeof(char));
    strcpy(newNode->nume_echipa, v->nume_echipa);
    
    newNode->punctaj_e = v->punctaj_e;
    newNode->poz = v->poz;
    newNode->next = NULL ;

    if (q->spate == NULL ) q->spate = newNode ;
        else {
            (q->spate )->next = newNode ;
            (q->spate )= newNode ;
        }
    if (q->fata == NULL ) q->fata = q->spate;
}

Echipa *deQueue(Coada *q){
    Echipa  *aux ; Echipa d;
    if ( isEmpty (q)) return NULL;
    
    aux = q->fata ;
    q->fata = (q->fata) ->next;

    return aux;
}

int isEmpty(Coada *queue){
	return (queue->fata) == NULL;
}

Graph* alocare(){
    Graph *g = (Graph*)calloc(1,sizeof(Graph));
    
    g->a = (int**)calloc(32,sizeof(int*));
    
    for(int i = 0; i < 32; i++)
        g->a[i] = (int*)calloc(32, sizeof(int)); 
    
    return g;
}

void enQueue_q(Coada *q, Coada *castigatori){
    
    printf("eroare");
    Echipa * newNode =(Echipa*)malloc(sizeof(Echipa));
    Echipa *aux = castigatori->fata;
    
    newNode->nume_echipa = (char*)calloc(strlen(aux->nume_echipa) + 1, sizeof(char));
    strcpy(newNode->nume_echipa, aux->nume_echipa);
    
    newNode->punctaj_e = aux->punctaj_e;
    newNode->poz = aux->poz;
    newNode->next = NULL ;

    if (q->spate == NULL ) q->spate = newNode ;
        else {
            (q->spate )->next = newNode ;
            (q->spate )= newNode ;
        }
    if (q->fata == NULL ) q->fata = q->spate;
}
