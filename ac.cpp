#define _CRT_SECURE_NO_WARNINGS
#define MAX_FUNC_SIZE 100001
#define MAX_DATA_SIZE 11000000
#define MAX_DEQUE_SIZE 100001
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char p[MAX_FUNC_SIZE];            // 함수 문자열
char input[MAX_DATA_SIZE];        // 수배열 문자열

typedef struct {
	int data[MAX_DEQUE_SIZE];
	int start, end;
}Dequetype;

Dequetype arr;

void Init(Dequetype* dq) {
	dq->start = dq->end = 0;
}

void Push(Dequetype* dq, int x) {
	dq->end = (dq->end + 1) % MAX_DEQUE_SIZE;
	dq->data[dq->end] = x;
}

void ShowDeque(Dequetype* dq, int reverse_flag) {
	int size;

	/* 리버스 아닐 때 */
	if (!reverse_flag) {
		size = (dq->end - dq->start + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
		
		if (size == 0) {
			printf("[]\n");
			return;
		}

		printf("[");
		for (int i = 1; i < size; i++)
			printf("%d,", dq->data[dq->start + i]);
		printf("%d]\n", dq->data[dq->start + size]);
	}

	/* 리버스일 때 */
	else {
		size = (dq->start - dq->end + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;

		if (size == 0) {
			printf("[]\n");
			return;
		}

		printf("[");
		for (int i = 1; i < size; i++)
			printf("%d,", dq->data[dq->start - i]);
		printf("%d]\n", dq->data[dq->start - size]);
	}
}

int Delete(Dequetype* dq, int reverse_flag) {
	
	/* 비어있으면 오류 */
	if (dq->start == dq->end)
		return 0;
	
	/* 리버스 아닐 때 */
	if (!reverse_flag) {
		dq->start = (dq->start + 1) % MAX_DEQUE_SIZE;
		return dq->data[dq->start];
	}
	
	/* 리버스일 때 */
	else {
		dq->start = (dq->start - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
		return dq->data[dq->start];
	}
		
}

void Reverse(Dequetype* dq, int reverse_flag) {
	int temp;

	/* 리버스 아닐 때 */
	if (!reverse_flag) {
		temp = dq->start;
		dq->start = (dq->end + 1) % MAX_DEQUE_SIZE;
		dq->end = (temp + 1) % MAX_DEQUE_SIZE;
	}

	else {
		temp = dq->start;
		dq->start = (dq->end - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
		dq->end = (temp - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	}
}

int main() {
	int t;
	int input_num, input_len, func_len;
	int temp_input[4];
	int idx = 0, temp_num = 0, mul = 1;
	int no_error_flag = 1, reverse_flag = 0;

	scanf("%d", &t);
	while (t--) {
		Init(&arr);

		/* 입력 */
		scanf("%s", p);
		scanf("%d", &input_num);
		scanf("%s", input);
		input_len = strlen(input);
		func_len = strlen(p);

		/* 입력 문자열에서 숫자 분리하여 저장 */
		for (int i = 0; i < input_len - 1; i++) {
			if (input[i] == '[' || input[i] == ']' || input[i] == ',')
				continue;

			while (input[i] >= '0' && input[i] <= '9') {
				temp_input[idx++] = input[i] - '0';
				i++;
			}

			for (int j = idx - 1; j >= 0; j--) {
				temp_num += temp_input[j] * mul;
				mul *= 10;
			}

			Push(&arr, temp_num);
			idx = 0;
			mul = 1;
			temp_num = 0;
		}

		/* 함수에 따라 처리 */
		for (int i = 0; i < func_len; i++) {
			if (p[i] == 'R') {
				Reverse(&arr,reverse_flag);
				reverse_flag = !reverse_flag;
			}
			if (p[i] == 'D') {
				no_error_flag = Delete(&arr, reverse_flag);
			}
		}
		if (no_error_flag)
			ShowDeque(&arr, reverse_flag);
		else
			printf("error\n");
		reverse_flag = 0;
		no_error_flag = 1;
	}
}