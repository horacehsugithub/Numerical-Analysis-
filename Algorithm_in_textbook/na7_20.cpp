#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define scanf scanf_s

//先定义一个被积分函数，可任意修改
double f(double x) {
	return x * x;
}

double CompGLQuad(double a,double b,int n) {
	double h = (b - a) / n;
	double G = 0;
	for (int j = 0; j < n; j++) {
	double t[2] = {-sqrt(3) / 3,sqrt(3) / 3};
	double A[2] = { 1,1 };

	double x[2] = { 0,0 };
	for (int i = 0; i < 2; i++) {
		x[i] = t[i] * h / 2 + a + (j + 0.5) * h;
	}
	    G += (A[0] * f(x[0])+A[1]*f(x[1]))*h/2;
	}
	return G;
}

int main() {
	int n;
	scanf("%d", &n);
	double a = 0;
	scanf("%lf", &a);
	double b = 0;
	scanf("%lf", &b);
	double result=CompGLQuad(a, b, n);
	printf("%lf", result);
	return 0;
}

//一组示例数据
//4 0.0 2.0
//2.666667