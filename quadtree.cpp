#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char str[64][64];
int image[64][64];

int CheckImage(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if(image[x][y] != image[i][j])
				return 0;
		}
	}
	return 1;
}

void PrintImage(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			printf("%c", str[i][j]);
		}
	}
}

void Compress(int x, int y, int n) {
	
	/* 하얀색 */
	if (image[x][y] == 0 && CheckImage(x, y, n)) {
		printf("%c", '0');
		return;
	}

	/* 검은색 */
	if (image[x][y] == 1 && CheckImage(x, y, n)) {
		printf("%c", '1');
		return;
	}
	printf("(");
	Compress(x, y, n / 2);                       // 좌상
	Compress(x, y + (n / 2), n / 2);             // 우상
	Compress(x + (n / 2), y, n / 2);             // 좌하
	Compress(x + (n / 2), y + (n / 2), n / 2);   // 우하
	printf(")");
}


int main() {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
		for (int j = 0; j < n; j++) {
			image[i][j] = str[i][j] - '0';
		}
	}

	Compress(0, 0, n);
	printf("\n");
	return 0;
}