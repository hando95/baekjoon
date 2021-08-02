#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
N!에서 i의 지수의 개수를 구하는 방법
-> N을 i^k로 계속 나누어주기

ex) N = 25, i = 2
25 / 2 = 12    (2, 4, 6, ..., 24)
25 / 4 = 6     (4, 8, 12, 20, 24)
25 / 8 = 3     (8, 16, 24)
25 / 16 = 1    (16)

-> 25!에 포함된 2의 지수 개수 = 12 + 6 + 3 + 1 == 22

*/


long long GetMin(long long a, long long b) {
    return a < b ? a : b;
}

/* n!에서 x의 지수를 구하는 함수 */
long long CountExp(int n, int x) {
    long long count = 0;
    for (long long i = x; i <= n; i *= x)
        count += n / i;

    return count;
}

int main() {
    long long n, m;
    long long two, five;

    scanf("%lld %lld", &n, &m);

    two = CountExp(n, 2) - CountExp(m, 2) - CountExp(n - m, 2);
    five = CountExp(n, 5) - CountExp(m, 5) - CountExp(n - m, 5);

    if (two <= 0 || five <= 0)
        printf("0\n");
    else 
        printf("%llu\n", GetMin(two, five));

    return 0;
}

// reference: https://j3sung.tistory.com/235