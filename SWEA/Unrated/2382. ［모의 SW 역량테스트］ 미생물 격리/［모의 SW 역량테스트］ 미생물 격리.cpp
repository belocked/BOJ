#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int dy[]={0,-1,1,0,0};
int dx[]={0,0,0,-1,1};
struct microbe{
	int y,x,size,dir;
};
int n,m,k;
int main()
{
	int t;
	cin>>t;
	for(int tc=1;tc<=t;tc++)
	{
		int cnt=0;
		scanf("%d%d%d",&n,&m,&k);
		microbe micro[1000]={};
		int bumplist[10001]={};
		for(int i=0;i<k;i++)
			cin>>micro[i].y>>micro[i].x>>micro[i].size>>micro[i].dir;
		while(m--)
		{
			int v[10001][4]={};
			int bcnt = 0;
			for(int i=0;i<k;i++)
			{
				int ny = micro[i].y+dy[micro[i].dir];
				int nx = micro[i].x+dx[micro[i].dir];
				int ndir = micro[i].dir;
				if(ny==0||ny==n-1||nx==0||nx==n-1)
				{
					micro[i].size /=2;
					if(!micro[i].size)
					{
						continue;
					}
					micro[i].y = ny;
					micro[i].x = nx;
					micro[i].dir = ndir - 1 + (ndir%2)*2;
				}
				else
				{
					micro[i].y = ny;
					micro[i].x = nx;
					int last = 0;
					while(v[ny*n+nx][last])
					{
						last++;
					}
					if(last==1)
						bumplist[bcnt++]=ny*n+nx;
					v[ny*n+nx][last]=i+1;
				}
			}
			for(int i=0;i<bcnt;i++)
			{
				int tar = bumplist[i];
				int mxk = v[tar][0]-1;
				int mx = micro[v[tar][0]-1].size;
				for(int j=1;v[tar][j]&&j<4;j++)
				{
					if(micro[v[tar][j]-1].size>mx)
					{
						mx = micro[v[tar][j]-1].size;
						mxk = v[tar][j]-1;
					}
				}
				for(int j=0;v[tar][j]&&j<4;j++)
				{
					if(v[tar][j]-1!=mxk)
					{
						micro[mxk].size+=micro[v[tar][j]-1].size;
						micro[v[tar][j]-1].size=0;
					}
				}
			}
		}
		for(int i=0;i<k;i++)
		{
			cnt+=micro[i].size;
		}
		printf("#%d %d\n",tc,cnt);
	}
}