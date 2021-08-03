#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 500001
#include <stdio.h>
#include <stdlib.h>

/* 원형 큐 */
typedef struct {
	int* card;
	int front;
	int rear;
}Queuetype;

/* 초기화 */
void Init(Queuetype* q) {
	q->front = q->rear = 0;
}

/* 빈 상태 */
int IsEmpty(Queuetype* q) {
	return (q->front == q->rear);
}

/* 가득 찬 상태 */
int IsFull(Queuetype* q) {
	return ((q->rear + 1) % MAX_SIZE == q->front);
}

/* 삽입 */
void Enqueue(Queuetype* q, int x) {
	if (IsFull(q))
		return;
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->card[q->rear] = x;
}

/* 삭제 */
int Dequeue(Queuetype* q) {
	if (IsEmpty(q))
		return 0;
	q->front = (q->front + 1) % MAX_SIZE;
	return q->card[q->front];
}


int main() {
	int n, c;
	static Queuetype q;
	q.card = (int*)malloc(sizeof(int) * MAX_SIZE);

	scanf("%d", &n);

	Init(&q);
	for (int i = 1; i <= n; i++)
		Enqueue(&q, i);

	while (!IsEmpty(&q)) {
		c = Dequeue(&q);
		if (IsEmpty(&q))
			break;
		Enqueue(&q, Dequeue(&q));
	}

	printf("%d\n", c);
	return 0;
}