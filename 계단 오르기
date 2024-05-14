#include <stdio.h>
#include <stdlib.h>
#define MAXSTARE 300

int findMaxScore(int stare,int arr[]) {
	//계단 거꾸로 내려가기
	int max = arr[stare-1];
	int index1 = 0; 
	int index2 = stare - 1;
	int i1 = stare - 2, i2 = stare - 3;
	while (1) {
		index1 = index2;

		if (arr[i1] >= arr[i2]) {
			max += arr[i1];
			index2 = i1;
		}
		else {
			max += arr[i2];
			index2 = i2;
		}
		if (index1 - 1 == index2) {
			max += arr[index2 - 2];
			i1 -= 3; i2 -= 3;
		}
		else {
			i1 -= 2; i2 -= 2;
		}

		if (index1 == 2 && index2 == 1)
			break;
		else if (index2 == 1) {
			max += arr[0];
			break;
		}
	}


	return max;
}

int main() {
	int stare;
	int scores[MAXSTARE] = { 0 };
	int max_score = 0;
	scanf_s("%d", &stare);
	for (int i = 0;i < stare;i++) {
		scanf_s("%d", &scores[i]);
	}
	max_score = findMaxScore(stare,scores);
	printf("%d", max_score);

	return 0;
}
