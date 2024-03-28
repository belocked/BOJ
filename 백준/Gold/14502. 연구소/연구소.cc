#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int arr[8][8] = {};
int wall[3] = {};
vector<int> w_list;
vector<int> v_list;
int mx = 0;
struct pos {
	int y, x;
};
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };


void bfs()
{
	int cnt = 0;
	queue<pair<pos, int>> q;
	bool used[8][8] = {};
	for (int i = 0; i < v_list.size(); i++)
		q.push({ {v_list[i] / 10,v_list[i] % 10},i + 1 });
	cnt = v_list.size();
	while (!q.empty())
	{
		pos npos = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = npos.y + dy[i];
			int nx = npos.x + dx[i];
			if (ny < 0 || nx < 0 || nx >= m || ny >= n)
				continue;
			if (arr[ny][nx] != 0)
				continue;
			if (used[ny][nx])
				continue;
			used[ny][nx] = true;
			cnt++;
			q.push({ {ny,nx},cnt});
		}
	}
	mx = max(mx, (int)(w_list.size()+v_list.size()-cnt-3));
}


void comb(int depth, int pre)
{
	if (depth == 3)
	{
		arr[wall[0] / 10][wall[0] % 10] = 1;
		arr[wall[1] / 10][wall[1] % 10] = 1;
		arr[wall[2] / 10][wall[2] % 10] = 1;
		bfs();
		arr[wall[0] / 10][wall[0] % 10] = 0;
		arr[wall[1] / 10][wall[1] % 10] = 0;
		arr[wall[2] / 10][wall[2] % 10] = 0;
		return;
	}
	for (int i = pre; i < w_list.size(); i++)
	{
		wall[depth] = w_list[i];
		comb(depth + 1, i + 1);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				w_list.push_back(i * 10 + j);
			if (arr[i][j] == 2)
				v_list.push_back(i * 10 + j);
		}
	}
	comb(0, 0);
	cout << mx;

}