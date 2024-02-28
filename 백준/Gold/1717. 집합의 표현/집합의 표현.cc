#include<iostream>

using namespace std;

int n,m;
int arr[1000002]={};

int find(int a)
{
	if(a==arr[a])
		return a;
	int ret = find(arr[a]);
	arr[a] = ret;
	return ret;
}

void un(int a,int b)
{
	int t1 = find(a);
	int t2 = find(b);
	if(t1 == t2)
		return;
	arr[t2] = t1;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		arr[i] = i;
	for(int i=0;i<m;i++)
	{
		int cmd, a,b;
		scanf("%d%d%d",&cmd,&a,&b);
		if(cmd)
		{
			if(find(a)==find(b))
				printf("yes\n");
			else
				printf("no\n");
		}
		else
		{
			un(a,b);
		}
	}
}