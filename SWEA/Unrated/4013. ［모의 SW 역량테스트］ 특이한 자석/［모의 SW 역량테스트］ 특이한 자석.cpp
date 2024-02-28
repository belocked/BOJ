#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


vector<int> v[4];

int rot[4] = {};

void vrot(int idx, int dir)
{
	if (dir == 1)
	{
		int temp = v[idx][7];
		v[idx].pop_back();
		v[idx].insert(v[idx].begin(), temp);
	}
	else if(dir==-1)
	{
		int temp = v[idx][0];
		v[idx].erase(v[idx].begin());
		v[idx].push_back(temp);
	}
}



int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		int k;
		cin >> k;
		for (int i = 0; i < 4; i++)
		{
			v[i].clear();
			v[i].resize(8);
			for (int j = 0; j < 8; j++)
				cin >> v[i][j];
		}
		while (k--)
		{
			int idx, dir;
			cin >> idx >> dir;
			for (int i = 0; i < 4; i++)
				rot[i] = 0;
			rot[idx - 1] = dir;
			for (int i = idx-2;i>=0; i--)
			{
				if (v[i][2] != v[i + 1][6])
					rot[i] = -rot[i + 1];
			}
			for (int i = idx; i < 4; i++)
			{
				if (v[i][6] != v[i - 1][2])
					rot[i] = -rot[i - 1];
			}
			for (int i = 0; i < 4; i++)
				vrot(i, rot[i]);
		}
		int cal = 0;
		for (int i = 3; i >= 0; i--)
		{
			cal <<= 1;
			cal += v[i][0];
		}
		printf("#%d %d\n", tc, cal);
	}
}
