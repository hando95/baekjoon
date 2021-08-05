#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int paper[128][128];
int white_cnt = 0;
int blue_cnt = 0;

/* 색 확인하는 함수 */
int CheckPaper(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (paper[x][y] != paper[i][j])
				return 0;
		}
	}
	return 1;
}

/* 색종이 분할 함수 */
void CutPaper(int x, int y, int n) {
	
	/* 하얀색 */
	if (paper[x][y] == 0 && CheckPaper(x, y, n)) {
		white_cnt++;
		return;
	}
	
	/* 파란색 */
	if (paper[x][y] == 1 && CheckPaper(x, y, n)) {
		blue_cnt++;
		return;
	}
	
	/* 자르기 */
	CutPaper(x, y, n / 2);                      // 좌상
	CutPaper(x, y + (n / 2), n / 2);            // 우상
	CutPaper(x + (n / 2), y, n / 2);            // 좌하
	CutPaper(x + (n / 2), y + (n / 2), n / 2);  // 우하
}


int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	CutPaper(0, 0, n);

	printf("%d\n%d\n", white_cnt, blue_cnt);
	return 0;
}