// limarr.h -- LimitArr class

#ifndef _LIMARR_H_
#define _LIMARR_H_

#include "arraydb.h"

class LimitArr : public ArrayDb
{
protected:
   int low_bnd;      // new data member
   void ok(int i) const;      // handle bounds checking
public:
// constructors
   LimitArr();
   LimitArr(int n, double val = 0.0);
   LimitArr(int n, int lb, double val = 0.0);
   LimitArr(const double * pn, unsigned int n,int lb=0);
   LimitArr(const LimitArr & a);
   LimitArr(const ArrayDb & a);
// new methods
   void new_lb(int lb) {low_bnd = lb; }  // reset lower bound
   int lbound() {return low_bnd;}   // return lower bound
   int ubound() {return low_bnd + arsize() -1;} // return upper bound
// redefined operators
   double & operator[](int i);
   const double & operator[](int i) const;
};

#endif

