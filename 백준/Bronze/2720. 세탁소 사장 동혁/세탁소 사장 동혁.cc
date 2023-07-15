#include<iostream>
using namespace std;
void cal(int n)
{
    int q=n/25;
    n-=q*25;
    int d=n/10;
    n-=d*10;
    int ni=n/5;
    n-=ni*5;
    cout<<q<<' '<<d<<' '<<ni<<' '<<n<<'\n';
}
int main()
{
    int n;
    cin>>n;
    int k;
    while(n--)
    {
        cin>>k;
        cal(k);
    }
}