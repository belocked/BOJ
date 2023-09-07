#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int i=0;
    while(i<people.size())
    {
        if(people.back()+people[i]<=limit)
            i++;
        answer++;
        people.pop_back();
    }
    return answer;
}