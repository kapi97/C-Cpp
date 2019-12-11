// arraydb.h ‐‐ define array class
#ifndef _ARRAYDB_H_
#define _ARRAYDB_H_
#include <ostream>
#include <iostream>
using namespace std;
class ArrayDb
{
private:
	int size; // number of array elements
protected:
	double * arr; // address of first element
public:
	ArrayDb(); // default constructor
	// create an ArrayDb of n elements, set each to val
	ArrayDb(int n, double val = 0.0);
	// create an ArrayDb of n elements, initialize to array pn
	ArrayDb(const double * pn, unsigned int n);
	ArrayDb(const ArrayDb & a); // copy constructor
	virtual ~ArrayDb(); // destructor
	unsigned int arsize() const { return size; } // returns array size
	// overloaded operators
	virtual double & operator[](int i); // array indexing
	virtual const double & operator[](int i) const; // array indexing (no =)
	ArrayDb & operator=(const ArrayDb & a);
	friend std::ostream & operator<<(std::ostream & os, const ArrayDb & a);
};
#endif