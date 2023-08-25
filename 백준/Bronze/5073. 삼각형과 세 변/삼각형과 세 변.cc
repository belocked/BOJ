#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	while((a+b+c)!=0)
	{
		int sum = a+b+c;
		int mx = max(a,max(b,c));
		if(sum<=(2*mx))
			cout<<"Invalid";
		else if(a==b&b==c&&c==a)
			cout<<"Equilateral";
		else if(a!=b&&b!=c&&c!=a)
			cout<<"Scalene";
		else
			cout<<"Isosceles";
		cout<<endl;
		cin>>a>>b>>c;
	}
	
}