#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int dist[50001] = {};
struct edge {
	int to, cost;
};
vector<edge> edges[50001];
bool operator<(edge l, edge r) {
	if (l.cost < r.cost) return false;
	if (l.cost > r.cost) return true;
	if (l.to < r.to) return false;
	if (l.to > r.to) return true;
	return true;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dist[i] = 21e7;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}
	dist[1] = 0;
	priority_queue<edge> pq;
	pq.push({ 1,0 });
	bool used[50001] = {};
	while (!pq.empty())
	{
		int now = pq.top().to;
		int cost = pq.top().cost;
		pq.pop();
		if (used[now])
			continue;
		used[now] = true;
		for (int i = 0; i < edges[now].size(); i++)
		{
			int next = edges[now][i].to;
			int nextcost = edges[now][i].cost + cost;
			if (dist[next] <= nextcost)
				continue;
			dist[next] = nextcost;
			pq.push({ next,nextcost });
		}
	}
	cout << dist[n];
}