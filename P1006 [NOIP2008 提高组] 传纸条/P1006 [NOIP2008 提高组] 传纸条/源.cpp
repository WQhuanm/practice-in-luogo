#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int arr[60][60];
int dp[60][60][120];   //表示第一个人x坐标为i，第二个人x坐标为j，共走了k步

int main() {
	int n, m;
	scanf("%d %d", &m, &n);
	memset(arr, 0, sizeof(arr));
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= m; ++i)for (int j = 1; j <= n; ++j)scanf("%d", &arr[i][j]);
	
	for (int k = 3; k < n + m; ++k) {
		for (int i = 1; i <= m&&i<k; ++i) {        //一定要限定i与j小于k，这样才保证不会越步多余赋值给DP
			for (int j = 1; j <= m && j != i && j < k; ++j) {

				dp[i][j][k] = max(dp[i - 1][j][k - 1], max(dp[i - 1][j - 1][k - 1], max(dp[i][j][k - 1], dp[i][j - 1][k - 1]))) + arr[i][k - i] + arr[j][k - j];
			}
		}
	}
	printf("%d\n", max(dp[m][m-1][n+m-1],dp[m-1][m][n+m-1]));


	return 0;
}