#define _CRT_SECURE_NO_WARNINGS
#define MAX_MAP_SIZE 25
#include <stdio.h>

int map[MAX_MAP_SIZE][MAX_MAP_SIZE];
int visited[MAX_MAP_SIZE][MAX_MAP_SIZE];
int dir_x[4] = { 0, 0, -1, 1 };
int dir_y[4] = { -1, 1, 0, 0 };
int ans[625];

void GroupingHousebyBFS(int n, int x, int y, int group_num) {
	int cur, new_x, new_y;
	int house[2][MAX_MAP_SIZE * MAX_MAP_SIZE + 1];
	int front = 0;
	int rear = 0;

	ans[group_num]++;
	visited[x][y] = 1;
	rear++;
	house[0][rear] = x;
	house[1][rear] = y;

	while (front != rear) {
		front++;
		x = house[0][front];
		y = house[1][front];

		for (int i = 0; i < 4; i++) {
			new_x = x + dir_x[i];
			new_y = y + dir_y[i];

			/* 인접한 집 방문하고 큐에 넣기 */
			if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < n) {
				if (map[new_x][new_y] == 1 && !visited[new_x][new_y]) {
					visited[new_x][new_y] = 1;
					rear++;
					house[0][rear] = new_x;
					house[1][rear] = new_y;
					ans[group_num]++;
				}
			}
		}
	}

}


int main() {
	int n, temp;
	int group_num = 0;
	char str[MAX_MAP_SIZE + 1];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				GroupingHousebyBFS(n, i, j, group_num);
				group_num++;
			}
		}
	}

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