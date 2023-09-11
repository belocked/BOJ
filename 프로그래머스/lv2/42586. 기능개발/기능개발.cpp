#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 1;
    int tmp = 0;
    while(progresses.size())
    {
        if((progresses[0]+speeds[0]*day)<100)
        {
            if(tmp>0)
                answer.push_back(tmp);
            tmp=0;
            day++;
        }
        else
        {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            tmp++;
        }
    }
    if(tmp)
        answer.push_back(tmp);
    return answer;
}