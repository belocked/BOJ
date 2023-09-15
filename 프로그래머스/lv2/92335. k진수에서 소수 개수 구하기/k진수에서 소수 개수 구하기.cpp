#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string str;
int answer=0;
void p(long n,int ans)
{
    if(n==1)
        return;
    for(long i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return;
    }
    answer+=ans;
}

void mkstr(int n, int k)
{
    if(n>=k)
        mkstr(n/k,k);
    str+=(char)('0'+n%k);
}

int solution(int n, int k) {
    mkstr(n,k);
    map<long,int> m;
    string tmp;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='0')
        {
            if(tmp.length())
                m[stol(tmp)]++;
            tmp.clear();
        }
        else
            tmp+=str[i];
    }
    if(tmp.length())
        m[stol(tmp)]++;
    for(auto it : m)
        p(it.first,it.second);
    return answer;
}