//
// Created by Дмитрий on 22.04.2020.
//
#include <iostream>
#include "Vector.h"

using namespace std;

    Vector3D::Vector3D(double x, double y, double z){
        this->x=x;
        this->y=y;
        this->z=z;
    };
    Vector3D::Vector3D() : Vector3D(0, 0, 0) {
    };
    Vector3D::~Vector3D(){};
    double Vector3D::getX() const{
        return this->x;
    }
    double Vector3D::getY() const{
        return this->y;
    }
    double Vector3D::getZ() const{
        return this->z;
    }
    void Vector3D::setX(double x){
        this->x=x;
    }
    void Vector3D::setY(double y){
        this->y=y;
    }
    void Vector3D::setZ(double z){
        this->z=z;
    }
    const Vector3D Vector3D::operator*(double c) const {
        return Vector3D(this->x*c, this->y*c, this->z*c);
    }
    const Vector3D Vector3D::operator+(const Vector3D& v3) const{
        return Vector3D(this->getX()+v3.getX(),
                        this->getY()+v3.getY(), this->getZ()+v3.getZ());
    }
    const Vector3D Vector3D::operator-(const Vector3D& v3) const{
        return Vector3D(this->getX()-v3.getX(),
                        this->getY()-v3.getY(), this->getZ()-v3.getZ());
    }
    const double Vector3D::operator*(const Vector3D& v3) const {
        return this->getX()*v3.getX() +
               this->getY()*v3.getY() + this->getZ()*v3.getZ();
    }

const Vector3D operator*(double c, const Vector3D& v3){
    return Vector3D(v3.getX()*c, v3.getY()*c, v3.getZ()*c);
}
istream& operator>>(istream &is, Vector3D &v3){
    double x, y, z;
    is >> x >> y >> z;
    v3.setX(x);
    v3.setY(y);
    v3.setZ(z);
    return is;
}
ostream& operator<<(ostream &os, const Vector3D &v3){
    os << "(" << v3.getX() << "; " << v3.getY() << "; " <<v3.getZ()<< ")";
    return os;
}
const Vector3D operator*(const Matrix3D &m, const Vector3D &v) {
    return Vector3D((m.getElem(0, 0)*v.getX()+m.getElem(0, 1)*v.getY()+m.getElem(0, 2)*v.getZ()),
                    (m.getElem(1, 0)*v.getX()+m.getElem(1, 1)*v.getY()+m.getElem(1, 2)*v.getZ()),
                    (m.getElem(2, 0)*v.getX()+m.getElem(2, 1)*v.getY()+m.getElem(2, 2)*v.getZ()));
}
