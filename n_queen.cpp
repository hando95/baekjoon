#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
백트래킹 - N-Queen
해당 행에서 이전 행에 있는 퀸들과 비교
1) 열 비교
2) 대각 비교
둘 다 조건을 만족하면 해당 칸에 퀸 놓기
다음 행 검사
*/

int col_visited[15];

int isPossible(int row) {
	int i = 0;
	
	/* 이전 행에 있는 퀸들과 비교 */
	for (i = 0; i < row; i++) {
		
		/* 열 비교 */
		if (col_visited[i] == col_visited[row])
			return 0;

		/* 대각 비교 */
		else if (abs(col_visited[row] - col_visited[i]) == abs(row - i))
			return 0;
	}

	/* 현재 자리에 퀸을 놓을 수 있으면 1 */
	return 1;
}


void BackTrackingDFS(int row, int n, int* cnt) {
	int i;

	/* 퀸 n개를 모두 놓았다면 */
	if (row == n) {  
		(*cnt)++;
		return;
	}

	/* DFS로 0...n-1 행까지 검사 */
	else {
		for (i = 0; i < n; i++) {
			col_visited[row] = i;                    // 해당 행에 i번째 열 퀸 놓기
			if (isPossible(row))                     // 해당 행에 퀸을 놓을 수 있으면
				BackTrackingDFS(row + 1, n, cnt);    // 다음 행으로 진입
			col_visited[row] = 0;                    // 재방문 가능하게 미방문 처리
		}
	}
}

int main() {
	int n;
	int cnt = 0;
	scanf("%d", &n);
	BackTrackingDFS(0, n, &cnt);
	printf("%d\n", cnt);
	return 0;
}