#include<iostream>
using namespace std;
int main()
{
    int result = 0;
    int flag = 1,idx = 0;
    int base;
    char str[34]={};
    cin>>str>>base;
    while(str[idx])
    {
        result *= base;
        if(str[idx] == '-')
            flag = -1;
        else if(str[idx] >= '0' && str[idx]<='9')
            result = result + str[idx] - '0';
        else
            result = result + str[idx] - 'A' + 10;
        idx = idx + 1;
    }
    cout<<result;
}