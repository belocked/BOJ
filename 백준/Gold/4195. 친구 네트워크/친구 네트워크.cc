#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


unordered_map<string,string> m;
unordered_map<string,int> cntmap;
string find(string s)
{
	if(s==m[s])
		return s;
	string ret = find(m[s]);
	m[s] = ret;
	return ret;
}

void un(string s1,string s2)
{
	string t1 = find(s1);
	string t2 = find(s2);
	if(t1==t2)
		return ;
	cntmap[t1]+=cntmap[t2];
	m[t2] = t1;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int f;
		cin>>f;
		m.clear();
		cntmap.clear();
		while(f--)
		{
			string s1,s2;
			cin>>s1>>s2;
			if(cntmap[s1]==0)
			{
				m[s1] = s1;
				cntmap[s1] = 1;
			}
			if(cntmap[s2]==0)
			{
				m[s2] = s2;
				cntmap[s2] = 1;
			}
			un(s1,s2);
			cout<<cntmap[find(s1)]<<'\n';
		}
	}
}