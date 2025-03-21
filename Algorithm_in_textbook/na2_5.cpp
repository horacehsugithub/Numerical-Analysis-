#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define scanf scanf_s

void cholesky(int n, double** A) {
    A[0][0] = sqrt(A[0][0]);
    for (int i = 1; i < n; i++) {
        A[i][0] /= A[0][0];
    }

    for (int i = 1; i < n; i++){
        double sum1 = 0.0;
        for (int j = 0; j < i; j++) {
           sum1  += A[i][j] * A[i][j];
        }
        A[i][i] = sqrt(A[i][i] - sum1);
        for (int j = i + 1; j < n; j++) {
                double sum = 0.0;
                for (int k = 0; k < i; k++) {
                    sum += A[j][k] * A[i][k];
                }
                A[j][i] = (A[j][i] - sum) / A[i][i];
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    cholesky(n, A);

    printf("\nsolution:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//3
//4 12 - 16
//12 37 - 43
//- 16 - 43 98
//
//solution:
//2.000000 12.000000 - 16.000000
//6.000000 1.000000 - 43.000000
//- 8.000000 5.000000 3.000000