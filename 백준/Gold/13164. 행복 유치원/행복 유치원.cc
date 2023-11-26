#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[300000]={};
int main()
{
	int n,k;
	vector<int> v;
	cin>>n>>k;
	for(int i =0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n-1;i++)
		v.push_back(arr[i+1]-arr[i]);
	sort(v.rbegin(),v.rend());
	int result = 0;
	result = arr[n-1]-arr[0];
	for(int i=0;i<k-1;i++)
		result-=v[i];
	cout<<result;
}