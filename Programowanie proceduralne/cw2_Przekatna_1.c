#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 3 //liczba wierszy
#define M 3 //liczba kolumn

int wypisz(int tab[N][M], int m)
{
	int i;
	for (i=11; i<=13; i++)
	{
		printf("Podaj element tab[%d]\n",i);
		scanf("%d",&tab[i]);
	}

	for (i=21; i<=23; i++)
	{
		printf("Podaj element tab[%d]\n",i);
		scanf("%d",&tab[i]);
	}

	for (i=31; i<=33; i++)
	{
		printf("Podaj element tab[%d]\n",i);
		scanf("%d",&tab[i]);
	}
	return 0;
}

int funkcja(int tab[N][M], int m)
{
	int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("Podaj znak ktory ma byc wpisany do tablicy\n",i,j);
        	scanf("%2c",&tab[i][j]);
        }
    }
        for(i=0;i<N;i++)
        {
            printf("\n");
            for(j=0;j<N;j++)
            {
               printf("%2c",tab[i][j]);
        	}
        }
    return 0;
}

int main(void)
{
   	int a, b, n, liczba, tablica[N][M]; 
	do
    {
        printf("Podaj ilosc elementow tablicy:");
        scanf("%d",&n);
    }
    while(n<=11||n>=33);
    
    wypisz (tablica, liczba);
    funkcja (tablica, liczba);
    
    return 0;
}