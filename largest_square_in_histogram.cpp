#define _CRT_SECURE_NO_WARNINGS
#define MAX_SQUARE_NUM 100000
#include <stdio.h>

long long sq_h[MAX_SQUARE_NUM];
long long pop_idx, pop_h;

typedef struct {
	long long index[MAX_SQUARE_NUM];
	long long height[MAX_SQUARE_NUM];
	int top;
}Stacktype;

Stacktype his;

void InitStack(Stacktype* s) {
	s->top = -1;
}

int IsEmpty(Stacktype* s) {
	return s->top == -1;
}

int IsFull(Stacktype* s) {
	return s->top == MAX_SQUARE_NUM;
}

void Push(Stacktype* s, int idx, int h) {
	if (IsFull(s))
		return;
	s->top++;
	s->index[s->top] = idx;
	s->height[s->top] = h;
}

void Pop(Stacktype* s) {
	if (IsEmpty(s))
		return;
	pop_idx = s->index[s->top];
	pop_h = s->height[s->top];
	s->top--;
}

long long TopHeight(Stacktype* s) {
	return s->height[s->top];
}

long long GetMax(long long a, long long b) {
	return a < b ? b : a;
}

long long GetMaxSquare(Stacktype* s, int n) {
	long long min_idx = 0;
	long long max_area = 0;

	/* 모든 직사각형 검사 */
	for (int idx = 0; idx < n; idx++) {

		/* 비어있으면 스택에 대입 */
		if (IsEmpty(s))
			Push(s, min_idx, sq_h[idx]);

		/* 비어있지않으면 */
		else {
			
			/* 이전 높이보다 현재 높이가 더 낮으면 계산 */
			if (TopHeight(s) > sq_h[idx]) {
				while (TopHeight(s) > sq_h[idx]) {
					Pop(s);
					max_area = GetMax(max_area, ((long long)idx - pop_idx) * pop_h);
					min_idx = pop_idx;
				}

				/* 가장 낮은 직사각형이 있는 위치와 현재 높이 스택에 대입 */
				Push(s, min_idx, sq_h[idx]);
			}

			/* 이전 높이보다 현재 높이가 더 높거나 같으면 스택에 대입 */
			else
				Push(s, idx, sq_h[idx]);
		}
	}

	/* 모든 직사각형 검사 완료 */
	while (!IsEmpty(s)) {
		Pop(s);
		max_area = GetMax(max_area, ((long long)n - pop_idx) * pop_h);
	}

	return max_area;
}

int main() {
	int n;
	
	while (1) {
		/* 입력 */
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			scanf("%lld", &sq_h[i]);

		/* 히스토그램에서 가장 큰 직사각형 넓이 구하기 */
		InitStack(&his);
		printf("%lld\n", GetMaxSquare(&his, n));
	}

	return 0;
}