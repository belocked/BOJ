#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    long long int arr[5001]={};
    arr[0]=1;
    arr[2]=3;
    if(n%2)
        return 0;
    for(int i=4;i<=n;i+=2)
    {
        arr[i] = (arr[i-2]*3)%1000000007;
        for(int j=0;j<i-2;j+=2)
            arr[i]+=arr[j]*2;
        arr[i] = arr[i]%1000000007;
    }
    return arr[n];
}