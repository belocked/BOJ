#include<iostream>

using namespace std;
int n,l;
int main()
{
	cin>>n>>l;
	for(int i=l;i<=100;i++)
	{
		int bia = (i*(i-1))/2;
		if(bia>n)
		{
			cout<<-1;
			return 0;
		}
		if((n-bia)%i==0)
		{
			int k = (n-bia)/i;
			for(int j=0;j<i;j++)
				cout<<j+k<<' ';
			return 0;
		}
	}
	cout<<-1;
}