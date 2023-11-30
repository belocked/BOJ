#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;
string s;
int n;
char conv(char c)
{
	if(c=='R')
		return 'G';
	else if(c=='G')
		return 'B';
	else
		return 'R';
}
int count(char target)
{
	int ret = 200001;
	int cnt = 0;
	string cp;
	cp = s;
	for(int i=1;i<n-1;i++)
	{
		int k =3;
		while(cp[i-1]!=target&&(k--))
		{
			cp[i-1]=conv(cp[i-1]);
			cp[i]=conv(cp[i]);
			cp[i+1]=conv(cp[i+1]);
			cnt++;
		}
	}
	if(cp[n-2]==target&&cp[n-1]==target)
		return cnt;
	return ret;
}

int main()
{
	cin>>n;
	cin>>s;
	int ret;
	ret = min(count('R'),count('G'));
	ret = min(ret,count('B'));
	if(ret == 200001)
		ret = -1;
	cout<<ret;
}