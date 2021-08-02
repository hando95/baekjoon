#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>
#include <string.h>

typedef struct {
	char paren[MAX];
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
	if (s->top == MAX)
		return 1;
	else
		return 0;
}

void Push(Stacktype* s, char c) {
	if (IsFull(s))
		return;
	else
		s->paren[++(s->top)] = c;
}

void Pop(Stacktype* s) {
	if (IsEmpty(s))
		return;
	else
		s->paren[(s->top)--];
}

/* 입력 버퍼 비우는 함수 */
void ClearInputBuffer() {
	while (getchar() != '\n');
}

int main() {
	char str[101];
	int len;
	int no_flag = 0;
	Stacktype p;

	while (1) {
		Init(&p);

		scanf("%[^\n]s", str);
		ClearInputBuffer();
		len = strlen(str);

		/* 문자열이 "."이면 종료 */
		if (strcmp(str, ".") == 0)
			break;

		for (int i = 0; i < len; i++) {
			/* ( ) 괄호 확인 */
			if (str[i] == '(') {
				Push(&p, '(');
			}
			else if (str[i] == ')') {
				if (p.top == -1 || p.paren[p.top] == '[') {
					no_flag = 1;
					break;
				}
				else {
					Pop(&p);
				}
			}
			
			/* [ ] 괄호 확인 */
			if (str[i] == '[') {
				Push(&p, '[');
			}
			else if (str[i] == ']') {
				if (p.top == -1 || p.paren[p.top] == '(') {
					no_flag = 1;
					break;
				}
				else {
					Pop(&p);
				}
			}
		}

		if (p.top == -1 && no_flag == 0)
			printf("yes\n");
		else
			printf("no\n");

		no_flag = 0;
	}
}