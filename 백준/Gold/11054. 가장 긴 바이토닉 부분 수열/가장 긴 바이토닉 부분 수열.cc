#include<iostream>
#include<algorithm>
using namespace std;

int org[1001]={};
int front[1001]={};
int back[1001]={};
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin >>org[i];
	
	//현재 위치에서 앞에 있는 칸들중 자신보다 작고 가장 긴 수열에서 +1로 채움
	for(int i=1;i<=n;i++)
	{
		front[i]=1;
		for(int j=1;j<i;j++)
		{
			if(org[i]>org[j])
				front[i]=max(front[j]+1,front[i]);
		}
	}

	//위와 같은 원리지만 뒤에서 부터 채움
	for(int i=n;i>=1;i--)
	{
		back[i]=1;
		for(int j=n;j>i;j--)
		{
			if(org[i]>org[j])
				back[i]=max(back[j]+1,back[i]);
		}
	}
	int ret=0;
	//각 지점에서 앞에서 뒤에서 길이를 더하고 중점은 2번 들어가니 -1 해서 최댓값 탐색
	for(int i=1;i<=n;i++)
		ret = max(ret,front[i]+back[i]-1);
	cout<<ret;
}
