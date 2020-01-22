#ifndef _MATH_LIB_COMPLEX_H_
#define _MATH_LIB_COMPLEX_H_

template <typename T>
class Complex
{
private:
    /* data */
public:
    T real;
    T imag;
    Complex();
    Complex(T real, T imag);
    //~Complex();

    Complex<T> conj() const;
    void operator = (Complex<T> const &rhs);
    Complex<T> operator + (Complex<T> const &rhs);
    Complex<T> operator - (Complex const &rhs);
    Complex<T> operator * (Complex<T> const &rhs);
    Complex<T> operator / (Complex<T> const &rhs);
    bool operator == (Complex<T> const &rhs);
};
//
template<typename T, typename U>
Complex<T> operator + (U const real, Complex<T> complex);

template<typename T, typename U>
Complex<U> operator - (U const real, Complex<T> complex);

template<typename T, typename U>
Complex<T> operator * (U const real, Complex<T> complex);

template<typename T, typename U>
Complex<T> operator / (U const real, Complex<T> complex);
//
template<typename T, typename U>
Complex<T> operator + (Complex<T> complex, U const real);

template<typename T, typename U>
Complex<U> operator - (Complex<T> complex, U const real);

template<typename T, typename U>
Complex<U> operator * (Complex<T> complex, U const real);

template<typename T, typename U>
Complex<T> operator / (Complex<T> complex, U const real);
#endif /* _MATH_LIB_COMPLEX_H_ */