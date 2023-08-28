#include<iostream>
using namespace std;
int main()
{
	int p;
	cin>>p;
	int start = p/5;
	int p5,p7;
	int ans;
	if(p<4)
	{
		cout<<1;
		return 0;
	}
	else if(p<8)
	{
		cout<<3;
		return 0;
	}
	while(start)
	{
		p5 = start;
		p7 = 0;
		if(p5 * 5 + p5 - 1 > p)
		{
			start--;
			continue;
		}
		while(p5)
		{
			if((p5*5+p7*7+start-1)==p)
			{
				cout<<3*(p5+p7)+start - 1;
				return 0;
			}	
			p5--;
			p7++;
		}
		start--;
	}
}