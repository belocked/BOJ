#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int count = 0;
    int div=1;
    while(div<=n)
    {
        if(!(n%div))
            count++;
        if(count == k)
        {
            cout<<div;
            return 0;
        }
        div++;
    }
    cout<<0;
}