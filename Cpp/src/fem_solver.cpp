#include "fem_solver.h"
#include <iostream>
#include <mpi.h>

FEMSolver::FEMSolver() {
    // MPI Initialization
}

void FEMSolver::run() {
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        std::cout << "Running FEM Solver with " << size << " MPI processes.\n";
    }

    // Create mesh and solve system
    Mesh mesh;
    Solver solver(mesh);
    solver.solve();
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    FEMSolver solver;
    solver.run();

    MPI_Finalize();
    return 0;
}