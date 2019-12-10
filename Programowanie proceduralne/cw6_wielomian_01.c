#include <stdio.h>

void main ()
{	
	int a, b, c, il, i;
	float d, y, x1, x2;
	
	printf("Podaj parametry funkcji:\n");
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("c = ");
	scanf("%d", &c);
	
	printf("\nPodaj przedzial: od x1 = ");
	scanf("%f", &x1);
	printf(" do x2 = ");
	scanf("%f", &x2);
	
	printf("\nPodaj ilosc wynikow jaka chcesz otrzymac: ");
	scanf("%d", &il);
	
	d=(x2-x1)/il;
	y=0;
	
	printf("\n%f", d);
	
	FILE *pliktxt;
	pliktxt=fopen("funkcja.txt", "w");
	
	FILE *plikbin;
	plikbin=fopen("funkcja.bin", "w");
	
	for(i=1; i<il; i++)
    {
		y=(a*x1*x1)+(b*x1)+c;
		fprintf(pliktxt, "\n%f", y);
		fprintf(plikbin, "\n%f", y);
		x1=x1+d;
	}
	y=(a*x2*x2)+(b*x2)+c;
	fprintf(pliktxt, "\n%f.2", y);
	fprintf(plikbin, "\n%f.2", y);
	fclose (pliktxt);
	fclose (plikbin);
	
	return 0;
}