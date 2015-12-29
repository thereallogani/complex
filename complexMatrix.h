#ifndef COMPLEXMATRIX_H
#define COMPLEXMATRIX_H

#include <vector>
#include "complex.h"
#include "matrix.h"

using namespace std;

class complexMatrix : public Matrix
{
public:
  complexMatrix();
  virtual ~complexMatrix();
  virtual void importMatrix(vector<vector<Complex>>) override;
  virtual Complex operator() (int,int) const override;

private:
  vector<vector<Complex>> elements;

};

#endif
