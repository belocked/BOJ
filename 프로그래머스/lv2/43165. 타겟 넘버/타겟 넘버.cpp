#include <string>
#include <vector>

using namespace std;
int answer =0;

void dfs(int depth, int sum, vector<int> n, int target)
{
    if(depth==n.size())
    {
        if(sum==target)
            answer++;
        return;
    }
    dfs(depth+1, sum+n[depth],n,target);
    dfs(depth+1, sum-n[depth],n,target);
}

int solution(vector<int> numbers, int target) {
    dfs(0,0,numbers,target);
    return answer;
}