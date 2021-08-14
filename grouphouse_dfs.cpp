#define _CRT_SECURE_NO_WARNINGS
#define MAX_MAP_SIZE 25
#include <stdio.h>

int map[MAX_MAP_SIZE][MAX_MAP_SIZE];
int visited[MAX_MAP_SIZE][MAX_MAP_SIZE];
int dir_x[4] = { 0, 0, -1, 1 };
int dir_y[4] = { -1, 1, 0, 0 };
int ans[625];

/* DFS로 그룹화 */
void GroupingHouseDFS(int n, int x, int y, int group_num) {
	int new_x, new_y;

	ans[group_num]++;
	visited[x][y] = 1;
	
	for (int i = 0; i < 4; i++) {
		new_x = x + dir_x[i];
		new_y = y + dir_y[i];

		if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < n) {
			if (map[new_x][new_y] == 1 && !visited[new_x][new_y]) {
				GroupingHouseDFS(n, new_x, new_y, group_num);
			}
		}
	}
	return;
}



int main() {
	int n, temp, group_num = 0;
	char str[MAX_MAP_SIZE + 1];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	
	/* 집이 나오면 탐색 시작 */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				GroupingHouseDFS(n, i, j, group_num);
				group_num++;
				
			}
		}
	}

	/* 오름차순 정렬 */
	for (int i = 0; i < group_num; i++) {
		for (int j = i; j < group_num; j++) {
			if (ans[i] > ans[j]) {
				temp = ans[i];
				ans[i] = ans[j];
				ans[j] = temp;
			}
		}
	}

	printf("%d\n", group_num);
	for (int i = 0; i < group_num; i++) {
		printf("%d\n", ans[i]);
	}
}