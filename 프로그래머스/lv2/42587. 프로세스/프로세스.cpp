#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    for(int i=0;i<priorities.size();i++)
        q.push({priorities[i],i});
    sort(priorities.begin(),priorities.end(),greater<int>());

    return answer;
}