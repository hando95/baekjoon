#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int coin[10];

int GetCoinCnt(int n, int k) {
	int remain = k;
	int cnt = 0;

	for(int i = n - 1; i >= 0; i--) {
		cnt += (remain / coin[i]);
		remain %= coin[i];
	}
	return cnt;
}


int main() {
	int n, k;
	int cnt = 0;

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}

	printf("%d\n", GetCoinCnt(n, k));
	return 0;
}