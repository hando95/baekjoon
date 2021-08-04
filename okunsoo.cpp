#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 1000001
#include <stdio.h>
#include <stdlib.h>

/*
3 9 5 2 7
top 비교
1) 3의 idx Push                                              [0]
2) 3과 현재 수인 9 비교 -> 3 < 9                             
3) 3의 idx Pop, ans[3의 idx] = 9                             [ ], ans[0] = 9
4) 비어있으므로 9의 idx Push                                 [1]
5) 9와 현재 수인 5 비교 -> 9 > 5  =  5의 idx Push            [1 2]
6) 5와 현재 수인 2 비교 -> 5 > 2  =  2의 idx Push            [1 2 3]
7) 2와 현재 수인 7 비교 -> 2 < 7
8) 2의 idx Pop, ans[2의 idx] = 7                             [1 2], ans[3] = 7
9) 5와 현재 수인 7 비교 -> 5 < 7
10) 5의 idx Pop, ans[5의 idx] = 7                            [1], ans[2] = 7
11) 9와 현재 수인 7 비교 -> 9 > 7  =  7의 idx Push           [1 4]
12) stack에 남아있는 idx를 Pop하면서 ans[idx] = -1           ans[4] = -1, ans[1] = -1

9 -1 7 7 -1
*/

int num[MAX_SIZE];
int ans[MAX_SIZE];

typedef struct {
	int* idx_stack;
	int top;
}Ngetype;

void Init(Ngetype* s) {
	s->top = -1;
}

int IsEmpty(Ngetype* s) {
	if (s->top == -1)
		return 1;
	return 0;
}

int IsFull(Ngetype* s) {
	if (s->top == MAX_SIZE - 1)
		return 1;
	return 0;
}

void Push(Ngetype* s, int x) {
	if (IsFull(s))
		return;
	s->idx_stack[++(s->top)] = x;
}

int Pop(Ngetype* s) {
	if (IsEmpty(s))
		return -1;
	return	s->idx_stack[(s->top)--];
}

int main() {
	int n, cnt = 1;
	Ngetype s;
	s.idx_stack = (int*)malloc(sizeof(int) * MAX_SIZE);
	Init(&s);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	Push(&s, 0);
	for (int i = 1; i < n; i++) {

		/* 비어있지 않은 스택 맨 위 idx가 가리키는 num과 현재 num 비교 */
		while (!IsEmpty(&s) && num[s.idx_stack[s.top]] < num[i]) {
			ans[Pop(&s)] = num[i];
		}
		Push(&s, i);
	}

	/* 스택에 남아있는 수는 오큰수가 없으므로 -1 */
	while (!IsEmpty(&s)) {
		ans[Pop(&s)] = -1;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
    printf("\n");
	free(s.idx_stack);
	return 0;
}

// reference: https://suhwanc.tistory.com/58