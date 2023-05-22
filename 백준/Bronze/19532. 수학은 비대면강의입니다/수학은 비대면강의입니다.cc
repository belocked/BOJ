#include<iostream>
using namespace std;
int main()
{
   int x=-999,y=-999;
   int arr[6];
   for(int i =0;i<6;i++)
        cin>>arr[i];
   while(1)
   {
       if(((arr[0]*x+arr[1]*y)==arr[2])&&((arr[3]*x+arr[4]*y)==arr[5]))
           break;
       y++;
       if(y==1000)
       {
           x++;
           y=-999;
       }
   }
   cout<<x<<' '<<y;
}