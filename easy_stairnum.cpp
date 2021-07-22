#define _CRT_SECURE_NO_WARNINGS
#define MOD 1000000000
#include <stdio.h>


int stair_num[100][10];  // [길이][0 ~ 9]

long GetStairNumCnt(int n) {
	long sum = 0;

	stair_num[0][0] = 0;
	for (int i = 1; i < 10; i++) {
		stair_num[0][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)																	  // 현재 수가 0이면 이전 수는 무조건 1
				stair_num[i][j] = stair_num[i - 1][j + 1];
			else if (j == 9)															  // 현재 수가 9이면 이전 수는 무조건 8
				stair_num[i][j] = stair_num[i - 1][j - 1];
			else                                                                          // 현재 수가 예를 들어 3이면 이전 수는 2와 4까지의 계단 수의 합
				stair_num[i][j] = (stair_num[i - 1][j - 1] + stair_num[i - 1][j + 1]) % MOD;
		}
	}

	for (int i = 0; i < 10; i++) {
		sum = (sum + stair_num[n - 1][i]) % MOD;
	}
	
	return sum;
}

int main() {
	int n;
	
	scanf("%d", &n);
	printf("%ld\n", GetStairNumCnt(n));
	return 0;
}