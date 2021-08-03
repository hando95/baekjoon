#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 1001
#include <stdio.h>
#include <stdlib.h>

/*
요세푸스 순열: 둘러앉은 N명 중 K번째 사람을 한 명씩 모두 제거하는 문제
Queue에서 자신의 차례가 아니면 뒤로 삽입 자신의 차례면 삭제
*/


typedef struct {
	int* jose;
	int front;
	int rear;
}Queuetype;

void Init(Queuetype* q) {
	q->front = q->rear = 0;
}

int IsEmpty(Queuetype* q) {
	return (q->front == q->rear);
}

int IsFull(Queuetype* q) {
	return (q->rear + 1) % MAX_SIZE == q->front;
}

void Enqueue(Queuetype* q, int x) {
	if (IsFull(q))
		return;
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->jose[q->rear] = x;
}

int Dequeue(Queuetype* q) {
	if (IsEmpty(q))
		return 0;
	q->front = (q->front + 1) % MAX_SIZE;
	return q->jose[q->front];
}

int main() {
	int n, k, cnt = 1, idx = 0;
	int ans[1000];
	Queuetype q;

	scanf("%d %d", &n, &k);
	Init(&q);
	q.jose = (int*)malloc(sizeof(int) * MAX_SIZE);

	for (int i = 1; i <= n; i++)
		Enqueue(&q, i);

	while (!IsEmpty(&q)) {
		if (cnt == k) {
			ans[idx++] = Dequeue(&q);
			cnt = 1;
		}
		else {
			Enqueue(&q, Dequeue(&q));
			cnt++;
		}

	}

	printf("<");
	for (int i = 0; i < idx; i++) {
		if(i == idx - 1)
			printf("%d>\n", ans[i]);
		else
			printf("%d, ", ans[i]);
	}
	return 0;
}