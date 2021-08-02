#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100000
#include <stdio.h>

typedef struct {
	int num[MAX_SIZE];
	int top;
}Stacktype;

void Init(Stacktype* s) {
	s->top = -1;
}

int IsEmpty(Stacktype* s) {
	if (s->top == -1)
		return 1;
	return 0;
}

int IsFull(Stacktype* s) {
	if (s->top == MAX_SIZE - 1)
		return 1;
	return 0;
}

void Push(Stacktype* s, int number) {
	if (IsFull(s))
		return;
	s->num[++(s->top)] = number;
}

int Pop(Stacktype* s) {
	if (IsEmpty(s))
		return 0;
	return s->num[(s->top)--];
}

int Top(Stacktype* s) {
	if (IsEmpty(s))
		return 0;
	return s->num[s->top];
}

int main() {
	int n, number = 1, no_flag = 0, idx = 0;
	static char plus_minus[MAX_SIZE * 2];   // +,- 두 개
	static int seq[MAX_SIZE];
	static Stacktype s;


	scanf("%d", &n);

	/* 수열의 처음 수 stack 처리 */
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}

	while (Top(&s) != seq[0]) {
		Push(&s, number++);
		plus_minus[idx++] = '+';
	}
	Pop(&s);
	plus_minus[idx++] = '-';

	/* 수열의 나머지 수 stack 처리 */
	for (int i = 1; i < n; i++) {

		/* 이전 수보다 크면 해당 수까지 Push 후 Pop */
		if (seq[i] > seq[i - 1]) {
			while (Top(&s) != seq[i]) {
				Push(&s, number++);
				plus_minus[idx++] = '+';
			}
			Pop(&s);
			plus_minus[idx++] = '-';
		}

		/* 이전 수보다 작으면 stack의 top 확인 */
		else {
			if (Top(&s) != seq[i]) {
				no_flag = 1;
				break;
			}

			Pop(&s);
			plus_minus[idx++] = '-';
		}
	}

	if (no_flag == 1)
		printf("NO\n");
	else {
		for (int i = 0; i < idx; i++)
			printf("%c\n", plus_minus[i]);
	}

	return 0;
}