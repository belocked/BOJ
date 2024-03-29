#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int n, m;
int arr[1001][1001] = {};
int used[1001][1001] = {};
int mn = 1000000;
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
struct state{
	int y, x,cost,wall;
};
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string st;
		cin >> st;
		for (int j = 0; j < m; j++)
			arr[i][j + 1] = st[j]-'0';
	}
	queue<state> q;
	q.push({ 1,1,1,0 });
	used[1][1] = 1;
	while (!q.empty())
	{
		state now = q.front();
		q.pop();
		if (now.y == n && now.x == m)
		{
			cout << now.cost;
			return 0;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny <= 0 || nx <= 0 ||ny > n || nx > m)
				continue;
			if (now.wall == 1 && arr[ny][nx])
				continue;
			if (arr[ny][nx] == 1 && now.wall == 0)
			{
				q.push({ ny,nx,now.cost + 1,1 });
			}
			else if (arr[ny][nx]==0)
			{
				if (used[ny][nx] == 0)
				{
					used[ny][nx] = now.wall + 1;
					q.push({ ny,nx,now.cost + 1,now.wall});
				}
				else if (used[ny][nx] == 2 && now.wall == 0)
				{
					used[ny][nx] = 1;
					q.push({ ny,nx,now.cost + 1,0 });
				}
			}
		}
	}
	cout << -1;
}