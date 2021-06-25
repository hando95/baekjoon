#include <stdio.h>

long long sum(int *a, int n) {
	long long ans = 0;
	int i = 0;
	for (i = 0; i < n; i++)
		ans += a[i];
	return ans;
}

int main() {
	int nums[5] = { 1,2,3,4,5 };
	printf("%lld\n", sum(nums, 5));

	return 0;
}