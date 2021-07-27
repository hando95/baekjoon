#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int w[101] = { 0, };                 // 물건의 무게
int v[101] = { 0, };                 // 물건의 가치
int v_sum[101][100001] = { 0, };     // 물건의 가치합

int GetMax(int a, int b) {
	return a < b ? b : a;
}

int GetMaxValueSum(int n, int k) {

	/* 물건 1...n개까지 */
	for (int i = 1; i <= n; i++) {
		/* 가방의 무게를 1...k까지 */
		for (int j = 1; j <= k; j++) {
			if (j - w[i] >= 0)                                                          // 무게가 j인 배낭에 물건 i를 넣을 수 있으면
				v_sum[i][j] = GetMax(v_sum[i - 1][j - w[i]] + v[i], v_sum[i - 1][j]);   // 물건 i를 고를 경우와 고르지 않을 경우 중 큰 가치합 저장
			else                                                                        // 넣지 못 하면
				v_sum[i][j] = v_sum[i - 1][j];                                          // 이전 가치합 저장
		}
	}

	return v_sum[n][k];
}


int main() {
	int n, k;               // 물건의 개수, 배낭의 무게

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &w[i], &v[i]);

	printf("%d\n", GetMaxValueSum(n, k));
	return 0;
}