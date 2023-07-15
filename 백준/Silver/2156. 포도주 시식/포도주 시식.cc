#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int arr[10001]={};
	int dp[10001]={};
	int n;
	cin>>n;
	int k;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	dp[0]=arr[0];
	dp[1]=arr[1];
	dp[2]=arr[1]+arr[2];
	for(int i=3;i<=n;i++)
	{
		dp[i]=max(dp[i-3]+arr[i]+arr[i-1],max(dp[i-2]+arr[i],dp[i-1]));
	}
	cout<<dp[n];
}