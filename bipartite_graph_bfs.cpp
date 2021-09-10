#define _CRT_SECURE_NO_WARNINGS
#define MAX_VERTEX 20001
#define MAX_QUEUE_SIZE 20002
#include <stdio.h>
#include <stdlib.h>

int graph[MAX_VERTEX][MAX_VERTEX];
int color[MAX_VERTEX];

typedef struct {
	int queue[MAX_QUEUE_SIZE];
	int front, rear;
}Queuetype;

Queuetype bp;

void InitQueue(Queuetype* q) {
	q->front = q->rear = 0;
}

int IsEmpty(Queuetype* q) {
	return q->front == q->rear;
}

int IsFull(Queuetype *q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void Enqueue(Queuetype* q, int v) {
	if (IsFull(q))
		return;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = v;
}

int Dequeue(Queuetype* q) {
	if (IsEmpty(q))
		return -1;
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

int IsBipartiteGraph(int start_v, int v) {
	int now_v;

	/* 시작노드 빨강 칠하기 */
	color[start_v] = -1;
	InitQueue(&bp);
	Enqueue(&bp, start_v);

	/* 인접노드 탐색 */
	while (!IsEmpty(&bp)) {
		now_v = Dequeue(&bp);
		for (int i = 1; i <= v; i++) {

			/* 방문하지 않은 노드 발견 */
			if (graph[now_v][i] == 1 && color[i] == 0) {
				color[i] = (color[now_v] * -1);
				Enqueue(&bp, i);
			}
			/* 인접노드가 다른 색이면 */
			else if (graph[now_v][i] == 1 && color[i] == (-1 * color[now_v]))
				continue;
			/* 인접노드가 같은 색이면 */
			else if (graph[now_v][i] == 1 && color[i] == color[now_v])
				return 0;
		}
	}

	return 1;
}

int main() {
	int k, v, e;
	int v1, v2;
	int bp;

	scanf("%d", &k);
	while (k--) {
		bp = 1;
		scanf("%d %d", &v, &e);

		for (int i = 1; i <= v; i++) {
			color[i] = 0;
			for (int j = 1; j <= v; j++) {
				graph[i][j] = 0;
				graph[j][i] = 0;
			}
		}

		for (int i = 0; i < e; i++) {
			scanf("%d %d", &v1, &v2);
			
			graph[v1][v2] = 1;
			graph[v2][v1] = 1;
		}

		/* 칠해지지 않은 노드가 있으면 그 노드부터 인접탐색 시작 */
		for (int i = 1; i <= v; i++) {
			if (color[i] == 0) {
				if (!IsBipartiteGraph(i, v))
					bp = 0;
			}
		}

		if (bp)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}