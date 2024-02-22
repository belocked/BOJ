#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[100001] = {};

struct edge {
	int a, b, c;
};

vector<edge> edges;

bool comp(edge a, edge b) {
	return a.c < b.c;
}

int find(int a)
{
	if (a == arr[a])
		return a;
	int ret = find(arr[a]);
	arr[a] = ret;
	return ret;
}

void un(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)
		return;
	arr[t2] = t1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ a,b,c });
	}
	sort(edges.begin(), edges.end(), comp);
	for (int i = 1; i <= n; i++)
		arr[i] = i;

	int cnt = n - 2;
	int cost = 0;
	for (edge i : edges)
	{
		if (!cnt)
			break;
		if (find(i.a) == find(i.b))
			continue;
		cnt--;
		cost += i.c;
		un(i.a, i.b);
	}
	cout << cost;

}