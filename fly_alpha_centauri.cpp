#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int t, x, y, d, a;
	int i = 0;

	scanf("%d", &t);   // 테스트 케이스

	for (i = 0; i < t; i++) {
		scanf("%d %d", &x, &y);  // 출발점, 도착점
		d = y - x;               // 거리
		a = int(sqrt(d));
		if (d == a * a)
			printf("%d\n", 2 * a - 1);
		else if (a * a < d && d < a * a + a + 1)
			printf("%d\n", 2 * a);
		else
			printf("%d\n", 2 * a + 1);
	}
	return 0;
}