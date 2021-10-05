#define _CRT_SECURE_NO_WARNINGS
#define MAX_B_SIZE 10000000000
#include <stdio.h>
#include <stdlib.h>

long long GetMin(long long a, long long b) {
	return a < b ? a : b;
}

long long CountSmallNum(long long s, long long n) {
	long long cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += GetMin(s / i, n);
	return cnt;
}

int main() {
	long long n, k;
	long long low, high, mid;
	long long cnt = 0, result = 0;

	/* 입력 */
	scanf("%lld", &n);
	scanf("%lld", &k);
	k = GetMin(1000000000, k);
	low = 1;
	high = n * n;

	while (low <= high) {
		mid = (low + high) / 2;
		cnt = CountSmallNum(mid, n);

		if (cnt >= k) {
			result = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;

	}

	/* 출력 */
	printf("%lld\n", result);
	return 0;
}

// reference: https://kbw1101.tistory.com/29