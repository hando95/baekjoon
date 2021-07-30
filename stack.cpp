#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 10000
#include <stdio.h>
#include <string.h>

typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
}stack;

/* 스택 초기화 함수 */
void Init(stack* s) {
	s->top = -1;
}


/* 비어있는 스택 확인 함수 */
int IsEmpty(stack* s) {
	if (s->top == -1)
		return 1;

	return 0;
}

/* 가득 찬 스택 확인 함수 */
int IsFull(stack* s) {
	if (s->top == MAX_STACK_SIZE - 1)
		return 1;

	return 0;
}

/* 스택에 들어있는 정수 개수 반환 함수 */
int Size(stack* s) {
	if (IsFull(s))
		return MAX_STACK_SIZE;

	return (s->top) + 1;
}

/* 스택 push 함수 */
void Push(stack* s, int x) {
	if (IsFull(s))
		return;
	else
		s->data[++(s->top)] = x;
}

/* 스택 pop 함수 */
int Pop(stack* s) {
	if (IsEmpty(s))
		return -1;

	return s->data[(s->top)--];
}

/* 가장 위의 수 반환 함수 */
int Top(stack* s) {
	if (IsEmpty(s))
		return -1;

	return s->data[s->top];
}


int main() {
	int n, x;
	char cmd[6];
	stack s;
	Init(&s);

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%s", cmd);

		if (!strcmp(cmd, "push")) {
			scanf("%d", &x);
			Push(&s, x);
		}

		else if (!strcmp(cmd, "pop"))
			printf("%d\n", Pop(&s));
		
		else if (!strcmp(cmd, "size"))
			printf("%d\n", Size(&s));

		else if (!strcmp(cmd, "empty")) 
			printf("%d\n", IsEmpty(&s));

		else if (!strcmp(cmd, "top")) 
			printf("%d\n", Top(&s));
	}
	return 0;
}