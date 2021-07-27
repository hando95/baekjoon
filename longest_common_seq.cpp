#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
문자열 LCS
ACAYKP, CAPCAKL 중 최장 공통 부분 수열 길이 구하기

Board[ACAYKP 길이 + 1][CAPCAKL 길이 + 1]
0 0 A C A Y K P 
0 0 0 0 0 0 0 0
C 0 0 1 1 1 1 1
A 0 1 1 2 2 2 2
P 0 1 1 2 2 2 3
C 0 1 2 2 2 2 3
A 0 1 2 3 3 3 3
K 0 1 2 3 3 4 4
P 0 1 2 3 3 4 5 에서 마지막인 Board[6][7]이 최장 공통 부분 수열 길이
*/


int cmp[1001][1001] = { 0, };

int GetMax(int a, int b) {
	return a < b ? b : a;
}

int GetLCSLen(char* a, char* b, int a_len, int b_len) {

	for (int i = 1; i <= a_len; i++) {
		for (int j = 1; j <= b_len; j++) {
			if (a[i - 1] == b[j - 1])                                   // 알파벳이 같으면
				cmp[i][j] = cmp[i - 1][j - 1] + 1;                      // 좌대각 + 1 저장
			else                                                        // 알파벳이 다르면
				cmp[i][j] = GetMax(cmp[i - 1][j], cmp[i][j - 1]);       // 왼쪽과 위쪽 중 큰 수 저장
		}
	}
	return cmp[a_len][b_len];
}



int main() {
	int len;
	char a[1000];
	char b[1000];


	scanf("%s", a);
	scanf("%s", b);

	printf("%d\n", GetLCSLen(a, b, strlen(a), strlen(b)));
	return 0;
}