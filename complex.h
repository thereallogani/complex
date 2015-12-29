#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <iomanip>

using namespace std;

class Complex {
  //overload stream insertion and extraction operators
  friend std::ostream &operator<<(std::ostream&, const Complex&);
  friend std::istream &operator>>(std::istream&, Complex&);
  friend Complex operator+(double lhs, const Complex & rhs); //double+complex
  friend Complex operator+(Complex lhs, const Complex & rhs); //complex*complex
  friend Complex operator*(double lhs, const Complex & rhs); //double*complex
  friend Complex operator*(Complex lhs, const Complex & rhs); // complex*complex

public:
  //public member functions
  Complex(double x, double);
  Complex();
  double getReal();
  double getImag();
  void setReal(double);
  void setImag(double);
  void printSign();
  Complex operator+(Complex & c); //complex+complex
  Complex operator+(double & d); // complex+double
  Complex operator*(Complex & c); //complex*complex
  Complex operator*(double & d); //complex*double

private:
  //data members of class Complex
  double realPart;
  double imagPart;
  char sign;
  char compSign;
};

#endif
