#include <iostream>
#include "complex.h"
#include <cmath>

Complex::Complex(double x, double y):realPart(x),imagPart(y){
  if (y>=0)
  sign = '+';
  else sign = '-';
  compSign = 'i';
}

Complex::Complex() {
  realPart = 0;
  imagPart = 0;
  sign = '+';
  compSign = 'i';
}

//implementation of insertion operator overload
ostream & operator<<(ostream& os, const Complex& c) {
   if (c.imagPart >= 0) {
   os << c.realPart << "+i" << c.imagPart;
   return os;
   }
   else if (c.imagPart < 0) {
   os << c.realPart << "-i" << (abs(c.imagPart));
   return os;
   }
}
//implementation of extraction operator overload
istream & operator>>(istream& is, Complex& c) {
  is >> c.realPart >> c.sign >> c.compSign >> c.imagPart;
  if (c.sign == '-')
  {c.imagPart = -c.imagPart;}
  return is;
}
//double+complex
Complex operator+(double lhs, const Complex & rhs) {
  return Complex(lhs+rhs.realPart, rhs.imagPart);
}
//double*complex
Complex operator*(double lhs, const Complex & rhs) {
  return Complex(lhs*rhs.realPart, lhs*rhs.imagPart);
}
//complex*complex (for multiplying the matrix elements)
Complex operator*(Complex lhs, const Complex & rhs) {
  Complex temp;
  temp.realPart = (lhs.realPart*rhs.realPart)-(lhs.imagPart*rhs.imagPart);
  temp.imagPart = (lhs.realPart*rhs.imagPart)+(rhs.realPart*lhs.imagPart);
  return temp;
}
//complex+complex (for adding matrix elements)
Complex operator+(Complex lhs, const Complex & rhs) {
  Complex temp;
  temp.realPart = lhs.realPart + rhs.realPart;
  temp.imagPart = lhs.imagPart + rhs.imagPart;
  return temp;
}
//complex+complex
Complex Complex::operator+ (Complex & c) {
  Complex temp;
  temp.realPart = realPart + c.realPart;
  temp.imagPart = imagPart + c.imagPart;
  return temp;
}
//complex+double
Complex Complex::operator+ (double & d) {
  Complex temp;
  temp.realPart = realPart + d;
  temp.imagPart = imagPart;
  return temp;
}
//complex*complex
Complex Complex::operator* (Complex & c) {
  Complex temp;
  temp.realPart = (realPart*c.realPart)-(imagPart*c.imagPart);
  temp.imagPart = (realPart*c.imagPart)+(c.realPart*imagPart);
  return temp;
}

//complex*double
Complex Complex::operator* (double & d) {
  Complex temp;
  temp.realPart = realPart*d;
  temp.imagPart = imagPart*d;
  return temp;
}

double Complex::getReal() {
  return realPart;
}

double Complex::getImag() {
  return imagPart;
}

void Complex::setReal(double in) {
  realPart = in;
}

void Complex::setImag(double in) {
  imagPart = in;
}

void Complex::printSign() {
  cout << sign << endl;
}
