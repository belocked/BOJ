#include <iostream>
using namespace std;
int n;
int arr[100][100] = {};
long long int dp[100][100] = {};
void print()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<dp[i][j]<<' ';
		cout<<endl;
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	dp[0][0] = 1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==n-1&&j==n-1)
				break;
			if(arr[i][j]+j<n)
				dp[i][j+arr[i][j]]+=dp[i][j];
			if(arr[i][j]+i<n)
				dp[i+arr[i][j]][j]+=dp[i][j];
		}
	}
	cout<<dp[n-1][n-1];
}