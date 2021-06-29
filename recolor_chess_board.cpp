#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int m, n;
	char board[51][51];
	int min = 64;
	int cnt_w = 0, cnt_b = 0;
	int i = 0, j = 0, k = 0, l = 0;

	scanf("%d %d", &n, &m);
	if (n < 8 || m < 8 || 50 < n || 50 < m) {
		printf("보드판 크기 오류: n = %d, m = %d", n, m);
		return 0;
	}

	for (i = 0; i < n; i++) {              // 보드판 초기화
		scanf("%s", board[i]);
	}

	for (k = 0; k < n - 7; k++) {
		for (l = 0; l < m - 7; l++) {
			cnt_w = 0;
			cnt_b = 0;
			//흰색 시작일 경우
			for (i = k; i < k + 8; i++) {
				for (j = l; j < l + 8; j++) {
					if ((i - k + j - l) % 2 == 0) {// 흰색 칸							
						if (board[i][j] == 'B')    // 검은색이면 흰색 칠하기
							cnt_w++;                
					}
					else {                         // 검은색 칸
						if (board[i][j] == 'W')    // 흰색이면 검은색 칠하기
							cnt_w++;
					}
				}
			}
			//검은색 시작일 경우
			for (i = k; i < k + 8; i++) {
				for (j = l; j < l + 8; j++) {					
					if ((i - k + j - l) % 2 == 0) {// 검은색 칸
						if (board[i][j] == 'W')    // 흰색이면 검은색 칠하기
							cnt_b++;
					}
					else {                         // 흰색 칸
						if (board[i][j] == 'B')    // 검은색이면 흰색 칠하기
							cnt_b++;
					}
				}
			}
			min = cnt_w < min ? cnt_w : min;
			min = cnt_b < min ? cnt_b : min;
		}
	}
	printf("%d\n", min);
	return 0;
}