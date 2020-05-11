//
// Created by Дмитрий on 22.04.2020.
//

#ifndef LINALITERATION_MATRIX_H
#define LINALITERATION_MATRIX_H

#include <iostream>
using namespace std;
class Matrix3D {
private:
    double **matrix;
public:
    Matrix3D(double a11, double a12, double a13,
             double a21, double a22, double a23,
             double a31, double a32, double a33);

    Matrix3D();

    ~Matrix3D();

    double getElem(int i, int j) const;

    void setElem(int i, int j, double c);

    const Matrix3D operator*(double c) const;

    const Matrix3D operator+(const Matrix3D &m) const;

    const Matrix3D operator-(const Matrix3D &m) const;

    const Matrix3D operator*(const Matrix3D &m) const;

    double det();
};
const Matrix3D operator*(double c, const Matrix3D &m);
ostream& operator<<(ostream &os, const Matrix3D &m);
istream& operator>>(istream &is, Matrix3D &m);


#endif //LINALITERATION_MATRIX_H
