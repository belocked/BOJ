#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i =0;i<numbers.size();i++)
    {
        long long temp = numbers[i];
        int bias = 0;
        while(true)
        {
            if(temp%4!=3)
            {
                temp++;
                break;
            }
            temp/=2;
            bias++;
        }
        temp=temp<<bias;
        long long tmp = 0;
        while(bias--)
            tmp=tmp*2 + 1;
        tmp=tmp&numbers[i];
        temp=temp+tmp;
        answer.push_back(temp);
    }
    return answer;
}