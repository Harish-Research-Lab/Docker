#ifndef SOLVER_H
#define SOLVER_H

#include "mesh.h"

class Solver {
public:
    Solver(Mesh& mesh);
    void solve();
private:
    Mesh& mesh;
};

#endif // SOLVER_H