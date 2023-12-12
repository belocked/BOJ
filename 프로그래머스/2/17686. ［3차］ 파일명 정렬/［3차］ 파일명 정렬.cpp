#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
int change(string str1,string str2)
{
    string h1="";
    string n1="";
    int idx = 0;
    while(idx<str1.length())
    {
        if(isdigit(str1[idx]))
            break;
        h1+=str1[idx];
        idx++;
    }
    while(idx<str1.length())
    {
        if(!isdigit(str1[idx]))
            break;
        n1+=str1[idx];
        idx++;
    }
    string h2="";
    string n2="";
    idx = 0;
    while(idx<str2.length())
    {
        if(isdigit(str2[idx]))
            break;
        h2+=str2[idx];
        idx++;
    }
    while(idx<str2.length())
    {
        if(!isdigit(str2[idx]))
            break;
        n2+=str2[idx];
        idx++;
    }
    idx = 0;
    while(idx<h1.length()&&idx<h2.length())
    {
        if(tolower(h1[idx])!=tolower(h2[idx]))
        {
            return tolower(h1[idx])-tolower(h2[idx]);
        }
        idx++;
    }
    if(h1.length()!=h2.length())
    {
        return h1.length()-h2.length();
    }
  
    return stoi(n1)-stoi(n2);
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for(int i =0;i<files.size()-1;i++)
    {
        for(int j=0;j<files.size()-i-1;j++)
        {
            if(change(files[j],files[j+1])>0)
            {
                string tmp;
                tmp=files[j];
                files[j]=files[j+1];
                files[j+1]=tmp;
            }
        }
    }
    return files;
}