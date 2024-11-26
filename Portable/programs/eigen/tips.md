1. 矩阵和向量的创建
创建矩阵和向量：


Eigen::MatrixXd mat(2, 2); // 2x2 矩阵
Eigen::VectorXd vec(2);     // 2 维向量
使用初始化列表：

cpp
复制代码
Eigen::MatrixXd mat = (Eigen::MatrixXd(2, 2) << 1, 2, 3, 4).finished();