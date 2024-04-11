#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int n,long long int mid, vector<int> times){
    long long int ret = 0;
    for(int i=0;i<times.size();i++)
    {
        ret +=mid/times[i];
    }
    if(ret>=n)
        return true;
    return false;
}
long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    long long r = (long long)times[times.size()-1]*n;
    long long l = 0;
    while(l<r)
    {
        long long int mid = (l+r)/2;
        if(check(n,mid,times))
        {
            answer = mid;
            r = mid;
        }
        else 
            l = mid+1;
    }
        
    return answer;
}