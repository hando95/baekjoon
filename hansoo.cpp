#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int hansoo_count(int n) {
	int a, b, c, temp;
	int total = 99;
	
	if (n / 100 == 0)
		return n;

	else {
		for (int i = 100; i < n + 1; i++) {
			temp = i;
			a = temp/ 100;    // first
			temp %= 100;
			b = temp / 10;    // second
			temp %= 10;
			c = temp;         // third
			if ((a - b) == (b - c))
				total += 1;
		}

		return total;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", hansoo_count(n));
}