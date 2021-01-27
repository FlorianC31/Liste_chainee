#ifndef LISTE_CHAINEE_H_INCLUDED
#define LISTE_CHAINEE_H_INCLUDED

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};



void InitList(Element**, int);
void AddElmToEnd(Element*, int);
void PrintElms(Element*);
void InsertAfterVal(Element*, int, int);
void AddElmToBegin(Element*, int);
int SizeOfElm(Element*);
void RemoveAll(Element**);
void RemoveElmByVal(Element**, int);
void RemoveElmByPos(Element**, int);
void AddElmByPos(Element**, int, int);


#endif // LISTE_CHAINEE_H_INCLUDED
