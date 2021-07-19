#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int s_team = 0;
int l_team = 0;
int stats[20][20];
int member[20];
int min = 1000;

int CmpAbility(int a, int b, int c) {
	int cmp;
	if (b - c < 0)
		cmp = c - b;
	else
		cmp = b - c;
	return a < cmp ? a : cmp;
}



void team_select(int n, int cnt, int idx) {

	if (cnt == n / 2) {
		for (int j = 0; j < n; j++) {
			for(int k = j; k < n; k++){
				if (member[j] == 1 && member[j] == member[k]) {        // s_team
					s_team += stats[j][k];
					s_team += stats[k][j];
				}
				else if (member[j] == 0 && member[j] == member[k]) {   // l_team
					l_team += stats[j][k];
					l_team += stats[k][j];
				}
			}
		}
		min = CmpAbility(min, s_team, l_team);
		s_team = 0;
		l_team = 0;
		return;
	}

	for (int i = idx; i < n; i++) {                                    // idx로 중복 제거
		if (!member[i]) {
			member[i] = 1;
			team_select(n, cnt + 1, i + 1);
			member[i] = 0;
		}
	}

}



int main() {
	int n;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &stats[i][j]);
		}
	}
	team_select(n, 0, 0);

	printf("%d\n", min);
	return 0;
}