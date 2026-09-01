#include <bits/stdc++.h>
#include <string>
using namespace std;

string Ispalindrome(string value)
{
	vector<char> stack;
	for (char i : value) stack.push_back(i);

	for (int i=0; i<stack.size(); i++)
	{
		if (stack.back() != stack[i])
		{
			return "Not a Palindrome";
		}
		stack.pop_back();	
	}
	
	return "Palindrome";
}


int main()
{
	string stack = "racecar";
	cout<<Ispalindrome(stack);	 
	
}