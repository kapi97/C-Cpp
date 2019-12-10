#include <stdio.h>
#include <stdlib.h>
 
struct n
{
    int x;
    struct n *next;
};
typedef struct n n;
 
void dodaj(n* head, int i);
void usun(n*head, int i);
void print(n* head);
 
void dodaj(n* head, int i)
{
    n *temp, *nowy;
    temp = head;
 
    while(temp != NULL)
        temp = temp->next;
        
        temp->next=nowy;
 
    nowy = (n*)malloc(sizeof(n));
    nowy->x = i;
    nowy->next = NULL;
    temp->next = nowy;
}

void usun(n* head, int i)
{
    n *temp, *stary;
    temp = head;
 
    while(temp == NULL)
        temp = temp->next;
        
        temp->next=stary;
 
    stary = (n*)malloc(sizeof(n));
    stary->x = i;
    stary->next = NULL;
    temp->next = stary;
}

void print(n* head)
{
    struct n *temp;
    temp = head;
 
    while(temp != NULL)
    {
        printf("%d \n" ,temp->x);
        temp = temp->next;
    }
}
 
int main(int argc, char *argv[])
{
    int w;
    n *head;
 
    head = (n*) malloc(sizeof(struct n));
    head->x = 1;
    head->next = NULL;
 
    for( ; ;)
    {
 
        scanf("%d" ,&w);
        dodaj(head, w);
        print(head);
 
    }
 
    return 0;
}