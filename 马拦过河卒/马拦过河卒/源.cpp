#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

//棋盘上 AA 点有一个过河卒，需要走到目标 BB 点。卒行走的规则：可以向下、或者向右。同时在棋盘上 CC 点有一个对方的马，
//该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。
//棋盘用坐标表示，AA 点(0, 0)(0, 0)、BB 点(n, m)(n, m)，同样马的位置坐标是需要给出的。


                    //题目起点从（0，0）开始，我们要防越界，所以全部加1，即从（1，1）开始
long long dp[25][25];   //开long long 因为是指数次，基本是*2*2*2*2那种
long long a[25][25];
int main() {
	memset(dp, 0, sizeof(dp));
	memset(a, 0, sizeof(a));
	int x1, y1, x2, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	a[x2+1][y2+1] = -1; a[x2-1][y2] = -1; a[x2][y2-1] = -1; a[x2+3][y2+2] = -1; a[x2+2][y2+3] = -1; a[x2-1][y2+2] = -1; a[x2][y2+3] = -1; a[x2+2][y2-1] = -1; a[x2+3][y2] = -1;
	for (int i = 1; i <= x1+1; ++i) {
		for (int j = 1; j <= y1+1; ++j) {
			if (i == 1 && j == 2) {
				if (a[i][j] != -1)dp[i][j] = 1;
			}
			else if (i == 2 && j == 1) {
				if (a[i][j] != -1)dp[i][j] = 1;
			}
			else {
				if (a[i - 1][j] != -1)dp[i][j] += dp[i - 1][j];
				if (a[i][j - 1] != -1)dp[i][j] += dp[i][j - 1];
			}

		}
	}
	printf("%lld\n", dp[x1+1][y1+1]);
	return 0;
}