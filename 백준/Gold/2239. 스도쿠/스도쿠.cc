#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector <pair<int, int>> v;
bool flag = true;
int board[9][9] = {};
int n;

bool check(int cy, int cx, int k)
{
	for (int i = 0; i < 9; i++)
	{
		if (board[cy][i] == k)
			return false;
		if (board[i][cx] == k)
			return false;
		if (board[(cy / 3) * 3 + i / 3][(cx / 3) * 3 + i % 3] == k)
			return false;
	}
	return true;
}


void sudoku(int depth) {
	if (flag&&(depth == n))
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << board[i][j];
			cout << endl;
		}
		flag = false;
		return;
	}
	int cy = v[depth].first;
	int cx = v[depth].second;
	for (int i = 1; i < 10; i++)
	{
		if (flag) {
			board[cy][cx] = 0;
			if (check(cy, cx, i))
			{
				board[cy][cx] = i;
				sudoku(depth + 1);
			}
			board[cy][cx] = 0;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = s[j] - 48;
			if (!board[i][j])
				v.push_back({ i,j });
		}
	}
	n = v.size();
	sudoku(0);
}