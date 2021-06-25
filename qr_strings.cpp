#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int test_num;
	int r, i = 0, j = 0, k = 0;
	char s[20];
	scanf("%d", &test_num);

	for (i = 0; i < test_num; i++) { // 테스트 수만큼 반복
		scanf("%d %s", &r, &s);

		for (j = 0; j < strlen(s); j++) { // 문자 수만큼 반복
			for (k = 0; k < r; k++) {
				printf("%c", s[j]);
			}
		}
		printf("\n");
	}

	return 0;
}
