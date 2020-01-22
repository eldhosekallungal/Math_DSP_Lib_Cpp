#ifndef _MATH_LIB_MATRIX_H_
#define _MATH_LIB_MATRIX_H_
#include <initializer_list>
#include "MathLib_Vector.h"

template<typename T>
class Matrix
{
private:
    // Array of row vectors
    Vector<T> *pMatrix;
    unsigned long numRowVectors;
public:
    // Constructor and disctructor
    Matrix();
    Matrix(std::initializer_list<std::initializer_list<T>> listOfList);
    Matrix(unsigned long rowSize, unsigned long colSize);
    ~Matrix();
    // Overloaded operators
    // Indexing operator
    Vector<T> & operator[] (unsigned long index);
    // Initializing operator
    void operator() (unsigned long rowSize, unsigned long colSize);
};
#endif