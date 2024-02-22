#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[100000] = {};
struct edge {
	int a, b,c;
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
	int m, n;
	cin >> m >> n;
	while (m * n)
	{
		int org = 0;
		edges.clear();
		while (n--)
		{
			int a, b, c;
			cin >> a >> b >> c;
			edges.push_back({ a,b,c });
			org += c;
		}
		for (int i = 0; i < m; i++)
			arr[i] = i;
		sort(edges.begin(), edges.end(), comp);
		int cost = 0;
		int cnt = m - 1;
		for (edge i : edges)
		{
			if (find(i.a) == find(i.b))
				continue;
			cost += i.c;
			cnt--;
			un(i.a, i.b);
			if (!cnt)
				break;
		}
		cin >> m >> n;
		cout << org-cost<<endl;
	}
}