#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct edge{
	int a,b,c;
};
vector<edge> edges;

bool comp(edge a,edge b){
	return a.c<b.c;
}

int n;
int arr[1000]={};

int find(int a)
{
	if(a==arr[a])
		return a;
	int ret = find(arr[a]);
	arr[a] = ret;
	return ret;
}

void un(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);
	if(t1==t2)
		return ;
	arr[t2] = t1;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		arr[i]=i;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int tmp;
			cin>>tmp;
			if(j>i&&tmp)
				edges.push_back({i,j,tmp});		
		}
	}
	sort(edges.begin(),edges.end(),comp);
	int cnt = n-1;
	long long int cost = 0;
	for(edge i : edges)
	{
		if(find(i.a)==find(i.b))
			continue;
		cost += i.c;
		cnt--;
		un(i.a,i.b);
		if(!cnt)
			break;
	}
	cout<<cost;
}