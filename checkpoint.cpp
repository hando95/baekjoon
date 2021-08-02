#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
A[0] = (A[0] / M) * M + R
A[1] = (A[1] / M) * M + R
A[2] = (A[2] / M) * M + R
...
A[n - 1] - A[n] = M * (A[n - 1] / M - A[n] / M)

-> 각 수의 차이의 최대공약수 M 찾기
-> M의 약수 찾기
*/

int sorted[1000];

void Merge(int* arr, int left, int mid, int right) {
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
		for (l = i; l <= mid; l++) {
			sorted[k++] = arr[l];
		}
	}

	for (l = left; l <= right; l++)
		arr[l] = sorted[l];
}

void MergeSort(int* arr, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
}



int GetMax(int a, int b) {
	return a < b ? b : a;
}

int GetMin(int a, int b) {
	return a < b ? a : b;
}

int GetGCD(int a, int b) {
	int num1, num2, r;
	num1 = GetMax(a, b);
	num2 = GetMin(a, b);

	while (1) {
		r = num1 % num2;
		if (r == 0)
			return num2;
		else {
			num1 = num2;
			num2 = r;
		}
	}
}

int main() {
	int n, m , idx = 0;
	int m_gcd[1000];
	int num[100];


	scanf("%d", &n);
	scanf("%d", &num[0]);
	scanf("%d", &num[1]);
	m = abs(num[1] - num[0]);

	for (int i = 2; i < n; i++) {
		scanf("%d", &num[i]);
		m = GetGCD(abs(num[i] - num[i - 1]), m);
	}

	/* 절반만 검사 */
	for (int i = 2; i * i <= m; i++) {
		if (m % i == 0) {
			if (m / i == i) {
				m_gcd[idx++] = i;
			}
			else {
				m_gcd[idx++] = i;
				m_gcd[idx++] = m / i;
			}
		}
	}

	/* 정렬 후 출력 */
	MergeSort(m_gcd, 0, idx - 1);

	for (int i = 0; i < idx; i++)
		printf("%d ", m_gcd[i]);
	printf("%d ", m);
	printf("\n");
	return 0;
}