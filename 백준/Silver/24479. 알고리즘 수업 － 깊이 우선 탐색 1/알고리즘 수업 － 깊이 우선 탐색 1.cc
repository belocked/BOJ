#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> v[100001];
int visited[100001];
int result[100001];
int cnt=0;
void dfs(int r)
{
	if(visited[r])
		return;
	cnt++;
	visited[r]=1;
	result[r]=cnt;
	for(int i=0;i<v[r].size();i++)
		dfs(v[r][i]);
}
int main()
{
	int n,m,r;
	cin>>n>>m>>r;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
		sort(v[i].begin(),v[i].end());
	dfs(r);
	for(int i=1;i<=n;i++)
	{
		cout<<result[i]<<'\n';
	}
}