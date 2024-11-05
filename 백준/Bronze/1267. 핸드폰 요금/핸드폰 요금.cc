#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int y=0,m=0;
    while(n--)
    {
        int k;
        cin>>k;
        y=y+(k/30)+1;
        m=m+(k/60)+1;
    }
    y = y*10;
    m = m*15;
    if(y<m)
        cout<<"Y "<<y;
    else if(m<y)
        cout<<"M "<<m;
    else
        cout<<"Y M "<<y;
}