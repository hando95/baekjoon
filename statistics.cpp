#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 500000
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int sorted[MAX_SIZE];


void merge(int* arr, int left, int mid, int right) {
	int i, j, k, l;
	i = left;                  // 정렬된 왼쪽 배열에 대한 인덱스
	j = mid + 1;               // 정렬된 오른쪽 배열에 대한 인덱스
	k = left;                  // 정렬된 배열에 대한 인덱스

	// 분할 정렬된 배열의 합병
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	// 남아있는 값들을 일괄 복사
	if (i > mid) {                      // 왼쪽 배열 인덱스가 먼저 끝났으면
		for (l = j; l <= right; l++)    // 오른쪽 배열 남은 값을 sorted 뒤에 복사
			sorted[k++] = arr[l];
	}
	else {
		for (l = i; l <= mid; l++)      // 오른쪽 배열 인덱스가 먼저 끝났으면
			sorted[k++] = arr[l];       // 왼쪽 배열 남은 값을 sorted 뒤에 복사
	}

	// sorted를 arr에 재복사
	for (l = left; l <= right; l++)
		arr[l] = sorted[l];
}

void merge_sort(int* arr, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;        // 리스트 균등 분할 - divide
		merge_sort(arr, left, mid);      // 왼쪽 부분 정렬 - conquer
		merge_sort(arr, mid + 1, right); // 오른쪽 부분 정렬 - conquer
		merge(arr, left, mid, right);    // 정렬된 2개의 부분 배열 합병 - combine
	}
}


int main() {
	int n, max = -4001, min = 4001, i = 0, j = 0;
	int idx = 0, second = 0, max_mode = 0;
	double sum = 0;
	int avg, med, mode, rng;
	int* nums;
	int count[8001] = { 0, };

	scanf("%d", &n);
	nums = (int*)malloc(sizeof(int) * n);      // 수 배열 초기화
	for (i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
		if (nums[i] < min)                     // 최소, 최대
			min = nums[i];
		if (nums[i] > max)
			max = nums[i];
		sum += (double)nums[i];                // 산술평균을 위해 합 구하기
		count[nums[i] + 4000]++;               // 최빈값을 위해 수 세기
	}

	merge_sort(nums, 0, n - 1);                // 합병정렬

	rng = max - min;                           // 범위
	avg = (int)round(sum / (double) n);        // 산술평균
	med = nums[n / 2];                         // 중앙값

	for (i = 0; i < n; i++) {
		if (count[nums[i] + 4000] >= max_mode)
			max_mode = count[nums[i] + 4000];
	}


	for (i = 0; i < 8001; i++) {
		if (count[i] == 0)
			continue;
		if (count[i] == max_mode) {
			if (second == 0) {                 // 중복 체크
				idx = i;
				second = 1;
			}
			else {                             // 중복이 있으면 최빈값 중 가장 작은 값
				idx = i;
				break;
			}
		}
	}
	mode = idx - 4000;                         // 최빈값

	printf("%d\n", avg);
	printf("%d\n", med);
	printf("%d\n", mode);
	printf("%d\n", rng);

	return 0;

}