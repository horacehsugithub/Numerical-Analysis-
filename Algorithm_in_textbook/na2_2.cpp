
#include <stdio.h>
#include <stdlib.h>

#define scanf scanf_s

//解线性方程组的消元过程
// 给定矩阵A和向量b，计算经过顺序Gauss消元后的矩阵U和向量b

void gaussu(int n, double** A, double* b) {
    for (int k = 0; k < n - 1; k++) {
        if (A[k][k] == 0) {
            printf("Error.");
            exit(0);
        }

        for (int i = k + 1; i < n; i++) {
            double factor = A[i][k] / A[k][k];
            for (int j = k; j < n; j++) {
                A[i][j] -= factor * A[k][j];
            }
            b[i] -= factor * b[k];
        }
    }
}

// 测试函数
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

    gaussu(n, A, b);

    printf("Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ",A[i][j]);
        }
        printf("\n");
    }


    printf("Vector b:\n");
    for (int i = 0; i < n; i++) {
        printf("%lf ", b[i]);
    }

    return 0;
}

//一组示例数据
//3
//2 1 - 1
//- 3 - 1 2
//- 2 1 2
//8 - 11 - 3
//Matrix A :
//2.000000 1.000000 - 1.000000
//0.000000 0.500000 0.500000
//0.000000 0.000000 - 1.000000
//Vector b :
//8.000000 1.000000 1.000000