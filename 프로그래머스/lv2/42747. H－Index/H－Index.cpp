#include <string>
#include <vector>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int arr[10001]={};
    for(int i=0;i<citations.size();i++)
        arr[citations[i]]++;
    int size=citations.size();
    for(int i=0;i<10001;i++)
    {
        if(i<=size)
        {
            answer=i;
            size-=arr[i];
        }
        else
            break;
    }
    return answer;
}