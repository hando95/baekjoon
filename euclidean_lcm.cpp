#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
유클리드 호제법
GCD: 
a > b일 때 GCD(a, b) = GCD(a % b, b)이고 a % b = 0일 때 b가 최대공약수
LCM:
LCM(a, b) = a * b / GCD(a, b)
*/


int GetMax(int a, int b) {
	return a < b ? b : a;
}

int GetMin(int a, int b) {
	return a < b ? a : b;
}

int GetEuclideanGCD(int a, int b) {
	int num1 = GetMax(a, b);
	int num2 = GetMin(a, b);
	int r;

	while (1) {
		r = num1 % num2;
		if (r == 0)
			return num2;
		num1 = num2;
		num2 = r;
	}
}

int GetEuclideanLCM(int a, int b) {
	return (a * b) / GetEuclideanGCD(a, b);
}

int main() {
	int t;
	int a, b;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", GetEuclideanLCM(a, b));
	}
	return 0;
}

// reference: https://coding-factory.tistory.com/599