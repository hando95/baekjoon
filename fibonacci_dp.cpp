#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int t, n;
	int* t_case;
	int i;
	int z[41] = { 1, 0, };
	int o[41] = { 0, 1, };

	for (i = 2; i < 41; i++) {
		z[i] = z[i - 1] + z[i - 2];                 // fibonacci(0) 호출 횟수
		o[i] = o[i - 1] + o[i - 2];                 // fibonacci(1) 호출 횟수
	}

	
	scanf("%d", &t);
	t_case = (int*)malloc(sizeof(int) * t);

	for (i = 0; i < t; i++) {
		scanf("%d", &t_case[i]);
	}

	for (i = 0; i < t; i++) {
		printf("%d %d\n", z[t_case[i]], o[t_case[i]]);
	}
	return 0;
}