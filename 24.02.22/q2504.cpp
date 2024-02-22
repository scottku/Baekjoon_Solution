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

using namespace std;

char c;
char arr[30];
stack<char> s;

int main(void)
{
	for (int i = 0; i < 30; i++)
		arr[i] = '\n';
	int i = 0;
	while (true)
	{
		scanf("%c", &c);
		if ((int)c == (int)'\n')
			break;
		arr[i] = c;
		i++;
	}

	i = 0;
	int temp = 1;
	int answer = 0;
	while (true)
	{
		if (i > 29)
			break;
		if ((int)arr[i] == (int)'\n')
			break;

		if ((int)arr[i] == (int)'(')
		{
			temp *= 2;
			i++;
			s.push('(');
		}
		else if ((int)arr[i] == (int)'[')
		{
			temp *= 3;
			s.push('[');
			i++;
		}
		else if ((int)arr[i] == (int)')')
		{
			if (s.empty())
			{
				printf("%d", 0);
				return 0;
			}

			if ((int)s.top() == (int)'[')
			{
				printf("%d", 0);
				return 0;
			}

			if ((int)s.top() == (int)'(')
			{
				if ((int)arr[i - 1] == (int)'(')
				{
					answer += temp;
					temp /= 2;
					s.pop();
				}
				else
				{
					temp /= 2;
					s.pop();
				}
			}
			i++;
		}
		else if ((int)arr[i] == (int)']')
		{
			if (s.empty())
			{
				printf("%d", 0);
				return 0;
			}

			if ((int)s.top() == (int)'(')
			{
				printf("%d", 0);
				return 0;
			}
			else if ((int)s.top() == (int)'[')
			{
				if ((int)arr[i - 1] == (int)'[')
				{
					answer += temp;
					temp /= 3;
					s.pop();
				}
				else
				{
					temp /= 3;
					s.pop();
				}
			}
			i++;
		}
	}

	if (!s.empty())
		printf("%d", 0);
	else
		printf("%d", answer);
}