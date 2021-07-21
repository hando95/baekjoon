#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int tri[501][501];
int sum[501][501];

int GetMax(int a, int b) {
	return a < b ? b : a;
}

int GetTriSum(int n) {
	int i, j;
	int max = 0;
	sum[0][0] = tri[0][0];               // 맨 위 꼭짓점 7 대입

	for (i = 1; i < n; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0)
				sum[i][j] = sum[i - 1][j] + tri[i][j];                             // 왼쪽 대각선
			else if (j == i)
				sum[i][j] = sum[i - 1][j - 1] + tri[i][j];                         // 오른쪽 대각선
			else
				sum[i][j] = GetMax(sum[i - 1][j - 1], sum[i - 1][j]) + tri[i][j];  // 여러 가지 경우의 수
		}
	}

	max = sum[n - 1][0];
	for (j = 0; j < n; j++) {
		max = GetMax(max, sum[n - 1][j]);
	}
	return max;
}


int main() {
	int n, i, j;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d", &tri[i][j]);
		}
	}
	printf("%d\n", GetTriSum(n));
	return 0;
}