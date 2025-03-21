#include <stdio.h>
#include <stdlib.h>

#define scanf scanf_s
// 回代法求解上三角矩阵 Ux = b,不替换x

void Back_Substitution(int n, double** U, double* b, double* x) {
    double* x0 = (double*)malloc(n * sizeof(double));
    double* b0 = (double*)malloc(n * sizeof(double));
    for (int i = n - 1; i >= 0; i--) {
        if (U[i][i] == 0) {
            printf("error");
            exit(0);
        }
        //U为奇异矩阵时不符合题意，报错并退出进程
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
}

// 测试函数
int main() {
    int n = 0;
    scanf("%d", &n);
    double** U = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        U[i] = (double*)malloc(n * sizeof(double));
    }
    double* b = (double*)malloc(n * sizeof(double));
    double* x = (double*)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &U[i][j]);
        }
    }

    for (int j = 0; j < n; j++) {
        scanf("%lf", &b[j]);
    }

    for (int j = 0; j < n; j++) {
        x[j] = 0;
    }
    Back_Substitution(n, U, b, x);

    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %lf\n", i, x[i]);
    }

    return 0;
}

//一组测试样例
//n=3
//U=2.0 - 1.0 3.0
//0.0 1.0 - 2.0
//0.0 0.0 4.0
//b=5.0 - 3.0 8.0
//Solution:
//x[0] = 0.000000
//x[1] = 1.000000
//x[2] = 2.000000