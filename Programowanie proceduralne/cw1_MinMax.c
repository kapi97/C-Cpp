#include <stdio.h>
#include <stdlib.h>
#define N 10

void wyswietl (int tab[N], int n)
{
	int i;
	n=10;
 
	for(i=0; i<n; i++)
	{
		printf("Podaj element tab[%d]\n", i);
		scanf("%d", &tab[i]);
	}
}

void wypisz (int tab[N], int n)
{
	int i;
	n=10;
	
	for(i=0; i<n; i++)
	{
		printf("%d, ", tab[i]);
	}
}

int minimalny(int tab[N], int n)
{
	int i;
	int min;
	min=tab[0];
	for(i=0; i<n; i++)
	if(tab[i]<min)
	min=tab[i];
 
	return min;
}
 
int maksymalny(int tab[N], int n)
{
	int i;
	int max;
	max=tab[0]; 
	for(i=0; i<n; i++)
	if(tab[i]>max)
	max=tab[i];
 
	return max;
}
 
int main()
{
	int n=10;
	int tab[N];
 
	printf("Podaj %d liczb\n\n", n);
 	
	wyswietl(tab, n);
	wypisz(tab, n);
 
	printf("\n\n");
	
	printf("Najmniejszy element w tablicy to %d\n", minimalny(tab, n));
	printf("Najwiekszy element w tablicy to %d\n", maksymalny(tab, n));
 
	system("PAUSE");  
	return 0;
}