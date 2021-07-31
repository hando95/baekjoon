#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100000
#include <stdio.h>

int wrong_sum = 0;

typedef struct {
	int money[MAX_SIZE];
	int top;
}stack;

void Init(stack* s) {
	s->top = -1;
}

int IsFull(stack* s) {
	if (s->top == MAX_SIZE - 1)
		return 1;
	else
		return 0;
}

int IsEmpty(stack* s) {
	if (s->top == -1)
		return 1;
	else
		return 0;
}

int Pop(stack* s) {
	if (IsEmpty(s))
		return 0;
	else
		return s->money[(s->top)--];
}

void PushOrDelete(stack* s, int input) {
	if (IsFull(s))                        // 가득 찼으면 함수 종료
		return;
	else if (input == 0)                  // 0이면 지우고 지운 수 저장
		wrong_sum += Pop(s);
	else                                  // 0이 아니면 기록
		s->money[++(s->top)] = input;
}



int main() {
	int k, input, input_sum = 0;
	stack s;
	Init(&s);

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &input);
		input_sum += input;
		PushOrDelete(&s, input);
	}

	printf("%d\n", input_sum - wrong_sum);
	return 0;
}