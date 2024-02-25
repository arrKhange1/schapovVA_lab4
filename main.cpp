#define N 4
#include "mpi.h"
#include <ctime>
#include <iostream>

void print_results(char* text, int matrix[N][N]) {
    std::cout << text << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf(" %d", a[i][j]);
        }
        printf ("\n");
    }
    printf ("\n\n");
}
