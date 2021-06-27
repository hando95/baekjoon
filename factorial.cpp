#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	return n * factorial(n - 1);   // 재귀함수
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", factorial(n));
}