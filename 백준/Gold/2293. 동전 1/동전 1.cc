#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, k;

int value[100] = {};
int dp[10001] = {};
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> value[i];
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = value[i]; j <= k; j++)
			dp[j] += dp[j - value[i]];
	}
	cout << dp[k];
}


