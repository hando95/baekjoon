#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
SJF 알고리즘
실행시간이 짧은 순서대로 실행하는 알고리즘
-> 정렬한 후 조건에 맞게 출력
*/

int sorted[1000];

void merge(int* arr, int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
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

void merge_sort(int* arr, int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}


int GetWaitingTime(int* sorted_person, int n) {
	int time = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
			time += sorted_person[j];
	}

	return time;
}

int main() {
	int n;
	int* person;

	scanf("%d", &n);
	person = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &person[i]);

	merge_sort(person, 0, n - 1);

	printf("%d\n", GetWaitingTime(person, n));
}