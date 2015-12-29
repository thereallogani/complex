#ifndef REALMATRIX_H
#define REALMATRIX_H

#include <vector>
#include "complex.h"
#include "matrix.h"

using namespace std;

class realMatrix: public Matrix
{
public:
  realMatrix();
  virtual ~realMatrix();
  virtual void importMatrix(vector<vector<Complex>>) override;
  virtual Complex operator() (int,int) const override;

private:
  vector<vector<double>> elements;

};



#endif
