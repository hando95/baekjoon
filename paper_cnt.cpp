#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int minus_one = 0;
int zero = 0;
int one = 0;


int CheckPaper(int** paper, int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (paper[x][y] != paper[i][j])
				return 0;
		}
	}
	return 1;
}


void CutPaper(int** paper, int x, int y, int n) {
	if (paper[x][y] == -1 && CheckPaper(paper, x, y, n)) {
		minus_one++;
		return;
	}

	if (paper[x][y] == 0 && CheckPaper(paper, x, y, n)) {
		zero++;
		return;
	}
	if (paper[x][y] == 1 && CheckPaper(paper, x, y, n)) {
		one++;
		return;
	}

	CutPaper(paper, x, y, (n / 3));                               // 1번 칸
	CutPaper(paper, x, y + (n / 3), (n / 3));                     // 2번 칸
	CutPaper(paper, x, y + (2 * n / 3), (n / 3));                 // 3번 칸
	CutPaper(paper, x + (n / 3), y, (n / 3));                     // 4번 칸
	CutPaper(paper, x + (n / 3), y + (n / 3), (n / 3));           // 5번 칸
	CutPaper(paper, x + (n / 3), y + (2 * n / 3), (n / 3));       // 6번 칸
	CutPaper(paper, x + (2 * n / 3), y, (n / 3));                 // 7번 칸
	CutPaper(paper, x + (2 * n / 3), y + (n / 3), (n / 3));       // 8번 칸
	CutPaper(paper, x + (2 * n / 3), y + (2 * n / 3), (n / 3));   // 9번 칸
}


int main() {
	int n;
	int** paper;

	scanf("%d", &n);
	paper = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		paper[i] = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	CutPaper(paper, 0, 0, n);

	printf("%d\n%d\n%d\n", minus_one, zero, one);
	
	for (int i = 0; i < n; i++)
		free(paper[i]);
	free(paper);
	
	return 0;
	
}