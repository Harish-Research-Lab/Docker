#include "solver.h"
#include <iostream>
#include <omp.h>

Solver::Solver(Mesh& mesh) : mesh(mesh) {}

void Solver::solve() {
    Eigen::MatrixXd elements = mesh.generate();
    
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        #pragma omp single
        std::cout << "Solving FEM system using " << omp_get_num_threads() << " OpenMP threads.\n";

        #pragma omp for
        for (int i = 0; i < elements.rows(); i++) {
            std::cout << "Thread " << thread_id << " processing element " << i << "\n";
        }
    }
}