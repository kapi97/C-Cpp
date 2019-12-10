#include<stdio.h>
#define N 4 //liczba wierszy
#define M 4 //liczba kolumn

int tablica(int tab[N][M])
{
	int i,j;
	for(i=0; i<N; i++)
	{
		for (j=0; j<M; j++)
        printf("%3d", tab[i][j]);
        printf("\n");
    } 
	printf("\n");
}

int przekatna (int tab[N][M])
{
	int i;
	for (i=0; i<N; i++)
	printf("%d\t", tab[i][i]);
}

int main (void)
{
	int tab[N][M]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	tablica(tab);
	printf ("\n\n");
	przekatna(tab);

	return 0;
}