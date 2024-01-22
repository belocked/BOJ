#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ret = 1;
	int dp[101] = {};
	vector <pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		int left, right;
		cin >> left >> right;
		v[i].first = left;
		v[i].second = right;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (v[i].second > v[j].second && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				ret = max(ret, dp[i]);
			}
		}
	}
	cout << n - ret;
}