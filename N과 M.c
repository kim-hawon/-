#include <stdio.h>
#include <stdlib.h>

//N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성
//N개의 자연수 중에서 M개를 고른 수열
//같은 수를 여러 번 골라도 된다.
//재귀와 백트래킹 활용


// 비교 함수
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// 백트래킹 함수
void backtrack(int* numbers, int* sequence, int N, int M, int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        sequence[depth] = numbers[i];
        backtrack(numbers, sequence, N, M, depth + 1);
    }
}

int main() {
    int N, M;
    scanf_s("%d %d", &N, &M);

    int* numbers = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf_s("%d", &numbers[i]);
    }

    // 정렬
    qsort(numbers, N, sizeof(int), compare);

    int* sequence = (int*)malloc(M * sizeof(int));

    // 백트래킹 시작
    backtrack(numbers, sequence, N, M, 0);

    // 메모리 해제
    free(numbers);
    free(sequence);

    return 0;
}
