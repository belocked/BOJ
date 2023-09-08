#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int size = elements.size();
    set <int> s;
    for(int i=0;i<size;i++)
        elements.push_back(elements[i]);
    for(int i=0;i<size;i++)
    {
        int sum = elements[i];
        s.insert(sum);
        for(int j=1;j<size;j++)
        {
            sum+=elements[i+j];
            s.insert(sum);
        }
    }
    answer=s.size();
    return answer;
}