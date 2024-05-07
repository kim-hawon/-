#include<stdio.h>

int main() {
	int n = 1, m = 1;
	int count = 0;
	scanf_s("%d %d", &n, &m);
	count += (m-1);
	count += m * (n-1);
	printf("%d", count);
	return 0;
}
