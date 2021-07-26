#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100000
#include <stdio.h>

int sum[MAX_SIZE];
int seq[MAX_SIZE];

int GetMax(int a, int b) {
	return a < b ? b : a;
}

int GetMaxConSum(int n) {
	int sum_max = seq[0];
	sum[0] = seq[0];

	for (int i = 1; i < n; i++) {
		sum[i] = GetMax(seq[i], seq[i] + sum[i - 1]);   // 이전 연속합과 현재 수와의 합 vs 현재 수 비교
		sum_max = GetMax(sum[i], sum_max);              // 지금까지의 최대합
	}
	return sum_max;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}

	printf("%d\n", GetMaxConSum(n));
	return 0;
}