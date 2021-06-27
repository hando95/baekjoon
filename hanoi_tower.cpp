#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void hanoi(int n, int from, int via, int to) { // 출발, 경유, 도착
	if (n == 1)
		printf("%d %d\n", from, to); 
	// 원반이 한 개 남으면 기둥1에서 기둥3으로
	else {
		hanoi(n - 1, from, to, via);
		// 기둥1 n-1개 -> 기둥3 -> 기둥2
		printf("%d %d\n", from, to);
		// 기둥1 큰 원반 -> 기둥3 
		hanoi(n - 1, via, from, to);
		// 기둥2 n-1개 -> 기둥1 -> 기둥3
	}
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", int(pow(2, double(n)) - 1)); // (2^n - 1)번 움직임
	hanoi(n, 1, 2, 3);  // 기둥1에서 기둥2를 거쳐 기둥3으로
	return 0;
}