#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
Greedy하게 접근
1) SJF
짧은 회의가 두 긴 회의 중간에서 못 하게 할 수 있음
         -------
-----------
             -------------

2) FIFO
먼저 들어온 회의가 뒤의 회의를 못 하게 할 수 있음
--------------------
    -----
	       ------

3) EDF
일찍 끝나는 회의부터 시작!! 
*/

typedef struct {
    int begin;
    int end;
}meeting;

meeting m[100000];
meeting sorted[100000];

/* 일찍 끝나는 회의, 같으면 짧은 회의 순으로 정렬 */
void Merge(int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right) {
        if (m[i].end < m[j].end)
            sorted[k++] = m[i++];
        else if(m[i].end > m[j].end)
            sorted[k++] = m[j++];
        else {
            if (m[i].begin <= m[j].begin)
                sorted[k++] = m[i++];
            else
                sorted[k++] = m[j++];
        }      
    }

    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = m[l];
    }
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = m[l];
    }
    for (l = left; l <= right; l++)
        m[l] = sorted[l];
}

void MergeSort(int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid, right);
    }
}

/* 가능한 회의 최대 개수 */
int RoomMaxAssign(int n) {
    int cnt = 1;
    meeting cur = m[0];
    
    /* 정렬된 meeting 탐색하며 가능한 회의 개수 세기 */
    for (int i = 1; i < n; i++) {
        if (cur.end <= m[i].begin) {
            cnt++;
            cur = m[i];
        }
    }
    return cnt;
}

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m[i].begin, &m[i].end);
    }

    MergeSort(0, n - 1);
    printf("%d\n", RoomMaxAssign(n));

    return 0;
}