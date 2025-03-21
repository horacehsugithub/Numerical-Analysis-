#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define scanf scanf_s
//Lagrange 差值 利用Lagrange插值方法，近似确定函数f(x)在x=xs处的函数值，其中插值结点为x0,x1,...,xn

double Lagrange(int n, double* x, double* y, double xs) {
	double ys = 0.0;
	for (int i = 0; i < n; i++) {
		double li = 1;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				li *= (xs - x[j]) / (x[i] - x[j]);
			}
		}
		ys += li * y[i];
	}
	return ys;
}

int main() {
	int n;
	scanf("%d", &n);
	double xs = 0.0;
	scanf("%lf", &xs);
	double ys = 0.0;
	double* x = (double*)malloc(n * sizeof(double));
	double* y = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		scanf("%lf", &x[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%lf", &y[i]);
	}

	ys=Lagrange(n, x, y, xs);
	printf("%lf", ys);
	return 0;
}

//3 1.5
//0 1 2
//1 3 2
//2.875000