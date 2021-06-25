#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, cnt_5 = 0, cnt_3 = 0, remain;
	scanf("%d", &n);
	
	if (n < 3 || 5000 < n) {  // 범위 오류
		printf("너무 가볍거나 무겁습니다.");
		return 0;
	}

	cnt_5 = n / 5;   // 5kg 봉지 최대 개수
	remain = n % 5;  // 남은 kg 수
	
	while (3 * cnt_3 + 5 * cnt_5 != n) {
		if (cnt_5 < 0) {
			break;
		}
		
		if (remain % 3 == 0) {
			cnt_3 = remain / 3; // 나누어 떨어지면 3kg 봉지 개수
		}
		else {
			cnt_5--;          // 5kg 봉지 하나 빼고
			remain += 5;      // 남은 kg 수 5 증가
		}
	}

	if (cnt_5 < 0)
		printf("%d\n", -1);
	else
		printf("%d\n", cnt_3 + cnt_5);
	return 0;
}