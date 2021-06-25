#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char a[10002];
	char b[10002];
	char ans[10003] = { 0, };
	int x, y, a_len, b_len, t_num;
	int i = 0;
	
	scanf("%s %s", a, b);  // a, b를 문자열로 입력
	a_len = strlen(a) - 1;
	b_len = strlen(b) - 1;

	while (a_len >= 0 || b_len >= 0) {
		x = (a_len >= 0) ? (a[a_len] - '0') : 0;   // 숫자로 변환
		y = (b_len >= 0) ? (b[b_len] - '0') : 0;   // 숫자로 변환
		t_num = ans[i] + x + y;  // 올림값 + 해당 자리값 덧셈
		ans[i] = t_num % 10;     // 자리값 덧셈 - 올림 값
		ans[i + 1] = t_num / 10; // 올림 값을 다음 값에 넣어줌

		i++;       // i는 한 칸 증가
		a_len--;   // 다음 자리수로
		b_len--;   // 다음 자리수로
	}

	if (ans[i] == 0) // 마지막에 올림값이 없다면 i를 1 감소
		i--;

	for (; i >= 0; i--)
		printf("%d", ans[i]);
	printf("\n");
	return 0;
}