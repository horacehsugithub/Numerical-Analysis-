#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define scanf scanf_s

void doolittle(int n,double** A) {
    double sum = 0.0;
    for (int i = 1; i < n; i++) {
        A[i][0] /= A[0][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = 0; k < i; k++) {
                A[i][j] -= A[i][k] * A[k][j];
            }
        }
        for (int j = i+1; j < n; j++) {
            for (int k = 0; k < i; k++) {
                sum += A[j][k] * A[k][i];    
            }
            A[j][i] -= sum;
            A[j][i] /= A[i][i];
            sum = 0;
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

    doolittle(n, A);

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
//2 - 1 - 2
//- 4 6 3
//- 4 - 2 8
//
//solution:
//2.000000 - 1.000000 - 2.000000
//- 2.000000 4.000000 - 1.000000
//- 2.000000 - 1.000000 3.000000

