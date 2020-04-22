//
// Created by Дмитрий on 22.04.2020.
//

#ifndef LINALITERATION_VECTOR_H
#define LINALITERATION_VECTOR_H
#include "Matrix.h"

using namespace std;
class Vector3D{
private:
    double x;
    double y;
    double z;
public:
    Vector3D(double x, double y, double z);
    Vector3D();
    ~Vector3D();
    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    const Vector3D operator*(double c) const;
    const Vector3D operator+(Vector3D& v3) const;
    const Vector3D operator-(Vector3D& v3) const;
    const double operator*(Vector3D& v3) const;
};
const Vector3D operator*(double c, Vector3D& v3);
istream& operator>>(istream &is, Vector3D &v3);
ostream& operator<<(ostream &os, const Vector3D &v3);
const Vector3D operator*(Matrix3D &m, Vector3D &v);

#endif //LINALITERATION_VECTOR_H
