#include "liste_chainee.h"
#include <stdio.h>
#include <stdlib.h>

void InitList(Element** pt_element, int nombre){
    *pt_element = (Element*)malloc(sizeof(Element*));
    (*pt_element)->suivant = NULL;
    (*pt_element)->nombre = nombre;
}



void AddElmToEnd(Element* element, int nombre){

    if (element->suivant==NULL){
        element->suivant = (Element*)malloc(sizeof(Element*));
        element->suivant->suivant = NULL;
        element->suivant->nombre = nombre;
    }else{
        AddElmToEnd(element->suivant, nombre);
    }
}

void PrintElms(Element* element){
    printf("Adresse Elm: %p - Valeur: %d - Adresse Elm suivant:%p\n", element, element->nombre, element->suivant);
    if (element->suivant != NULL){
        PrintElms(element->suivant);
    }
}



void InsertAfterVal(Element* element, int val_to_add, int val_ref){
    if (element->nombre == val_ref){
        Element* next_elm = element->suivant;
        element->suivant = (Element*)malloc(sizeof(Element*));
        element->suivant->suivant = next_elm;
        element->suivant->nombre = val_to_add;
    }else{
        InsertAfterVal(element->suivant, val_to_add, val_ref);
    }


}


void AddElmToBegin(Element* element, int nombre){

    Element* next_element = (Element*)malloc(sizeof(Element*));
    next_element->suivant = element->suivant;
    next_element->nombre = element->nombre;

    element->suivant = next_element;
    element->nombre = nombre;

}

int SizeOfElm(Element* element){

    if (element == NULL){
        return 0;
    }

    int size = 1;
    if (element->suivant != NULL){
        size += SizeOfElm(element->suivant);
    }
    return size;

}

void RemoveAll(Element** pt_element){

    if ((*pt_element)->suivant != NULL){
        RemoveAll(&(*pt_element)->suivant);
    }
    free(*pt_element);
    *pt_element = NULL;

}


void RemoveElmByVal(Element** pt_element, int value){
    if ((*pt_element)->nombre == value){
        Element* removed = *pt_element;
        *pt_element = (*pt_element)->suivant;
        free(removed);
    }
    else{
        RemoveElmByVal(&((*pt_element)->suivant), value);
    }
}


void RemoveElmByPos(Element** pt_element, int pos){
    if (pos == 1){
        Element* removed = *pt_element;
        *pt_element = (*pt_element)->suivant;
        free(removed);
    }else{
        RemoveElmByPos(&((*pt_element)->suivant), pos -1);
    }
}


void AddElmByPos(Element** pt_element, int nombre, int pos){
    if (pos == 1){
        Element* new_element = (Element*)malloc(sizeof(Element*));
        new_element->suivant = *pt_element;
        new_element->nombre = nombre;

        *pt_element = new_element;
    }else{
        AddElmByPos(&((*pt_element)->suivant), nombre, pos -1);
    }

}
