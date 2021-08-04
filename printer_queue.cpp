#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 101
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int prior;
	int order;
}Document;

typedef struct {
	Document d[MAX_SIZE];
	int front;
	int rear;
	int size;
}Queuetype;

void Init(Queuetype* q, int n) {
	q->front = q->rear = 0;
	q->size = n;
}

int IsEmpty(Queuetype* q) {
	return q->front == q->rear;
}

int IsFull(Queuetype* q) {
	return (q->rear + 1) % MAX_SIZE == q->front;
}

void Enqueue(Queuetype* q, Document x) {
	if (IsFull(q))
		return;
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->d[q->rear] = x;
}

Document Dequeue(Queuetype* q) {
	if (IsEmpty(q))
		exit(1);
	q->front = (q->front + 1) % MAX_SIZE;
	return q->d[q->front];
}

/* 맨 앞 문서가 가장 중요한 문서인지 확인하는 함수 */
int IsFirstPrior(Queuetype* q) {
	int cur, next;
	if (IsEmpty(q))
		exit(1);

	cur = (q->front + 1) % MAX_SIZE;
	next = (q->front + 1) % MAX_SIZE;

	/* 하나씩 검사 */
	for (int i = 0; i < q->size - 1; i++) {
		next = (next + 1) % MAX_SIZE;
		if (q->d[cur].prior < q->d[next].prior)
			return 0;
	}
	return 1;
}


int main() {
	int t, n, m, print_cnt;
	Queuetype prt;
	Document docu;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		Init(&prt, n);
		print_cnt = 1;
		
		/* 순위를 입력받아 순서와 순위를 가진 문서를 큐에 넣기 */
		for (int j = 1; j <= n; j++) {
			scanf("%d", &docu.prior);
			docu.order = j - 1;
			Enqueue(&prt, docu);
		}

		if (n == 1) {
			printf("1\n");
			continue;
		}

		while (1) {
			/* 가장 중요한 문서가 맨 앞으로 나올 때까지 반복 */
			while(!IsFirstPrior(&prt)) {
				Enqueue(&prt, Dequeue(&prt));
			}

			/* 맨 앞 문서가 원하는 순번의 문서면 출력 */
			if (m == Dequeue(&prt).order) {
				printf("%d\n", print_cnt);
				break;
			}

			/* 다른 순번의문서면 출력 수++, 문서 수-- */
			else {
				print_cnt++;
				prt.size--;
			}
		}
	}
	return 0;
}