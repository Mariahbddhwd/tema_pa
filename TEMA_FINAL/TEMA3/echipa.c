#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "echipa.h"

void adaugaJucator(Echipa *echipa, char *nume, char *prenume, int puncte)
{
    echipa->jucatori = realloc(echipa->jucatori,(echipa->numarJucatori +1)*sizeof(Jucator));

    //creez jucator nou
    Jucator jucatorNou;
    strcpy(jucatorNou.nume,nume);
    strcpy(jucatorNou.prenume, prenume);
    jucatorNou.puncte = puncte;

    for(int i=echipa->numarJucatori-1;i>=0; i--)
    {
        echipa->jucatori[i+1] = echipa->jucatori[i];
    }

    //adaug jucator nou la inceputul listei
    echipa->jucatori[0] = jucatorNou;

    echipa->numarJucatori++;
}


Node *adaugaEchipa(Node *listaEchipe, Echipa echipa)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->val = echipa;
    newNode->next = listaEchipe;

    return newNode;
}


void eliminareEchipe(Node **listaEchipe, int numarEchipe)
{
    if(numarEchipe <= 1)
        return;

    int i,j,k;
    int index = 0;
    int numarEchipeRamase = 1;

    Echipa *echipe = (Echipa*)malloc(numarEchipe * sizeof(Echipa));
    Node *current = *listaEchipe;

    while(current != NULL)
    {
        echipe[index++] = current->val;
        current = current->next;
    }

    for(i = 0;i < numarEchipe; i+= 2)
    {
        if(i+1 < numarEchipe && echipe[i].val.puncte > echipe[i+1].val.puncte)
        {
            echipe[i+1] = echipe[i];
        }
    }

    for(i=2; i< numarEchipe; i*=2)
    {
        for(j=i; j< numarEchipe; j+=i*2)
        {
            for(k=0; k<i; k++)
            {
                if(j+k< numarEchipe && echipe[numarEchipeRamase-1].val.puncte > echipe[j+k].val.puncte)
                {
                    echipe[numarEchipeRamse++] = echipe[j+k];
                }
            }
        }
    }

    for(i=0; i< numarEchipeRamase; i++)
    {
        Node *temp = *listaEchipe;
        while(temp != NULL)
        {
            if(strcmp(temp0>val.nume,echipe[i].nume)==0)
            {
                if(*listaEchipe == temp)
                {
                    *listaEchipe = temp->next;
                }
                else
                {
                    Node *prev = *listaEchipe;
                    while(prev->next != temp)
                    {
                        prev = prev->next;
                    }
                    prev->next = temp->next;
                }
                free(temp->val.jucatori);
                free(temp);
                break;
            }
            temp = temp->next;
        }
    }
    free(echipe);
}

void scrieEchipeInFisier(Node *listaechipe)
{
    FILE *file = fopen("r.out,"w");
    if(file == NULL)
    {
        printf("NU SE POATE DESCHIDE !\n");
        return;
    }

    Node *current = listaEchipe;
    while(current != NULL)
    {
        fprintf(file, "%s\n",current->val.nume);
        current =current->next;
    }

    fclose(file);
}

void adaugaMeci(Queue *coada , Echipa echipa1, Echipa echipa2)
{
    Node *newNode1 = malloc(sizeof(Node));
    Node *newNode2 = malloc(sizeof(Node));

    newNode1->val = echipa1;
    newNode1->next  = NULL;
    newNode1->prev = coada->spate;


    newNode2->val = echipa2;
    newNode2->next  = NULL;
    newNode2->prev = newNode1;

    if(coada->spate ==NULL)
    {
        coada->fata = newNode1;
        coada->spate = newNode2;
    }
    else
    {
        coada->spate->next = newNode1;
        coada->spate = newNode2;
    }


}
