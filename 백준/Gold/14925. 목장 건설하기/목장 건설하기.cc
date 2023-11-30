#include<iostream>
#include<algorithm>
using namespace std;
int dp[1001][1001]={};
int field[1001][1001]={};
int m,n;
int main()
{
	cin>>m>>n;
	int mx = 0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			cin>>field[i][j];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(field[i][j]==0)
			{
				if(!(dp[i-1][j]*dp[i-1][j-1]*dp[i][j-1]))
					dp[i][j] = 1;
				else
					dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
				mx = max(mx,dp[i][j]);
			}
		}
	}
	cout<<mx;
}