#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[10001] = {};
struct edge {
	int a, b, c;
};

vector<edge> edges;

bool cmp(edge a, edge b)
{
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
	int v, e;
	cin >> v >> e;
	for (int i = 1; i <= e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ a,b,c });
	}
	sort(edges.begin(), edges.end(), cmp);
	int vcnt = v - 1;
	int cost = 0;
	for (edge i : edges)
	{
		if (!arr[i.a])
			arr[i.a] = i.a;
		if (!arr[i.b])
			arr[i.b] = i.b;
		if (find(i.a) == find(i.b))
			continue;
		vcnt--;
		un(i.a, i.b);
		cost += i.c;
		if (!vcnt)
			break;
	}
	cout << cost;
}