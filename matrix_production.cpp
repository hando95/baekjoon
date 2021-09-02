#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <stdio.h>
#include <stdlib.h>

int a[MAX_SIZE][MAX_SIZE];
int b[MAX_SIZE][MAX_SIZE];
int result[MAX_SIZE][MAX_SIZE];

int main() {
	int n, m, k;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	scanf("%d %d", &m, &k);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%d", &b[i][j]);
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int t = 0; t < m; t++)
				result[i][j] += (a[i][t] * b[t][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}