#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> st;
    int now =0;
    for(int i=1;i<=order.size();i++)
    {
        st.push(i);
        while(!st.empty())
        {
            if(st.top()==order[now])
            {
                st.pop();
                now++;
            }
            else
                break;
        }
    }
    return now;
}