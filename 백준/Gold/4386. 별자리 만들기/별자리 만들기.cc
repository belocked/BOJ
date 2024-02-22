#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[101] = {};
double coor[101][2] = {};
struct edge {
	int a, b;
	double c;
};

vector<edge> edges;

bool comp(edge a, edge b) {
	return a.c < b.c;
}

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

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> coor[i][0];
		cin >> coor[i][1];
	}
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			edges.push_back({ i,j,sqrt(pow(coor[i][0] - coor[j][0],2) + pow(coor[i][1] - coor[j][1],2)) });
		}
	}
	sort(edges.begin(), edges.end(), comp);
	for (int i = 1; i <= n; i++)
		arr[i] = i;

	int cnt = n - 1;
	double cost = 0;
	for (edge i : edges)
	{
		if (find(i.a) == find(i.b))
			continue;
		cnt--;
		cost += i.c;
		un(i.a, i.b);
		if (!cnt)
			break;
	}
	cout << cost;

}