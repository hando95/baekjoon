#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int liter[10000];
int total_wine[10000];

int GetMax(int a, int b) {
	return a < b ? b : a;
}

int GetWineMax(int n) {
	int drink2, drink1, drink0;
	total_wine[0] = liter[0];
	total_wine[1] = liter[0] + liter[1];
	total_wine[2] = GetMax(GetMax(liter[0] + liter[2], liter[1] + liter[2]), liter[0] + liter[1]);

	for (int i = 3; i < n; i++) {
		drink2 = total_wine[i - 3] + liter[i - 1] + liter[i];         // 연속 2번 마시기
		drink1 = total_wine[i - 2] + liter[i];                        // 연속 1번 마시기
		drink0 = total_wine[i - 1];                                   // 연속 0번 마시기
		total_wine[i] = GetMax(GetMax(drink2, drink1), drink0);
	}
	return total_wine[n - 1];
}


int main() {
	int n;

	scanf("%d", &n);                   // 포도주 개수
	for (int i = 0; i < n; i++) {      // 포도주 양
		scanf("%d", &liter[i]);
	}

	printf("%d\n", GetWineMax(n));
	return 0;
}