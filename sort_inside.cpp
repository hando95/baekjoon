#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void sort_desc(int* arr, int len) {
	int i, j, temp = 0;
	for (i = 0; i < len; i++) {
		for (j = i; j < len; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


int main() {
	int n, i = 0, len = 0;
	int nums[10] = { 0, };
	scanf("%d", &n);
	
	while (1) {                            // 각 자리수로 배열 초기화
		if (n / 10 == 0) {
			nums[i] = n;
			break;
		}
		else {
			nums[i] = n % 10;
			n = n / 10;
			i++;
		}
	}
	len = i + 1;
	sort_desc(nums, len);

	for (i = 0; i < len; i++)
		printf("%d", nums[i]);

	return 0;
}