#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, int> m1;
    map<int, int> m2;
    for(int i=0;i<records.size();i++)
    {
        int hour = stoi(records[i].substr(0,2));
        int min = stoi(records[i].substr(3,5));
        int name =stoi(records[i].substr(6,10));
        if(records[i][11]=='I')
            m1[name]=hour*60+min;
        else
        {
            int dif = hour*60+min-m1[name];
            m1.erase(name);
            m2[name]+=dif;
        }
    }
    for(auto it : m1)
    {
            int dif = 1439 - it.second;
            m2[it.first]+=dif;
    }
    for(auto it :m2)
    {
        int tmp = fees[1];
        if(it.second>fees[0])
        {
            if((it.second-fees[0])%fees[2])
                it.second+=fees[2];
            tmp=tmp +((it.second-fees[0])/fees[2])*fees[3];
        }
        answer.push_back(tmp);
    }
    return answer;
}