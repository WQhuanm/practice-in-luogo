#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>


int main() {
	int a, n, m, x;
	scanf("%d %d %d %d", &a, &n, &m, &x);
	long long f1 = 1; long long f2 = 1,fn=0;  
	long long sum = a;//表示目前车上人数
	

	sum = a; int k = 0;      
	for (int i = 3; i <=n-1; ++i) {
	
		if (i == 3) sum += a;
		if (i == 4)k += 1;                    //sum表示总人数，因为发现上车人数也为斐波那契数列，所以每次上车为a*f1+f2*h，h为第二站上车人数，目前未知
		if (i >= 5) {
			fn = f1 + f2;
			sum += a * f1; k += f2;
			f1 = f2; f2 = fn;

		}

	}
	int h = (m - sum) / k; int sum2 = a;   //求出h后，就是正常的重新求总人数
	f1 = a; f2 = h;
	for (int i = 3; i <=x; ++i) {
		fn = f1 + f2;
		sum2 += f1;
		f1 = f2; f2 = fn;
	}
	



	if (n == 2)printf("%d\n",a);
	else printf("%d", sum2);
	return 0;
}