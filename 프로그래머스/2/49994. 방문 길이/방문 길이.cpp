#include <string>
using namespace std;

int solution(string dirs) {
    int answer = 0;

    int arr[21][21]={};
    int cy=10;
    int cx=10;
    for(int c=0;c<dirs.length();c++)
    {
        int dx = 0;
        int dy = 0;
        if(dirs[c]=='U')
            dy=2;
        else if(dirs[c]=='D')
            dy=-2;
        else if(dirs[c]=='L')
            dx=-2;
        else
            dx=2;
        int nx =dx+cx;
        int ny =dy+cy;
        if(nx<0||nx>20||ny<0||ny>20)
            continue;
        if(arr[cy+dy/2][cx+dx/2]==0)
        {
            arr[cy+dy/2][cx+dx/2]=1;
            answer++;
        }
        cy=ny;
        cx=nx;
    }
    return answer;
}