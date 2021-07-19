#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long padovan[101] = { 0, 1, 1, 1, };

long long GetPadovan(int n) {
	int i;

	if (n < 3)
		return padovan[n];
	else {
		if (padovan[n])                        // 이미 계산한 결과가 있으면 리턴
			return padovan[n];

		for (i = 4; i <= n; i++)               // 계산 결과가 없으면 계산 후 리턴
			padovan[i] = padovan[i - 2] + padovan[i - 3];
		return padovan[n];
	}
}

int main() {
	int t , i;
	int t_case[100];

	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &t_case[i]);
		printf("%lld\n", GetPadovan(t_case[i]));
	}
	return 0;
}