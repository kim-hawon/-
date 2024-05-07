#include<stdio.h>
#include<stdlib.h>
#define MAX_ARRAY 100

int main() {
	
	int size, conn;
	scanf_s("%d", &size);
	scanf_s("%d", &conn);
	int count = 1;
	int x, y;
	int arr1[MAX_ARRAY] = { 0 };
	int index1 = 0;
	int arr2[MAX_ARRAY] = { 0 };
	int index2 = 0;
	for (int i = 0;i < conn;i++) {
		scanf_s("%d %d", &x, &y);
		if (x == 1) {
			arr1[index1] = y;
			index1++;
		}
		else {
			arr2[index2] = x;
			arr2[index2 + 1] = y;
			index2 += 2;
		}
	}
	for (int i = 0;i < conn ;i++) {
		for (int j = 0;j < conn*2;j += 2) {
			if (arr1[i] == arr2[j]) {
				arr1[++index1] = arr2[j + 1];
			}
		}
	}
	int arraysize = 0;
	for (int i = 0;i < MAX_ARRAY;i++) {
		if (arr1[i] == 0) {
			arraysize = i;
			break;
		}
	}
	for (int i = 0;i < arraysize;i++) {
		if (count == 7) break;
		if (arr1[i] == i + 1) {
			count++;
			break;
		}
	}

	printf("%d", count);
	
	return 0;
}
