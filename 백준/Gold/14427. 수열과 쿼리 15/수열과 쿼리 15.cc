#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m;
vector<int> arr;
vector<int> tree;

int init(int start, int end, int node)
{
	if (start == end)
		return tree[node] = start;
	int mid = (start + end) / 2;
	int l = init(start, mid, node * 2);
	int r = init(mid + 1, end, node * 2+1);
	if (arr[r] > arr[l]) 
		return tree[node] = l;
	else if (arr[r] < arr[l]) 
		return tree[node] = r;
	else 
		return tree[node] = min(l, r);
}
int update(int start,int end, int idx,int node)
{
	if (idx<start||idx>end||start==end)
		return tree[node];
	int mid = (start + end) / 2;
	int l = update(start, mid, idx, node * 2);
	int r = update( mid+1,end, idx, node * 2+1);
	if (arr[r] > arr[l]) 
		return tree[node] = l;
	else if (arr[r] < arr[l]) 
		return tree[node] = r;
	else 
		return tree[node] = min(l, r);
}
int main()
{
	scanf("%d", &n);
	arr.resize(n);
	tree.resize(4 * n);
	for (int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	init(0, n - 1, 1);
	scanf("%d", &m);
	while (m--)
	{
		int q;
		scanf("%d", &q);
		if (q == 1)
		{
			int i, v;
			scanf("%d%d", &i, &v);
			arr[i - 1] = v;
			update(0, n - 1, i - 1, 1);
		}
		else
			printf("%d\n",tree[1] + 1);
	}
}