#include<stdio.h>

int silnia_1 (int liczba)
{
	int a;
	if (liczba<0) //lub 1
	return a;
	if (liczba==0 || liczba==1) 
	return 1; //silnia z 0 i 1 wynosi 1
	a = liczba*silnia_1(liczba-1); //wywołanie funkcji przez samą siebie ze zmniejszonym argumentem
}

int silnia_2 (int liczba)
{
	if (liczba<2) //lub 1 
	return 1; //silnia z 0 i 1 wynosi 1
	else
	return liczba*silnia_2(liczba-1);
}

int silnia_3 (int liczba)
{
	if (liczba==0) //lub 1 
	return 1; //silnia z 0 i 1 wynosi 1
	else
	return liczba*silnia_3(liczba-1);
}

int main()
{
	int n;
	printf("Podaj liczbe: ");
	scanf("%d", &n);
	printf("%d!=%d\n\n", n, silnia_1(n));
	printf("%d!=%d\n\n", n, silnia_2(n));
	printf("%d!=%d\n", n, silnia_3(n));
	return 0;
}