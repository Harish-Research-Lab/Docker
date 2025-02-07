#ifndef FEM_SOLVER_H
#define FEM_SOLVER_H

#include "mesh.h"
#include "solver.h"

class FEMSolver {
public:
    FEMSolver();
    void run();
};

#endif // FEM_SOLVER_H