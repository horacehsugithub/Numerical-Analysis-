#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define scanf scanf_s
void swapRows(int n, double** A, int row1, int row2) {
	for (int i = 0; i <= n; i++) {
		double temp = A[row1][i];
		A[row1][i] = A[row2][i];
		A[row2][i] = temp;
	}
}

void PLU(int n, double** A) {
	int *p = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		p[i] = 0;
	}
	for (int i = 0; i < n-1; i++) {
		int r = 0;
		double maxunit = A[i][i];
		p[i] = i;
		for (int j = i; j < n; j++) {
			if (fabs(A[j][i]) > maxunit) {
				maxunit = fabs(A[j][i]);
				p[i] = j;
			}
		}
		swapRows(n, A, i, p[i]);
		for (int j = i + 1; j < n; j++) {
			A[j][i] /= A[i][i];
			for (int k = i + 1; k < n; k++) {
				A[j][k] -= A[j][i] * A[i][k];
			}
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

	PLU(n, A);

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
//1 2 3  
//4 5 6  
//7 8 10
//
//solution:
//7.000000 8.000000 10.000000
//0.142857 0.857143 1.571429
//0.571429 0.500000 - 0.500000


//


//void Substitute(int n,double A[][100])