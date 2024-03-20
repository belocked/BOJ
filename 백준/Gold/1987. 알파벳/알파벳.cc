#include<iostream>
#include<string>
using namespace std;
int dy[]={0,0,-1,1};
int dx[]={1,-1,0,0};

int dat[26]={};

int r,c;
int mx = 0;
char arr[20][20]={};

void dfs(int depth, int cy, int cx)
{
	mx = max(mx,depth);
	for(int i=0;i<4;i++)
	{
		int ny = cy+dy[i];
		int nx = cx +dx[i];
		if(ny<0||ny>=r||nx<0||nx>=c)
		{
			continue;
		}
		if(dat[arr[ny][nx]-'A'])
			continue;
		dat[arr[ny][nx]-'A']++;
		dfs(depth+1,ny,nx);
		dat[arr[ny][nx]-'A']--;
	}
}
int main()
{
	cin>>r>>c;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cin>>arr[i][j];
	}
	dat[arr[0][0]-'A']++;
	dfs(1,0,0);
	cout<<mx;
}
