#include <stdio.h>
#include <math.h>
#include<stdlib.h>

#define scanf scanf_s

//四阶四级Runge-Kutta 方法

double f(double x, double y) {
	return (x + y);
}


double* RK4(double a, double b, double h, double y0) {
	int N = (b - a) / h + 1;
	double* y = (double*)malloc(N * sizeof(double));
	y[0] = y0;
	double* x = (double*)malloc(N * sizeof(double));
	for (int i = 0; i < N; i++) {
		x[i] = a + i * h;
	}

	for (int i = 0; i < N - 1; i++) {
		double K0 = f(x[i], y[i]);
		double K1 = f(x[i] + h / 2, y[i] + h / 2*K0);
		double K2 = f(x[i] + h / 2, y[i] + h / 2*K1);
		double K3 = f(x[i+1] , y[i] + K2 * h);
		y[i + 1] = y[i] + h * (K0+2*K1+2*K2+K3) / 6;
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
	double* result = RK4(a, b, h, y0);
	for (int i = 0; i < n; i++) {
		printf("%lf ", result[i]);
	}

	return 0;
}

//一组示例数据
//0 1 0.2 1
//1.000000 1.242800 1.583636 2.044213 2.651042 3.436502


