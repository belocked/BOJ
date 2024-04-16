#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
            triangle[i][j] = max(triangle[i+1][j],triangle[i+1][j+1])+triangle[i][j];
    }
    return triangle[0][0];
}