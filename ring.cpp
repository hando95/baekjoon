#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int GetMax(int a, int b) {
	return a < b ? b : a;
}

int GetMin(int a, int b) {
	return a < b ? a : b;
}

int GetGCD(int a, int b) {
	int n1 = GetMax(a, b);
	int n2 = GetMin(a, b);
	int r;
	while (1) {
		r = n1 % n2;
		if (r == 0)
			return n2;
		n1 = n2;
		n2 = r;
	}
}


int main() {
	int n, gcd;
	int ring[100];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &ring[i]);
	}

	for (int i = 1; i < n; i++) {
		gcd = GetGCD(ring[0], ring[i]);
		printf("%d/%d \n", ring[0] / gcd, ring[i] / gcd);
	}
	return 0;
}