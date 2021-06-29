#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;     // 전체 사람 수
	int* w;    // 몸무게
	int* h;    // 키
	int i = 0, j = 0;
	int count;
	
	scanf("%d", &n);
	if (n < 2 || 50 < n) {
		printf("사람 수 오류: %d\n", n);
		return 0;
	}

	w = (int*)malloc(sizeof(int) * n);
	h = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n;  i++) {
		scanf("%d %d", &w[i], &h[i]);
		if (w[i] < 10 || 200 < w[i] || h[i] < 10 || 200 < h[i]) {
			printf("몸무게 또는 키 오류: %d %d\n", w[i], h[i]);
			return 0;
		}
	}

	for (i = 0; i < n; i++) {
		count = 1;
		for (j = 0; j < n; j++) {
			if (w[i] < w[j] && h[i] < h[j])
				count++;
		}
		printf("%d ", count);
	}
    printf("\n");
	return 0;
}