#include "StdAfx.h"
#include "ArithArr.h"

ArithArr::ArithArr(void) : LimitArr(){
}
ArithArr::ArithArr(int n, double val) : LimitArr(n, val){
}
ArithArr::ArithArr(int n, int lb, double val) : LimitArr(n,lb, val){
}
double ArithArr::sum() const
{
	int size = arsize();
	double suma = 0.0;
	for (int i=0;i<size;i++)
		suma+=arr[i];

	return suma;
}
double ArithArr::average() const
{
	int size = arsize();
	double suma = 0.0;
	for (int i=0;i<size;i++)
		suma+=arr[i];

	return suma/arsize();
}
ArithArr ArithArr::operator+(ArithArr & a)
{
	unsigned int rozmiar1 = arsize();
	unsigned int rozmiar2 = a.arsize();
	if (rozmiar1 != rozmiar2){
		cerr << "tablice s¹ ró¿ne\n";
		system("pause");
		exit(1);
	}

	ArithArr tab(rozmiar1);
	for(unsigned int i=0;i<rozmiar1;i++){
		tab.arr[i] = a.arr[i] + arr[i];
	}

	return tab;
}