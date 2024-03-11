#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <map>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <climits>
#include <time.h>

using namespace std;

string s;
string s_bomb;
stack<char> _stack;

//string findString(string& s, string& s_bomb);
// 재귀로 돌리면 메모리가 할당이 너무 높아져서 메모리 초과

int main(void)
{
	while (true)
	{
		char c;
		scanf("%c", &c);
		if ((int)c == (int)' ' || (int)c == (int)'\n')
			break;
		else
			s += c;
	}
	while (true)
	{
		char c;
		scanf("%c", &c);
		if ((int)c == (int)' ' || (int)c == (int)'\n')
			break;
		else
			s_bomb += c;
	}

	int i = 0;
	while (true)
	{
		if (i >= s.size())
			break;

		if ((int)s[i] != (int)s_bomb[s_bomb.size() - 1] || _stack.size() < s_bomb.length() - 1)
		{
			_stack.push(s[i]);
			i++;
		}
		else
		{
			stack<int> temp_stack;
			temp_stack.push(s[i]);
			for (int j = s_bomb.size() - 2; j >= 0; j--)
			{
				if (_stack.top() == s_bomb[j])
				{
					temp_stack.push(_stack.top());
					_stack.pop();
				}
				else
				{
					while (!temp_stack.empty())
					{
						_stack.push(temp_stack.top());
						temp_stack.pop();
					}
					break;
				}
			}
			i++;
		}
	}

	if (_stack.empty())
	{
		printf("%s", "FRULA");
		return 0;
	}

	stack<int> temp_stack;
	while (!_stack.empty())
	{
		temp_stack.push(_stack.top());
		_stack.pop();
	}
	while (!temp_stack.empty())
	{
		printf("%c", temp_stack.top());
		temp_stack.pop();
	}
}