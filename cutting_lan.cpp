#define _CRT_SECURE_NO_WARNINGS
#define MAX_LAN_CABLE 10000
#include <stdio.h>

long long lan[MAX_LAN_CABLE];

int LanCntOk(long long lan_len, int k, int n) {
	int cnt = 0;
	for (int i = 0; i < k; i++)
		cnt += (lan[i] / lan_len);

	/* 랜선 개수 조건 */
	if (cnt >= n)
		return 1;
	else
		return 0;
}

long long CutLan(long long min_lan_len, long long max_lan_len, int k, int n) {
	long long mid = 0;
	long long max = 0;

	while (min_lan_len <= max_lan_len) {
		mid = (min_lan_len + max_lan_len) / 2;

		/* 랜선 개수 조건 충족 시 더 긴 랜선 확인 */
		if (LanCntOk(mid, k, n)) {
			max = mid;
			min_lan_len = mid + 1;
		}
		
		/* 랜선 개수 조건 불충족 시 더 짧은 랜선 확인 */
		else
			max_lan_len = mid - 1;
	}
	return max;
}


int main() {
	int n, k;
	long long max_lan = 0;
	scanf("%d %d", &k, &n);

	for (int i = 0; i < k; i++) {
		scanf("%lld", &lan[i]);
		max_lan = max_lan < lan[i] ? lan[i] : max_lan;
	}

	printf("%lld\n", CutLan(1, max_lan, k, n));
	return 0;
}