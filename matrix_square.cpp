#define _CRT_SECURE_NO_WARNINGS
#define MAX_MAT 5
#include <stdio.h>

long long mat[MAX_MAT][MAX_MAT];
long long ans[MAX_MAT][MAX_MAT];
long long temp[MAX_MAT][MAX_MAT];

/* 정답행렬에 A행렬을 곱하는 함수 */
void Production(long long n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < n; k++) {
				temp[i][j] += (ans[i][k] * mat[k][j]) % 1000;
			}
			temp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = temp[i][j];
		}
	}
}

/* A행렬을 제곱하는 함수 */
void Square(long long n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < n; k++) {
				temp[i][j] += (mat[i][k] * mat[k][j]) % 1000;
			}
			temp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = temp[i][j];
		}
	}
}

int main() {
	long long n;
	long long b;
	scanf("%lld %lld", &n, &b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%lld", &mat[i][j]);
		}
		ans[i][i] = 1;
	}

	while (b) {
		if (b % 2 == 1)
			Production(n);
		Square(n);
		b /= 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%lld ", ans[i][j]);
		}
		printf("\n");
	}
}

// reference: https://cocoon1787.tistory.com/293