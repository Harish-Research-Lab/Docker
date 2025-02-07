#ifndef MESH_H
#define MESH_H

#include <Eigen/Dense>
#include <vector>

class Mesh {
public:
    Mesh();
    Eigen::MatrixXd generate();
private:
    Eigen::MatrixXd nodes;
};

#endif // MESH_H