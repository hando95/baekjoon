#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cost[1000][3] = { {0, 0, 0}, };    // 총 비용
int house[1000][3] = { {0, 0, 0}, };   // i번째 집 초기 비용

int GetMin(int a, int b) {
	return a < b ? a : b;
}

int Coloring(int n) {
	int i;
	cost[0][0] = house[0][0];
	cost[0][1] = house[0][1];
	cost[0][2] = house[0][2];
	
	/* 이전 비용 중 작은 비용 + 현재 비용 */
	for (i = 1; i < n; i++) {
		// 가장 처음에 2번째 집에 R, G, B를 칠해보고 그 전의 집 색이 무엇일 때 최소 비용인지 구해서 저장
		cost[i][0] = GetMin(cost[i - 1][1], cost[i - 1][2]) + house[i][0];   // i번째 집을 R로 칠한 경우
		cost[i][1] = GetMin(cost[i - 1][0], cost[i - 1][2]) + house[i][1];   // i번째 집을 G로 칠한 경우
		cost[i][2] = GetMin(cost[i - 1][0], cost[i - 1][1]) + house[i][2];   // i번째 집을 B로 칠한 경우
	
        // i번째 집에 R, G, B 중 하나를 칠하고 그 전에 구해놓은 최소 비용을 골라서 합한 후 저장
	}
	
	return GetMin(GetMin(cost[n - 1][0], cost[n - 1][1]), cost[n - 1][2]);
}


int main() {
	int n, i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++)
			scanf("%d", &house[i][j]);
	}

	printf("%d\n", Coloring(n));
	return 0;
}