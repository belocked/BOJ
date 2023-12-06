#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long int tmp;
	long long int sum0 = 0;
	long long int sum1 = 0;
	int pre[2]={0,1};
	cin>>tmp;
	sum0+=tmp;
	sum1++;
	for(int i=1;i<n;i++)
	{
		cin>>tmp;
		if(tmp!=0)
		{
			pre[0]=0;
			pre[1]=0;
			sum0+=tmp;
			sum1+=tmp;
			continue;
		}
		if(pre[0]==0)
		{
			sum0++;
			pre[0]=1;
		}
		else
			pre[0]=0;
		if(pre[1]==0)
		{
			sum1++;
			pre[1]=1;
		}
		else
			pre[1]=0;
	}
	sum1-=pre[1];
	cout<<max(sum0,sum1)<<endl;
	
}
