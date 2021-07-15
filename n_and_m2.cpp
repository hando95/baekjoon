#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
백트래킹 알고리즘
- 중복이 허락되지 않은 조합 = 순서가 미리 정해진 조합

기본적으로 DFS를 이용하여 가능한 노드를 탐색
조건에 맞지 않는 노드일 경우 다시 전의 상태로 돌아와 다른 노드를 탐색
조건 = 1...n 중 순서를 고려하지 않고 m개 고르기 (순서는 오름차순으로 정해지므로)
visted를 이용하여 중복 제거하고 idx를 이용해 현재 수보다 큰 수만 탐색하게 만들기
*/

int visited[9];

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
	for (i = idx; i <= n; i++) {                                // 전의 인덱스보다 1 큰 수부터 탐색
		if (visited[i] == 0) {
			visited[i] = 1;
			result[cnt] = i;
			BackTrackingDFS(result, cnt + 1, n, m, i + 1);      // i + 1 = 현재 인덱스보다 작은 노드는 다시 보지 않음
			visited[i] = 0;
		}
	}
}

int main() {
	int n, m;
	int ans[8];
	scanf("%d %d", &n, &m);
	BackTrackingDFS(ans, 0, n, m, 1);
}