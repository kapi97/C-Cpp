#include <stdio.h>
#define N 5	

int min(int *t, int w)
{
	int min,i;
	min=t[0];
	for(i=0; i<w; i++)
	if (min>t[i])
	min=t[i];
	return min;
}

int max(int *t, int w){
	int max,i;
	max=t[0];
	for(i=0; i<w; i++)
	if (max<t[i])
	max=t[i];
	return max;
}

int main (void)
{	
	int a, i;	
	int suma=0;
	int tab[N];
	printf("Podaj %d liczb całkowitych\n", N);	
																						
	do
	{										
		scanf("%d", &a);						
		tab[i]=a;							
		i++;								
	}
	while(i<N);
	
	for(i=0; i<N; i++)							
	printf("Elementy tablicy: %d\t", tab[i]);
	
	printf("\nMin: %d", min(tab,5));
	printf("\nMax: %d", max(tab,5));
	
	return 0;
}