#include <iostream>
#include "complexMatrix.h"

using namespace std;
//default constructor
complexMatrix::complexMatrix():elements() {
  is_real = 0;
}
//destructor
complexMatrix::~complexMatrix() {
  elements.clear();
  cout << "The memory allocated for the matrix has been deleted." << endl;
}
//bring in matrix and store as data member of the class
//set function for matrix elements
void complexMatrix::importMatrix(vector<vector<Complex>> temp) {
  int in_row = temp.size();
  int in_col = temp[0].size();
  Complex c1(0,0);
  vector<Complex> vec;
  rows = in_row;
  columns = in_col;
  for (int i=0; i<columns; i++)
    vec.push_back(c1);
  for (int i=0; i<rows; i++)
    elements.push_back(vec);

  for (int i=0; i<rows; i++)
    for (int j=0; j<columns; j++)
      elements[i][j] = temp[i][j];

  return;
}
//overloaded operator for indexing matrices
Complex complexMatrix::operator() (int r, int c) const {
  return elements[r][c];
}
