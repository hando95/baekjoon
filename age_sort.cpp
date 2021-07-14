#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100000
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[101];
	int age;
	int order;
}member;

member sorted[MAX_SIZE];

void merge(member* arr, int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (arr[i].age < arr[j].age)
			sorted[k++] = arr[i++];
		else if (arr[i].age > arr[j].age)
			sorted[k++] = arr[j++];
		else {
			if (arr[i].order < arr[j].order)
				sorted[k++] = arr[i++];
			else
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

	for (l = left; l <= right; l++) {
		arr[l] = sorted[l];
	}
}

void merge_sort(member* arr, int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}


int main() {
	int n, i, j;
	member* mem;

	scanf("%d", &n);
	mem = (member*)malloc(sizeof(member) * n);

	for (i = 0; i < n; i++) {
		scanf("%d %s", &mem[i].age, mem[i].name);
		mem[i].order = i;
	}

	merge_sort(mem, 0, n - 1);

	for (i = 0; i < n; i++) {
		printf("%d %s\n", mem[i].age, mem[i].name);
	}

	free(mem);
	return 0;
}