#define N 4
#include "mpi.h"
#include <ctime>
#include <iostream>

void print_matrix(char* text, int matrix[N][N]) {
    std::cout << text << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf(" %d", a[i][j]);
        }
        printf ("\n");
    }
    printf ("\n\n");
}

void initMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand() % 21 - 10; // -10 до 10
        }
    }
}

int main(int argc, char *argv[]) {
    int rank, size, sum = 0;
    int a[N][N], b[N][N], c[N][N], aRows[N], cRows[N];
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        srand(time(NULL));
        initMatrix(a);
        initMatrix(b);

        print_matrix("Matrix A:", a);
        print_matrix("Matrix B:", b);
    }

    MPI_Scatter(a, N*N/size, MPI_INT, aRows, N*N/size, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(b, N*N, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);


}
