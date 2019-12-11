// ex2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LimitArr.h"
#include "ArithArr.h"

const int arrlen = 4;

int _tmain(int argc, _TCHAR* argv[])
{
	ArithArr lim1(10,20,12);
	ArithArr lim2(10,20,13);
	ArithArr lim3(10,20,12);

	cout << lim1;

	for (int i=20; i<24;i++)
		lim1[i]=i+100;

	cout << lim1;
	cout << lim1[22]<< "\n";

	ArrayDb & ra = lim1;
	ArrayDb * pa = &lim1;

	ra[22]= 88.87;
	(*pa)[21] = 66;

	cout << lim1;

	cout << "suma: " <<((ArithArr*) pa)->sum()<< " srednia:" <<((ArithArr*) pa)->average()<<"\n";
	cout << "suma: " <<((ArithArr&) ra).sum()<< " srednia:" <<((ArithArr&) ra).average()<<"\n";
	cout <<"lim1\n" << lim1;
	cout <<"lim2\n" << lim2;

	lim3=lim1+lim2;
	cout <<"lim3\n" << lim3;

	system("pause");
	return 0;
}