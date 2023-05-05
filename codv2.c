#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <mpi.h>

int nSolution(int n, int rank);
int solve(int *board, int row, int n);
int isSafe(int *board, int row, int col, int n);

int main(int argc, char *argv[]) {

    int n, rank, size, t;
    int solutions = 0, result = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    n = atoi(argv[1]);

    if (argc < 3)
        t = 0;
    else
        t = atoi(argv[2]);

    omp_set_num_threads(t);

    double start_time = MPI_Wtime();

    #pragma omp parallel for reduction(+:solutions)
    for (int i = rank; i < n; i += size) {
        solutions += nSolution(n, i);
    }

    int *solutions_array = NULL;
    if (rank == 0) {
        solutions_array = (int *)malloc(size * sizeof(int));
    }

    MPI_Gather(&solutions, 1, MPI_INT, solutions_array, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        for (int i = 0; i < size; i++) {
            result += solutions_array[i];
        }

        free(solutions_array);

        double end_time = MPI_Wtime();

        printf("Soluções: %d\n", result);
        printf("Tempo de execução: %fs\n", end_time - start_time);
    }

    MPI_Finalize();
    return 0;
}

int nSolution(int n, int rank) {
    int solutions = 0;
    int *board = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        board[i] = -1;
    }

    board[0] = rank;

    #pragma omp parallel for reduction(+:solutions)
    for (int col = 0; col < n; col++) {
        if (isSafe(board, 1, col, n)) {
            board[1] = col;
            solutions += solve(board, 2, n);
            board[1] = -1;
        }
    }

    free(board);

    return solutions;
}

int solve(int *board, int row, int n) {
    int solutions = 0;

    if (row == n) {
        return 1;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;
            solutions += solve(board, row + 1, n);
            board[row] = -1;
        }
    }

    return solutions;
}

int isSafe(int *board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return 0;
        }
    }

    return 1;
}
