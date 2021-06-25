#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char word[1000000];
	char most_used;
	int used_cnt, len = 0, same = -1;
	int alphabet[26] = { 0, };
	int i = 0, j = 0;

	scanf("%s", word);
	len = strlen(word);
	for (i = 0; i < len; i++) {
		if (word[i] >= 'a' && word[i] <= 'z') // 소문자 -> 대문자
			word[i] -= 32;
		alphabet[word[i] - 'A']++; // 해당 알파벳 수 증가
	}

	most_used = 'A';
	used_cnt = alphabet[0];

	for (i = 0; i < 26; i++) { // 사용횟수 비교
		if (used_cnt < alphabet[i]) {
			most_used = 'A' + i;
			used_cnt = alphabet[i];
		}
	}

	for (i = 0; i < 26; i++) { // 같은 개수 체크
		if (used_cnt == alphabet[i])
			same++;
	}

	if (same > 0) {
		printf("?\n");
	}
	else
		printf("%c", most_used);

	return 0;
}