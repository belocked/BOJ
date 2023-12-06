#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long int tmp;
	long long int sum = 0;
	int start = 0, pre;
	cin>>tmp;
	sum+=tmp;
	if(tmp==0)
		start = 1;
	pre = start;
	for(int i=1;i<n;i++)
	{
		cin>>tmp;
		sum+=tmp;

		if(tmp!=0)
		{
			pre=0;
			continue;
		}
		if(pre ==1)
			pre = 0;
		else
		{
			pre = 1;
			sum++;
		}
	}
	if(start==1&&pre==1)
		sum--;
	cout<<sum<<endl;
	
}
