#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, v;
	int remain, cur = 0, day = 0;

	scanf("%d %d %d", &a, &b, &v);
	
	if (a > 1000000000 || b > 1000000000 || v > 1000000000) {
		printf("수가 너무 큽니다.");
		return 0;
	}

	if (b < 1 || a <= b || v <= b || a > v) {
		printf("범위가 틀립니다.");
		return 0;
	}

	remain = v - a;   // 마지막 도약거리를 뺀 나머지 부분
	day = remain % (a - b) == 0 ? remain / (a - b) : remain / (a - b) + 1; // 나머지 부분은 올라가고 내려가며 하루가 지나감
	day++; // 마지막에 a칸 올라가면 정상

	printf("%d\n", day);
	return 0;
}