#include <bits/stdc++.h>
#include <string>
using namespace std;


bool checkstuff(string s, string t)
{
	vector<char> stack1;
	vector<char> stack2;
	for (char i : s)
	{
		if (i == '#')
		{
			stack1.pop_back();continue;
		}
		stack1.push_back(i);
	}
	
	for (char i : t)
	{
		if (i == '#')
		{
			stack2.pop_back();continue;
		}
		stack2.push_back(i);
	}
	
	if (stack1.size() != stack2.size()) return false;
	for (int i=0; i<stack1.size(); i++)
	{
		if (stack1[i] != stack2[i]) return false; 
	}
	return true;
}


int main()
{
	string s = "ab#c";
	string t = "ad#c#";
	cout<<checkstuff(s,t);
}