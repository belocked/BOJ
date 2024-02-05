#include<iostream>
#include<vector>

using namespace std;

vector<int> v[101];
bool used[101] = {};
int n;
int x, y;
int dis = -1;
void dfs(int k, int depth)
{
	if (k == y)
	{
		dis = depth;
		return;
	}
	for (auto i : v[k])
	{
		if (!used[i])
		{
			used[i] = true;
			dfs(i, depth + 1);
			used[i] = false;
		}
	}
}

int main()
{
	cin >> n;
	cin >> x >> y;
	int m;
	cin >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	used[x] = true;
	dfs(x,0);
	cout << dis;
}