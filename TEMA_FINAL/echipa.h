#ifndef ECHIPA_H
#define ECHIPA_H



struct Jucator
{
    char nume[50];
    char prenume[50];
    int puncte;
} ;
typedef struct Jucator Jucator;

struct team
{
    int numarJucatori;
    char nume[50];
    Jucator *jucatori;
};
typedef struct team Echipa;

struct Node
{
    Echipa val;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node Node;

struct Queue
{
    Node *fata;
    Node *spate;
};
typedef struct Queue Queue;

void adaugaJucator(Echipa *echipa,char *nume,char *prenume, int puncte);
Node* adaugaEchipa(Node *listaEchipe, Echipa echipa);
void eliminareEchipe(Node **listaEchipe, int numarEchipe);
void scrieEchipeInFisier(Node *listaechipe);
void adaugaMeci(Queue *coada , Echipa echipa1, Echipa echipa2);


#endif // ECHIPA_H

