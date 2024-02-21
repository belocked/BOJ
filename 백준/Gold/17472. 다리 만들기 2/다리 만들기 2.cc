#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int y, x;

int field[10][10] = {};
bool used[10][10] = {};
int is_cnt = 0;
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int dif[7][7] = {};

int arr[7] = {};

struct edge {
	int a, b, cost;
};

bool comp(edge a, edge b)
{
	return a.cost < b.cost;
}
vector<edge> edges;

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

void bfs(int cy, int cx)
{
	is_cnt++;
	queue < pair<int, int>> q;
	q.push({ cy,cx });
	used[cy][cx]=true;
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		field[cy][cx] = is_cnt;
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || nx >= x || ny >= y)
				continue;
			if (!used[ny][nx] && field[ny][nx] == 1)
			{
				used[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}


void getdist(int yy, int xx)
{
	int from = field[yy][xx];
	for (int i = 1; i < 10; i++)
	{
		int ny = yy + i;
		int nx = xx;
		if (ny < 0 || nx < 0 || nx >= x || ny >= y)
			break;
		if (field[ny][nx] == from)
			break;
		if (field[ny][nx] != from && field[ny][nx])
		{
			if (i < 3)
				break;
			int to = field[ny][nx];
			if (!dif[from][to])
				dif[from][to] = i-1;
			else
				dif[from][to] = min(dif[from][to], i-1);
			break;
		}
	}
	for (int i = 1; i < 10; i++)
	{
		int ny = yy - i;
		int nx = xx;
		if (ny < 0 || nx < 0 || nx >= x || ny >= y)
			break;
		if (field[ny][nx] == from)
			break;
		if (field[ny][nx] != from && field[ny][nx])
		{
			if (i < 3)
				break;
			int to = field[ny][nx];
			if (!dif[from][to])
				dif[from][to] = i-1;
			else
				dif[from][to] = min(dif[from][to], i-1);
			break;
		}
	}	
	for (int i = 1; i < 10; i++)
	{
		int ny = yy;
		int nx = xx+i;
		if (ny < 0 || nx < 0 || nx >= x || ny >= y)
			break;
		if (field[ny][nx] == from)
			break;
		if (field[ny][nx] != from && field[ny][nx])
		{
			if (i < 3)
				break;
			int to = field[ny][nx];
			if (!dif[from][to])
				dif[from][to] = i-1;
			else
				dif[from][to] = min(dif[from][to], i-1);
			break;
		}
	}
	for (int i = 1; i < 10; i++)
	{
		int ny = yy;
		int nx = xx-i;
		if (ny < 0 || nx < 0 || nx >= x || ny >= y)
			break;
		if (field[ny][nx] == from)
			break;
		if (field[ny][nx] != from && field[ny][nx])
		{
			if (i < 3)
				break;
			int to = field[ny][nx];
			if (!dif[from][to])
				dif[from][to] = i-1;
			else
				dif[from][to] = min(dif[from][to], i-1);
			break;
		}
	}
}


int main()
{

	cin >> y >> x;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
			cin >> field[i][j];
	}
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
			if (field[i][j]&&!used[i][j])
				bfs(i, j);
	}

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (field[i][j])
				getdist(i, j);
		}
	}
	for (int i = 1; i <= is_cnt; i++)
	{
		for (int j = i; j <= is_cnt; j++)
		{
			if (dif[i][j])
				edges.push_back({ i,j,dif[i][j] });
		}
	}
	sort(edges.begin(), edges.end(), comp);
	for (int i = 0; i < 7; i++)
		arr[i] = i;

	int cost = 0;
	for (edge i : edges)
	{
		if (find(i.a) == find(i.b))
			continue;
		cost += i.cost;
		un(i.a, i.b);
		is_cnt--;
		if (is_cnt == 1)
			break;
	}
	if (is_cnt == 1)
		cout << cost;
	else
		cout << -1;
}