#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 10001
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int data[MAX_SIZE];
	int front, rear;
}Dequetype;

Dequetype dq;

void Init(Dequetype* dq) {
	dq->front = dq->rear = 0;
}

int IsEmpty(Dequetype* dq) {
	return dq->front == dq->rear;
}

int IsFull(Dequetype* dq) {
	return (dq->rear + 1) % MAX_SIZE == dq->front;
}

void PushFront(Dequetype* dq, int x) {
	if (IsFull(dq))
		return;
	dq->data[dq->front] = x;
	dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
}

void PushBack(Dequetype* dq, int x) {
	if (IsFull(dq))
		return;
	dq->rear = (dq->rear + 1) % MAX_SIZE;
	dq->data[dq->rear] = x;
}

int PopFront(Dequetype* dq) {
	if (IsEmpty(dq))
		return -1;
	dq->front = (dq->front + 1) % MAX_SIZE;
	return dq->data[dq->front];
}

int PopBack(Dequetype* dq) {
	if (IsEmpty(dq))
		return -1;
	int x;
	x = dq->data[dq->rear];
	dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
	return x;
}

int Size(Dequetype* dq) {
	return (dq->rear - dq->front + MAX_SIZE) % MAX_SIZE;
}

int Front(Dequetype* dq) {
	if (IsEmpty(dq))
		return -1;
	return dq->data[(dq->front + 1) % MAX_SIZE];
}

int Back(Dequetype* dq) {
	if (IsEmpty(dq))
		return -1;
	return dq->data[dq->rear];
}

int main() {
	int n, x;
	char cmd[11];

	Init(&dq);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", cmd);

		if (strcmp(cmd, "push_front") == 0) {
			scanf("%d", &x);
			PushFront(&dq, x);
		}
		else if (strcmp(cmd, "push_back") == 0) {
			scanf("%d", &x);
			PushBack(&dq, x);
		}
		else if (strcmp(cmd, "pop_front") == 0)
			printf("%d\n", PopFront(&dq));
		else if (strcmp(cmd, "pop_back") == 0)
			printf("%d\n", PopBack(&dq));
		else if (strcmp(cmd, "size") == 0)
			printf("%d\n", Size(&dq));
		else if (strcmp(cmd, "empty") == 0)
			printf("%d\n", IsEmpty(&dq));
		else if (strcmp(cmd, "front") == 0)
			printf("%d\n", Front(&dq));
		else if (strcmp(cmd, "back") == 0)
			printf("%d\n", Back(&dq));
	}

	return 0;
}