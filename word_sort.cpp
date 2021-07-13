#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 20000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	char str[51];
	int len;
}word;

word sorted[MAX_SIZE];


void merge(word* arr, int left, int mid, int right) {
	int i, j, k, l, m;
	int cmp;
	i = left;
	j = mid + 1;
	k = left;


	while (i <= mid && j <= right) {
		if (arr[i].len < arr[j].len)
			sorted[k++] = arr[i++];
		else if (arr[i].len > arr[j].len)
			sorted[k++] = arr[j++];
		else {
			cmp = strcmp(arr[i].str, arr[j].str);      // ASCII 코드 기준 앞이 크면 1, 같으면 0, 뒤가 크면 -1
			if (cmp < 0)                             // 뒤가 크다 = 앞이 사전순 앞이다 
				sorted[k++] = arr[i++];
			else                                       // 앞이 크다 = 뒤가 사전순 앞이다
				sorted[k++] = arr[j++];
		}
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

void merge_sort(word* arr, int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;           // 분할
		merge_sort(arr, left, mid);         // 정복
		merge_sort(arr, mid + 1, right);    // 정복
		merge(arr, left, mid, right);       // 합병
	}
}

int main() {
	int n, i, j, cmp;
	word temp;
	word* words;
	
	scanf("%d", &n);
	words = (word*)malloc(sizeof(word) * n);  // 동적 할당

	for (i = 0; i < n; i++) {
		scanf("%s", words[i].str);
		words[i].len = strlen(words[i].str);
	}

	merge_sort(words, 0, n - 1);
	

	printf("%s\n", words[0].str);
	for (i = 1; i < n; i++) {
		cmp = strcmp(words[i - 1].str, words[i].str);
		if(cmp != 0)
			printf("%s\n", words[i].str);
	}

	free(words);                             // 할당 해제

	return 0;
}