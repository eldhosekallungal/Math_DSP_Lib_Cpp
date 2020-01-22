#include "MathLib_Vector.h"
#include <stdlib.h>

template<typename T>
Vector<T>::Vector(){}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> s)
{
    T *pTmpArray;
    this->pArray = (T *)malloc(s.size() * sizeof(T));
    this->size = s.size();

    pTmpArray = this->pArray;
    for(auto iCnt = s.begin(); iCnt != s.end(); iCnt++)
    {
        *pTmpArray++ = *iCnt;
    }
}

template<typename T>
Vector<T>::Vector(unsigned long numElements)
{
    this->pArray = (T *)malloc(numElements * sizeof(T));
    this->size = numElements;
}

template<typename T>
Vector<T>::~Vector()
{
    if(this->pArray != NULL)
    {
        free(this->pArray);
    }
}

template<typename T>
T & Vector<T>::operator [] (unsigned long index)
{
    if(index >= this->size)
    {
        // Return out of bound exception
    }
    else
    {
        return *(this->pArray + index);
    }
    
}

template<typename T>
void Vector<T>::operator () (unsigned long numElements)
{
    if(this->pArray != NULL)
    {
        free(this->pArray);
    }
    this->pArray = (T *)malloc(numElements * sizeof(T));
    this->size = numElements;
}

template<typename T>
Vector<T> Vector<T>::operator + (Vector<T> const &rhs)
{
    unsigned long iCnt;
    Vector ret;
    Vector rhsCopy = rhs;

    if(this->size != rhs.size)
    {
        // Return size mismatch exception
    }
    else
    {
        ret(this->size);
        for(iCnt = 0; iCnt < this->size; iCnt++)      
        {
            ret[iCnt] = (*this)[iCnt] + rhsCopy[iCnt];
        }

        return ret;
    }
    
}

template<typename T>
Vector<T> Vector<T>::operator - (Vector<T> const &rhs)
{
    unsigned long iCnt;
    Vector ret;
    Vector rhsCopy = rhs;

    if(this->size != rhs.size)
    {
        // Return size mismatch exception
    }
    else
    {
        ret(this->size);
        for(iCnt = 0; iCnt < this->size; iCnt++)      
        {
            ret[iCnt] = (*this)[iCnt] - rhsCopy[iCnt];
        }

        return ret;
    }
    
}

template<typename T>
void Vector<T>::operator = (T *pArray)
{
    unsigned long iCnt;

    if(this->size == 0 || this->pArray == NULL)
    {
        // Return uninitialized exception
    }
    else
    {
        for(iCnt = 0; iCnt < this->size; iCnt++)
        {
            (*this)[iCnt] = pArray[iCnt];
        }
    }
    
}

template<typename T>
void Vector<T>::operator = (std::initializer_list<T> list)
{
    T *pTmpArray;
    
    this->pArray = (T *)malloc(list.size() * sizeof(T));
    this->size = list.size();

    pTmpArray = this->pArray;
    for(auto iCnt = list.begin(); iCnt != list.end(); iCnt++)
    {
        *pTmpArray++ = *iCnt;
    }
}

template<typename T>
T Vector<T>::dot(Vector<T> const &v1, Vector<T> const &v2)
{
    T res;
    unsigned long iCnt;
    Vector a = v1;
    Vector b = v2;

    if(v1.size != v2.size)
    {
        // Return size mismatch exception
    }
    else
    {
        res = 0;
        for(iCnt = 0; iCnt < v1.size; iCnt++)    
        {
            res = res + (a[iCnt] * b[iCnt]);
        }

        return res;
    }
    
}

template<typename T>
Vector<T> Vector<T>::cross(Vector<T> const &v1, Vector<T> const &v2)
{
    Vector res;
    Vector a = v1;
    Vector b = v2;

    if(v1.size != v2.size)
    {
        // Return size mismatch exception
    }
    else if(v1.size != 3)
    {
        // Rerturn undefined computation exception
    }
    else
    {
        res(3);
        res[0] = ((a[1]*b[2]) - (a[2]*b[1]));
        res[1] = ((a[2]*b[0]) - (a[0]*b[2]));
        res[2] = ((a[0]*b[1]) - (a[1]*b[0]));

        return res;
    }
}

template<typename T>
unsigned long Vector<T>::getSize()
{
    return this->size;
}

#if 0
#include <iostream>

using namespace std;

#include "MathLib_Complex.h"
#include "MathLib_Complex.cpp"
int main()
{
    Vector<Complex<int>> v(3);
    Vector<Complex<int>> u(3);
    Complex<int> i(0, 1);
    
    u[0] = 8 + 0*i;
    u[1] = 2 + 1*i;
    u[2] = 3 + 1*i;

    v[0] = 1 + 1*i;     
    v[1] = 1 + 2*i;
    v[2] = 1 + 3*i;
    
    Vector<Complex<int>> s = Vector<Complex<int>>::cross(u, v);

    cout << "[" << s[0].real << "," << s[0].imag << "]" << endl;

    return 0;
}
#endif