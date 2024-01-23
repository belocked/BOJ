#include<iostream>
using namespace std;
int tree[26][2] = {};

void pre(int n)
{
	if (n < 0)
		return;
	cout << (char)('A' + n);
	pre(tree[n][0]);
	pre(tree[n][1]);

}

void in(int n)
{
	if (n < 0)
		return;

	in(tree[n][0]);
	cout << (char)('A' + n);
	in(tree[n][1]);

}

void post(int n)
{
	if (n < 0)
		return;
	post(tree[n][0]);
	post(tree[n][1]);
	cout << (char)('A' + n);
}


int main()
{
	int n;
	cin >> n;
	char a, b, c;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		tree[a - 65][0] = b - 65;
		tree[a - 65][1] = c - 65;
	}
	pre(0);
	cout << endl;
	in(0);
	cout << endl;

	post(0);
}