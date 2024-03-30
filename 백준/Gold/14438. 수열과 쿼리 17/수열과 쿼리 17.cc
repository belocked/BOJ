#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n, m;
int arr[100010] = {};
int tree[400040] = {};

int init(int begin, int end, int node)
{
	if (begin == end)
		return tree[node] = arr[begin];
	int mid = (begin + end) / 2;
	return tree[node] = min(init(begin, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int find(int begin, int end, int node, int left, int right)
{
	if (left > end || right < begin)
		return 1111111111;
	if (left <= begin && right >= end)
		return tree[node];
	int mid = (begin + end) / 2;
	return min(find(begin, mid, node * 2, left, right), find(mid + 1, end, node * 2 + 1, left, right));
}

int update(int begin, int end, int node, int idx, int val)
{
	if (idx<begin || idx>end)
		return tree[node];
	if (begin == end)
		return tree[node] = val;
	int mid = (begin + end) / 2;
	return tree[node] = min(update(begin, mid, node * 2, idx, val), update(mid + 1, end, node * 2 + 1, idx, val));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	init(0, n - 1, 1);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a>>b>>c;
		if (a == 1)
		{
			update(0, n - 1, 1, b - 1, c);
		}
		else
		{
			cout << find(0, n - 1, 1, b - 1, c - 1)<<'\n';
		}
		int idx = 1;
		/*for (int i = -1; n > pow(2, i); i++)
		{
			for (int j = 0; j < pow(2, i+1); j++)
			{
				cout << tree[idx] << ' ';
				idx++;
			}
			cout << endl;
		}*/
	}
}