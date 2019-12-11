#pragma once
#ifndef _LIMARR_H_
#define _LIMARR_H_
#include "ArrayDb.h"
class LimitArr :
	public ArrayDb
{
protected:
	int low_bnd;
	void ok(int i) const;
public:
	LimitArr(void);
	LimitArr(int n, double val = 0.0);
	LimitArr(int n, int lb, double val = 0.0);
	//where lb is lower bond of array
	LimitArr(const double * pn, int n, int lb = 0);
	LimitArr(const LimitArr & a);
	LimitArr(const ArrayDb & a);
	~LimitArr(void);

	int l_bound;

	void new_lb(int lb);// reset lower bound
	int lbound(); // return lower bound
	int ubound(); // return upper bound

	double & operator[](int i); // array indexing
	const double & operator[](int i) const; // array indexing (no =)

};
#endif
