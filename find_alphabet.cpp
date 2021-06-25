#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char word[100];
	int alphabet[26];
	int seq;
	int i = 0, j = 0; 
	scanf("%s", word);

	for (i = 0; i < 26; i++) {
		alphabet[i] = -1;
	}
	for (i = 0; i < 26; i++) {
		while ((word[j] != 'a' + i) && word[j] != '\0') {
			j++;
		}
		if( j != strlen(word))
			alphabet[i] = j;
		j = 0;
	}

	for (i = 0; i < 26; i++) {
		printf("%d ", alphabet[i]);
	}
}