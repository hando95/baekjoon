#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int oper_cnt[1000001];

int GetMin(int a, int b) {
	return a < b ? a : b;
}

int GetOperMinCnt(int n) {

	oper_cnt[1] = 0;
	
	if (n == 1)
		return 0;

	for (int i = 2; i <= n; i++) {

		if (i % 3 == 0 && i % 2 == 0) {
			oper_cnt[i] = GetMin(GetMin(oper_cnt[i / 3] + 1, oper_cnt[i / 2] + 1), oper_cnt[i - 1] + 1);
		}
		else if (i % 3 == 0 && i % 2 != 0) {
			oper_cnt[i] = GetMin(oper_cnt[i / 3] + 1, oper_cnt[i - 1] + 1);
		}
		else if (i % 3 != 0 && i % 2 == 0) {
			oper_cnt[i] = GetMin(oper_cnt[i / 2] + 1, oper_cnt[i - 1] + 1);
		}
		else
			oper_cnt[i] = oper_cnt[i - 1] + 1;

	}
	return oper_cnt[n];
}


int main() {
	int n;

	scanf("%d", &n);
	printf("%d\n", GetOperMinCnt(n));
	return 0;
}