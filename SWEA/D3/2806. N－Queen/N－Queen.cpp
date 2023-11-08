#include<iostream>
using namespace std;

int cnt;
int k;
int field[10]={};
int check(int n)
{
    for(int i = 0;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(field[i]==field[j])
                return (0);
            if((field[i]-field[j])==(i-j))
                return (0);
            if((field[i]-field[j])==(j-i))
            	return (0);
        }
    }
    return (1);
}
void dfs(int depth)
{
    if(depth==k)
    {
        cnt++;
        return;
    }
    for(int i=0;i<k;i++)
    {
        field[depth]=i;
        if(check(depth))
            dfs(depth+1);
    }
}
int main()
{
    int t;
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        cnt = 0;
        cin>>k;
		dfs(0);
        cout<<"#"<<test<<" "<<cnt<<endl;
    }
}