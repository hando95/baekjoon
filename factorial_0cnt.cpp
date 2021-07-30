#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 소인수 중 2 * 5의 수를 찾는 함수 */
int GetTwoAndFiveCnt(int n) {
	int num;
	int two_cnt = 0;
	int five_cnt = 0;

	if (n == 0)
		return 0;


	for (int i = n; i > 0; i--) {
		/* 2 세기 */
		if (i % 2 == 0) {
			num = i;
			while (num % 2 == 0) {
				two_cnt++;
				num /= 2;
			}
		}

		/* 5 세기 */
		if (i % 5 == 0) {
			num = i;
			while (num % 5 == 0) {
				five_cnt++;
				num /= 5;
			}
		}
	}
	return two_cnt < five_cnt ? two_cnt : five_cnt;
}


int main() {
	int n;
	scanf("%d", &n);

	printf("%d\n", GetTwoAndFiveCnt(n));
	return 0;
}