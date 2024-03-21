#include<iostream>
#include<algorithm>
using namespace std;
long long int n;
long long int k;
bool cnt(long long int upper)
{
	long long int ret = 0;
	for(long long int i=1;i<=n;i++)
		ret+=min(n,upper/i);
	if(ret>=k)
		return true;
	return false;
}
int main()
{
	cin>>n;
	cin>>k;
	long long int start =1;
	long long int end = n*n;
	while(start<end)
	{
		long long int mid = (start+end)/2;
		if(cnt(mid))
		{
			end = mid;
		}
		else
			start = mid + 1;
	}
	cout<<end<<'\n';
}