#include<iostream>
using namespace std;
bool visit[8];
int arr[8];
int n,m;
void dfs(int cnt)
{
    if(cnt==m)
    {
        for(int i=0;i<m;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!visit[i])
        {
            visit[i]=true;
            arr[cnt]=i;
            dfs(cnt+1);
            visit[i]=false;
        }
    }
}
int main()
{
    cin>>n>>m;
    dfs(0);
}