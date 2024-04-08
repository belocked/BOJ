#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> ump;
    for(int i=0;i<participant.size();i++)
        ump[participant[i]]++;
    for(int i=0;i<completion.size();i++)
    {
        ump[completion[i]]--;
        if(ump[completion[i]]==0)
            ump.erase(completion[i]);
    }
    auto it = ump.begin();
    answer = it->first;
    return answer;
}