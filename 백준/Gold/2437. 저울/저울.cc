#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int arr[1000];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int mn = 1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > mn)
			break;
		mn += arr[i];
	}
	cout << mn;
}