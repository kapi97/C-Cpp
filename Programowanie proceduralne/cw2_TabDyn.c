#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	system("cls");
	printf("Tablica dynamiczna\n\n");
	int n, *tablica, *i, *koniec;
	printf("Podaj rozmiar tablicy: ");
	scanf("%d", &n);  
	tablica=(int*)malloc(n*sizeof(int));
	i=tablica;
	koniec=tablica+n*sizeof(int);
 
	for(tablica; tablica<(koniec); tablica=tablica+sizeof(int))
	{
		printf("Wartosc: ");
		scanf("%d", tablica);
	}
	printf("\nTABLICA: \n\n");
 
	for(i; i<(koniec); i=i+sizeof(int))
	{
		printf("Wartosc: %d  Adres: %p\n", *i, i);
	}
return 0;
}