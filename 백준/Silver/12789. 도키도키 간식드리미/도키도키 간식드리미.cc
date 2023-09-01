#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	stack <int> st;
	vector <int> v;
	int n;
	cin >> n;
	int step=1;
	int tmp;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		v.push_back(tmp);
	}
	int i = 0;
	while(1)
	{
		if(v[i]==step)
		{
			i++;
			step++;
		}
		else if(!st.empty()&&st.top()==step)
		{
			step++;
			st.pop();
		}
		else if(i<n)
		{
			st.push(v[i]);
			i++;
		}
		else if(step>n)
		{
			cout<<"Nice";
			return 0;
		}
		else
		{
			cout <<"Sad";
			return 0;
		}
	}
	if(st.empty())
		cout<<"Nice";
	else
		cout<<"Sad";
}