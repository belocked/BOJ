#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int max_idx = 0;
    int last_idx = 0;
    int len = number.length()-k;
    while(len)
    {
        max_idx = last_idx;
        for(int i = last_idx; i< number.length()-len+1; i++)
        {
            if(number[max_idx]<number[i])
                max_idx = i;
        }
        answer+=number[max_idx];
        last_idx = max_idx+1;
        len--;
    }
    return answer;
}