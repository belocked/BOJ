#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t;
    double x,y,dis,alpha;
    cin>>t;
    while(t)
    {
        cin>>x>>y;
        dis=y-x;
        alpha=ceil(sqrt(dis));
        if(dis>(alpha*alpha-alpha))
            cout<<alpha*2-1<<'\n';
        else
            cout<<alpha*2-2<<'\n';
        t--;
    }
}