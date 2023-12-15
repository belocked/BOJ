#include<iostream>

using namespace std;

int df[21][21][21]={};

int cal(int a, int b, int c)
{
	if(a<=0||b<=0||c<=0)
	{
		return 1;
	}
	if(a>20||b>20||c>20)
	{
		if(df[20][20][20]!=0)
			return df[20][20][20];
		df[20][20][20]=cal(20,20,20);
		return df[20][20][20];
	}
	if(df[a][b][c])
		return df[a][b][c];
	if(a<b&&b<c)
	{
		df[a][b][c]= cal(a,b,c-1)+cal(a,b-1,c-1)-cal(a,b-1,c);
		return df[a][b][c];
	}
	df[a][b][c] = cal(a-1,b,c)+cal(a-1,b-1,c)+cal(a-1,b,c-1)-cal(a-1,b-1,c-1);
	return df[a][b][c];
}



int main()
{
	int a=0,b=0,c=0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(true)
	{
		cin>>a>>b>>c;
		if(a==-1&&b==-1&&c==-1)
			return 0;
		printf("w(%d, %d, %d) = %d\n",a,b,c,cal(a,b,c));
	}
}