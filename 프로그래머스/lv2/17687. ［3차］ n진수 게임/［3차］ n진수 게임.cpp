#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int anslen=0;
string tmp ="";
void add(int n, int k)
{
    if(k>=n)
        add(n,k/n);
    if(k%n<10)
        tmp+=(char)('0'+(k%n));
    else
        tmp+=(char)('A'+(k%n)-10);
    anslen++;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    int k=0;
    while(anslen<t*m)
    {
        add(n,k);
        k++;
    }
    while(t)
    {
        answer+=tmp[p-1];
        p+=m;
        t--;
    }
    return answer;
}