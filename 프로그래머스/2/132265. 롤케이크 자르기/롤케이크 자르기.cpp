#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int kind = 0;
    map<int,int> l;
    map<int,int> r;
    
    for(int i =0;i<topping.size();i++)
    {
        if(l[topping[i]]==0)
            kind++;
        l[topping[i]]++;
    }
    int lkind = 0;
    for(int i = 0; i < topping.size()-1;i++)
    {
        l[topping[i]]--;
        if(l[topping[i]]==0)
            kind--;
        if(r[topping[i]]==0)
            lkind++;
        r[topping[i]]++;
        if(lkind == kind)
            answer++;
        
    }
    return answer;
}