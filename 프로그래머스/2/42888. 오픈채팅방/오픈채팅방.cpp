#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    for(int i = 0;i<record.size();i++)
    {
        string userId ="";
        string userName ="";
        int check_space =0;
        for(int j=0;j<record[i].size();j++)
        {
            if(record[i][j]==' ')
                check_space++;
            else if(check_space == 1)
                userId+=record[i][j];
            else if(check_space == 2)
                userName+=record[i][j];
        }
        if(record[i][0]!='L')
            m[userId] = userName;
    }
    for(int i = 0;i<record.size();i++)
    {
        string userId ="";
        string userName ="";
        int check_space =0;
        for(int j=0;j<record[i].size();j++)
        {
            if(record[i][j]==' ')
                check_space++;
            else if(check_space == 1)
                userId+=record[i][j];
        }
        string result = "";
        result += m[userId];
        if(record[i][0]=='E')
        {
            result+="님이 들어왔습니다.";
            answer.push_back(result);
        }
        else if(record[i][0]=='L')
        {    
            result+="님이 나갔습니다.";
            answer.push_back(result);
        }   
    }
    
    return answer;
}