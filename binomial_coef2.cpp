#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
이항 계수 - 파스칼의 삼각형
*/

int cbn[1001][1001] = {0, };

/* n줄까지 C(n, k)를 모두 구하는 함수 */
void Com(int n) {
	cbn[1][0] = 1;
	cbn[1][1] = 1;

	if (n == 1) {
		return;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				cbn[i][j] = cbn[i - 1][j] % 10007;
			else if (j == i)
				cbn[i][j] = cbn[i - 1][i - 1] % 10007;
			else
				cbn[i][j] = (cbn[i - 1][j - 1] + cbn[i - 1][j]) % 10007;
		}
	}
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	Com(n);
	printf("%d\n", cbn[n][k]);
	return 0;
}