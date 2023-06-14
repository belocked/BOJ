#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int f0 = 0;
    int f1 = 1;
    int answer = 0;
    int fn = 2;
    
    while (fn <= n)
    {
        answer = f0 + f1;
        f0 = f1;
        f1 = answer;
        answer = answer%1234567;
        f0 = f0%1234567;
        f1 = f1%1234567;
        fn = fn + 1;
    }
    return answer;
}