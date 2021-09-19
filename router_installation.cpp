#define _CRT_SECURE_NO_WARNINGS
#define MAX_HOUSE_NUM 200000
#include <stdio.h>

int x[MAX_HOUSE_NUM];             // 집의 좌표
int distance[MAX_HOUSE_NUM - 1];  // 집과 집 사이의 거리
int sorted[MAX_HOUSE_NUM];

void Merge(int left, int mid, int right) {
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (x[i] <= x[j])
			sorted[k++] = x[i++];
		else
			sorted[k++] = x[j++];
	}

	if (i > mid) {
		for (int l = j; l <= right; l++)
			sorted[k++] = x[l];
	}
	else {
		for (int l = i; l <= mid; l++)
			sorted[k++] = x[l];
	}

	for (int l = left; l <= right; l++)
		x[l] = sorted[l];
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

/* 공유기 설치 */
int InstallingRouter(int low, int high, int n, int c) {
	int mid = 0;
	int cnt;
	int sx;
	int result = -1;

	while (low <= high) {
		mid = (low + high) / 2;
		cnt = 1;   // 맨 앞 집에 공유기 설치
		sx = x[0];

		for (int i = 1; i < n; i++) {
			if (mid <= (x[i] - sx)) {
				cnt++;
				sx = x[i];
			}
		}

		/* 설치할 수 있는 공유기 개수가 원래보다 더 많으면 거리 넓히기 */
		if (cnt >= c) {
			result = mid;
			low = mid + 1;
		}

		/* 설치할 수 있는 공유기 개수가 원래보다 더 적으면 거리 좁히기 */
		else {
			high = mid - 1;
		}
	}
	return result;
}

int main() {
	int n, c;    // 집 개수, 공유기 개수
	int end_to_end = 0;

	scanf("%d %d", &n, &c);
	
	/* 집 좌표 저장 */
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);

	/* 오름차순 정렬 */
	MergeSort(0, n - 1);

	/* 최대 간격 저장 */
	end_to_end = x[n - 1] - x[0];

	/* 가장 인접한 두 공유기 사이의 최대 거리 출력 */
	printf("%d\n", InstallingRouter(1, end_to_end, n, c));
	
	return 0;
}