#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int GetFactorial(int num) {
	int result = 1;
	for (int i = 1; i <= num; i++) {
		result *= i;
	}
	return result;
}

int GetBiCoefficient(int n, int k) {
	return GetFactorial(n) / (GetFactorial(n - k) * GetFactorial(k));
}


int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", GetBiCoefficient(n , k));
	return 0;
}