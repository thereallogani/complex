//  Code for testing the Complex, Matrix, RealMatrix, and ComplexMatrix classes.

#include <iostream>
#include "complex.h"
#include "complexMatrix.h"
#include "realMatrix.h"

void inputMatrix(vector < vector < Complex> > & , int &);

using namespace std;

int main()
{
//  This section will test your Complex class.
   Complex c1(1.0, 5.0);  // this should create Complex object 1.0 + i5.0
   Complex c2, c3, c4;  // these should all be initialized to 0.0 + i0.0
   double d1;

//  Print out c1 and c2 to check them
   cout << "Initial variable values:" << endl;
   cout << "c1 = " << c1 << ", c2 = " << c2 << endl << endl;

//  Prompt user to input a complex number
   cout << "Please enter complex number c3, in the format X + iY, or X - iY: ";
   cin >> c3;
//  Print out c3 to check it
   cout << "You entered c3 = " << c3 << endl;

//  Prompt user for double precision number and check the addition and
//    multiplication operators.
   cout << "Please enter a double precision number d1: ";
   cin >> d1;

   cout << "d1 + c3 = " << (d1 + c3) << endl;
   cout << "c3 + d1 = " << (c3 + d1) << endl << endl;
   cout << "d1 * c3 = " << (d1 * c3) << endl;
   cout << "c3 * d1 = " << (c3 * d1) << endl << endl;

//  Prompt user for complex number and check addition and multiplication.
   cout << "Please enter another complex number c4, in the format X + iY, or X - iY: ";
   cin >> c4;

   cout << "c3 + c4 = " << (c3 + c4) << endl;
   cout << "c3 * c4 = " << (c3 * c4) << endl << endl;


//  This section is to test your Matrix, ComplexMatrix and RealMatrix classes.
   Matrix * m1_ptr;
   Matrix * m2_ptr;

//  Prompt the user for the first of two matrices to be multiplied.
   cout << "Please enter the first matrix to be multiplied: " << endl;
//   We will temporarily hold the matrix in a vector of vectors, because we
//    don't know how large the matrix will be.
   vector < vector < Complex > > temp_matrix;
   int is_real;
//  Function to read the matrix from user input.  Also returns information on
//   whether all of the matrix elements are real.
   inputMatrix(temp_matrix, is_real);
//  If the imaginary parts of all elements are zero, store the matrix as a RealMatrix.
   if (is_real)
     m1_ptr = new realMatrix;
//  Otherwise, store the matrix as a ComplexMatrix.
   else
     m1_ptr = new complexMatrix;
//  We have to make a base class reference in order to use the overloaded
//   multiplication operator (later).
   Matrix & m1 = *m1_ptr;
//  Call importMatrix to move matrix elements from temp_matrix into m1.
   m1.importMatrix(temp_matrix);
//  Show the user the matrix entered for verification purposes.
   cout << "The matrix you entered was: " << endl;
   cout << m1;
//  We need to remember the number of columns of the first matrix, to ensure it
//   equals the number of rows of the second matrix.
   int m1_columns = temp_matrix[0].size();

//  m2_valid will be 1 if the m2's number of rows == m1's number of columns.
   int m2_valid = 0;
   while (!m2_valid)
   {
//   Clear out the vector of vectors, reset size to 0.
     temp_matrix.clear();
//   Prompt user for second matrix to be multiplied.
     cout << "Please enter the second matrix to be multiplied: " << endl;
     inputMatrix(temp_matrix, is_real);
//   Check if second matrix is valid.
     if (temp_matrix.size() != m1_columns)
     {
       cout << "Error!  Matrix 2's number of rows must equal Matrix 1's number of columns."  << endl;
       continue;
     }
     m2_valid = 1;
   }
//  As before, if m2 is real store as RealMatrix, otherwise as ComplexMatrix.
   if (is_real)
     m2_ptr = new realMatrix;
   else
     m2_ptr = new complexMatrix;
//   Base class reference for use with multiplication operator (later).
   Matrix & m2 = *m2_ptr;
//  Call importMatrix to move matrix elements from temp_matrix into m2.
   m2.importMatrix(temp_matrix);
//  Print out m2 for verification purposes.
   cout << "The matrix you entered was: " << endl;
   cout << m2;

// Perform the multiplication, put the result into a base class reference called m3.
   Matrix & m3 =  m1 * m2;
//  Create a pointer to m3, which we will use to deallocate m3 later.
   Matrix * m3_ptr = &m3;
//  Print out the result.
   cout << "The product of the two matrices is: " << endl;
   cout << m3;

//  Deallocate m1, m2, m3.  This will also call the destructors of m1, m2, m3.
  delete m1_ptr;
  delete m2_ptr;
  delete m3_ptr;

}
