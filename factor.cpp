#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void sort(int* nums, int cnt) {
	int temp;

	for (int i = 0; i < cnt; i++) {
		for (int j = i; j < cnt; j++) {
			if (nums[i] > nums[j]) {
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
}

int FindNumberByFactor(int* nums, int cnt) {
	int n;
	
	sort(nums, cnt);                    // 정렬 후
	n = nums[0] * nums[cnt - 1];        // 맨 앞 수와 맨 뒷 수 곱하기

	return n;
}

int main() {
	int cnt;
	int* nums;
	scanf("%d", &cnt);
	nums = (int*)malloc(sizeof(int) * cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d", &nums[i]);
	}

	printf("%d\n", FindNumberByFactor(nums, cnt));
	return 0;
}