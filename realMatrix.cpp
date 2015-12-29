#include "matrix.h"
#include "realMatrix.h"

using namespace std;
//default constructor
realMatrix::realMatrix():elements() {
  is_real = 1;
}
//destructor
realMatrix::~realMatrix() {
  elements.clear();
  cout << "The memory allocated for the matrix has been deleted." << endl;
}
//import matrix and store as real matrix
void realMatrix::importMatrix(vector<vector<Complex>> temp) {
  int in_row = temp.size();
  int in_col = temp[0].size();
  vector<double> vec;
  rows = in_row;
  columns = in_col;
  //create 2d vector of doubles of right size
  for (int i=0; i<columns; i++)
    vec.push_back(0);
  for (int i=0; i<rows; i++)
    elements.push_back(vec);
  //store inputs into data member or class with only real part (imag is 0)
  for (int i=0; i<in_row; i++)
    for (int j=0; j<in_col; j++)
      elements[i][j] = temp[i][j].getReal();

  return;
}
//overloaded () operator for indexing using row and column numbers
Complex realMatrix::operator() (int r, int c) const {
  Complex c1(elements[r][c],0);
  return c1;
}
