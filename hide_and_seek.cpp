#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100001
#include <stdio.h>

int visited[MAX_SIZE];
int time[MAX_SIZE];
int loca_q[MAX_SIZE + 1];
int dir_x[2] = { -1, 1 };


int SeekBro(int n, int k) {
	int front = 0, rear = 0;
	int cur_x, next_x;

	visited[n] = 1;
	rear++;
	loca_q[rear] = n;

	/* 탐색 시작 */
	while (front != rear) {
		front++;
		cur_x = loca_q[front];

		/* 왼쪽 걷기, 오른쪽 걷기, 순간이동 */
		for (int i = 0; i < 3; i++) {
			if (i < 2)
				next_x = cur_x + dir_x[i];
			else
				next_x = cur_x * 2;

			/* 범위 내에서 */
			if (next_x >= 0 && next_x < MAX_SIZE) {

				/* 방문 확인 */
				if (!visited[next_x]) {
					visited[next_x] = 1;
					time[next_x] = time[cur_x] + 1;

					if (next_x == k)
						return time[next_x];

					rear++;
					loca_q[rear] = next_x;
				}
			}
		}
	}
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	// 같은 곳에 있을 때
	if (n == k) {
		printf("0\n");
		return 0;
	}

	// 다른 곳에 있을 때
	printf("%d\n", SeekBro(n, k));
	return 0;
}