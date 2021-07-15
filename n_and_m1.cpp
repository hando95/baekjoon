#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
백트래킹 알고리즘
- 중복이 허락되지 않은 순열

기본적으로 DFS를 이용하여 가능한 노드를 탐색
조건에 맞지 않는 노드일 경우 다시 전의 상태로 돌아와 다른 노드를 탐색
조건 = 1...n 중 순서를 고려해 m개 고르기
visited를 이용하여 중복 제거
*/

int visited[9];

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
		if (visited[i] == 0) {                         // 미방문 노드 시
			visited[i] = 1;                            // 방문 체크
			result[cnt] = i;                           // 요소 선택
			BackTrackingDFS(result, cnt + 1, n, m);    // 다음 요소 선택
			visited[i] = 0;                            // 재방문 가능하게 미방문 처리
		}
	}
}


int main() {
	int n, m;
	int ans[8];
	scanf("%d %d", &n, &m);
	BackTrackingDFS(ans, 0, n, m);
}