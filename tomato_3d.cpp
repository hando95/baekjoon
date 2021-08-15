#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#define MAX_NUM 1000001
#include <stdio.h>

int box[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int time[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int pop_h = 0, pop_x = 0, pop_y = 0;
int no_tomato = 1;    // 토마토 0개 확인 여부
int all_ripe = 1;     // 처음부터 모두 익은 토마토 확인 여부

/* 아래, 위, 상, 하, 좌, 우 */
int dir_z[6] = { -1, 1, 0, 0, 0, 0 };
int dir_x[6] = { 0, 0, -1, 1, 0, 0 };
int dir_y[6] = { 0, 0, 0, 0, -1, 1 };


typedef struct {
	int h, x, y;
}Coordtype;

typedef struct {
	Coordtype tomato[MAX_NUM];
	int front;
	int rear;
}Queuetype;

Queuetype container;

void InitQueue(Queuetype* q) {
	q->front = q->rear = 0;
}

int IsEmpty(Queuetype* q) {
	return q->front == q->rear;
}

int IsFull(Queuetype* q) {
	return (q->rear + 1) % MAX_NUM == q->front;
}

void Enqueue(Queuetype* q, int h, int x, int y) {
	q->rear = (q->rear + 1) % MAX_NUM;
	q->tomato[q->rear].h = h;
	q->tomato[q->rear].x = x;
	q->tomato[q->rear].y = y;
}

void Dequeue(Queuetype* q) {
	q->front = (q->front + 1) % MAX_NUM;
	pop_h = q->tomato[q->front].h;
	pop_x = q->tomato[q->front].x;
	pop_y = q->tomato[q->front].y;
}

int GetMin(int a, int b) {
	return a < b ? a : b;
}

int GetMax(int a, int b) {
	return a < b ? b : a;
}

/* 익히는 함수 */
void LetsRipen(Queuetype* q, int h, int n, int m) {
	int next_z, next_x, next_y;
	int x, y, z;


	while (!IsEmpty(q)) {
		Dequeue(q);
		z = pop_h;
		x = pop_x;
		y = pop_y;

		/* 아래, 위, 상, 하, 좌, 우 검사*/
		for (int i = 0; i < 6; i++) {
			next_z = z + dir_z[i];
			next_x = x + dir_x[i];
			next_y = y + dir_y[i];

			/* 범위 내에서 */
			if (next_z >= 0 && next_z < h && next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {

				/* 안 익은 토마토 발견 */
				if (box[next_z][next_x][next_y] == 0 && !visited[next_z][next_x][next_y]) {
					all_ripe = 0;
					visited[next_z][next_x][next_y] = 1;
					time[next_z][next_x][next_y] = time[z][x][y] + 1;
					Enqueue(&container, next_z, next_x, next_y);
				}
			}


		}
	}
}

int main() {
	int n, m, h; // 세로, 가로, 높이
	int ans = 0;

	scanf("%d %d %d", &m, &n, &h);
	InitQueue(&container);

	/* 박스 상태 입력 */
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &box[k][i][j]);

				/* 토마토가 0개인지 아닌지 확인 */
				if (box[k][i][j] != -1)
					no_tomato = 0;

				/* 시작할 익은 토마토 큐에 넣기 */
				if (box[k][i][j] == 1) {
					visited[k][i][j] = 1;
					Enqueue(&container, k, i, j);
				}
			}
		}
	}

	/* 익히기 */
	LetsRipen(&container, h, n, m);

	/* 최소 일수 구하기 */
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				/* 안 익은 토마토 존재 */
				if (time[k][i][j] == 0 && box[k][i][j] != 1 && box[k][i][j] != -1) {
					printf("-1\n");
					return 0;
				}
				ans = GetMax(ans, time[k][i][j]);
			}
		}
	}

	/* 처음부터 모두 익어있는 상태 */
	if (all_ripe) {
		printf("0\n");
		return 0;
	}

	/* 토마토가 아예 없는 상태 */
	else if (no_tomato) {
		printf("-1\n");
		return 0;
	}

	printf("%d\n", ans);
	return 0;
}
