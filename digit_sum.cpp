#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i, sum = 0;
	char num[100] = { 0, };
	scanf("%d", &n);
	scanf("%s", num);
	for (i = 0; i < n; i++) {
		sum += num[i] - '0';
	}
	printf("%d\n", sum);
}