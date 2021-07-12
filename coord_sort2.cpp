#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100000
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
} coord;

coord sorted[MAX_SIZE];

void merge(coord* arr, int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	/* 왼쪽, 오른쪽 배열 비교 후 정렬 */
	while (i <= mid && j <= right) {           
		if (arr[i].y < arr[j].y)
			sorted[k++] = arr[i++];
		else if (arr[i].y > arr[j].y)
			sorted[k++] = arr[j++];
		else {
			if (arr[i].x <= arr[j].x)
				sorted[k++] = arr[i++];
			else
				sorted[k++] = arr[j++];
		}
	}

	/* 왼쪽, 오른쪽 중 남은 값들 sorted 뒤에 대입 */
	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = arr[l];
	}
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = arr[l];
	}

	/* 원래 배열에 어느 정도 정렬된 sorted 대입 */
	for (l = left; l <= right; l++)
		arr[l] = sorted[l];
}

void merge_sort(coord* arr, int left, int right) {
	int mid;
	
	if (left < right) {
		mid = (left + right) / 2;           // 분할
		merge_sort(arr, left, mid);         // 정복
		merge_sort(arr, mid + 1, right);    // 정복
		merge(arr, left, mid, right);       // 합병
	}
}

int main() {
	int n, i;
	coord* loc;

	scanf("%d", &n);
	loc = (coord*)malloc(sizeof(coord) * n);
	
	for (i = 0; i < n; i++)
		scanf("%d %d", &loc[i].x, &loc[i].y);

	merge_sort(loc, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d %d\n", loc[i].x, loc[i].y);

	free(loc);

	return 0;
}