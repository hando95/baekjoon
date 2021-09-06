#define _CRT_SECURE_NO_WARNINGS
#define MOD 1000000007
#include <stdio.h>

unsigned long long matrix[2][2] = { {0, 1}, {1, 1} };
unsigned long long result[2][2] = { {1, 0}, {0, 1} };
unsigned long long temp[2][2];


void Production() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				temp[i][j] += (result[i][k] * matrix[k][j]);
			}
			temp[i][j] %= MOD;
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			result[i][j] = temp[i][j];
		}
	}
}

void Square() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				temp[i][j] += (matrix[i][k] * matrix[k][j]);
			}
			temp[i][j] %= MOD;
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			matrix[i][j] = temp[i][j];
		}
	}
}

int main() {
	unsigned long long n;

	scanf("%llu", &n);

	while (n) {
		if (n % 2 == 1)
			Production();
		Square();
		n /= 2;
	}

	printf("%llu\n", result[0][1]);
}