#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100000
#include <stdio.h>

int sorted[MAX_SIZE];
int num[MAX_SIZE];
int key[MAX_SIZE];

/* 병합 */
void Merge(int left, int mid, int right) {
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (num[i] <= num[j])
			sorted[k++] = num[i++];
		else
			sorted[k++] = num[j++];
	}

	if (i > mid) {
		for (int l = j; l <= right; l++)
			sorted[k++] = num[l];
	}
	else {
		for (int l = i; l <= mid; l++)
			sorted[k++] = num[l];
	}

	for (int l = left; l <= right; l++)
		num[l] = sorted[l];
}

/* 병합정렬 */
void MergeSort(int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(left, mid);
		MergeSort(mid + 1, right);
		Merge(left, mid, right);
	}
}

int BinarySearch(int key, int left, int right) {
	int mid = (left + right) / 2;

	/* 찾지 못 하면 0 */
	if (left > right)
		return -1;

	if (num[mid] == key)
		return mid;
	else if (num[mid] > key)
		return BinarySearch(key, left, mid - 1);
	else if (num[mid] < key)
		return BinarySearch(key, mid + 1, right);
}

int main() {
	int n, find_n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	
	scanf("%d", &find_n);
	for (int i = 0; i < find_n; i++) {
		scanf("%d", &key[i]);

	}

	/* 병합정렬 */
	MergeSort(0, n - 1);

	/* 이분탐색 */
	for (int i = 0; i < find_n; i++) {
		if (BinarySearch(key[i], 0, n - 1) == -1)
			printf("0\n");
		else
			printf("1\n");
	}
}