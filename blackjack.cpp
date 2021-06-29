#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;     // 카드의 수
	int m = 0;     // 블랙잭 목표합
	int i = 0, j = 0, k = 0;
	int* cards;    // 카드 배열
	int sum = 0, max = 0;
	scanf("%d %d", &n, &m);
	
	if (n < 3 || n > 100) {
		printf("카드 수 오류: %d", n);
		return 0;
	}

	if (m < 10 || m > 300000) {
		printf("블랙잭 목표합 오류: %d", n);
		return 0;
	}

	cards = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &cards[i]);
	}

	for (i = 0; i < n - 2; i++) { 
		for (j = i + 1; j < n - 1; j++) {
			for (k = j + 1; k < n; k++) {
				sum = cards[i] + cards[j] + cards[k];
				if (max < sum && sum <= m)
					max = sum;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}