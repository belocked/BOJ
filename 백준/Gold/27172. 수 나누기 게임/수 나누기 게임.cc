#include<iostream>

using namespace std;
int n;
int score[1000001]={};
int num[100001]={};
bool used[1000001]={};
void check(int k)
{
	for(int i=1;i*i<=k;i++)
	{
		if(k%i==0)
		{
			if(used[i])
			{
				score[i]++;
				score[k]--;
			}
			if((i*i)!=k&&used[k/i])
			{
				score[k/i]++;
				score[k]--;
			}
		}
	}
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		used[num[i]]=true;
	}
	for(int i=0;i<n;i++)
		check(num[i]);

	for(int i=0;i<n;i++)
		cout<<score[num[i]]<<' ';
}