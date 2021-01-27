#include <stdio.h>
#include <stdlib.h>

#include "liste_chainee.h"


int main()
{
    Element* ListElm = NULL;


    printf("\nInitialisation de la valeur 1:\n");
    InitList(&ListElm, 1);
    PrintElms(ListElm);


    printf("\nCréation des valeurs 2 à 10:\n");
    for (int i=2; i<=10; i++){
        AddElmToEnd(ListElm, i);
    }
    PrintElms(ListElm);

    printf("\nSuppresion de la valeur 3:\n");
    RemoveElmByVal(&ListElm, 3);
    PrintElms(ListElm);

    printf("\nInsertion de la valeur 3 après la valeur 2:\n");
    InsertAfterVal(ListElm, 3, 2);
    PrintElms(ListElm);

    printf("\nAjout de la valeur 0 tout au début:\n");
    AddElmToBegin(ListElm, 0);
    PrintElms(ListElm);


    printf("\nSuppresion de l'élement en 4ème position:\n");
    RemoveElmByPos(&ListElm, 4);
    PrintElms(ListElm);

    printf("\nInsertion de la valeur 3 en 4ème position:\n");
    AddElmByPos(&ListElm, 3, 4);
    PrintElms(ListElm);

    printf("\nSize of liste: %d\n", SizeOfElm(ListElm));

    printf("\nSuppresion de tous les éléments:\n");
    RemoveAll(&ListElm);
    printf("\nSize of liste: %d\n", SizeOfElm(ListElm));


}
