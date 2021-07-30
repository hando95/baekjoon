#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	char wear[21];       // 옷 이름
	char kind[21];       // 옷 종류
}fashion;

fashion cloth[100][30];  // 모든 케이스의 옷

/* 옷 종류를 사전 순으로 정렬하는 함수 */
void SortClothesKind(int t, int n) {
	fashion temp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (strcmp(cloth[t][j].kind, cloth[t][i].kind) > 0) {
				temp = cloth[t][i];
				cloth[t][i] = cloth[t][j];
				cloth[t][j] = temp;
			}
		}
	}
}


int main() {
	int t, n;         // 테스트케이스, 옷 개수
	int cnt = 1, ans = 1;
	fashion temp;

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		
		/* 옷이 없으면 0 */
		if (n == 0) {
			printf("%d\n", 0);
			continue;
		}

		for (int j = 0; j < n; j++)
			scanf("%s %s", cloth[i][j].wear, cloth[i][j].kind);

		/* 옷 종류별로 정렬 */
		SortClothesKind(i, n);
		temp = cloth[i][0];

		/* 같은 옷이 있으면 cnt로 세고 없으면 결과에 곱 */
		for (int j = 1; j < n; j++) {
			if (strcmp(temp.kind, cloth[i][j].kind) == 0){
				cnt++;
			}
			else {
				temp = cloth[i][j];
				ans *= (cnt + 1);
				cnt = 1;
			}
		}
		ans *= (cnt + 1);

		printf("%d\n", ans - 1);

		/* 다음 테스트케이스를 위한 초기화 */
		cnt = 1;
		ans = 1;
	}
	return 0;
}