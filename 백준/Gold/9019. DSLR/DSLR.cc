#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int D(int n)
{
	return (n * 2) % 10000;
}

int S(int n)
{
	return (n + 9999) % 10000;
}

int L(int n)
{
	return n / 1000 + (n % 1000) * 10;
}

int R(int n)
{
	return n / 10 + (n % 10) * 1000;
}

string DSLR(int a, int b)
{
	queue<pair<string, int>> q;
	q.push({ "", a });
	bool used[10000] = {};
	while (!q.empty())
	{
		string s = q.front().first;
		int num = q.front().second;
		q.pop();
		if (num == b)
			return s;
		if (!used[D(num)])
        {
            q.push({ s + 'D',D(num) });
		    used[D(num)] = true;
        }
		if (!used[S(num)])
        {
            q.push({ s + 'S',S(num) });
            used[S(num)]=true;
        }
		if (!used[L(num)])
        {
            q.push({ s + 'L',L(num) });
            used[L(num)]=true;
        }
		if (!used[R(num)])
        {
            q.push({ s + 'R',R(num) });
            used[R(num)]=true;
        }
	}
}



int main()
{
	int n;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		cout<<DSLR(a, b)<<endl;
	}
}