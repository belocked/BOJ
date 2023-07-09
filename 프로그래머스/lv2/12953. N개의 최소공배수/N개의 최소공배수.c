#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int gcd(int a,int b)
{
    if (!b)
        return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}
int solution(int arr[], size_t arr_len) {
    int answer = 1;
    for (int i=0;i<arr_len;i++)
        answer = lcm(answer,arr[i]);
    return answer;
}