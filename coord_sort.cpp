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
	i = left;                                // 정렬된 왼쪽 배열 인덱스
	j = mid + 1;                             // 정렬된 오른쪽 배열 인덱스
	k = left;                                // sorted 인덱스

	while (i <= mid && j <= right) {
		if (arr[i].x < arr[j].x)             // x좌표 중 왼쪽이 작으면 sorted에 왼쪽 값 대입
			sorted[k++] = arr[i++];          
		else if(arr[i].x > arr[j].x)         // x좌표 중 오른쪽이 작으면 sorted에 오른쪽 값 대입
			sorted[k++] = arr[j++];
		else {                               // x좌표가 같으면
			if (arr[i].y <= arr[j].y)        // y좌표 중 왼쪽이 작으면 sorted에 왼쪽 값 대입
				sorted[k++] = arr[i++];
			else                             // y좌표 중 오른쪽이 작으면 sorted에 오른쪽 값 대입
				sorted[k++] = arr[j++];
		}
	}

	if (i > mid) {                           // 왼쪽 배열 인덱스 끝
		for (l = j; l <= right; l++)         // 오른쪽 배열에 남은 값 sorted 뒤에 복사
			sorted[k++] = arr[l];
	}
	else {                                   // 오른쪽 배열 인덱스 끝
		for (l = i; l <= mid; l++)           // 왼쪽 배열에 남은 값 sorted 뒤에 복사
			sorted[k++] = arr[l];            
	}

	for (l = left; l <= right; l++)          // arr에 sorted 복사
		arr[l] = sorted[l];
}

void merge_sort(coord* arr, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;            // 배열 균등 분할 - divide
		merge_sort(arr, left, mid);          // 왼쪽 배열 정렬 - conquer
		merge_sort(arr, mid + 1, right);     // 오른쪽 배열 정렬 - conquer
		merge(arr, left, mid, right);        // 정렬된 2개의 부분 배열 합병 - combine
	}
}

int main() {
	int n, i;
	coord* loc;
	scanf("%d", &n);

	loc = (coord*)malloc(sizeof(coord) * n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &loc[i].x, &loc[i].y);
	}

	merge_sort(loc, 0, n - 1);

	for (i = 0; i < n; i++) {
		printf("%d %d\n", loc[i].x, loc[i].y);
	}

	free(loc);
}

// reference: https://daydreamx.tistory.com/entry/baekjoon11650