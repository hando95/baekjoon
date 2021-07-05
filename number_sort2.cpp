#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 1000000
#include <stdio.h>
#include <stdlib.h>
int sorted[MAX_SIZE];

/*
합병 정렬 (분할 정복)
1) 배열의 길이가 0이나 1이면 정렬된 것으로 본다.
2) 정렬되지 않은 배열을 절반으로 잘라 비슷한 크기의 두 부분 리스트로 나눈다.
3) 각 부분 배열을 재귀적으로 합병 정렬을 이용해 정렬한다.
4) 두 부분 배열을 다시 하나의 정렬된 배열로 합병한다.
*/


/* 2개의 인접한 배열 arr[left...mid]와 arr[mid + 1...right]의 합병*/
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
	int n;
	int i = 0;
	int* arr;

	scanf("%d", &n);
	if (n < 1 || 1000000 < n) {
		printf("n의 범위 오류: %d\n", n);
		printf("1 이상 1000000 이하 범위로 입력하세요.\n");
		return 0;
	}

	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	merge_sort(arr, 0, n - 1);

	for (i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}

// reference: https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html