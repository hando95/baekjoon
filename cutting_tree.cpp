#define _CRT_SECURE_NO_WARNINGS
#define MAX_TREE_NUM 1000000
#include <stdio.h>

long long trees[MAX_TREE_NUM];

int IsEnoughTree(long long cut_h, int n, int m) {
	long long len = 0;

	/* 절단한 나무 길이 합 */
	for (int i = 0; i < n; i++) {
		if(trees[i] > cut_h)
			len += (trees[i] - cut_h);
	}

	if (len >= m)
		return 1;
	else
		return 0;
}

long long FindMaxHeight(int min_h, int max_h, int n, int m) {
	long long mid = 0;
	long long result = 0;

	while (min_h <= max_h) {
		mid = (min_h + max_h) / 2;

		/* 자른 나무 길이가 충분하면 */
		if (IsEnoughTree(mid, n, m)) {
			result = mid;
			min_h = mid + 1;
		}

		/* 자른 나무 길이가 부족하면 */
		else
			max_h = mid - 1;
	}

	return result;
}


int main() {
	int n, m;     // 나무 수, 나무 높이
	int max_h = 0;
	scanf("%d %d", &n, &m);

	/* 나무 높이 입력과 동시에 확인할 높이 지정 */
	for (int i = 0; i < n; i++) {
		scanf("%lld", &trees[i]);
		max_h = max_h < trees[i] ? trees[i] : max_h;
	}

	printf("%lld\n", FindMaxHeight(0, max_h, n, m));
	return 0;
}