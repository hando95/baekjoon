#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int tile_try[1000001] = { 0, 1, 2, };

int TilePlayCount(int n) {
	int i = 0;
	
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else {
		for(i = 3; i <= n; i++)
			tile_try[i] = (tile_try[i - 1] + tile_try[i - 2]) % 15746;
	}
	return tile_try[n];
}

int main() {
	int n, i;
	
	scanf("%d", &n);
	
	printf("%d\n", TilePlayCount(n));
	return 0;
}