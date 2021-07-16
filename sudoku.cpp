#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int solved = 0;                                  // 스도쿠판 여러 개 중 하나만 출력하는 장치

/* 스도쿠 출력 함수 */
void PrintSudoku(int** sudoku) {
	int i, j;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			printf("%d ", sudoku[i][j]);
		}
		printf("\n");
	}
}

/* 행 검사 함수 */
int RowCheck(int** sudoku, int row, int num) {
	int i;

	// 해당 수가 있으면 1 없으면 0
	for (i = 0; i < 9; i++) {
		if (sudoku[row][i] == num) {
			return 1;
		}
	}
	return 0;
}

/* 열 검사 함수 */
int ColCheck(int** sudoku, int col, int num) {
	int i;

	// 해당 수가 있으면 1 없으면 0
	for (i = 0; i < 9; i++) {
		if (sudoku[i][col] == num) {
			return 1;
		}
	}
	return 0;
}

/* 사각형 검사 함수 */
int SquareCheck(int** sudoku, int x, int y, int num) {
	int x_init = (x / 3) * 3, y_init = (y / 3) * 3;
	int i, j;

	// 해당 수가 있으면 1 없으면 0
	for (i = x_init; i < x_init + 3; i++) {
		for (j = y_init; j < y_init + 3; j++) {
			if (sudoku[i][j] == num) {
				return 1;
			}
		}
	}
	return 0;
}

/* 백트래킹 함수 */
void BackTrackingDFS(int** sudoku, int cnt){
	int x = cnt / 9;
	int y = cnt % 9;
	int i, j;

	if (solved) {                                // 유일 출력 조건
		return;
	}

	if (cnt == 81) {                             // 종료 조건
		PrintSudoku(sudoku);
		solved = 1;
		return;                                  
	}
	
	if (sudoku[x][y] != 0) {                     // 해당 칸에 수가 있으면 다음 칸으로
		BackTrackingDFS(sudoku, cnt + 1);
	}
	else {                                       // 수가 없으면 1...9 검사해서 채우기
		for (i = 0; i < 9; i++) {
			if (!RowCheck(sudoku, x, i + 1) && !ColCheck(sudoku, y, i + 1) && !SquareCheck(sudoku, x, y, i + 1)) { 
				sudoku[x][y] = i + 1;
				BackTrackingDFS(sudoku, cnt + 1);
				sudoku[x][y] = 0;
			}
		}
	}
}

int main() {
	int i;
	int** sudoku;

	sudoku = (int**)malloc(sizeof(int*) * 9);
	for (i = 0; i < 9; i++)
		sudoku[i] = (int*)malloc(sizeof(int) * 9);
	
	for (i = 0; i < 9; i++) {
		scanf("%d %d %d %d %d %d %d %d %d", &sudoku[i][0], &sudoku[i][1],
			&sudoku[i][2], &sudoku[i][3], &sudoku[i][4], &sudoku[i][5],
			&sudoku[i][6], &sudoku[i][7], &sudoku[i][8]);
	}

	BackTrackingDFS(sudoku, 0);

	for (i = 0; i < 9; i++)
		free(sudoku[i]);
	free(sudoku);
	return 0;
}