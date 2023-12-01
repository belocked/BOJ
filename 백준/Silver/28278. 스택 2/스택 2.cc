#include<iostream>
#include<stack>

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
		int cmd;
		cin>>cmd;
		if(cmd == 1)
		{
			int tmp;
			cin>>tmp;
			st.push(tmp);
		}
		else if(cmd == 2){
			if(st.empty())
				cout<<-1<<'\n';
			else
			{
				cout<<st.top()<<'\n';
				st.pop();
			}
		}
		else if(cmd ==3)
			cout<<st.size()<<'\n';
		else if(cmd==4)
			cout<<st.empty()<<'\n';
		else if(cmd==5)
		{
			if(st.empty())
				cout<<-1<<'\n';
			else
				cout<<st.top()<<'\n';
		}

	}
}