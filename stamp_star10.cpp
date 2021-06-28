#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void stamp(int n, int i, int j) {
	
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) // n * n 매트릭스에서 가운데일 때
		printf(" ");                          // 빈 칸

	else {
		if (n / 3 == 0) {                     // n이 3보다 작으면
			printf("*");                      // *
		}
		else {
			stamp(n / 3, i, j);               // (n / 3)인 매트릭스에서 다시 진행
		}
	}
}

int main() {
	int n;
	double k;
	int i = 0, j = 0;
	scanf("%d", &n);

	k = log(double(n)) / log(3);
	if (k < 1 || 7 < k) {                    // k 범위 제한사항
		printf("k 범위 오류: k = %f\n", k);
		return 0;
	}
	if (fmod(n,3) != 0) {                    // k 3의 승수 제한사항
		printf("k 3의 승수 오류: k = %f\n", k);
		return 0;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			stamp(n, i, j);
		}
		printf("\n");
	}
	return 0;
}