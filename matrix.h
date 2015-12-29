// Header file for base class Matrix.
//  Classes RealMatrix and ComplexMatrix will be derived from this.

#include "complex.h"
#include <vector>
//  Include guard
#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

void inputMatrix(vector < vector < Complex> > &, int &);

class Matrix
{
// Overload the stream insertion operator for printing out matrices.
//  Derived classes do not inherit friends, so this will not be inherited by
//  ComplexMatrix nor RealMatrix, but we'll always call this operator from
//  a base class reference anyways.
  friend std::ostream &operator<< (std::ostream &, Matrix &);

  public:
//  Default constructor - not inherited by derived classes
    Matrix();

//  Pure virtual importMatrix member function.
//   This function should allocate memory to store the matrix elements, and
//   copy the matrix elements over from the input vector of vectors into
//   data members of the class.
//  For ComplexMatrix the data should be stored as Complex objects.
//  For RealMatrix the data should be stored as doubles.
    virtual void importMatrix(vector < vector < Complex> >) = 0;

//  Destructor - should be virtual, see notes.
//   The derived class destructors should call delete[] to deallocate the
//   matrix element data IF you use 'new' to dynamically allocate the matrix
//   element data in importMatrix.
    virtual ~Matrix();

//  Overloaded multiplication operator.  This operator can be the same for all
//   derived classes as long as it uses the overloaded () operator below to access
//   matrix elements.  Thus, it is not declared as virtual.
    Matrix & operator*(Matrix &);

//  Overloaded () operator to access matrix elements.  This should be virtual.
//   For both ComplexMatrix and RealMatrix objects, it is convenient to have this
//   operator return a Complex.
//  This is pure virtual because a ComplexMatrix will just return the matrix element,
//   whereas a RealMatrix has to copy the matrix element into the real part,
//   and set the imaginary part to zero.
    virtual Complex operator()(int, int) const = 0;

  protected:
//  number of rows
    int rows;
//  number of columns
    int columns;
//  1 if all elements are real, 0 otherwise
    int is_real;

//  Note that the base class has no data members to store the matrix elements.
//  The derived classes will have to have data members to do this.
//  For example, ComplexMatrix could have Complex ** matrix_elements, or
//   a vector of vectors of Complexes.
//  RealMatrix could have double ** matrix_elements, or a vector of vectors of
//   doubles.

};

#endif
