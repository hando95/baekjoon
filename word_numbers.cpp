#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char senten[1000001];
	int i = 0, len = 0, start = 0, word_cnt = 0;
	scanf("%[^\n]", senten);
	len = strlen(senten);

	for (i = 0; i < len; i++) {
		if (senten[i] != ' ' && (senten[i + 1] == ' ' || senten[i + 1] == '\0')) {
			// 현재 공백이 아닐 때 다음 칸이 공백이거나 문장의 끝이라면
			word_cnt++;
		}
	}
	printf("%d\n", word_cnt);

	return 0;
}