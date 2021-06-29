#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int decom(int n) {
	int sum = n;
	while (n != 0) {
		sum += (n % 10);
		n = n / 10;
	}
	return sum;
}


int main() {
	int n;     // 자연수
	int con = 0;   // 생성자
	int i = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		if (decom(i) == n) {
			con = i;
			break;
		}
	}
	printf("%d\n", con);
	return 0;
}