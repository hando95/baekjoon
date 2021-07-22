#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int seq_a[1000];
int left[1000];
int right[1000];

int GetMax(int a, int b) {
	return a < b ? b : a;
}

int GetLongBitonicSeq(int n) {
	int result = 0;

	/* 왼쪽에서 i까지 증가하는 부분 수열의 길이 */
	for (int i = 0; i < n; i++) {
		left[i] = 1;
		for (int j = 0; j < i; j++) {
			if (seq_a[i] > seq_a[j])
				left[i] = GetMax(left[i], left[j] + 1);
		}
	}

	/* 오른쪽에서 i까지 증가하는 부분 수열의 길이 */
	for (int i = n - 1; i >= 0; i--) {
		right[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (seq_a[i] > seq_a[j])
				right[i] = GetMax(right[i], right[j] + 1);
		}
	}

	for (int i = 0; i < n; i++) {
		result = GetMax(result, left[i] + right[i] - 1);
	}

	return result;
}

int main() {
	int n;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq_a[i]);
	}

	printf("%d\n", GetLongBitonicSeq(n));
	return 0;
}