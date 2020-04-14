#include <iostream>
#include <cmath>

using namespace std;

class Vector3D{
private:
    double x;
    double y;
    double z;
public:
    Vector3D(double x, double y, double z){
        this->x=x;
        this->y=y;
        this->z=z;
    };
    Vector3D() : Vector3D(0, 0, 0) {
    };
    ~Vector3D(){};
    double getX() const{
        return this->x;
    }
    double getY() const{
        return this->y;
    }
    double getZ() const{
        return this->z;
    }
    void setX(double x){
        this->x=x;
    }
    void setY(double y){
        this->y=y;
    }
    void setZ(double z){
        this->z=z;
    }
    const Vector3D operator*(double c) const {
        return Vector3D(this->x*c, this->y*c, this->z*c);
    }
    const Vector3D operator+(Vector3D& v3) const{
        return Vector3D(this->getX()+v3.getX(),
                        this->getY()+v3.getY(), this->getZ()+v3.getZ());
    }
    const Vector3D operator-(Vector3D& v3) const{
        return Vector3D(this->getX()-v3.getX(),
                        this->getY()-v3.getY(), this->getZ()-v3.getZ());
    }
    const double operator*(Vector3D& v3) const {
        return this->getX()*v3.getX() +
                        this->getY()*v3.getY() + this->getZ()*v3.getZ();
    }
};
    const Vector3D operator*(double c, Vector3D& v3){
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
class Matrix3D{
private:
        double** matrix;
public:
        Matrix3D(double a11, double a12, double a13,
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
        Matrix3D(): Matrix3D(0, 0, 0, 0, 0, 0, 0, 0, 0){};
        ~Matrix3D(){
            for(int i = 0; i<3; i++){
                delete[] this->matrix[i];
            }
            delete[] this->matrix;
        };
        double getElem(int i, int j) const{
            return this->matrix[i][j];
        }
        void setElem(int i, int j, double c){
            this->matrix[i][j]=c;
        }
        const Matrix3D operator*(double c) const{
            return Matrix3D(this->getElem(0, 0)*c, this->getElem(0, 1)*c, this->getElem(0, 2)*c,
                            this->getElem(1, 0)*c, this->getElem(1, 1)*c, this->getElem(1, 2)*c,
                            this->getElem(2, 0)*c, this->getElem(2, 1)*c, this->getElem(2, 2)*c);
        }
        const Matrix3D operator+(Matrix3D &m) const{
            return Matrix3D(this->getElem(0, 0)+m.getElem(0, 0), this->getElem(0, 1)+m.getElem(0, 1), this->getElem(0, 2)+m.getElem(0, 2),
                            this->getElem(1, 0)+m.getElem(1, 0), this->getElem(1, 1)+m.getElem(1, 1), this->getElem(1, 2)+m.getElem(1, 2),
                            this->getElem(2, 0)+m.getElem(2, 0), this->getElem(2, 1)+m.getElem(2, 1), this->getElem(2, 2)+m.getElem(2, 2));
        }
        const Matrix3D operator-(Matrix3D &m) const{
            return Matrix3D(this->getElem(0, 0)-m.getElem(0, 0), this->getElem(0, 1)-m.getElem(0, 1), this->getElem(0, 2)-m.getElem(0, 2),
                            this->getElem(1, 0)-m.getElem(1, 0), this->getElem(1, 1)-m.getElem(1, 1), this->getElem(1, 2)-m.getElem(1, 2),
                            this->getElem(2, 0)-m.getElem(2, 0), this->getElem(2, 1)-m.getElem(2, 1), this->getElem(2, 2)-m.getElem(2, 2));
        }
        const Matrix3D operator*(Matrix3D &m) const{
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
        double det(){
            double d = 0;
            d = this->getElem(0, 0)*(this->getElem(1, 1)*this->getElem(2, 2)-this->getElem(1, 2)*this->getElem(2, 1)) -
                    this->getElem(0, 1)*(this->getElem(1, 0)*this->getElem(2, 2)-this->getElem(1, 2)*this->getElem(2, 0)) +
                        this->getElem(0, 2)*(this->getElem(1, 0)*this->getElem(2, 1)-this->getElem(1, 1)*this->getElem(2, 0));
            return d;
        }

};
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
const Vector3D operator*(Matrix3D &m, Vector3D &v) {
    return Vector3D((m.getElem(0, 0)*v.getX()+m.getElem(0, 1)*v.getY()+m.getElem(0, 2)*v.getZ()),
                    (m.getElem(1, 0)*v.getX()+m.getElem(1, 1)*v.getY()+m.getElem(1, 2)*v.getZ()),
                    (m.getElem(2, 0)*v.getX()+m.getElem(2, 1)*v.getY()+m.getElem(2, 2)*v.getZ()));
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

int main() {
    // Вектор задан в коде
    Vector3D A(1, 2, 3);
    // Вектор читается из cin
    Vector3D B;
    cin >> B;

    // Базовые операции с векторами
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "A * 3 = " << A * 3 << endl;
    cout << "2 * B = " << 2 * B << endl;
    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;
    // Матрица задана в коде
    Matrix3D C(1, 0, 0, 0, 1, 0, 0, 0, 1);
    // Матрица читается из cin
    Matrix3D D;
    cin >> D;

    // Базовые операции с матрицами
    cout << "C = " << C << endl;
    cout << "D = " << D << endl;
    cout << "C * 3 = " << C * 3 << endl;
    cout << "2 * D = " << 2 * D << endl;
    cout << "C + D = " << C + D << endl;
    cout << "C - D = " << C - D << endl;
    cout << "C * D = " << C * D << endl;

    // Детерминант матрицы
    cout << "det(D) = " << D.det() << endl;

    // Умножение матрицы на вектор
    cout << "D * B = " << D * B << endl;
    return 0;
}