#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n;
struct edge {
	int to, cost;
};
vector <edge> edges[1001];
bool operator<(edge l, edge r) {
	if (l.cost < r.cost)
		return false;
	if (l.cost > r.cost)
		return true;
	if (l.to < r.to)
		return false;
	if (l.to > r.to)
		return true;
	return false;
}
int dist[1001] = {};
int tar[1001] = {};
bool used[1001] = {};

int main()
{
	cin >> n;
	int m;
	cin >> m;
	for (int i = 0; i <= n; i++)
	{
		dist[i] = 212345678;
	}
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
	}
	int start, end;
	cin >> start >> end;
	dist[start] = 0;
	priority_queue<edge> pq;
	pq.push({ start,0 });
	while (!pq.empty())
	{
		int now = pq.top().to;
		int nowcost = pq.top().cost;
		pq.pop();
		if (used[now])
			continue;
		used[now] = true;
		for (edge i : edges[now])
		{
			int nextcost = nowcost + i.cost;
			if (nextcost >= dist[i.to])
				continue;
			dist[i.to] = nextcost;
			tar[i.to] = now;
			pq.push({ i.to,nextcost });
		}
	}
	cout << dist[end]<<endl;
	int last = end;
	vector<int> uselist;
	while (last)
	{
		uselist.push_back(last);
		last = tar[last];
	}
	cout << uselist.size() << endl;
	for (int i = uselist.size() - 1; i >= 0; i--)
		cout << uselist[i] << ' ';
}