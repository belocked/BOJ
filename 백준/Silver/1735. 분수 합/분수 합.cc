#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	if (a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int p,q;
	p = b*d;
	q = b*c+a*d;
	cout<<q/gcd(p,q)<<' '<<p/gcd(p,q);
}