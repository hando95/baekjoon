#define _CRT_SECURE_NO_WARNINGS
#define MOD 1000000007
#include <stdio.h>
#include <math.h>

/*
페르마의 소정리
A! / B! % MOD = A! * pow(B!, MOD - 2) % MOD
*/

long long Pow(long long n, long long m) {
	long long mid;

	if (m == 0)
		return 1;
	else if (m == 1)
		return n;
	else if (m % 2)
		return (n * (Pow(n, m - 1) % MOD)) % MOD;
	else {
		mid = Pow(n, m / 2) % MOD;
		return (mid * mid) % MOD;
	}
}


int main() {
	int n, k;
	long long a = 1;
	long long b = 1;

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		a *= i;
		a %= MOD;
	}

	/* (n - k)! */
	for (int i = 1; i <= n - k; i++) {
		b *= i;
		b %= MOD;
	}

	/* (n - k)! / k! */
	for (int i = 1; i <= k; i++) {
		b *= i;
		b %= MOD;
	}

	printf("%lld\n", (a * Pow(b, MOD - 2)) % MOD);
}