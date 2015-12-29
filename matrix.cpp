#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "realMatrix.h"
#include "complex.h"
#include "complexMatrix.h"
#include "matrix.h"

using namespace std;
//default constructor for Matrix class
Matrix::Matrix():rows(0),columns(0),is_real(0) {}
//destructor for matrix class
Matrix::~Matrix() {}
//overloaded stream insertion operator for printing matrix
ostream &operator<<(ostream &out, Matrix &m)
{
  //loops through all matrix elements
  for (int i = 0; i<m.rows; i++){
    for (int j = 0; j <m.columns; j++)
    {
      //m(i,j) calls overloaded operator for the complex class
      out << setw(10) << m(i, j) << "  ";
    }
    out << endl;
  }
  //return printed matrix stored in out
  return out;
}
//overloaded multiply operator for multiplying matrices
Matrix &Matrix::operator* (Matrix & m2)
{
  //initialize pointers to matrix objects
  Matrix* m1_ptr;
  Matrix* m2_ptr;
  Matrix* m3_ptr;
  m1_ptr = this;
  m2_ptr = &m2;
  //initialize temporary 2d matrix vector and another vector
  //will be used for creating a matrix of desired size
  vector< vector<Complex> > temp_matrix;
  vector<Complex> in_vec;
  Complex in;
  //variables for indexing
  int r, c, isreal;
  isreal = 1;
  r = rows;
  c = m2.columns;
  //creates matrix of desired size with all complex data point
  //equal to 0+i0
  for (int i = 0; i<c; i++)
    in_vec.push_back(in);
  for (int i = 0; i<r; i++)
    temp_matrix.push_back(in_vec);
  //nested for loops for multiplying each row and column according to
  //rules of matrix multiplication
  for (int i = 0; i< r; i++)
  for (int j = 0; j<c; j++){
    for (int k = 0; k < columns; k++)
      temp_matrix[i][j] = temp_matrix[i][j] + this->operator()(i, k)* m2.operator()(k, j);
    //is real is false if any imag part is nonzero
    if ( temp_matrix[i][j].getImag() != 0)
      isreal = 0;
  }
  //allocate memory
  if (isreal)
    m3_ptr = new realMatrix;
  else
    m3_ptr = new complexMatrix;

  Matrix &m3 = *m3_ptr;
  m3.importMatrix(temp_matrix);
  return m3;
}

void inputMatrix(vector<vector<Complex>> &temp_matrix,int &is_real) {
  int ln = 500;
  int r_index = 1;
  int c_index = 1;
  int end1 = 0;
  char line[ln];
  //create line of characters equal to 0
  for (int i = 0; i < 500; i++)
    line[i] = '0';//static_cast<char>(0);
  //alter line of characters based on user input
  for (int i = 0; line[i - 1] != ']'; i++)
    line[i] = cin.get();

  ln = 500;
  r_index = 1;
  c_index = 1;
  //figure out the number of rows and columns
  end1 = 0;
  for (int i = 0; i < ln; i++) {
    if (line[i] == ';') {
      r_index++; //increase row amount every time there is a semicolon
      if (r_index == 2)
        end1 = i;
    }
  }
  if (end1 == 0) end1 = ln;

  for (int i = 3; i < end1; i++) {
    if (line[i] == ' '){
      switch (line[i + 1])
      {
      case ';':
        i = end1;
        break;
      //if there is a space followed by a number
      //increment column count
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        c_index++;
        break;
      case '+':
      //if a plus sign, increment index and start over
        i += 3;
        break;
      case '-':
      //if negative sign, check next element
        if (line[i + 2] == ' ')
        //if next is a space, increment and start over
          i += 3;
        else
        //if not, it is a number and increment column count
          c_index++;
        break;
      }
    }
  }


  //initialize 2d vector for matrix elements and
  //complex object for filling in vector
  Complex c1;
  vector<Complex> vec;
  //creates 2d vector of the right size
  for (int i = 0; i<c_index; i++)
    vec.push_back(c1);
  for (int i = 0; i<r_index; i++)
    temp_matrix.push_back(vec);


  //extracting complex number values from input
  stringstream ss;
  double real = 0;
  int i, j, k, l, r, c;
  r = 0;
  c = 0;
  for (i = 3; i < ln && line[i] != ']'; i++) {
    for (j = i; line[j] != ' '; j++);
    //if complex sign
    if (line[j + 3] == 'i') {
      for (k = j + 4; line[k] != ' '; k++);

        for (l = i; l < k; l++) {
          ss << line[l];
        }
      ss << " ";
      i = k;
      //string puts input to complex number
      ss >> c1;
    }
    //if no complex sign
    else {
      for (l = i; l < j; l++) {
        ss << line[l];
      }
      ss << " ";
      i = j;
      ss >> real;
      c1.setReal(real);
      c1.setImag(0);

    }

    if (line[i + 1] == ';')
      i = i + 2;
    //store c1 variable to location in temp_matrix
    temp_matrix[r][c].setReal(c1.getReal());
    temp_matrix[r][c].setImag(c1.getImag());

    if (c == c_index - 1){
      r++;
      c = 0;
    }
    else
      c++;

    if (r == r_index)
      break;
  }
  //is_real is true until a nonzero imagPart component is found
  is_real = 1;
  for (i = 0; i < r_index; i++)
    for (j = 0; j < c_index; j++)
      if (temp_matrix[i][j].getImag() != 0) is_real = 0;

  return;

}
