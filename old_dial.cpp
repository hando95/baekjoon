#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int sec(char a) { // seconds 반납 함수
	if ('A' <= a && 'C' >= a)
		return 3;
	else if ('D' <= a && 'F' >= a)
		return 4;
	else if ('G' <= a && 'I' >= a)
		return 5;
	else if ('J' <= a && 'L' >= a)
		return 6;
	else if ('M' <= a && 'O' >= a)
		return 7;
	else if ('P' <= a && 'S' >= a)
		return 8;
	else if ('T' <= a && 'V' >= a)
		return 9;
	else if ('W' <= a && 'Z' >= a)
		return 10;
}

int main() {
	char dial[16];
	int i = 0, len = 0, sum = 0;
	
	scanf("%s", dial);
	len = strlen(dial);

	for (i = 0; i < len; i++) {
		sum += sec(dial[i]);
	}

	printf("%d\n", sum);
	
	return 0;
}