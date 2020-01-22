#ifndef _MATH_LIB_VECTOR_H_
#define _MATH_LIB_VECTOR_H_
#include <initializer_list>

template<typename T>
class Vector
{
private:
    T *pArray;
    unsigned long size;
public:
    Vector();
    Vector(std::initializer_list<T> s);
    Vector(unsigned long numElements);
    ~Vector();
    T & operator [] (unsigned long index);
    void operator () (unsigned long numElements);
    Vector operator + (Vector const &rhs);
    Vector operator - (Vector const &rhs);
    void operator = (T *pArray);
    void operator = (std::initializer_list<T> list);
    static T dot(Vector const &v1, Vector const &v2);
    static Vector cross(Vector const &v1, Vector const &v2);
    unsigned long getSize();
};

#endif /* _MATH_LIB_VECTOR_H_ */