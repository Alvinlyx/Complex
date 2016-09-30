#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
using namespace std;
template<class T>
class Complex
{
public:
    Complex();
    Complex(T real, T imag);
    Complex operator*(Complex &rhs) const;
    Complex operator+(Complex &rhs) const;
    Complex operator-(Complex &rhs) const;
    Complex operator/(Complex &rhs) const;
    
    Complex operator+(T rhs) const;
    Complex operator-(T rhs) const;
    Complex operator/(T rhs) const;
    Complex operator*(T rhs) const;
    Complex & operator*=(Complex & rhs);
    Complex & operator+=(Complex & rhs);
    Complex & operator-=(Complex & rhs);
    Complex & operator/=(Complex & rhs);
    
    Complex & operator*=(T rhs);
    Complex & operator+=(T rhs);
    Complex & operator-=(T rhs);
    Complex & operator/=(T rhs);

    const T& real() const;
    T & real();
    const T& imag() const;
    T  & imag();
    template<class type>
    friend ostream & operator<<(ostream & os ,Complex<type> & rhs);
    ~Complex();
private:
    T m_real;
    T m_imag;
};


template<class T>
Complex<T>::Complex()
    :m_real(0), m_imag(0)
{
}

template<class T>
Complex<T>::~Complex()
{
}

template<class T>
Complex<T>::Complex(T real, T imag)
    :m_real(real), m_imag(imag)
{
}

template<class T>
Complex<T> Complex<T>::operator*(Complex<T> & rhs) const 
{
    T real = rhs.real();
    T imag = rhs.imag();
    real = real*m_real-imag*m_imag;
    imag = rhs.real()*m_imag+imag*m_real;
    return Complex<T>(real, imag);
}

template<class T>
Complex<T> Complex<T>::operator-(Complex<T> & rhs) const
{
    return Complex<T>(m_real-rhs.real(), m_imag-rhs.imag());
}

template<class T>
Complex<T> Complex<T>::operator+(Complex<T> & rhs) const
{
    return Complex<T>(m_real+rhs.real(), m_imag+rhs.imag());
}

template<class T>
Complex<T> Complex<T>::operator/(Complex<T> & rhs) const
{
    if (rhs.real() ==0 && rhs.imag() ==0)
    {
        throw ;
        return Complex<T>();
    }
    
    T tmp = rhs.imag()*rhs.imag()+rhs.real()*rhs.real();
    rhs.imag() *= static_cast<T>(-1);
    Complex<T> result(*this);
    result *= rhs;
    result /= tmp;
    rhs.imag() *= static_cast<T>(-1);
    return result;
}
    
template<class T>
Complex<T> Complex<T>::operator+(T rhs) const
{
    return Complex<T>(rhs+m_real, m_imag);
}

template<class T>
Complex<T> Complex<T>::operator-(T rhs) const
{
    return Complex<T>(m_real-rhs, m_imag);
}

template<class T>
Complex<T> Complex<T>::operator*(T rhs) const
{
    return Complex<T>(m_real*rhs, m_imag*rhs);
}

template<class T>
Complex<T> Complex<T>::operator/(T rhs) const
{
    if (rhs == 0)
        return Complex<T>();
    return Complex<T>(m_real/rhs, m_imag/rhs);
}

template<class T>
Complex<T> & Complex<T>::operator*=(Complex<T> &rhs)
{
    *this = *this*rhs;
    return *this;
}

template<class T>
Complex<T> & Complex<T>::operator+=(Complex<T> &rhs)
{
    m_real += rhs.real();
    m_imag += rhs.imag();
    return *this;
}

template<class T>
Complex<T> & Complex<T>::operator-=(Complex<T> & rhs)
{
    m_real -= rhs.real();
    m_imag -= rhs.imag();
    return *this;
}

template<class T>
Complex<T> &Complex<T>::operator/=(Complex<T> & rhs)
{
    *this = *this/rhs;
    return *this;
}

template<class T>
Complex<T> & Complex<T>::operator*=(T rhs)
{
    m_real*= rhs;
    m_imag *= rhs;
    return *this;
}
template<class T>
Complex<T> & Complex<T>::operator+=(T rhs)
{
    m_real += rhs;
    return *this;
}

template<class T>
Complex<T> & Complex<T>::operator-=(T rhs)
{
    m_real -= rhs;
    return *this;
}

template<class T>
Complex<T> & Complex<T>::operator/=(T rhs)
{
    if(rhs == 0)
    {
        throw ;
        return *this;
    }
    m_real /= rhs;
    m_imag /= rhs;
    return *this;
}

template<class T>
const T & Complex<T>::real() const
{
    return m_real;
}

template<class T>
T  & Complex<T>::real()
{
    return const_cast<T &>(static_cast<const Complex<T> *>(this)->real());
    
}

template<class T>
const T & Complex<T>::imag() const
{
    return m_imag;
}

template<class T>
T  & Complex<T>::imag()
{
    return const_cast<T &>(static_cast<const Complex<T> *>(this)->imag());
}

template<class type>
ostream & operator<<(ostream & os, Complex<type> &rhs)
{
    os.unsetf(ios::showpos);
    os << rhs.real() ;
    os.setf(ios::showpos);
    os << rhs.imag() << "j  ";
    return os;
}

#endif /* COMPLEX_H */
