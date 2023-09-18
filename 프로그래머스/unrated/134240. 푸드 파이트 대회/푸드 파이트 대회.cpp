#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for(int i=1;i<food.size();i++)
    {
        for(int j=0;j<food[i]/2;j++)
            answer+=(char)('0'+i);
    }
    answer+='0';
    for(int i=food.size()-1;i>=1;i--)
    {
        for(int j=0;j<food[i]/2;j++)
            answer+=(char)('0'+i);
    }
    return answer;
}