#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
버블 정렬
매번 연속된 두 개의 인덱스를 비교하여 정렬
비교시마다 큰 값이 뒤로 이동하여 큰 값부터 배치
*/

void sort_asc(int* nums, int len) {
	int i = 0, j = 0, temp = 0;
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < len; i++) {
		printf("%d\n", nums[i]);
	}
}


int main() {
	int n, i = 0;
	int* nums;
	scanf("%d", &n);
	nums = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}

	sort_asc(nums, n);
	return 0;
}