#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, sum = 2, cnt = 0;
	scanf("%d", &n);

	while (sum <= n) { // 등비수열의 합이 n 이상이 될 때의 레이어 찾기
		sum += 6 * cnt;
		cnt++;
	}

	if (n == 1)
		printf("%d", 1);
	else
		printf("%d\n", cnt);
	return 0;
}