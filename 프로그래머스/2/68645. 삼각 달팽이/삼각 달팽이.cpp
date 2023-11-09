#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int dx[3]={0,1,-1};
    int dy[3]={1,0,-1};
    int cycle=0;
    int startX=1;
    int startY=0;
    int arr[1001][1001]={};
    int k=1;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            startX+=dx[cycle];
            startY+=dy[cycle];
            arr[startY][startX]=k;
            k++;
        }
        cycle=(cycle+1)%3;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            answer.push_back(arr[i][j]);
    }
    return answer;
}