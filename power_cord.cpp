#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cord[501] = { 0, };
int cnt[501];

int GetMax(int a, int b) {
	return a < b ? b : a;
}

int GetDeleteCordNum(int line_n, int a_max_num) {
	int cord_max = 0;
	cnt[0] = 0;

	/* 증가하는 전깃줄 번호 수열의 최대 길이 */
	for (int i = 1; i <= a_max_num; i++) {
		if (cord[i] == 0)  // 해당 번호에 전깃줄 없으면 건너뛰기
			continue;

		cnt[i] = 1;
		for (int j = 1; j < i; j++) {
			if (cord[i] > cord[j])
				cnt[i] = GetMax(cnt[i], cnt[j] + 1);
		}
		cord_max = GetMax(cnt[i], cord_max);
	}
	return line_n - cord_max;
}

int main() {
	int line_n;
	int a_num, b_num;
	int a_max_num = 0;
	scanf("%d", &line_n);
	
	/* cord[A번호] = B번호 */
	for (int i = 0; i < line_n; i++) {
		scanf("%d %d", &a_num, &b_num);
		cord[a_num] = b_num;
		a_max_num = GetMax(a_num, a_max_num);
	}

	printf("%d\n", GetDeleteCordNum(line_n, a_max_num));
	return 0;
}