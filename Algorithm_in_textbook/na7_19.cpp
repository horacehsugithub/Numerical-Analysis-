#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define scanf scanf_s

//利用Romberg积分法数值计算函数f(x)在区间

//先定义一个被积分函数，可任意修改
double f(double x) {
	return x * x;
}


double RombQuad(int n,double a, double b,double epsilon) {
	double h = (b - a);
	double** R = (double**)malloc(1000 * sizeof(double*));
	for (int i = 0; i < 1000; i++) {
		R[i] = (double*)malloc((100) * sizeof(double));
	}

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 100; j++) {
			R[i][j] = 0;
		}
	}

	R[0][0] = (f(a) + f(b)) * (b - a) / 2;
	double error = 1e5;
	int k = 1;//折半次数

	while (error > epsilon) {
		double sum = 0.0;
		for (int i = 1; i< pow(2,k-1); i++) {
			sum += f(a + (2 * i - 1) * h / 2);
		}
		R[k][0] = 0.5 * R[k - 1][0] + sum * h / 2;
		int m = 1;
		for (int j = 1; j <= k; j++) {
			R[k][m] = (pow(4, m) * R[k][m - 1] - R[k - 1][m - 1]) / (pow(4, m) - 1);
			m++;
		}

		error = fabs(R[k][k]-R[k-1][k-1]);
		k++;
		h /= 2;
	}
	double In = R[k - 1][k - 1];
	return In;
}

int main() {
	int n = 0;
	double a = 0.0;
	double b = 0.0;
	double epsilon = 1e-5;
	scanf("%d", &n);
	scanf("%lf %lf", &a,&b);
	
	double result = RombQuad(n, a, b,epsilon);

	printf("%lf", result);

	return 0;
}

//一组示例
//5 0 2
//2.666660