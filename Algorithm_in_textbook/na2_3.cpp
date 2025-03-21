#include <stdio.h>
#include <math.h>
#include<stdlib.h>

#define scanf scanf_s

// 行交换
void swapRows(int n, double** A, int row1, int row2) {
    for (int i = 0; i <= n; i++) {
        double temp = A[row1][i];
        A[row1][i] = A[row2][i];
        A[row2][i] = temp;
    }
}

//列主元消去法
void pgauss(int n,double** A, double* b) {
    for (int col = 0; col < n; col++) {
        int maxRow = col;
        for (int i = col + 1; i < n; i++) {
            if (fabs(A[i][col]) > fabs(A[maxRow][col])) {
                maxRow = i;
            }
        }

        if (maxRow != col) {
            swapRows(n,A,col,maxRow);
            double temp = b[col];
            b[col] = b[maxRow];
            b[maxRow] = temp;
        }

        for (int row = col + 1; row < n; row++) {
            double factor = A[row][col] / A[col][col];
            for (int j = col; j <= n; j++) {
                A[row][j] -= factor * A[col][j];
            }
            b[row] -= factor * b[col];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        b[i] /= A[i][i];
        for (int j = 0; j < i; j++) {
            b[j] -= A[j][i] * b[i];
        }
        
    }
}


int main() {
    int n = 0;
    scanf("%d", &n);
    double** A = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        A[i] = (double*)malloc(n * sizeof(double));
    }
    double* b = (double*)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    for (int j = 0; j < n; j++) {
        scanf("%lf", &b[j]);
    }
    pgauss(n,A,b);

    printf("\nsolution:\n");
    for (int i = 0; i < n; i++) {
        printf("%lf ", b[i]);
    }

    return 0;
}

//3
//2 1 - 1
//- 3 - 1 2
//- 2 1 2
//8 - 11 - 3
//
//solution:
//2.000000 3.000000 - 1.000000