#include <iostream>
#include <Eigen/Dense>
#include <chrono>
using namespace std;

int main()
{
    Eigen::Matrix2d A;
    A << 1,2,3,4;
    Eigen::Vector3i B;
    B << 8,8,8;
    Eigen::Matrix<int,6,8> C = Eigen::Matrix<int, 6, 8>::Zero();
    C.setZero();
    Eigen::Matrix<int,10,10> D;
    D.setConstant(6);
    cout<< A << endl << B << endl << C << endl << D << endl;
    Eigen::Matrix2d E;
    E << 0,1,1,0;
    cout<< A * E<<endl;
    /*转置和逆*/
    cout <<"transpose: \n" << A.transpose() << endl 
        << "inverse: \n" << A.inverse() << endl;
    Eigen::Matrix4d G;
    G << -6,1,0,0
        ,0,1,0,0
        ,0,0,6,0
        ,0,0,0,1;
    /*特征值和特征向量*/
    auto start = std::chrono::high_resolution_clock::now();
    Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> solver(G);
    auto end = std::chrono::high_resolution_clock::now();
    Eigen::VectorXd eigenvalues = solver.eigenvalues();
    Eigen::MatrixXd eigenvectors = solver.eigenvectors();
    // 计算所需时间
    std::chrono::duration<double, std::milli> duration = end - start;
    // 输出结果
    std::cout << "Eigenvalues:\n" << eigenvalues.transpose() << std::endl;
    std::cout << "Eigenvectors:\n" << eigenvectors << std::endl;
    std::cout << "Calculation time: " << duration.count() << " ms" << std::endl;

    return 0;
}

