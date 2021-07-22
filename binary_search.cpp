#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


/* 이진탐색 함수 */
int BinarySearch(int* arr, int len, int key) {
	int left = 0;
	int right = len - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;

		if (key > arr[mid])
			left = mid + 1;
		else if (key < arr[mid])
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}


/* 앞에서부터 탐색하며 주어진 값보다 크거나 같으면 처음으로 나오는 인덱스를 찾는 함수 */
int LowerBound(int* arr, int len, int key) {
	int left = 0;
	int right = len;
	int mid;

	while (left < right) {
		mid = (left + right) / 2;
		if (key <= arr[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

/* 앞에서부터 탐색하며 주어진 값보다 큰 값이 처음으로 나오는 인덱스를 찾는 함수*/
int UpperBound(int* arr, int len, int key) {
	int left = 0;
	int right = len;
	int mid;

	while (left < right) {
		mid = (left + right) / 2;
		if (key >= arr[mid])
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

int main() {
	int arr[10] = { 1, 2, 2, 2, 3, 4, 4, 5, 6, 7 };

	printf("Sorted array: ");
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("Index of 5 by BinarySearch: %d\n", BinarySearch(arr, 10, 5));
	printf("LowerBound of 2: %d\n", LowerBound(arr, 10, 2));
	printf("UpperBound of 2: %d\n", UpperBound(arr, 10, 2));
}