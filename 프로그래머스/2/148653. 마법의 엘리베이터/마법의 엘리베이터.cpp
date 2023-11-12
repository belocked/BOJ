#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey)
    {
        if(storey%10 > 5)
        {
            storey += 10 ;
            answer += 10 - storey %10;
        }
        else if(storey%10 <5)
            answer += storey%10;
        else
        {
            if(storey%100 >=50)
                storey += 10;
            answer += 5;
        }
        storey /=10;
    }
    return answer;
}