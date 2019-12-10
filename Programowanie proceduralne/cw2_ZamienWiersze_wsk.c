#include <stdio.h>
#define N 2 // liczba wierszy
#define M 4 // liczba kolumn

int zamiana(int t[N][M], int a, int b)
{
	int i, j, tmp;
	for (i=0; i<M; i++)
	{
		tmp=t[a][i];
		t[a][i]=t[b][i];
		t[b][i]=tmp;
	}
}

int main (void)
{
	int tab[N][M]={{1,2,3,4},{5,6,7,8}};
	int i, j;
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<M; j++)
		printf ("%3d", *(*(tab+i)+j));
		printf("\n");
	}
	printf("\n");
	
	zamiana(tab, 0, 1);
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<M; j++)
		printf ("%3d", *(*(tab+i)+j));
		printf("\n");
	}
	return 0;
}