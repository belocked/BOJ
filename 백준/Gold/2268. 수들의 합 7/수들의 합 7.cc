#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
long long int arr[1000010]={};
long long int tree[4000040] ={};
long long int find(int begin, int end, int node, int left, int right)
{
	if(left>end||right<begin)
		return 0;
	if(left<=begin&&right>=end)
		return tree[node];
	int mid = (begin+end)/2;
	return find(begin,mid,node*2,left,right)+find(mid+1,end,node*2+1,left,right);
}

void update(int begin, int end, int node, int idx, long long int val)
{
	if(idx<begin||idx>end)
		return;
	tree[node] +=val;
	if(begin==end)
		return;
	int mid = (begin+end)/2;
	update(begin,mid,node*2,idx,val);
	update(mid+1,end,node*2+1,idx,val);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(!a)
		{
			cout<<find(0,n-1,1,min(b,c)-1,max(b,c)-1)<<'\n';
		}
		else
		{
			long long int val = c-arr[b-1];
			update(0,n-1,1,b-1,val);
			arr[b-1] = c;
		}
	}
}