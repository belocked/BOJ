#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge {
	int a, b, cost;
};

bool comp(edge a, edge b)
{
	return a.cost < b.cost;
}

vector<edge> edges;
int arr[1001] = {};

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
	for (int i = 1; i <= n; i++)
		arr[i] = i;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ a,b,c });
	}
	sort(edges.begin(), edges.end(), comp);
	int cnt = n - 1;
	int cost = 0;
	for (edge i : edges)
	{
		if (find(i.a) == find(i.b))
			continue;
		cnt--;
		cost += i.cost;
		un(i.a, i.b);
		if (!cnt)
			break;
	}
	cout << cost;

}