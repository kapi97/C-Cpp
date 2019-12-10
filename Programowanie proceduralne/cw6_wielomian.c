#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
	int a, b, c, delta, i, x, y, x_1, x_2;
	float x0, x1, x2;
	char tab[3];
	FILE *pliktxt;
	FILE *plikbin;
	pliktxt=fopen("fkw.txt", "w+");
	plikbin=fopen("fkw.bin", "w+");
	
	printf("Prosze podac a: ");
	scanf("%d", &a);
	printf("Prosze podac b: ");
	scanf("%d", &b);
	printf("Prosze podac c: ");
	scanf("%d", &c);
	
	fprintf(pliktxt, "Parametr a: %d\nParametr b: %d\nParametr c: %d\n\n", a, b, c);
	fprintf(plikbin, "Parametr a: %d\nParametr b: %d\nParametr c: %d\n\n", a, b, c);	
	
	delta=b*b-4*a*c;
	if(delta<0) 
	{
		printf("Brak miejsc zerowych");
		fprintf(pliktxt, "Brak miejsc zerowych");
		fprintf(plikbin, "Brak miejsc zerowych");
	}
	else if(delta==0)
	{
		printf("Jedno miejsce zerowe");
		x0=-b/2*a;
		printf("Twoje miejsce zerowe wynosi: %f", x0);
		fprintf(pliktxt,"Twoje miejsce zerowe wynosi: %f", x0);
		fprintf(plikbin,"Twoje miejsce zerowe wynosi: %f", x0);
	}
	else //if(delta>0)
	{
		x1=(-b-sqrt(delta))/2*a;
		x2=(-b+sqrt(delta))/2*a;
		printf("Jedno miejsce zerowe rowna sie: %f, drugie miejsce zerowe rowna sie: %f", x1, x2);
		fprintf(pliktxt,"Twoje miejsca zerowe:\nx1: %f\nx2: %f\n", x1, x2);
		fprintf(plikbin,"Twoje miejsca zerowe:\nx1: %f\nx2: %f\n", x1, x2);
	}

	printf("\n\nPodaj zakres liczb\n");
	scanf("%d", &x_1);
	scanf("%d", &x_2);
	printf("Podales zakres liczb od %d do %d", x_1, x_2);
	
	if(x_1<x_2)
	{
		for(i=x_1; i<=x_2; i++)
		{
			y=x_1;
			y=a*(x*x)+b*x+c;
			printf("\nx=%d, y=%d\n", x, y);
			x_1=x_1+1;
			fprintf(pliktxt,"\nx=%d, y=%d\n", x, y);
			getch(); //system("PAUSE");
			//return y; //break;
		}
	}
	else if(x_1>x_2)
	{
		for(i=x_2; i<=x_1; i--)
		{
			y=x_2;
			y=a*(x*x)+b*x+c;
			printf("\nx=%d, y=%d\n", x, y);
			x_1=x_1+1;
			fprintf(pliktxt,"\nx=%d, y=%d\n", x, y);
			getch(); //system("PAUSE");
			//return y; //break;
		}
	}
	fprintf(pliktxt,"%s\n", tab);
	fprintf(plikbin,"%s\n", tab);
	fclose(pliktxt);
	fclose(plikbin);
}