#include "Matrix.h"//
// Created by Дмитрий on 22.04.2020.
//
#include <iostream>
#include "Matrix.h"
using namespace std;



    Matrix3D::Matrix3D(double a11, double a12, double a13,
             double a21, double a22, double a23,
             double a31, double a32, double a33){
        this->matrix = new double *[3];
        for(int i = 0; i<3; i++){
            this->matrix[i] = new double [3];
        }
        this->matrix[0][0] = a11; this->matrix[0][1] = a12; this->matrix[0][2] = a13;
        this->matrix[1][0] = a21; this->matrix[1][1] = a22; this->matrix[1][2] = a23;
        this->matrix[2][0] = a31; this->matrix[2][1] = a32; this->matrix[2][2] = a33;
    };
    Matrix3D::Matrix3D(): Matrix3D(0, 0, 0, 0, 0, 0, 0, 0, 0){};
    Matrix3D::~Matrix3D(){
        for(int i = 0; i<3; i++){
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
    };
    double Matrix3D::getElem(int i, int j) const{
        return this->matrix[i][j];
    }
    void Matrix3D::setElem(int i, int j, double c){
        this->matrix[i][j]=c;
    }
    const Matrix3D Matrix3D::operator*(double c) const{
        return Matrix3D(this->getElem(0, 0)*c, this->getElem(0, 1)*c, this->getElem(0, 2)*c,
                        this->getElem(1, 0)*c, this->getElem(1, 1)*c, this->getElem(1, 2)*c,
                        this->getElem(2, 0)*c, this->getElem(2, 1)*c, this->getElem(2, 2)*c);
    }
    const Matrix3D Matrix3D::operator+(Matrix3D &m) const{
        return Matrix3D(this->getElem(0, 0)+m.getElem(0, 0), this->getElem(0, 1)+m.getElem(0, 1), this->getElem(0, 2)+m.getElem(0, 2),
                        this->getElem(1, 0)+m.getElem(1, 0), this->getElem(1, 1)+m.getElem(1, 1), this->getElem(1, 2)+m.getElem(1, 2),
                        this->getElem(2, 0)+m.getElem(2, 0), this->getElem(2, 1)+m.getElem(2, 1), this->getElem(2, 2)+m.getElem(2, 2));
    }
    const Matrix3D Matrix3D::operator-(Matrix3D &m) const{
        return Matrix3D(this->getElem(0, 0)-m.getElem(0, 0), this->getElem(0, 1)-m.getElem(0, 1), this->getElem(0, 2)-m.getElem(0, 2),
                        this->getElem(1, 0)-m.getElem(1, 0), this->getElem(1, 1)-m.getElem(1, 1), this->getElem(1, 2)-m.getElem(1, 2),
                        this->getElem(2, 0)-m.getElem(2, 0), this->getElem(2, 1)-m.getElem(2, 1), this->getElem(2, 2)-m.getElem(2, 2));
    }
    const Matrix3D Matrix3D::operator*(Matrix3D &m) const{
        Matrix3D r = Matrix3D();
        double elem=0;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                elem = 0;
                for(int count = 0; count<3; count++){
                    elem+=this->matrix[i][count]*m.matrix[count][j];
                }
                r.setElem(i, j, elem);
            }
        }
        return r;
    }
    double Matrix3D::det(){
        double d = 0;
        d = this->getElem(0, 0)*(this->getElem(1, 1)*this->getElem(2, 2)-this->getElem(1, 2)*this->getElem(2, 1)) -
            this->getElem(0, 1)*(this->getElem(1, 0)*this->getElem(2, 2)-this->getElem(1, 2)*this->getElem(2, 0)) +
            this->getElem(0, 2)*(this->getElem(1, 0)*this->getElem(2, 1)-this->getElem(1, 1)*this->getElem(2, 0));
        return d;
    }

const Matrix3D operator*(double c, Matrix3D &m) {
    return Matrix3D(m.getElem(0, 0)*c, m.getElem(0, 1)*c, m.getElem(0, 2)*c,
                    m.getElem(1, 0)*c, m.getElem(1, 1)*c, m.getElem(1, 2)*c,
                    m.getElem(2, 0)*c, m.getElem(2, 1)*c, m.getElem(2, 2)*c);
}
ostream& operator<<(ostream &os, const Matrix3D &m){
    os<<endl;
    os << "||" << m.getElem(0, 0) << " " << m.getElem(0, 1) << " " <<m.getElem(0, 2)<< "||"<<endl;
    os << "||" << m.getElem(1, 0) << " " << m.getElem(1, 1) << " " <<m.getElem(1, 2)<< "||"<<endl;
    os << "||" << m.getElem(2, 0) << " " << m.getElem(2, 1) << " " <<m.getElem(2, 2)<< "||"<<endl;
    return os;
}
istream& operator>>(istream &is, Matrix3D &m){
    double k;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            is >> k;
            m.setElem(i, j, k);
        }
    }
    return is;
}
