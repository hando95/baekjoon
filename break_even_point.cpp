#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, c;
	int margin = 0, cnt = 0;
	scanf("%d %d %d", &a, &b, &c);
	
	if (a > 2100000000 || b > 2100000000 || c > 2100000000) {
		printf("비용이 너무 큽니다.\n");
		return 0;
	}
	else if (b >= c) {
		printf("%d\n", -1);
		return 0;
	}

	
	margin = c - b; // 순익
	cnt = (a / margin) + 1;

	printf("%d\n", cnt);
	
	return 0;
}