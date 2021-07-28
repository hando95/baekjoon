#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int GetMin(int a, int b) {
	return a < b ? a : b;
}

int GetMax(int a, int b) {
	return a < b ? b : a;
}

int GetGreatestCommonFac(int a, int b) {
	int num = 1;
	int limit = GetMax(a, b);

	for (int i = 2; i <= limit; i++) {
		if (a % i == 0 && b % i == 0)
			num = i;
	}
	return num;
}

int GetLeastCommonMul(int a, int b) {
	int num = GetMax(a, b);

	while (1) {
		if (num % a == 0 && num % b == 0)
			return num;
		num++;
	}
}


int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", GetGreatestCommonFac(a, b));
	printf("%d\n", GetLeastCommonMul(a, b));
	return 0;
}