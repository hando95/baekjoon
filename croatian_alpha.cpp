#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char line[101];
	int i = 0, word_cnt = 0;
	scanf("%s", line);

	while (line[i] != '\0') { // 문장의 끝까지 탐색

		if (line[i] == 'c') { // c가 나오면
			if (line[i + 1] == '=' || line[i + 1] == '-') {
				word_cnt++;
				i += 2;
				continue;
			}
			else {
				word_cnt++;
				i++;
				continue;
			}
		}

		if (line[i] == 'd') { // d가 나오면
			if (line[i + 1] == 'z' && line[i + 2] == '=') {
				word_cnt++;
				i += 3;
				continue;
			}
			else if (line[i + 1] == '-') {
				word_cnt++;
				i += 2;
				continue;
			}
			else {
				word_cnt++;
				i++;
				continue;
			}
		}

		if (line[i] == 'l' || line[i] == 'n') { // ㅣ 또는 j가 나오면
			if (line[i + 1] == 'j') {
				word_cnt++;
				i += 2;
				continue;
			}
			else {
				word_cnt++;
				i++;
				continue;
			}
		}

		if (line[i] == 's' || line[i] == 'z') { // s 또는 z가 나오면
			if (line[i + 1] == '=') {
				word_cnt++;
				i += 2;
				continue;
			}
			else {
				word_cnt++;
				i++;
				continue;
			}
		}

		word_cnt++;
		i++;
	}
	printf("%d\n", word_cnt);
	return 0;
}