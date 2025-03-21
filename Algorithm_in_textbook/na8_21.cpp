#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define scanf scanf_s

//先定义一个被积分函数，可任意修改
double f(double x,double y) {
	return (x + y);
}


//向前Euler格式
//利用向前Euler法数值求解初值问题
double* ForEuler(double a, double b, double h,double y0) {
	int N = (b - a) / h + 1;
	double* y = (double*)malloc(N * sizeof(double));
	y[0] = y0;
	double* x = (double*)malloc(N * sizeof(double));
	for (int i = 0; i < N; i++) {
		x[i] = a + i * h;
	}
	
	for (int i = 0; i < N-1; i++) {
		y[i + 1] = y[i] + h * f(x[i], y[i]);
	}
	return y;
}

int main() {
	
	double a = 0;
	scanf("%lf", &a);
	double b = 0;
	scanf("%lf", &b);
	double h;
	scanf("%lf", &h);
	double y0;
	scanf("%lf", &y0);
	int n = (b - a) / h + 1;
	double* result = ForEuler(a, b, h,y0);
	for (int i = 0; i < n; i++) {
        printf("%lf ", result[i]);
	}
	
	return 0;
}


//0 1 0.2 1
//1.000000 1.200000 1.480000 1.856000 2.347200 2.976640
