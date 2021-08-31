#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 1001
#include <stdio.h>

char map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE][2];   // 부수기 전 방문, 부수기 후 방문
int cost[MAX_SIZE][MAX_SIZE][2];      // 경로 비용
int cur_r = 0, cur_c = 0, crashed = 0;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

typedef struct {
	int r, c;
	int crashed;
}Coordtype;

typedef struct {
	Coordtype loc[MAX_SIZE];
	int front;
	int rear;
}Queuetype;

Queuetype path;

void InitQueue(Queuetype* q) {
	q->front = q->rear = 0;
}

int IsEmpty(Queuetype* q) {
	return q->rear == q->front;
}

int IsFull(Queuetype* q) {
	return (q->rear + 1) % MAX_SIZE == q->front;
}

void Enqueue(Queuetype* q, int r, int c, int crashed) {
	if (IsFull(q))
		return;
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->loc[q->rear].r = r;
	q->loc[q->rear].c = c;
	q->loc[q->rear].crashed = crashed;
}

void Dequeue(Queuetype* q) {
	if (IsEmpty(q))
		return;
	q->front = (q->front + 1) % MAX_SIZE;
	cur_r = q->loc[q->front].r;
	cur_c = q->loc[q->front].c;
	crashed = q->loc[q->front].crashed;
}

int GetMin(int a, int b) {
	return a < b ? a : b;
}

int GetMax(int a, int b) {
	return a < b ? b : a;
}

int FindPath(Queuetype* q, int sr, int sc, int n, int m) {
	int nr, nc;

	/* 출발 */
	Enqueue(&path, sr, sc, crashed);
	visited[sr][sc][crashed] = 1;
	cost[sr][sc][crashed]++;


	/* 탐색 시작 */
	while (!IsEmpty(&path)) {
		Dequeue(&path);

		/* 도착할 때의 최단 거리 */
		if (cur_r == n - 1 && cur_c == m - 1)
			return cost[n - 1][m - 1][crashed];

		for (int i = 0; i < 4; i++) {
			nr = cur_r + dr[i];
			nc = cur_c + dc[i];

			/* 범위 내에서 */
			if (nr >= 0 && nc >= 0 && nr < n && nc < m) {

				/* 벽이고 부술 기회가 남아있다면 부수고 다음 칸으로 */
				if (map[nr][nc] == '1' && crashed == 0) {
					visited[nr][nc][crashed + 1] = 1;
					cost[nr][nc][crashed + 1] = cost[cur_r][cur_c][crashed] + 1;
					Enqueue(&path, nr, nc, crashed + 1);
				}

				/* 벽이 아니면 벽을 부수고 온 여부에 따라 visited에 방문 처리 후 다음 칸으로 */
				else if (map[nr][nc] == '0' && visited[nr][nc][crashed] == 0) {
					visited[nr][nc][crashed] = 1;
					cost[nr][nc][crashed] = cost[cur_r][cur_c][crashed] + 1;
					Enqueue(&path, nr, nc, crashed);
				}
			}
		}
	}

	/* 도착 불가능 */
	return -1;
}

int main() {
	int n, m;
	int ans;

	/* 입력 */
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
			scanf("%s", map[i]);

	/* 출력 */
	printf("%d\n", FindPath(&path, 0, 0, n, m));
	return 0;
}