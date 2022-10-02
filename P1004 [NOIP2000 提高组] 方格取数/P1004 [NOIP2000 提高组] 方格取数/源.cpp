#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

//
//拿到这道题是，我首先是想用动规跑两次，然后发现其实是不行的。如果用两次的动规取每次的最大值，其实是贪心的思想，因为分别跑时并没有考虑到另一次的路程。所以这种只是具体过程中用的是动态规划而已（下面的简单例子即可说明为何不行）：
//0 3 5
//2 6 0
//0 4 0
//第一次求最大值的话，是0->3->6->4->0
//第二次求最大值的话，是0->3（已经被去掉了，为了方便看）->5->0->0
//合起来是18，而实际答案应该是20：
//第一次：0->3->5->0->0
//第二次：0->2->6->4->0
//所以这题其实是经典的思维DP，我们用数组dp[i][j][k][l]表示第一次走到(i, j)时和第二次走到(k, l)时的最大值能取到多少。

  //所以要俩人一起走，但是四维数组太大了，想办法运用关系压成三维
long long dp[20][20][100];   //dp[i][j][k]表示第一个人x坐标上走的路i，和第二个人x坐标走的路j,k表示走的总路程，则各自y轴走了k-i,与k-j，这样就三维
int arr[20][20];



int main() {
	int n;
	scanf("%d", &n);
	int a, b, c;
	while (scanf("%d %d %d", &a, &b, &c) == 3 && (a || b || c))arr[a][b] = c;
	dp[1][1][1] = arr[1][1];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= 2 * n; ++k) {
				if (i != j) {
					dp[i][j][k] = max(dp[i - 1][j - 1][k - 1], max(dp[i][j][k - 1], max(dp[i - 1][j][k - 1], dp[i][j - 1][k - 1])))+arr[i][k-i]+arr[j][k-j];
				}
				else
					dp[i][j][k] = max(dp[i - 1][j - 1][k - 1], max(dp[i][j][k - 1], max(dp[i - 1][j][k - 1], dp[i][j - 1][k - 1]))) + arr[i][k - i];

			}
		}
	}
	printf("%lld\n", dp[n][n][2*n]);
	return 0;
}







//
//某人从图的左上角的 AA 点出发，可以向下行走，也可以向右走，直到到达右下角的 BB 点。在走过的路上，他可以取走方格中的数（取走后的方格中将变为数字 00）。
//此人从 AA 点到 BB 点共走两次，试找出 22 条这样的路径，使得取得的数之和为最大。
//
//输入格式
//输入的第一行为一个整数 NN（表示 N \times NN×N 的方格图），接下来的每行有三个整数，前两个表示位置，第三个数为该位置上所放的数。一行单独的 00 表示输入结束。
//
//输出格式
//只需输出一个整数，表示 22 条路径上取得的最大的和。

