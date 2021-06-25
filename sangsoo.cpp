#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	char a_num[4], b_num[4];
	char a_rev[4], b_rev[4];
	int sang_a, sang_b, i = 0;
	scanf("%s %s", a_num, b_num);

	for (i = 0; i < 4; i++) {  // 수 뒤집기
		a_rev[i] = a_num[2 - i];
		b_rev[i] = b_num[2 - i];
	}
	sang_a = atoi(a_rev);
	sang_b = atoi(b_rev);

	if (sang_a < sang_b)
		printf("%d\n", sang_b);
	else
		printf("%d\n", sang_a);

	return 0;
}