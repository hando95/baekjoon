#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int oper[4];
int max = -1000000000;
int min = 1000000000;

/* 최대, 최소 */
int MaxResult(int a, int b) {
	return a < b ? b : a;
}

int MinResult(int a, int b) {
	return a < b ? a : b;
}

void BackTrackingDFS(int* nums, int n, int oper_cnt, int result) {
	int i;

	if (oper_cnt == n - 1) {                  // 연산자 수가 n - 1이면 종료
		max = MaxResult(max, result);
		min = MinResult(min, result);
		return;
	}

	for (i = 0; i < 4; i++) {                 // 덧셈, 뺄셈, 곱셈, 나눗셈 한 번씩 검사
		if (oper[i] > 0) {
			oper[i]--;                        // 방문 처리
			if(i == 0)                        // 덧셈
				BackTrackingDFS(nums, n, oper_cnt + 1, result + nums[oper_cnt + 1]);
			else if(i == 1)                   // 뺄셈
				BackTrackingDFS(nums, n, oper_cnt + 1, result - nums[oper_cnt + 1]);
			else if(i == 2)                   // 곱셈
				BackTrackingDFS(nums, n, oper_cnt + 1, result * nums[oper_cnt + 1]);
			else                              // 나눗셈
				BackTrackingDFS(nums, n, oper_cnt + 1, result / nums[oper_cnt + 1]);
			oper[i]++;                        // 미방문 처리
		}
	}
	return;
}

int main() {
	int n, i;
	int nums[11];
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	scanf("%d %d %d %d", &oper[0], &oper[1], &oper[2], &oper[3]);

	BackTrackingDFS(nums, n, 0, nums[0]);
	printf("%d\n", max);
	printf("%d\n", min);

	return 0;
}