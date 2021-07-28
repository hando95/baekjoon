#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int IsFactor(int a, int b) {
	return b % a == 0 ? 1 : 0;
}

int IsMultiple(int a, int b) {
	return a % b == 0 ? 1 : 0;
}


int main() {
	int a, b;

	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			break;

		if (IsFactor(a, b))
			printf("factor\n");
		else if (IsMultiple(a, b))
			printf("multiple\n");
		else
			printf("neither\n");
	}
	return 0;
}