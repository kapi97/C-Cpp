#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 50

int wypisz(int tab[N][N], int m)
{
	int i;
	for (i=11; i<=13; i++)
	{
		printf("Podaj element tab[%d]\n", i);
		scanf("%d", &tab[i]);
	}
	for (i=21; i<=23; i++)
	{
		printf("Podaj element tab[%d]\n", i);
		scanf("%d", &tab[i]);
	}
	for (i=31; i<=33; i++)
	{
		printf("Podaj element tab[%d]\n", i);
		scanf("%d", &tab[i]);
	}
	return 0;
}

int zamiana(int tab[N][N], int m)
{
	int a[N], i, n, tmp;
	for(i=0; i<0.5*n; i++)
    {
        tmp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=tmp;
    }
    printf("Odwrocona tablica\n");
        
    for(i=0; i<n; i++) printf("a[%d]=%d\n", i, a[i]);
    return 0;
}

int main()
{
	int a, b, n, liczba, tab[N][N]; 
	do
    {
        printf("Podaj ilosc elementow tablicy: ");
        scanf("%d", &n);
    }
    while(n<=11||n>=33);
	
	wypisz(tab, liczba);
	zamiana(tab, liczba);
 
	system("PAUSE");  
	
	return 0;
}