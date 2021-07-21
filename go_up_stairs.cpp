#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stair_pt[300];
int stair_sum[300];

int GetMax(int a, int b) {
	return a < b ? b : a;
}


int GetStairSum(int n) {
	int i;
	int cnt = 1;
	stair_sum[0] = stair_pt[0];
	stair_sum[1] = stair_pt[0] + stair_pt[1];
	stair_sum[2] = GetMax(stair_pt[0], stair_pt[1]) + stair_pt[2];

	for (i = 3; i < n; i++) {
		// 이전 계단 밟았을 때 vs 이전 계단 밟지 않았을 때 중 점수가 큰 것
		stair_sum[i] = GetMax(stair_pt[i] + stair_pt[i - 1] + stair_sum[i - 3], stair_pt[i] + stair_sum[i - 2] );
	}
	return stair_sum[n - 1];
}


int main() {
	int stair_n;         // 300 이하
	int i;

	scanf("%d", &stair_n);

	for (i = 0; i < stair_n; i++)
		scanf("%d", &stair_pt[i]);

	printf("%d\n", GetStairSum(stair_n));
	return 0;
}