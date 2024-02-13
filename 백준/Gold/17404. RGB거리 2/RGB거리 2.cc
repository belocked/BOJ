#include<iostream>
#include<algorithm>

using namespace std;

int n;
int cost[1001][3] = {};
int dp[3][1001][3] = {};

int main()
{
	int ans = 10000000;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i][0];
		cin >> cost[i][1];
		cin >> cost[i][2];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dp[i][1][j] = cost[1][j];
			if (i != j)
				dp[i][1][j] += 1000000;
		}
		for (int j = 2; j <= n; j++)
		{
			dp[i][j][0] = min(dp[i][j-1][1], dp[i][j-1][2]) + cost[j][0];
			dp[i][j][1] = min(dp[i][j-1][0], dp[i][j-1][2]) + cost[j][1];
			dp[i][j][2] = min(dp[i][j-1][1], dp[i][j-1][0]) + cost[j][2];
		}
		int tmp = min(dp[i][n][(i+1)%3], dp[i][n][(i+2)%3]);
		ans = min(tmp, ans);
	}
	cout << ans;
}