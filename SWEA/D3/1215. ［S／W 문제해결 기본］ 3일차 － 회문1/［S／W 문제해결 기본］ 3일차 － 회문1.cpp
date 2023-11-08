#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int checkpd(string s,int n)
{
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-1-i])
            return 0;
    }
    return 1;
}

int main()
{
    for(int t=1;t<=10;t++)
    {
        int n;
        cin>>n;
        int result = 0;
       	string s[8];
        for(int i=0;i<8;i++)
            cin>>s[i];
		if(n==1)
            result = 64;
        else
        {
            for(int i=0;i<9-n;i++)
    		{
        		for(int j=0;j<8;j++)
        		{
            		string tmp;
            		for(int k=0;k<n;k++)
                		tmp+=s[i+k][j];
            		result+=checkpd(tmp,n);
        		}
    		}
            for(int i=0;i<8;i++)
    		{
        		for(int j=0;j<9-n;j++)
        		{
            		string tmp;
            		for(int k=0;k<n;k++)
                		tmp+=s[i][j+k];
            		result+=checkpd(tmp,n);
        		}
    		}
        }
        cout<<"#"<<t<<" "<<result<<endl;
    }
}