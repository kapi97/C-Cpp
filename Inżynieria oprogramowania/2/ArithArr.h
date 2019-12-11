#ifndef _ARITHARR_H_
#define _ARITHARR_H_
#include "ArrayDb.h"
#include "LimitArr.h"

class ArithArr : public LimitArr
{
public:

	ArithArr();
	ArithArr(int n, double val = 0.0);
	ArithArr(int n, int lb, double val = 0.0);

	double sum() const;
	double average() const;

	ArithArr operator+( ArithArr & a);


};

#endif