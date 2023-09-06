#include <string>
#include <vector>
#include <iostream>
using namespace std;
int get0(string s)
{
    int result=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
            result++;
    }
    return result;
}

string recur(int n)
{
	string ret;
	while(n)
	{
		if(n%2)
			ret+="1";
		else
			ret+="0";
		n/=2;
	}
	for(int i=0;i<ret.length()/2;i++)
	{
		char a;
		a=ret[i];
		ret[i] = ret[ret.length()-1-i];
		ret[ret.length()-1-i]=a;
	}
	return ret;
}

vector<int> solution(string s) {
    vector<int> answer;
    int result = 0;
    int cnt = 0;
    while(s!="1")
    {
        result+=get0(s);
    	s=recur(s.length()-get0(s));
        cnt++;
    }
	answer.push_back(cnt);
	answer.push_back(result);
    return answer;
}
