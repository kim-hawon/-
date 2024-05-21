#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c) {
    if (a > b && a > c) return a;
    else if (b > c) return b;
    else return c;
}

int main() {
    int n;
    scanf_s("%d", &n);
    int* wine = (int*)malloc(n * sizeof(int));
    int* dp = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf_s("%d", &wine[i]);
    }

    if (n == 1) {
        printf("%d\n", wine[0]);
        return 0;
    }

    dp[0] = wine[0]; //첫 번째 포도주만 마셨을 때 최대값
    dp[1] = wine[0] + wine[1]; //두 번째 포도주 까지 마셨을 때 최대값
    dp[2] = max(wine[0] + wine[2], wine[1] + wine[2], wine[0] + wine[1]); //세 번째 포도주 까지 마셨을 때 최대값

    //점화적으로 문제 해결
    for (int i = 3; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]); 
    }

    printf("%d\n", dp[n - 1]);

    free(wine);
    free(dp);

    return 0;
}
