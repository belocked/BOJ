#include<iostream>
#include<algorithm>
using namespace std;
int r,c,t;
int field[50][50]={};
int dy[]={0,0,-1,1};
int dx[]={1,-1,0,0};
int upy,downy;
void print()
{
	int ret = 0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			ret+=field[i][j];
			//cout<<field[i][j]<<' ';
		}
		//cout<<endl;
	}
	cout<<ret+2;
}
void func1()
{
	int cp[50][50]={};
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(field[i][j]>0)
			{
				int cnt =0;
				for(int k=0;k<4;k++)
				{
					int nr = i+dy[k];
					int nc = j+dx[k];
					if(nr<0||nc<0||nc>=c||nr>=r)
						continue;
					if(field[nr][nc]==-1)
						continue;
					cnt++;
					cp[nr][nc] += field[i][j]/5;
				}
				cp[i][j]= cp[i][j]+field[i][j]-(field[i][j]/5)*cnt;
			}
			else if(field[i][j]==-1)
				cp[i][j] = -1;
		}
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			field[i][j] = cp[i][j];
		}
	}
}

void func2()
{
	for(int i=upy-1;i>0;i--)
	{
		field[i][0] = field[i-1][0];
	}
	for(int i=0;i<c-1;i++)
	{
		field[0][i] = field[0][i+1];
	}
	for(int i=0;i<upy;i++)
	{
		field[i][c-1] = field[i+1][c-1];
	}
	for(int i = c-1;i>0;i--)
	{
		field[upy][i] = field[upy][i-1];
	}
	field[upy][1] = 0;

	for(int i=downy+1;i<r-1;i++)
	{
		field[i][0]=field[i+1][0];
	}
	for(int i=0;i<c-1;i++)
	{
		field[r-1][i] = field[r-1][i+1];
	}
	for(int i=r-1;i>downy;i--)
	{
		field[i][c-1] = field[i-1][c-1];
	}
	for(int i=c-1;i>0;i--)
	{
		field[downy][i] = field[downy][i-1];
	}
	field[downy][1] = 0;
}
int main()
{
	cin>>r>>c>>t;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>field[i][j];
			if(field[i][j]==-1&&upy==0)
			{
				upy = i;
			}
			else if(field[i][j]==-1)
			{
				downy=i;
			}
		}
	}
	while(t--)
	{
		func1();
		func2();
	}
	//cout<<endl;
	print();
}