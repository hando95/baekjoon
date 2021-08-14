#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 1001
#include <stdio.h>

int map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];

void InitVisited(int n) {
	for (int i = 1; i <= n; i++)
		visited[i] = 0;
}

/* 큐 */
typedef struct {
	int node[MAX_SIZE];
	int front;
	int rear;
}Queuetype;

void InitQueue(Queuetype* q) {
	q->front = -1;
	q->rear = -1;
}

int QueueEmpty(Queuetype* q) {
	return q->front == q->rear;
}

int QueueFull(Queuetype* q) {
	return q->rear == MAX_SIZE;
}

void Enqueue(Queuetype* q, int x) {
	if (QueueFull(q))
		return;
	q->rear = (q->rear + 1);
	q->node[q->rear] = x;
}

int Dequeue(Queuetype* q) {
	if (QueueEmpty(q))
		return 0;
	q->front = (q->front + 1);
	return	q->node[q->front];
}

int Size(Queuetype* q) {
	return (q->rear - q->front);
}

void DFS(int n, int v) {
	visited[v] = 1;
	printf("%d ", v);
	for (int i = 1; i <= n; i++) {                  // 미방문 노드 중 깊은 노드부터 방문
		if (map[v][i] == 1 && !visited[i])
			DFS(n, i);
	}
	return;
}

void BFS(int n, int v) {
	Queuetype q;
	int cur;

	InitQueue(&q);
	visited[v] = 1;
	printf("%d ", v);
	Enqueue(&q, v);

	while (!QueueEmpty(&q)) {
		 cur = Dequeue(&q);                           // 현재 노드

		 for (int i = 1; i <= n; i++) {               // 미방문 노드 중 인접한 노드부터 방문
			 if (map[cur][i] == 1 && !visited[i]) {
				 visited[i] = 1;
				 printf("%d ", i);
				 Enqueue(&q, i);
			 }
		 }
	}
    printf("\n");
}

int main() {
	int n, m, v;
	int from, to;
	Queuetype b;

	scanf("%d %d %d", &n, &m, &v);

	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &from, &to);
		map[from][to] = 1;
		map[to][from] = 1;
	}


	InitVisited(n);
	DFS(n, v);

	printf("\n");

	InitVisited(n);
	BFS(n, v);

	return 0;
}
