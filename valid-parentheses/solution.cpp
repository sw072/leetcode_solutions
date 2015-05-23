#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		char stack[1024];
		stack[0] = '#';
		int top = 0;
		for (int idx = 0; idx < s.size(); ++idx) {
			switch (s[idx]) {
			case ']':
				if (stack[top] == '[') { --top; break; }
				else return false;
			case ')':
				if (stack[top] == '(') { --top; break; }
				else return false;
			case '}':
				if (stack[top] == '{') { --top; break; }
				else return false;
			default: stack[++top] = s[idx];
			}
		}
		if (!top) return true;
		return false;
    }
};

int main()
{
	string str;
    Solution s;
    while(cin>>str) 
    {
		cout << s.isValid(str) << endl;
    }
	return 0;
}
