#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	int cnt = 0, six_con = 0;
	int movie = 0;
	int i = 0, num = 0;
	
	scanf("%d", &n);
	if (n > 10000 || n < 1) {
		printf("n 범위 오류: %d", n);
		return 0;
	}

	while(1) {
		num = i;                        // num에 현재 숫자 대입
		six_con = 0;
		while (num != 0) {
			if (num % 10 == 6)          // 뒷자리가 6이면
				six_con++;              // 6 연속 변수 + 1
			else                        // 뒷자리가 6이 아닐 때
				six_con = 0;            // 6 연속 변수 = 0
			
			if (six_con >= 3) {
				cnt++;
				break;
			}
			num /= 10;                  // 맨 뒷자리 없애기
		}

		if (cnt == n) {                 // n번째 종말 숫자면 나가기
			movie = i;
			break;
		}
		else 
			i++;
	}
	printf("%d\n", movie);
	return 0;
}