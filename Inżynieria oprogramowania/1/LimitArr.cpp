#include "pch.h"
#include "LimitArr.h"

#include <iostream>
#include <stdlib.h>


LimitArr::LimitArr(void) :ArrayDb()
{
	l_bound = 0;
}
LimitArr::LimitArr(int n, double val) : ArrayDb(n, val)
{
	l_bound = 0;
}

LimitArr::LimitArr(int n, int lb, double val) : ArrayDb(n, val)
{
	l_bound = lb;
}

LimitArr::LimitArr(const double * pn, int n, int lb) : ArrayDb(pn, n)
{
	l_bound = lb;
}
LimitArr::LimitArr(const LimitArr & a) : ArrayDb(a)
{
	l_bound = a.l_bound;
}
LimitArr::LimitArr(const ArrayDb & a) : ArrayDb(a)
{
	l_bound = 0;
}


LimitArr::~LimitArr(void)
{
	//delete[] arr;
}



void LimitArr::new_lb(int lb)
{
	l_bound = lb;
}

int LimitArr::lbound()
{
	return l_bound;
}

int LimitArr::ubound()
{
	return l_bound + arsize() - 1;
}

double & LimitArr::operator[](int i)
{
	return arr[i - l_bound];
}

const double & LimitArr::operator[](int i) const
{
	return arr[i - l_bound];
}
