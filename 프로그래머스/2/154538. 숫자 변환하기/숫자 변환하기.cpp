#include <string>
#include <vector>
#include <iostream>
int arr[1000001]={};
using namespace std;

void dfs(int x, int y, int n, int cnt)
{
    if(x > y)
        return ;
    if(y%2==0)
    {
        if(arr[y/2] < cnt&&arr[y/2]!=0)
            return ;
        else
        {
            arr[y/2] = cnt;
            dfs(x,y/2,n,cnt + 1);
        }
    }
    if(y%3 == 0)
    {
        if(arr[y/3] < cnt && arr[y/3]!=0)
            return ;
        else
        {
            arr[y/3] = cnt;
            dfs(x,y/3,n,cnt + 1);
        }
    }
    if(y>=n)
    {
        if(arr[y-n]<cnt&&arr[y-n]!=0)
            return;
        else
        {
            arr[y-n] =cnt;
            dfs(x,y-n,n,cnt+1);
        }
    }

}

int solution(int x, int y, int n) {

    if(x==y)
        return 0;
    dfs(x,y,n,1);
    if(arr[x]==0)
        return -1;
    return arr[x];
}