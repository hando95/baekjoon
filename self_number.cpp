#include <stdio.h>

int check_list[10000] = { 0, };

void d(int num) {	
	int result = num;
	int a, b, c, d, e;
	a = num / 10000;
	num %= 10000;
	b = num / 1000;
	num %= 1000;
	c = num / 100;
	num %= 100;
	d = num / 10;
	num %= 10;
	e = num;
	result = result + a + b + c + d + e;

	if (result > 10000)
		return;
	check_list[result - 1] = 1;
}

int main() {
	int n = 1;
	for (int i = 0; i < 10000; i++) {
		d(i);
	}
	for (int i = 0; i < 10000; i++) {
		if (check_list[i] == 0)
			printf("%d\n", i + 1);
	}
}