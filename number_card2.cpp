#define _CRT_SECURE_NO_WARNINGS
#define MAX_CARD_SIZE 500000
#define MAX_NUMBER_SIZE 500000
#include <stdio.h>

int card[MAX_CARD_SIZE];
int sorted[MAX_CARD_SIZE];
int number[MAX_NUMBER_SIZE];
int count = 0;

void Merge(int left, int mid, int right) {
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (card[i] <= card[j])
			sorted[k++] = card[i++];
		else
			sorted[k++] = card[j++];
	}

	if (i > mid) {
		for (int l = j; l <= right; l++)
			sorted[k++] = card[l];
	}
	else {
		for (int l = i; l <= mid; l++)
			sorted[k++] = card[l];
	}

	for (int l = left; l <= right; l++)
		card[l] = sorted[l];
}

void MergeSort(int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(left, mid);
		MergeSort(mid + 1, right);
		Merge(left, mid, right);
	}
}

/*
UpperBound
중간값이 key보다 더 작은 경우 + 같은 경우: start -> mid + 1
중간값이 key보다 더 큰 경우: end -> mid
** 같으면 제외하기가 핵심
*/
int UpperBound(int key, int size) {
	int mid;
	int start = 0;
	int end = size;

	while (start < end) {
		mid = (start + end) / 2;
		if (card[mid] <= key)
			start = mid + 1;
		else
			end = mid;
	}
	return start;
}

/*
LowerBound
중간값이 key보다 더 작은 경우: start -> mid + 1
중간값이 key보다 더 큰 경우 + 같은 경우: end -> mid
** 같으면 포함하기가 핵심
*/

int LowerBound(int key, int size) {
	int mid;
	int start = 0;
	int end = size;

	while (start < end) {
		mid = (start + end) / 2;
		if (card[mid] < key)
			start = mid + 1;
		else
			end = mid;
	}
	return start;
}


int main() {
	int n, m;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &card[i]);
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &number[i]);

	MergeSort(0, n - 1);


	for (int i = 0; i < m; i++) {
		printf("%d ", UpperBound(number[i], n) - LowerBound(number[i], n));
	}
	printf("\n");
	return 0;

}