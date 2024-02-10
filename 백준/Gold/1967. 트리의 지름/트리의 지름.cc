#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair <int,int> > v[10001];
bool used[10001]={};
int n;
int len=0;
int point;

void dfs(int node, int cost)
{
	if(len<cost)
	{
		len = cost;
		point = node;
	}
	for(int i=0;i<v[node].size();i++)
	{
		if(!used[v[node][i].first])
		{
			used[v[node][i].first]=true;
			dfs(v[node][i].first,v[node][i].second+cost);
			used[v[node][i].first]=false;
		}
	}
}

int main()
{
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});	
	}

	used[1]=true;
	dfs(1,0);
	for(int i=1;i<=n;i++)
		used[i]=false;
	used[point]=true;
	dfs(point,0);
	cout<<len;
}
