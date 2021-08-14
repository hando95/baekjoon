#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 101
#include <stdio.h>

char maze[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int path_cnt[MAX_SIZE][MAX_SIZE];
int dir_x[4] = { 0 ,0, -1, 1 };
int dir_y[4] = { -1, 1, 0, 0 };


typedef struct {
	int x, y;
	int cost;
}Coordtype;

Coordtype path[MAX_SIZE * MAX_SIZE];

int ShortPath(int x, int y, int n, int m) {
	int front = 0, rear = 0, cnt = 0;
	int next_x, next_y;

	visited[x][y] = 1;
	path_cnt[x][y] = 1;
	rear++;
	path[rear].x = x;
	path[rear].y = y;

	while (front != rear) {
		front++;
		x = path[front].x;
		y = path[front].y;

		/* 상하좌우 검사 */
		for (int i = 0; i < 4; i++) {
			next_x = x + dir_x[i];
			next_y = y + dir_y[i];

			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < m) {
				if (maze[next_x][next_y] == '1' && !visited[next_x][next_y]) {
					
					/* 도착 */
					if (next_x == n - 1 && next_y == m - 1) {
						visited[next_x][next_y] = 1;
						path_cnt[next_x][next_y] = path_cnt[x][y] + 1;
						return path_cnt[next_x][next_y];
					}

					/* 인접한 길 */
					visited[next_x][next_y] = 1;
					path_cnt[next_x][next_y] = path_cnt[x][y] + 1;
					rear++;
					path[rear].x = next_x;
					path[rear].y = next_y;
				}
			}

		}
	}
}


int main() {
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", maze[i]);
	}

	printf("%d\n", ShortPath(0, 0, n, m));
	return 0;
}