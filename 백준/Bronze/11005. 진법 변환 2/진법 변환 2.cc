#include<iostream>
using namespace std;
char arr[37]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void cur(int num, int n)
{
	if(num>=n)
		cur(num/n, n);
	cout<<arr[num%n];
}
int main()
{
	int num,n;
	cin>>num>>n;
	cur(num, n);
}