#include "MathLib_Matrix.h"
#include <stdlib.h>
#include <iostream>

template<typename T>
Matrix<T>::Matrix()
{
    this->pMatrix = NULL;
    this->numRowVectors = 0;
}

template<typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> listOfList)
{
    unsigned long iCnt = 0;
    Vector<T> *pVector;
    this->pMatrix = (Vector<T> *)malloc(listOfList.size() * sizeof(Vector<T>));
    this->numRowVectors = listOfList.size();

    pVector = this->pMatrix;
    for(auto list = listOfList.begin(); list != listOfList.end(); list++)
    {
        *pVector = *list;
        pVector++;
    }

}

template<typename T>
Matrix<T>::Matrix(unsigned long rowSize, unsigned long colSize)
{
    unsigned long iCnt;
    Vector<T> *pTmp;

    this->pMatrix = (Vector<T> *)malloc(rowSize * sizeof(Vector<T>));
    this->numRowVectors = rowSize;

    pTmp = this->pMatrix;
    for(iCnt = 0; iCnt < rowSize; iCnt++)
    {
        (*pTmp)(colSize);
        pTmp++;
    }

}

template<typename T>
Matrix<T>::~Matrix()
{
    unsigned long iCnt;
    Vector<T> *pTmp;
    
    pTmp = this->pMatrix;
    for(iCnt = 0; iCnt < this->numRowVectors; iCnt++)
    {
        // Call the destructor
        pTmp->~Vector();
        pTmp++;
    }

}

template<typename T>
Vector<T> & Matrix<T>::operator[] (unsigned long index)
{
    if(index >= this->numRowVectors)
    {
        // Return out of bound exception
    }
    else
    {
        return *(this->pMatrix + index);
    }
}

template<typename T>
void Matrix<T>::operator()(unsigned long rowSize, unsigned long colSize)
{
    unsigned long iCnt;
    Vector<T> *pTmp;

    this->pMatrix = (Vector<T> *)malloc(rowSize * sizeof(Vector<T>));
    this->numRowVectors = rowSize;

    pTmp = this->pMatrix;
    for(iCnt = 0; iCnt < rowSize; iCnt++)
    {
        (*pTmp)(colSize);
        pTmp++;
    }
}

#if 1
#include "MathLib_Vector.cpp"
#include "MathLib_Complex.cpp"
#include <iostream>

int main()
{
    const Complex<int> i(0, 1);
    Matrix<Complex<int>> M = {{1+2*i, 3+4*i}, {5+6*i, 7+8*i}};

    for(int i = 0; i < 2; i++)
    {
        std::cout << M[i][0].imag << std::endl;
    }
    return 0;
}
#endif