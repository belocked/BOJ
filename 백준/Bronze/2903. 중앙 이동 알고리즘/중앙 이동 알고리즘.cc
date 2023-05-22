#include<iostream>
using namespace std;
int main()
{
    int n;
    int result = 2;
    cin>>n;
    for(int i=1;i<=n;i++)
        result = result * 2 - 1;
    cout<<result *result;
}