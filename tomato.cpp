#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 1000
#include <stdio.h>

int box[MAX_SIZE][MAX_SIZE];               // 원상태
int visited[MAX_SIZE][MAX_SIZE];           // 방문 여부
int time[MAX_SIZE][MAX_SIZE];              // 익힐 일수
int all_ripe = 0;                          // 처음부터 모두 익은 토마토인지 확인 여부
int no_tomato = 1;
int dir_x[4] = { 0, 0, -1, 1 };
int dir_y[4] = { -1, 1, 0, 0 };

/* 좌표 구조체 */
typedef struct {
	int x, y;
}Coordtype;

Coordtype tomato[MAX_SIZE * MAX_SIZE + 1];
int front = 0, rear = 0;

int GetMin(int a, int b) {
	return a < b ? a : b;
}

int GetMax(int a, int b) {
	return a < b ? b : a;
}

/* 익히기 */
void LetsRipen(int n, int m) {
	int x, y;
	int next_x, next_y;


	/* 인접 토마토 확인 */
	while (front != rear) {
		front++;
		x = tomato[front].x;
		y = tomato[front].y;

		for (int i = 0; i < 4; i++) {
			next_x = x + dir_x[i];
			next_y = y + dir_y[i];

			/* 범위 내에서 */
			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < m) {

				/* 안 익은 토마토 발견 */
				if (box[next_x][next_y] == 0 && !visited[next_x][next_y]) {
					visited[next_x][next_y] = 1;
					time[next_x][next_y] = time[x][y] + 1;

					rear++;
					tomato[rear].x = next_x;
					tomato[rear].y = next_y;

				}
			}

		}
	}
}



int main() {
	int m, n;  // 가로, 세로
	int max_time = 0;
	scanf("%d %d", &m, &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &box[i][j]);

			if (box[i][j] != -1) {
				no_tomato = 0;
			}
	
			/* 시작할 익은 토마토 큐에 삽입 */
			if (box[i][j] == 1) {
				visited[i][j] = 1;
				rear++;
				tomato[rear].x = i;
				tomato[rear].y = j;
			}
		}
	}

	/* 익히기 */
	LetsRipen(n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			/* 안 익은 토마토 존재 */
			if (time[i][j] == 0 && box[i][j] != 1 && box[i][j] != -1) {
				no_tomato = 0;   // 토마토 없는 경우가 아님
				all_ripe = 0;    // 다 익은 경우가 아님
				printf("-1\n");
				return 0;
			}

			max_time = GetMax(max_time, time[i][j]);
		}
	}

	/* 모두 익은 경우 */
	if (all_ripe) {
		printf("0\n");
		return 0;
	}
	
	/* 토마토가 없는 경우 */
	else if (no_tomato) {
		printf("-1\n");
		return 0;
	}

	/* 모두 익을 때까지 최소 일수 */
	printf("%d\n", max_time);
	return 0;
}