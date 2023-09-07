#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a>b;
}
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> v(10000001);
    for(int i=0;i<tangerine.size();i++)
        v[tangerine[i]]++;
    sort(v.begin(),v.end(),cmp);
    while(k>0)
    {
        k-=v[answer];
        answer++;
    }
    
    return answer;
}