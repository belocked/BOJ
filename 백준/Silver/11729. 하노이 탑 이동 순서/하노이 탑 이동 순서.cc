#include<iostream>
using namespace std;
void hanoi(int num, int start, int end, int mid)
{
	if (num == 1)
		cout << start << ' ' << end << '\n';
	else
	{
		hanoi(num - 1, start, mid, end);
		cout << start << ' ' << end << '\n';
		hanoi(num - 1, mid, end, start);
	}
}
int main() 
{
	int num;
	cin >> num;
	cout << (1 << num) - 1 << "\n";
	hanoi(num, 1, 3, 2);
}