#include<iostream>
#include<string>
using namespace std;
int main()
{    
    const int M=1234567891;
    int len;
    long long sum=0,R=1;
    string hash;
    cin>>len;
    cin>>hash;
    for(int i=0;i<len;i++)
    {
        sum = (sum + (hash[i] - 'a' + 1) * R) % M;
		R = (R * 31) % M;
    }
    cout<<sum<<'\n';
}