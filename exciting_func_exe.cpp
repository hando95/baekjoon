#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int w[101][101][101];

int GetW(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	if (a > 20 || b > 20 || c > 20)
		return GetW(20, 20, 20);
	
	if (w[a][b][c])                         // 이미 결과가 있으면 바로 출력
		return w[a][b][c];

	else if (a < b && b < c) {
		/* 메모제이션 */
		w[a][b][c] = GetW(a, b, c - 1) + GetW(a, b - 1, c - 1) - GetW(a, b - 1, c);
		return w[a][b][c];
	}
	else {
		/* 메모제이션 */
		w[a][b][c] = GetW(a - 1, b, c) + GetW(a - 1, b - 1, c) + GetW(a - 1, b, c - 1) - GetW(a - 1, b - 1, c - 1);
		return w[a][b][c];
	}
}


int main() {
	int a, b, c;
	while (1) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == -1 && b == -1 && c == -1)
			break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, GetW(a, b, c));
	}
	return 0;
}