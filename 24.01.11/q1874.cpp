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

using namespace std;

stack<int> s;
deque<int> dq;
vector<char> v;

int main(void)
{
	int n;
	scanf("%d", &n);

	int temp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		dq.push_back(temp); // 4 3 6 8 7 5 2 1
	}

	s.push(1);
	v.push_back('+');
	for (int i = 2; i <= n; i++)
	{
		while (true)
		{
			if (s.empty())
				break;

			if (dq.front() == s.top())
			{
				v.push_back('-');
				dq.pop_front();
				s.pop();
			}
			else
			{
				if (s.top() > dq.front())
				{
					printf("%s", "NO");
					return 0;
				}
				else
					break;
			}
		}

		s.push(i);
		v.push_back('+');
	}

	while (!dq.empty()) // deque에 남아있는 인자들 모두 체크 = 텅 빌때까지
	{
		if (dq.front() == s.top())
		{
			v.push_back('-');
			dq.pop_front();
			s.pop();
		}
		else
		{
			if (s.top() > dq.front())
			{
				printf("%s", "NO");
				return 0;
			}
			else
				break;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		printf("%c\n", v[i]);
	}
}