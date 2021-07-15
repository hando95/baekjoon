#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
백트래킹 알고리즘
- 중복이 허락된 조합

기본적으로 DFS를 이용하여 가능한 노드를 탐색
조건에 맞지 않는 노드일 경우 다시 전의 상태로 돌아와 다른 노드를 탐색
조건 = 1...n 중 순서를 고려하지 않고 중복을 허락하여 m개 고르기 (순서는 이미 오름차순으로 정해짐) 
*/

void BackTrackingDFS(int* result, int cnt, int n, int m) {
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
	for (i = 1; i <= n; i++) {
		result[cnt] = i;
		BackTrackingDFS(result, cnt + 1, n, m);
	}
}

int main() {
	int n, m;
	int ans[7];
	scanf("%d %d", &n, &m);
	BackTrackingDFS(ans, 0, n, m);
}