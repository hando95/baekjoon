#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int t, w, h, n, room_no1, room_no2;
	int i = 0, j = 0;

	scanf("%d", &t);                // 테스트케이스 수
	for (i = 0; i < t; i++) {
		scanf("%d %d %d", &h, &w, &n);  // 층, 방, 사람
		if (w < 1 || h < 1 || 99 < w || 99 < h) {
			printf("방 또는 층 개수 오류");
			return 0;
		}

		if (n < 1 || n > w * h) {
			printf("사람 수 오류");
			return 0;
		}

		room_no2 = (n % h) == 0 ? n / h : (n / h) + 1; // 방 뒤 호수 계산
		room_no1 = (n % h) == 0 ? h : n % h;  // 방 앞 층 계산
		printf("%d\n",room_no1 * 100 + room_no2);
	}
	
	return 0;
}