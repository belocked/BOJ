#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	stack<int> st;
	while(n--)
	{
		string cmd;
		cin>>cmd;
		if(cmd == "push")
		{
			int tmp;
			cin>>tmp;
			st.push(tmp);
		}
		else if(cmd == "pop"){
			if(st.empty())
				cout<<-1<<'\n';
			else
			{
				cout<<st.top()<<'\n';
				st.pop();
			}
		}
		else if(cmd =="size")
			cout<<st.size()<<'\n';
		else if(cmd=="empty")
			cout<<st.empty()<<'\n';
		else if(cmd=="top")
		{
			if(st.empty())
				cout<<-1<<'\n';
			else
				cout<<st.top()<<'\n';
		}

	}
}