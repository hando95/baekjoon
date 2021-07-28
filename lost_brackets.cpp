#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int GetMinValue(char* ath, int len) {
	int operand[26] = { 0, };
	int idx = 0, num = 0, sum = 0;
	int ans;

	/* '-'가 나올 때마다 그 전까지의 수를 다 합해서 num에 저장 */
	for (int i = 0; i < len; i++) {
		if (ath[i] == '-') {
			sum += num;
			operand[idx++] = sum;
			sum = 0;
			num = 0;
		}
		else if (ath[i] == '+') {
			sum += num;
			num = 0;
		}
		else {
			num *= 10;                // 숫자가 연속될 때 자리수 올려주는 역할
			num += (ath[i] - '0');    // 맨 뒤 자리수 설정 역할
		}
	}

	/* 마지막 수 저장 */
	sum += num;
	operand[idx++] = sum;
	ans = operand[0];
	for (int i = 1; i <= idx; i++) {
		ans -= operand[i];
	}
	return ans;
}


int main() {
	char ath[51];
	
	scanf("%s", ath);
	printf("%d\n", GetMinValue(ath, strlen(ath)));
	return 0;
}

// reference: https://gogojung.tistory.com/category/%EB%B0%B1%EC%A4%80%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98