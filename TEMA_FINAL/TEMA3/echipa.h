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
};
typedef struct Node Node;

void adaugaJucator(Echipa *echipa,char *nume,char *prenume, int puncte);
Node *adaugaEchipa(Node *listaEchipe, Echipa echipa);


#endif // ECHIPA_H
