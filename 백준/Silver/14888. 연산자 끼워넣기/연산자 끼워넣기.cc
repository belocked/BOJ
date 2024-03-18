#include <iostream>

using namespace std;

int n;

int numl[11] = {};
int op[4] = {};
int mn = 1000000001;
int mx = -1000000001;
void dfs(int depth, int pre)
{
	if (depth == n)
	{
		mx = max(pre, mx);
		mn = min(pre, mn);
		return;
	}
	if (op[0] > 0)
	{
		op[0]--;
		dfs(depth + 1, pre + numl[depth]);
		op[0]++;
	}
	if (op[1]>0)
	{
		op[1]--;
		dfs(depth + 1, pre - numl[depth]);
		op[1]++;
	}
	if (op[2]>0)
	{
		op[2]--;
		dfs(depth + 1, pre * numl[depth]);
		op[2]++;
	}
	if (op[3]>0)
	{
		op[3]--;
		dfs(depth + 1, pre / numl[depth]);
		op[3]++;
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> numl[i];
	}
	for (int i = 0; i < 4; i++)
		cin >> op[i];
	dfs(1, numl[0]);
	cout << mx << endl<< mn;
}