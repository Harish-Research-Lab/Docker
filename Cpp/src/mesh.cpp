#include "mesh.h"
#include <iostream>

Mesh::Mesh() {
    // Generate a simple 2x2 mesh (4 nodes, for example)
    nodes = Eigen::MatrixXd(4, 2);
    nodes << 0, 0,
             1, 0,
             0, 1,
             1, 1;
}

Eigen::MatrixXd Mesh::generate() {
    std::cout << "Generated mesh:\n" << nodes << std::endl;
    return nodes;
}