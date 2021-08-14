#define _CRT_SECURE_NO_WARNINGS
#define MAX_CABBAGE 2501
#include <stdio.h>

int land[50][50];
int visited[50][50];
int dir_x[4] = { 0 ,0, -1, 1 };
int dir_y[4] = { -1, 1, 0, 0 };

typedef struct {
	int x;
	int y;
}Coordtype;

Coordtype cabbage[MAX_CABBAGE];


void Initialize(int n, int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			land[j][i] = 0;
			visited[j][i] = 0;
		}
	}
}

void CabbageGroup(int n, int m, int y, int x) {
	int front = 0, rear = 0;
	int new_x, new_y;

	visited[y][x] = 1;
	rear++;
	cabbage[rear].y = y;
	cabbage[rear].x = x;

	while (front != rear) {
		front++;
		y = cabbage[front].y;
		x = cabbage[front].x;

		for (int i = 0; i < 4; i++) {
			new_y = y + dir_y[i];
			new_x = x + dir_x[i];

			if (new_y >= 0 && new_x >= 0 && new_y < n && new_x < m) {
				if (land[new_y][new_x] == 1 && !visited[new_y][new_x]) {
					visited[new_y][new_x] = 1;
					rear++;
					cabbage[rear].y = new_y;
					cabbage[rear].x = new_x;
				}
			}
		}
	}


}


int main() {
	int t, n, m, k;
	int a, b;
	int cnt = 0;

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {

		/* 입력 */
		scanf("%d %d %d", &m, &n, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d %d", &a, &b);
			land[b][a] = 1;
		}

		/* 배추 찾으면 인접 배추 탐색 */
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (land[y][x] == 1 && !visited[y][x]) {
					CabbageGroup(n, m, y, x);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);

		/* 방문 초기화 */
		Initialize(n, m);
		cnt = 0;
	}

}