#include <string>
#include <vector>
#include <numeric>

using namespace std;

int S;

int addIndex(int idx) {
    return idx + 1 >= 2*S ? 0 : idx + 1; // 인덱스가 배열의 크기 넘어가면 맨 앞으로
}

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);
    
    S = queue1.size();
    int answer = 0;
    
    // 두 배열 concat
    queue1.insert(queue1.end(), queue2.begin(), queue2.end());
    int p1_1 = 0;
    int p2_1 = S;
    
    while(answer <= 2*S+3) { // 이동 횟수 4S 넘어가면 종료
        if(sum1 > sum2) {
            sum1 -= queue1[p1_1];
            sum2 += queue1[p1_1];
            
            p1_1 = addIndex(p1_1);
        }
        else if(sum1 < sum2) {
            sum2 -= queue1[p2_1];
            sum1 += queue1[p2_1];
            
            p2_1 = addIndex(p2_1);
        }
        else return answer;
        
        answer++;
    }
    
    return -1;
}