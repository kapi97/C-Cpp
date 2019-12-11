// limarr.cpp -- LimitArr methods
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include "limitarr.h"
// private method
   // lower bound for array index is now low_bnd, and 
   // upper bound is now low_bnd + size - 1
void LimitArr::ok(int i) const  // variable lower bound
{
	long size = arsize();
	if (i < low_bnd)
	{
       cout << "Error in array limits:\n"
            << "index " << i << " less than "
            << low_bnd <<  "\n";
       exit(2);
	}
	else if (i >= size + low_bnd)
	{
       cout << "Error in array limits:\n"
            << "index " << i << " greater than "
            << size + low_bnd - 1 << "\n";
       exit(3);
	}
}

// constructors -- initialize the new data member
LimitArr::LimitArr() : ArrayDb()
{
   low_bnd = 0;   // default sets starting subscript to 0
}

LimitArr::LimitArr(int n, double val) : ArrayDb(n, val)
{
   low_bnd = 0;   // default value
}

LimitArr::LimitArr(int n, int lb, double val)
   : ArrayDb(n, val)
{
   low_bnd = lb;  // set starting subscript explicitly
}

LimitArr::LimitArr(const double * pn,unsigned int n, int lb)
   : ArrayDb(pn, n)
{
   low_bnd = lb;
}

LimitArr::LimitArr(const LimitArr & a) : ArrayDb(a)
{
    low_bnd = a.low_bnd;
}

LimitArr::LimitArr(const ArrayDb & a) : ArrayDb(a)
{
   low_bnd = 0;
}

// redefined operators
double & LimitArr::operator[](int i)
{
   ok(i);
   return arr[i - low_bnd];
}

const double & LimitArr::operator[](int i) const
{
   ok(i);
   return arr[i - low_bnd];
}

