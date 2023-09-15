#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> um;
    for(int i=0;i<phone_book.size();i++)
        um[phone_book[i]]++;
    for(int i=0;i<phone_book.size();i++)
    {
        string tmp="";
        for(int j=0;j<phone_book[i].length()-1;j++)
        {
            tmp+=phone_book[i][j];
            if(um[tmp])
                return false;
        }
    }
    return answer;
}