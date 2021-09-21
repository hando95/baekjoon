#define _CRT_SECURE_NO_WARNINGS
#define MAX_BOARD_SIZE 300
#define MAX_QUEUE_SIZE 90001
#include <stdio.h>

int cost[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int visited[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int pop_x, pop_y;

int knightdx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int knightdy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

typedef struct{
	int x, y;
}Pos;

typedef struct {
	Pos chess[MAX_QUEUE_SIZE];
	int front, rear;
}Queue;

Queue knq;

void InitQueue(Queue* q) {
	q->front = q->rear = 0;
}

int EmptyQueue(Queue* q) {
	return q->front == q->rear;
}

int FullQueue(Queue* q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void Enqueue(Queue* q, int a, int b) {
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->chess[q->rear].x = a;
	q->chess[q->rear].y = b;
}

void Dequeue(Queue* q) {
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	pop_x = q->chess[q->front].x;
	pop_y = q->chess[q->front].y;
}

void InitVisitedCost(int l) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			visited[i][j] = 0;
			cost[i][j] = 0;
		}
	}
	return;
}

void MoveKnight(int l, int start_x, int start_y) {
	int cur_x, cur_y, next_x, next_y;
	
	InitQueue(&knq);
	visited[start_x][start_y] = 1;
	Enqueue(&knq, start_x, start_y);

	/* 탐색 시작 */
	while (!EmptyQueue(&knq)) {
		Dequeue(&knq);
		cur_x = pop_x;
		cur_y = pop_y;

		/* 인접 8방 검사 */
		for (int i = 0; i < 8; i++) {
			next_x = cur_x + knightdx[i];
			next_y = cur_y + knightdy[i];

			/* 범위 내에서 */
			if (next_x >= 0 && next_y >= 0 && next_x < l && next_y < l) {

				/* 미방문 칸 발견 */
				if (!visited[next_x][next_y]) {
					visited[next_x][next_y] = 1;
					cost[next_x][next_y] = cost[cur_x][cur_y] + 1;
					Enqueue(&knq, next_x, next_y);
				}

			}

		}
	}
	return;
}

int main() {
	int test_case;
	int l;
	int start_x, start_y;
	int dest_x, dest_y;

	scanf("%d", &test_case);
	while(test_case--) {
		scanf("%d", &l);                          // 체스판 크기
		scanf("%d %d", &start_x, &start_y);       // 시작칸
		scanf("%d %d", &dest_x, &dest_y);         // 도착칸

		/* 나이트 이동 */
		MoveKnight(l, start_x, start_y);

		printf("%d\n", cost[dest_x][dest_y]);

		/* 방문 여부, 경로 비용 초기화 */
		InitVisitedCost(l);
	}
	return 0;
}