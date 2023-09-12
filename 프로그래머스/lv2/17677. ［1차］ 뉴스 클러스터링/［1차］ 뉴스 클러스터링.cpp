#include <string>
#include <bits/stdc++.h>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    double n1=0,n2=0;
    map<string, int> m1;
    map<string, int> m2;
    for(int i=1;i<str1.length();i++)
    {
        if(isalpha(str1[i-1])&&isalpha(str1[i]))
        {
            string tmp="";
            tmp+=tolower(str1[i-1]);
            tmp+=tolower(str1[i]);
            m1[tmp]++;
            n1++;
            cout<<tmp<<" "<<n1<<endl;        
        }   
    }
    for(int i=1;i<str2.length();i++)
    {
        if(isalpha(str2[i-1])&&isalpha(str2[i]))
        {
            string tmp="";
            tmp+=tolower(str2[i-1]);
            tmp+=tolower(str2[i]);
            m2[tmp]++;
            n2++;
            cout<<tmp<<" "<<n2<<endl;
        }
    }
    if(!(n1+n2))
        return 65536;
    cout<<n1<<endl<<n2<<endl;
    map<string,int> uni;
    for(auto it : m1)
        uni[it.first]=it.second;
    for(auto it : m2)
    {
        if(uni[it.first])
            uni[it.first]=max(uni[it.first],it.second);
        else
            uni[it.first]=it.second;
    }
    double nuni=0;
    for(auto it : uni)
    {
        nuni+=it.second;
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<nuni;
    return (((n1+n2)-nuni)*65536)/nuni;
}