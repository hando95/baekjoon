#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long GetMinGasPrice(long long* dis, long long* price, int n) {
	long long won = 0;   // 총 가격
	int cur = 0;   // 현재 위치
	
	/* 가격 검사 */
	for (int i = cur + 1; i <= n - 1; i++) {
		if (price[cur] <= price[i]) {          // 현재 도시 가격이 같거나 더 저렴하면
			won += (price[cur] * dis[i - 1]);  // 현재 도시에서 다음 도시까지 거리만큼 주유
		}
		
		else {                                 // 다음 도시 가격이 더 저렴하면
			won += (price[cur] * dis[i - 1]);  // 현재 도시에서 다음 도시까지 거리만큼 주유
			cur = i;                           // 다음 도시로 이동
		}
	}
	return won;
}



int main() {
	int n;              // 도시 수
	long long* dis;     // 거리
	long long* price;   // 가격

	scanf("%d", &n);
	dis = (long long*)malloc(sizeof(long long) * (n - 1));
	price = (long long*)malloc(sizeof(long long) * n);

	for (int i = 0; i < n - 1; i++) {
		scanf("%lld", &dis[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &price[i]);
	}

	printf("%lld\n", GetMinGasPrice(dis, price, n));
	return 0;
}