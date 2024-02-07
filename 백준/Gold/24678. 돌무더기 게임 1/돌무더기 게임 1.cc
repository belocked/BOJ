#include<iostream>
using namespace std;

int main()
{
    int t;
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int cnt = a%2 + b%2 + c%2;
        if(cnt>1)
            cout<<"B\n";
        else
            cout<<"R\n";
    }
}