#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

//z型是斜45度（把三角形摆为正金字塔），一行一行取，奇数行从下开始，偶数行从上开始

int main() {
	int n;
	cin >> n;
	int k = 1;
	while (n >k) {   //其实发现n就是1到k的递增数列一直加，所以我每次n>k,我就n-k，使他进入下一行，最终n小于k时，表示n在k行的位置
		n -= k; k++;
	}
	if (k % 2 == 0)cout << n << "/" << k + 1 - n;
	else cout<<k+1-n<<"/"<<n;

	return 0;
}



//
//现代数学的著名证明之一是 Georg Cantor 证明了有理数是可枚举的。他是用下面这一张表来证明这一命题的：
//
//1 / 11 / 1, 1 / 21 / 2, 1 / 31 / 3, 1 / 41 / 4, 1 / 51 / 5, …
//
//2 / 12 / 1, 2 / 22 / 2, 2 / 32 / 3, 2 / 42 / 4, …
//
//3 / 13 / 1, 3 / 23 / 2, 3 / 33 / 3, …
//
//4 / 14 / 1, 4 / 24 / 2, …
//
//5 / 15 / 1, …
//
//…
//
//我们以 Z 字形给上表的每一项编号。第一项是 1 / 11 / 1，然后是 1 / 21 / 2，2 / 12 / 1，3 / 13 / 1，2 / 22 / 2，…
//
//
//

  
