#include <stdio.h>
#include <stdlib.h>

struct EList
{
	int klucz;
	struct EList *nast;
};

struct EList* dodaj_elem(struct EList*q, int x);
void drukuj_liste(struct EList* q);  
struct EList* usun_elem(struct EList*q, int x);
void drukuj_rek(struct EList *q);
void drukuj_ostatni(struct EList *q);

int main(void)
{
    int  i,x;
    struct EList* glowa=NULL;
 
    for(i=0; i<5; i++)
    glowa=dodaj_elem(glowa, i);	  
    printf("\n");
    drukuj_liste(glowa);
    
    if(glowa!=NULL)
    {
        printf("\nPodaj element do usuniecia: ");
        scanf("%d", &x);
        glowa=usun_elem(glowa, x);
    }
    else
    printf("Lista pusta");
    printf("\n");
    drukuj_rek(glowa);
    printf("\n");
    drukuj_ostatni(glowa);

    return 0;
}

struct EList* dodaj_elem(struct EList*q, int x)
{
    struct EList*pom;
    pom=(struct EList*)malloc(sizeof(struct EList));
    pom->klucz=x;
    pom->nast=q;
    q=pom;
    return q;
}

void drukuj_liste(struct EList* q)
{
    struct EList*pom;
    int i=0;
    pom=q;
    if(pom==NULL)
    printf("\nLista pusta");
    else
    {
        printf("\nElementy listy:");
        while(pom!=NULL)
        {
            printf("\nElement nr %d: %d", ++i, pom->klucz);
            pom=pom->nast;
        }
    }
}

struct EList* usun_elem(struct EList*q, int x)
{
    struct EList*pom, *tmp;
    pom=q;
    while (pom!=NULL && pom->klucz!=x)
    {
        tmp=pom;
        pom=pom->nast;
	}
    if(pom!=NULL)
    {
        if (pom==q)
        q=pom->nast;
        else
        tmp->nast=pom->nast;
        free(pom);
    }
    else
    printf("Elementu %d nie ma w liscie", x);
    return q;
}

void drukuj_rek(struct EList *q)
{
    if(q!=NULL)
    {
        drukuj_rek(q->nast);		
        printf("\n%d", q->klucz);	
    }
}

void drukuj_ostatni(struct EList *q)
{
    if(q->nast==NULL)
    printf("\n%d", q->klucz);
    else
    drukuj_ostatni(q->nast);
}