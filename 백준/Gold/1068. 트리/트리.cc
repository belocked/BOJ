#include<iostream>
#include<vector>
using namespace std;


vector<int> v[50];

int n,m;
int cnt=0;
void dfs(int node)
{
	if(node==m)
		return ;
	if(v[node].size()==0)
	{
		cnt++;
		return;
	}
	if(v[node].size()==1&&v[node][0]==m)
	{
		cnt++;
		return;
	}
	for(int i=0;i<v[node].size();i++)
	{
		dfs(v[node][i]);
	}
}

int main()
{
	cin>>n;
	int start = 0;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		if(k!=-1)
		{
			v[k].push_back(i);
		}
		else
			start =i;
	}
	cin>>m;
	dfs(start);
	cout<<cnt;
	
}