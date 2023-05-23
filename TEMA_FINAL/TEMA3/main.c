#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "echipa.h"

int main()
{
    int numarEchipe;

    FILE *file = fopen("d.in","r");
    if(file == NULL)
    {
        printf("Nu se poate deschide!\n");
        return 0;
    }

    fscanf(file,"%d",&numarEchipe);
    fgetc(file);

    Node *listaEchipe = NULL;
    for(int i = 0; i<numarEchipe; i++)
    {
        Echipa echipa;
        echipa.numarJucatori = 0;
        echipa.jucatori = NULL;

        fscanf(file,"%d",&(echipa.numarJucatori));
        fgetc(file);

        fgets(echipa.nume,sizeof(echipa.nume),file);
        echipa.nume[strcspn(echipa.nume,"\n")] = '\0'; // eliminare rand nou din numele echipei

        for(int j =0; j<echipa.numarJucatori; j++)
        {
            char numeJucator[50];
            char prenumeJucator[50];
            int puncteJucator;

            fscanf(file, "%s %s %d",numeJucator,prenumeJucator,&puncteJucator);
            fgetc(file);

            adaugaJucator(&echipa,numeJucator,prenumeJucator,puncteJucator);
        }
        //adaug echipa in lista de echipe
        listaEchipe = adaugaEchipa(listaEchipe,echipa);
    }

    fclose(file);

    Node *current = listaEchipe;
    while(current != NULL)
    {
        Echipa echipa = current->val;
        printf("Echipa:%s\n",echipa.nume);
        printf("Numar jucatori: %d\n",echipa.numarJucatori);

        printf("Lista jucatori:\n");
        for(int j=0; j<echipa.numarJucatori; j++)
        {
            Jucator jucator = echipa.jucatori[j];
            printf("Jucator %d: %s %s , Puncte :%d\n",j+1,jucator.nume,jucator.prenume,jucator.puncte);
        }
        printf("\n");

        current = current->next;
    }

    //ex2

    eliminareEchipe(&listaEchipe, numarEchipe);
    printf("\nEchipe ramase:\n");

    current = listaEchipe;
    while(current != NULL)
    {
        Echipa echipa = current->val;
        printf("Echipa: %S\n", echipa.nume);
        printf("Numar jucatori: %d\n",echipa.numarJucatori);

        printf("Lista jucatori:\n");
        for(int j=0; j< echipa.numarJucatori; j++)
        {
            Jucator jucator = echipa.jucatori[j];
            printf("Jucator %d: %s %s , Puncte: %d\n", j+1,jucator.nume,jucator.prenume,jucator.puncte);
        }
        printf("\n");
        current = current->next;
    }
    scrieEchipeInFisier(listaEchipe);

    current = listaEchipe;

    //ex3 coada
    Queue coada;
    coada.fata = NULL;
    coada.spate = NULL;

    Node *current = listaEchipe;
    while(current != NULL)
    {
        Echipa echipa = current->val;
        if(current->next != NULL)
        {
            Echipa urmatoareaEchipa = current->next->val;
            adaugaMeci(&coada,echipa,urmatoareaEchipa);
        }
        current = current->next;
    }

    while(current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp->val.jucatori);
        free(temp);
    }
    return 0;
}
