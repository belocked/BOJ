#include<iostream>
#include<algorithm>

using namespace std;

long long int arr[1000000] = {};
long long int tree[4000001] = {};
int n, m, k;
long long int init(int begin, int end, int node)
{
	if (begin == end)
		return tree[node] = arr[begin];
	int mid = (begin + end) / 2;
	return tree[node] = init(begin, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int begin, int end, int node, int idx, long long int val)
{
	if (idx<begin || idx>end)
		return;
	int mid = (begin + end) / 2;
	tree[node] += val;
	if (begin == end)
		return;
	update(begin, mid, node * 2, idx, val);
	update(mid+1,end, node * 2+1, idx, val);
}

long long int find(int begin, int end, int left, int right, int node)
{
	if (left>end || right<begin)
		return 0;
	if (left <= begin && right >= end)
		return tree[node];
	int mid = (begin + end) / 2;
	return find(begin, mid, left, right, node * 2) + find(mid + 1, end, left, right, node * 2+1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	init(0, n - 1, 1);
	for (int i = 0; i < m + k; i++)
	{
		long long int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(0, n - 1, 1, b-1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
		else
		{
			cout << find(0, n - 1, b - 1, c - 1, 1)<<'\n';
		}
	}
}