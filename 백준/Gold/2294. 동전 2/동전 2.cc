#include<iostream>
#include<algorithm>
using namespace std;


int dp[10001]={};
int coin[100]={};
int n,k;

int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>coin[i];
	for(int i=1;i<=k;i++)
		dp[i] = 10001;
	for(int i=0;i<n;i++)
	{
		if(coin[i]>k)
			continue;
		for(int j=coin[i];j<=k;j++)
		{
			dp[j] = min(dp[j],dp[j-coin[i]]+1);
		}
	}
	if(dp[k]==10001)
		cout<<-1;
	else
		cout<<dp[k];
}