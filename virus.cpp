#define _CRT_SECURE_NO_WARNINGS
#define MAX_COM_NUM 101
#include <stdio.h>

int network[MAX_COM_NUM][MAX_COM_NUM];
int visited[MAX_COM_NUM];

typedef struct {
	int com[MAX_COM_NUM];
	int front;
	int rear;
}Queuetype;

void InitQueue(Queuetype* q) {
	q->front = q->rear = 0;
}

int IsEmpty(Queuetype* q) {
	return q->front == q->rear;
}

int IsFull(Queuetype* q) {
	return q->front == (q->rear + 1) % MAX_COM_NUM;
}

void Enqueue(Queuetype* q, int x) {
	if (IsFull(q))
		return;
	q->rear = (q->rear + 1) % MAX_COM_NUM;
	q->com[q->rear] = x;
}

int Dequeue(Queuetype* q) {
	if (IsEmpty(q))
		return -1;
	q->front = (q->front + 1) % MAX_COM_NUM;
	return q->com[q->front];
}

int SpreadVirus(int v, int n) {
	Queuetype q;
	int cnt = 0;

	InitQueue(&q);
	visited[v] = 1;
	Enqueue(&q, v);

	while (!IsEmpty(&q)) {
		v = Dequeue(&q);

		for (int i = 1; i <= n; i++) {
			if (network[v][i] == 1 && !visited[i]) {
				visited[i] = 1;
				cnt++;
				Enqueue(&q, i);
			}
		}
	}

	return cnt;
}

int main() {
	int node, edge;
	int com1, com2;

	scanf("%d", &node);
	scanf("%d", &edge);
	for (int i = 1; i <= edge; i++) {
		scanf("%d %d", &com1, &com2);
		network[com1][com2] = 1;
		network[com2][com1] = 1;
	}

	printf("%d\n", SpreadVirus(1, node));
	return 0;
}