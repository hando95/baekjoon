#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int sum = 0, cnt = 0, temp, n;
	int a, i, j;
	scanf("%d", &n);

	while (sum < n) {
		sum += cnt;
		cnt++;
	}
	cnt--;
	sum -= cnt;

	if (cnt % 2 == 0) {
		i = --cnt; // 시작점
		j = 0;
		for (a = 0; a < n - sum; a++) {
			i--;
			j++;
		}
		printf("%d/%d\n", j, (i + 2));
	}
	else {
		i = 0;
		j = --cnt; // 시작점
		for (a = 0; a < n - sum; a++) {
			i++;
			j--;
		}
		printf("%d/%d\n", (j + 2), i);
	}
	
	return 0;
}