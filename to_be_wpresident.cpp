#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int t, k, n, i, j;
	int home[15][15] = { 0, };

	scanf("%d", &t); // 테스트케이스
	for (i = 0; i < 15; i++)
		home[0][i] = i;

	for (i = 1; i < 15; i++) {
		for (j = 1; j < 15; j++) {
			home[i][j] = home[i - 1][j] + home[i][j - 1];
			// 아래층 같은 호수 사람 + 같은 층 전 호수 사람
		}
	}

	for (i = 0; i < t; i++) {
		scanf("%d", &k); // 층
		scanf("%d", &n); // 호

		printf("%d\n", home[k][n]);
	}
	return 0;
}