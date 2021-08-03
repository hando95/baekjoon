#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 2000000
#include <stdio.h>
#include <string.h>

typedef struct {
	int queue[MAX_SIZE];
	int front;
	int rear;
}Queuetype;

/* 초기화 */
void Init(Queuetype* q) {
	q->front = -1;
	q->rear = -1;
}

/* 빈 상태 */
int IsEmpty(Queuetype* q) {
	return (q->front == q->rear);
}

/* 가득 찬 상태 */
int IsFull(Queuetype* q) {
	return (q->rear == MAX_SIZE - 1);
}

/* 삽입 */
void Push(Queuetype* q, int x) {
	if (IsFull(q))
		return;
	q->queue[++(q->rear)] = x;
}

/* 삭제 */
int Pop(Queuetype* q) {
	if (IsEmpty(q))
		return -1;
	return q->queue[++(q->front)];
}

/* 큐 크기 */
int Size(Queuetype* q) {
	return (q->rear - q->front);
}

/* 큐 맨 앞 */
int Front(Queuetype* q) {
	if (IsEmpty(q))
		return -1;
	return q->queue[q->front + 1];
}

/* 큐 맨 뒤 */
int Back(Queuetype* q) {
	if (IsEmpty(q))
		return -1;
	return q->queue[q->rear];
}

int main() {
	int n, x;
	char cmd[6];
	static Queuetype q;
	scanf("%d", &n);

	Init(&q);

	for (int i = 0; i < n; i++) {
		scanf("%s", cmd);

		if (strcmp(cmd, "push") == 0) {
			scanf("%d", &x);
			Push(&q, x);
		}
		else if (strcmp(cmd, "pop") == 0) {
			printf("%d\n", Pop(&q));
		}
		else if (strcmp(cmd, "size") == 0) {
			printf("%d\n", Size(&q));
		}
		else if (strcmp(cmd, "empty") == 0) {
			printf("%d\n", IsEmpty(&q));
		}
		else if (strcmp(cmd, "front") == 0) {
			printf("%d\n", Front(&q));
		}
		else if (strcmp(cmd, "back") == 0) {
			printf("%d\n", Back(&q));
		}
	}
	return 0;

}