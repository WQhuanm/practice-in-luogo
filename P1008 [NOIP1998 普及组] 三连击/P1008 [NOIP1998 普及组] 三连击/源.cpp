#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>


int arr[10];
int main() {
	int a, b, c;
	for (a = 123; a <= 987/3; ++a) {
		b = 2 * a; c = 3 * a;
		memset(arr, 0, sizeof(arr));
		arr[a / 100] = 1; arr[(a / 10) % 10] = 1; arr[a % 10] = 1;
		arr[b / 100] = 1; arr[(b / 10) % 10] = 1; arr[b % 10] = 1;
		arr[c / 100] = 1; arr[(c / 10) % 10] = 1; arr[c % 10] = 1;
		for (int i = 1; i <= 9; ++i) {
			if (arr[i] == 0)goto abc;
		}
		printf("%d %d %d\n", a, b, c);
	abc:;
	}


	return 0;
}