#include <iostream>
#include <algorithm>

using namespace std;

int n, q;
long long int arr[100010] = {};
long long int tree[400040] = {};
long long int init(int begin, int end, int node)
{
	if (begin == end)
		return tree[node] = arr[begin];
	int mid = (begin + end) / 2;
	return tree[node] = init(begin, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long int find(int begin, int end, int node, int left, int right)
{
	if (left > end || right < begin)
		return 0;
	if (left <= begin && right >= end)
		return tree[node];
	int mid = (begin + end)/2;
	return find(begin,mid,node*2,left,right)+find(mid+1,end,node*2+1,left,right);
}

void update(int begin, int end, int node, int idx, long long int var)
{
	if (idx < begin || idx > end)
		return;
	tree[node] += var;
	if(begin==end)
		return ;
	int mid = (begin + end) / 2;
	update(begin, mid, node * 2, idx, var);
	update(mid + 1, end, node * 2 + 1, idx, var);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	init(0, n - 1, 1);
	while (q--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << find(0, n - 1, 1, min(a, b) - 1, max(a, b) - 1) << '\n';
		long long int var = arr[c - 1];
		var = d - var;
		arr[c - 1] = d;
		update(0, n - 1, 1, c - 1, var);
	}
}