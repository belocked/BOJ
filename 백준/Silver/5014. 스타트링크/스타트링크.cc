#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool used[1000001] = {};

int main()
{
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	queue<pair<int, int>> q;
	q.push({ s,0 });
	used[s] = true;
	while (!q.empty())
	{
		int now = q.front().first;
		int cnt = q.front().second;
		if (now == g)
		{
			cout << cnt;
			return 0;
		}
		q.pop();
		int nu = now + u;
		int nd = now - d;
		if (nu <= f && !used[nu])
		{
			used[nu] = true;
			q.push({ nu,cnt + 1 });
		}
		if (nd > 0 && !used[nd])
		{
			used[nd] = true;
			q.push({ nd,cnt + 1 });
		}
	}
	cout << "use the stairs";
}