#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
파스칼의 삼각형 응용
*/

int bridge_num[30][30] = { 0, };    // [M site][N site]

void MemoBridgeNum(int m_site) {
	bridge_num[1][0] = 1;     // 1 Combination 0
	bridge_num[1][1] = 1;     // 1 Combination 1
	
	if (m_site == 1)
		return;

	for (int i = 2; i <= m_site; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				bridge_num[i][j] = bridge_num[i - 1][j];
			else if (j == i)
				bridge_num[i][j] = bridge_num[i - 1][i - 1];
			else
				bridge_num[i][j] = bridge_num[i - 1][j - 1] + bridge_num[i - 1][j];
		}
	}
}

int main() {
	int t, n, m;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		MemoBridgeNum(m);
		printf("%d\n", bridge_num[m][n]);
	}
	return 0;
}