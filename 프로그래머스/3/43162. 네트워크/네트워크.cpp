#include <string>
#include <vector>

using namespace std;
int arr[200];
int find(int a){
    if(a==arr[a])
        return a;
    int ret = find(arr[a]);
    arr[a] = ret;
    return ret;
}

void un(int a,int b)
{
    int tar1 = find(a);
    int tar2 = find(b);
    if(tar1==tar2)
        return;
    arr[tar2] = tar1;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = n;
    for(int i=0;i<n;i++)
        arr[i] = i;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            if(computers[i][j])
            {
                if(find(i)!=find(j))
                {
                    un(i,j);
                    answer--;
                }
            }
        }
    }
    return answer;
}