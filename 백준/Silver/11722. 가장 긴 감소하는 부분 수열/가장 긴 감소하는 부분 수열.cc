#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[1001] = {};
int dp[1001] = {};

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dp[0] = 1;
	int total = 1;
	for (int i = 1; i < n; i++)
	{
		int mx = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i])
			{
				mx = max(dp[j], mx);
			}
		}
		dp[i] = mx + 1;
		total = max(total, dp[i]);
	}
	cout << total;
}