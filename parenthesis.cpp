#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	char stack[50];
	int top;
}Stacktype;

void Init(Stacktype* s) {
	s->top = -1;
}

int IsEmpty(Stacktype* s) {
	if (s->top == -1)
		return 1;
	else
		return 0;
}

int IsFull(Stacktype* s) {
	if (s->top == 50)
		return 1;
	else
		return 0;
}

void Push(Stacktype* s, char ch) {
	if (IsFull(s))
		return;
	else
		s->stack[++(s->top)] = ch;
}

char Pop(Stacktype* s) {
	if (IsEmpty(s))
		return 0;
	else
		return s->stack[(s->top)--];
}

void Show(Stacktype* s) {
	for (int i = 0; i <= s->top; i++)
		printf("%d ", s->stack[i]);
	printf("\n");
}


int main() {
	char paren[51];
	Stacktype s;
	int t, len;
	int no_flag = 0;
	
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		Init(&s);
		scanf("%s", paren);
		len = strlen(paren);

		for (int j = 0; j < len; j++) {

			/* 열린 괄호면 push */
			if (paren[j] == '(')
				Push(&s, '(');

			/* 닫힌 괄호면 스택에 열린 괄호가 있을 시 pop 없으면 break */
			else {                          
				if (s.top != -1)
					Pop(&s);
				else {
					no_flag = 1;
					break;
				}
			}
		}

		if (s.top == -1 && no_flag == 0)
			printf("YES\n");
		else
			printf("NO\n");
		no_flag = 0;
	}
}