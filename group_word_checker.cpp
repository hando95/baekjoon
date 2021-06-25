#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int check_list[26] = { 0, };
	int num, i = 0, j = 0, cnt = 0, grp = 1;
	char word[100][101];
	char* p;

	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%s", word[i]);
	}


	for (i = 0; i < num; i++) {
		p = word[i]; // 문장의 처음

		while (*p != '\0') { // 문장의 끝까지 탐색

			if (*p != *(p + 1)) { // 다음 알파벳과 다를 때
				if (check_list[*p - 'a'] == 0) {
					check_list[*p - 'a']++;
					p++;
				}

				else {
					grp = 0; // 그룹이 아님
					break;
				}
			}
			else
				p++;
		}

		if (grp == 1) {    // 그룹이면 카운트
			cnt++;
		}
		else                // 그룹이 아니면 grp 1로 초기화
			grp = 1;

		for (j = 0; j < 26; j++)
			check_list[j] = 0;
	}


	printf("%d\n", cnt);
	return 0;
}