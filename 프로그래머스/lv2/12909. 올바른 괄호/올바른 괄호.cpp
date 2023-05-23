#include<string>
#include <iostream>

using namespace std;

bool solution(string temp)
{
	int stat = 0;
	bool check = true;
	for(int i=0;i<temp.length();i++)
	{
		if (temp[i] == '(')
			stat++;
		else if (temp[i] == ')')
			stat--;
		if (stat < 0)
		{
			check = false;
			break;
		}
	}
	if (!stat)
		return check;
	else
		return false;
}