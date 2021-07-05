#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM 10000
#include <stdio.h>
#include <stdlib.h>


/*
카운팅 정렬
1) arr[0...n], arr[1...n], ... , arr[n - 1, n], arr[n]을 순회한다.
2) 각 수마다 누적합을 구한다.
3) 누적합 자리에 해당 수를 대입하고 누적합을 1 줄인다.
4) 같은 수가 존재한다며 줄인 누적합 자리에 해당 수가 들어온다.
*/

// 밑의 코드는 메모리 제한을 성립시키기 위한 간략 코드

int main(){
    int n;
    int temp;
    int count[10001] = { 0, };
    int i = 0, j = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        count[temp]++;
    }

    for (i = 1; i < 10001; i++) {
        if (count[i]) {
            for (j = 0; j < count[i]; j++) {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}
