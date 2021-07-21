#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int seq_a[1000];
int seq_cnt[1000];

int GetMax(int a, int b) {
	return a < b ? b : a;
}

int GetLongSeq(int n) {
	int result = 1;

	seq_cnt[0] = 1;

	for (int i = 1; i < n; i++) {
		seq_cnt[i] = 1;
		for (int j = 0; j < i; j++) {
			if (seq_a[i] > seq_a[j]) {                                 // 이전의 수가 현재 수보다 작다면
				seq_cnt[i] = GetMax(seq_cnt[i], seq_cnt[j] + 1);       // 해당 수가 가지고 있는 증가하는 수열의 길이 비교
			}
		}
		result = GetMax(result, seq_cnt[i]);
	}
	return result;
}


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq_a[i]);
	}
	printf("%d\n", GetLongSeq(n));
	return 0;
}