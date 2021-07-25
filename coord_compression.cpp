#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 1000000
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int order;
}coord;

coord sorted[MAX_SIZE];
int answer[1000000];

/* 병합 정렬 */
void merge(coord* arr, int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (arr[i].x <= arr[j].x)
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = arr[l];
	}
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = arr[l];
	}

	for (l = left; l <= right; l++)
		arr[l] = sorted[l];
}


void merge_sort(coord* arr, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;        // 리스트 균등 분할 - divide
		merge_sort(arr, left, mid);      // 왼쪽 부분 정렬 - conquer
		merge_sort(arr, mid + 1, right); // 오른쪽 부분 정렬 - conquer
		merge(arr, left, mid, right);    // 정렬된 2개의 부분 배열 합병 - combine
	}
}


int main() {
	int n, cnt = 0;
	int cur;
	coord* x_list;

	scanf("%d", &n);
	x_list = (coord*)malloc(sizeof(coord) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x_list[i].x);          // 좌표 입력
		x_list[i].order = i;                // 순서 기억
	}

	merge_sort(x_list, 0, n - 1);


	/* 현재 좌표와 이전 좌표를 비교하면서 순서 정하기 */
	cnt = 0;
	cur = x_list[0].x;                      // 정렬된 첫 번째 x좌표를 cur로 설정

	for (int i = 0; i < n; i++) {
		if (x_list[i].x != cur)             // 현재 좌표와 cur가 다르면 cnt 증가
			cnt++;
		answer[x_list[i].order] = cnt;      // 현재 좌표 순서에 cnt 저장
		cur = x_list[i].x;                  // 다음 좌표로 이동
	}

	for (int i = 0; i < n; i++)
		printf("%d ", answer[i]);
	printf("\n");
	return 0;
}