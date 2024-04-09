#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
bool comp(pair<string, int> p1, pair<string, int> p2)
{
    return p1.second>p2.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> totalcnt;
    unordered_map<string, pair<int, int> > ump;
    for(int i=0;i<genres.size();i++)
    {
        totalcnt[genres[i]]+=plays[i];
        if(ump.find(genres[i])==ump.end())
        {
            ump[genres[i]]={i+1,0};
        }
        else
        {
            if(ump[genres[i]].second==0)
            {
                int top1 = ump[genres[i]].first-1;
                if(plays[i]>plays[top1])
                {
                    ump[genres[i]].second = ump[genres[i]].first;
                    ump[genres[i]].first = i+1;
                }
                else
                    ump[genres[i]].second=i+1;
                
            }
            else{
                int top1 = ump[genres[i]].first-1;
                int top2 = ump[genres[i]].second-1;
                if(plays[i]>plays[top1])
                {
                    ump[genres[i]].first = i+1;
                    ump[genres[i]].second = top1+1;
                }
                else if(plays[i]>plays[top2])
                {
                    ump[genres[i]].second = i+1;
                }
            }
        }
    }
    vector<pair<string, int>> mv(totalcnt.begin(),totalcnt.end());
    sort(mv.begin(),mv.end(),comp);
    for(int i=0;i<mv.size();i++)
    {
        answer.push_back(ump[mv[i].first].first-1);
        if(ump[mv[i].first].second)
            answer.push_back(ump[mv[i].first].second-1);
    }
    return answer;
}