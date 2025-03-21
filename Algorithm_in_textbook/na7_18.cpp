#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define scanf scanf_s

//利用复化Simpson公式数值计算函数f(x)在区间[a,b]上的积分

double CompSimpQuad(int N,double* x, double* y) {
	if ((N - 1) % 2 != 0) {
		printf("The interval must be divided into even intervals");
		exit(0);
	}

	int n = (N - 1) / 2;
	double h = (x[N - 1] - x[0]) / n;

	double In = 0.0;
	for (int i = 0; i < n; i++) {
		In += 2 * y[2 * i] + 4 * y[2 * i + 1];
	}

	In = In-y[0]+y[N - 1];
	In = h * In / 6;
	return In;
}

int main() {
	int N = 0;
	scanf("%d", &N);
	double* x = (double*)malloc(N * sizeof(double));
	double* y = (double*)malloc(N * sizeof(double));
	for (int i = 0; i < N; i++) {
		scanf("%lf", &x[i]);
	}

	for (int i = 0; i < N; i++) {
		scanf("%lf", &y[i]);
	}

	double result=CompSimpQuad(N, x,y);
    
	printf("%lf",result);
	
	return 0;
}

//5
//0.0 0.5 1.0 1.5 2.0
//0.0 0.25 1.0 2.25 4.0
//2.666667