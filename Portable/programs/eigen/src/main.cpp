#include <iostream>
#include <Eigen/Dense>
using namespace std;

int main()
{
    Eigen::Matrix2f A;
    A << 1,2,3,4;
    Eigen::Vector3i B;
    B << 8,8,8;
    Eigen::Matrix<int,6,8> C = Eigen::Matrix<int, 6, 8>::Zero();
    C.setZero();
    Eigen::Matrix<int,10,10> D;
    D.setConstant(6);
    cout<< A << endl << B << endl << C << endl << D;

    
    return 0;
}

