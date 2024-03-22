#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;



int n, m, x;
struct edge {
	int to, cost;
};
bool operator <(edge l, edge r)
{
	if (l.cost < r.cost) return false;
	if (l.cost > r.cost) return true;
	if (l.to < r.to) return false;
	if (l.to > r.to) return true;
	return true;
}
vector<edge> edges[1001];
int mx = 0;
int distx[1001] = {};
int dist[1001] = {};
void cal(int start)
{
	if (start == x)
		return;
	for (int i = 0; i <= n; i++)
		dist[i] = 213456789;
	dist[start] = 0;
	priority_queue<edge> pq;
	pq.push({ start,0 });
	bool used[1001] = {};
	while (!pq.empty())
	{
		edge now = pq.top();
		pq.pop();
		if (used[now.to])
			continue;
		used[now.to] = true;
		for (edge i : edges[now.to])
		{
			int nextcost = now.cost + i.cost;
			if (nextcost >= dist[i.to])
				continue;
			dist[i.to] = nextcost;
			pq.push({ i.to,nextcost });
		}
	}
	mx = max(dist[x] + distx[start], mx);
}
int main()
{
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
	}
	for (int i = 0; i <= n; i++)
		distx[i] = 213456789;
	distx[x] = 0;
	priority_queue<edge> pq;
	pq.push({ x,0 });
	bool used[1001] = {};
	while (!pq.empty())
	{
		edge now = pq.top();
		pq.pop();
		if (used[now.to])
			continue;
		used[now.to] = true;
		for (edge i : edges[now.to])
		{
			int nextcost = now.cost + i.cost;
			if (nextcost >= distx[i.to])
				continue;
			distx[i.to] = nextcost;
			pq.push({ i.to,nextcost });
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cal(i);
	}
	cout << mx;
}