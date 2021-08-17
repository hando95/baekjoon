#define _CRT_SECURE_NO_WARNINGS
#define MAX_DEQUE_SIZE 51
#include <stdio.h>

typedef struct {
	int data[MAX_DEQUE_SIZE];
	int front, rear;
}Dequetype;

Dequetype dq;
int count = 0;

void Init(Dequetype* dq) {
	dq->front = dq->rear = 0;
}

int DequeEmpty(Dequetype* dq) {
	return dq->front == dq->rear;
}

int DequeFull(Dequetype* dq) {
	return (dq->rear + 1) % MAX_DEQUE_SIZE == dq->front;
}

void PushFront(Dequetype* dq, int x) {
	if (DequeFull(dq))
		return;
	dq->data[dq->front] = x;
	dq->front = (dq->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

void PushBack(Dequetype* dq, int x) {
	if (DequeFull(dq))
		return;
	dq->rear = (dq->rear + 1) % MAX_DEQUE_SIZE;
	dq->data[dq->rear] = x;
}

int PopFront(Dequetype* dq) {
	if (DequeEmpty(dq))
		return -1;
	dq->front = (dq->front + 1) % MAX_DEQUE_SIZE;
	return dq->data[dq->front];
}

int PopBack(Dequetype* dq) {
	if (DequeEmpty(dq))
		return -1;
	int now;
	now = dq->rear;
	dq->rear = (dq->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	return dq->data[now];
}

int Size(Dequetype* dq) {
	return (dq->rear - dq->front + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

int FrontElem(Dequetype* dq) {
	return dq->data[(dq->front + 1) % MAX_DEQUE_SIZE];
}

int BackElem(Dequetype* dq) {
	return dq->data[dq->rear];
}

/* 원하는 수가 앞에 있는지 확인하는 함수 */
int IsLowerBound(Dequetype* dq, int x) {
	int bound;
	bound = Size(dq) / 2;
	
	for (int i = 1; i <= bound + 1; i++) {
		if (dq->data[(dq->front + i) % MAX_DEQUE_SIZE] == x)
			return 1;
	}
	return 0;
}


void Operation1(Dequetype* dq) {
	PopFront(dq);
}

void Operation2(Dequetype* dq) {
	PushBack(dq, PopFront(dq));
	count++;
}

void Operation3(Dequetype* dq) {
	PushFront(dq, PopBack(dq));
	count++;
}


int main() {
	int n, m;                    // 큐 크기, 추출 수
	int num[50] = { 0, };
	int idx = 0;

	Init(&dq);
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 1; i <= n; i++) {
		PushBack(&dq, i);
	}

	while (idx < m) {

		if (FrontElem(&dq) == num[idx]) {
			Operation1(&dq);
			idx++;
			continue;
		}

		if (IsLowerBound(&dq, num[idx]))
			Operation2(&dq);
		else
			Operation3(&dq);
	}

	printf("%d\n", count);
	return 0;
}