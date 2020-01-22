#include "MathLib_Complex.h"

template<typename T>
Complex<T>::Complex(){}

template<typename T>
Complex<T>::Complex(T real, T imag) : real(real), imag(imag){}

template<typename T>
Complex<T> Complex<T>::conj() const
{
    return Complex<T>(this->real, -this->imag);
}

template<typename T>
void Complex<T>::operator = (Complex<T> const &rhs)
{
    this->real = rhs.real;
    this->imag = rhs.imag;
}

template<typename T>
Complex<T> Complex<T>::operator + (Complex<T> const &rhs)
{
    return Complex<T>((this->real + rhs.real), (this->imag + rhs.imag));
}

template<typename T, typename U>
Complex<T> operator + (U const real, Complex<T> complex)
{
    return Complex<T>(real+complex.real, complex.imag);
}

template<typename T, typename U>
Complex<T> operator + (Complex<T> complex, U const real)
{
    return Complex<T>(real+complex.real, complex.imag);
}

template<typename T>
Complex<T> Complex<T>::operator - (Complex<T> const &rhs)
{
    return Complex<T>((this->real - rhs.real), (this->imag - rhs.imag));
}

template<typename T, typename U>
Complex<T> operator - (U const real, Complex<T> complex)
{
    return Complex<T>(real - complex.real, complex.imag);
}

template<typename T, typename U>
Complex<T> operator - (Complex<T> complex, U const real)
{
    return Complex<T>(complex.real - real, complex.imag);
}

template<typename T>
Complex<T> Complex<T>::operator * (Complex<T> const &rhs)
{
    return Complex<T>(((this->real * rhs.real) - (this->imag * rhs.imag)), ((this->real * rhs.imag) + (this->imag * rhs.real)));
}

template<typename T, typename U>
Complex<T> operator * (U const real, Complex<T> complex)
{
    return Complex<T>(real*complex.real, real*complex.imag);
}

template<typename T, typename U>
Complex<T> operator * (Complex<T> complex, U const real)
{
    return Complex<T>(real*complex.real, real*complex.imag);
}

template<typename T>
Complex<T> Complex<T>::operator / (Complex<T> const &rhs)
{
    Complex<T> res;
    T mod;
    res = rhs;
    mod = (res * res.conj()).real;
    res = (*this) * res.conj();
    res.real = res.real / mod;
    res.imag = res.imag / mod;

    return res;

}

template<typename T, typename U>
Complex<T> operator / (U const real, Complex<T> complex)
{
    return Complex<T>(complex.real/real, complex.imag/real);
}

template<typename T, typename U>
Complex<T> operator / (Complex<T> complex, U const real)
{
    return Complex<T>(complex.real/real, complex.imag/real);
}

template<typename T>
bool Complex<T>::operator == (Complex<T> const &rhs)
{
    if((this->real == rhs.real) && (this->imag == rhs.imag))
    {
        return true;
    }

    return false;
}

#if 0
#include <iostream>
using namespace std;
int main()
{
    Complex<float> a(2, 3);
    Complex<float> b(7, 10);
    Complex<float> i(0, 1);

    Complex<float> c = a * (b + (1 + 3*i));

    cout << c.real << "+" << c.imag << "i" << endl;
}
#endif