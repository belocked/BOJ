#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int arr[100001] = {};

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= 100000; i++)
		arr[i] = 100001;
	arr[n] = 0;
	queue<pair<int, int>> q;
	q.push({ n,0 });
	while (!q.empty())
	{
		int now = q.front().first;
		int cost = q.front().second;
		q.pop();
		if (arr[now] < cost)
			continue;
		if (now < 100000)
		{
			if (arr[now + 1] > cost + 1)
			{
				arr[now + 1] = cost + 1;
				q.push({ now + 1,cost + 1 });
			}
		}
		if (now > 0)
		{
			if (arr[now - 1] > cost + 1)
			{
				arr[now - 1] = cost + 1;
				q.push({ now - 1,cost + 1 });
			}
		}
		if (now <= 50000)
		{
			if (arr[now * 2] > cost)
			{
				arr[now * 2] = cost;
				q.push({ now * 2,cost });
			}
		}
	}
	cout << arr[k];
}