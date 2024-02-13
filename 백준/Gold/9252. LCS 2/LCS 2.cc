#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int arr[1001][1001] = {};



int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}
	int cy = len1;
	int cx = len2;
	string ans = "";
	while (arr[cy][cx])
	{
		if (arr[cy][cx]==arr[cy-1][cx]&&arr[cy][cx]!=arr[cy][cx-1])
		{
			cy--;
		}
		else if (arr[cy][cx] != arr[cy - 1][cx] && arr[cy][cx] == arr[cy][cx - 1])
		{
			cx--;
		}
		else if (arr[cy][cx] != arr[cy - 1][cx] && arr[cy][cx] != arr[cy][cx - 1])
		{
			ans += s2[cx-1];
			cy--;
			cx--;
		}
		else if (arr[cy][cx] == arr[cy - 1][cx] && arr[cy][cx] == arr[cy][cx - 1])
		{
			cy--;
		}
	}
	cout << ans.length() << endl;
	for (int i = 0; i < ans.length(); i++)
		cout << ans[ans.length() - 1 - i];
}