#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void BackTrackingDFS(int* result, int cnt, int n, int m, int idx) {
	int i;

	/* 길이가 m이면 출력 */
	if (cnt == m) {
		for (i = 0; i < m; i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
		return;
	}

	/* DFS를 이용하여 요소 선택하기 */
	for (i = idx; i <= n; i++) {
		result[cnt] = i;
		BackTrackingDFS(result, cnt + 1, n, m, i);
	}
}

int main() {
	int n, m;
	int ans[8];
	scanf("%d %d", &n, &m);
	
	BackTrackingDFS(ans, 0, n, m, 1);
	
	return 0;
}