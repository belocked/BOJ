#include <iostream>
#include<string>
using namespace std;
int main()
{
	string sik;
	cin >> sik;
	string temp = "";
	int sum = 0;
	bool m_check = true;
	int length = sik.size();
	for (int i = 0; i <= length; i++)
	{
		if (sik[i] == '+' || sik[i] == '-' || sik[i] == NULL)
		{
			if (m_check)
				sum += stoi(temp);
			else
				sum -= stoi(temp);
			if (sik[i] == '-')
				m_check = false;
			temp = "";
			continue;
		}
		temp += sik[i];
	}
	cout << sum << '\n';
}