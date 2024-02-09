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

using namespace std;

int tc;
vector<char> v_char;

int main(void)
{
	scanf("%d", &tc);
	bool isFirst = true;
	for (int _tc = 0; _tc < tc; _tc++)
	{
		v_char.clear();
		deque<int> q_int;
		deque<int> q_int_rev;

		while (true)
		{
			char c;
			scanf("%c", &c);
			if ((int)c == (int)'\n' || (int)c == (int)']')
			{
				if (v_char.empty())
					continue;
				else
					break;
			}
			v_char.push_back(c);
		}



		int num;
		scanf("%d", &num);
		int _count = 0;
		if (num == 0)
		{
			for (int i = 0; i < 2; i++)
			{
				char c;
				scanf("%c", &c);
			}
		}
		else
		{
			string str = "";
			while (_count < num)
			{
				char temp;
				scanf("%c", &temp);
				if ((int)temp == (int)'[' || (int)temp == (int)']' || (int)temp == (int)',' || (int)temp == (int)'\n')
				{
					if ((int)temp == (int)',' || (int)temp == (int)']')
					{
						q_int.push_back(stoi(str));
						_count++;
						str = "";
					}
					continue;
				}
				else
				{
					str += temp;
					//q_int.push_back((int)temp - 48);

				}
			}
		}

		int b_response = false;
		int _reverse = 0;
		for (int i = 0; i < v_char.size(); i++)
		{
			//if ((int)v_char[i] < 10)
			//	continue;
			if ((int)v_char[i] == (int)'R')
			{	// 뒤집기
				_reverse++;
			}
			else // 'D'
			{
				if (q_int.empty() && q_int_rev.empty())
				{
					b_response = true;
					printf("%s\n", "error");
					break;
				}

				if (_reverse % 2 == 1) // 반전 한 횟수가 홀수번이라면 뒤쪽에서 지우기
					q_int.pop_back();
				else
					q_int.pop_front();
			}

			if (i == v_char.size() - 1) // 마지막이면 뒤집어줘야함
			{
				if (_reverse % 2 == 1) // 반전 한 횟수가 홀수번이라면
				{
					if (q_int.empty()) // q_int_rev가 가득 차있다.
					{
						while (!q_int_rev.empty())
						{
							q_int.push_back(q_int_rev.back());
							q_int_rev.pop_back();
						}
					}
					else
					{
						while (!q_int.empty())
						{
							q_int_rev.push_back(q_int.back());
							q_int.pop_back();
						}
					}
				}
				_reverse = 0;
			}
		}

		if (b_response) // 이미 대답이 된 상태면
			continue;
		else
		{
			if (q_int.empty() && q_int_rev.empty())
			{
				printf("%s\n", "[]");
			}
			else if (q_int.empty())
			{
				printf("%c", '[');
				while (!q_int_rev.empty())
				{
					int t = q_int_rev.front();
					q_int_rev.pop_front();
					if (q_int_rev.empty())
					{
						printf("%d%c", t, ']');
					}
					else
						printf("%d%c", t, ',');
				}
				printf("\n");
			}
			else if (q_int_rev.empty())
			{
				printf("%c", '[');
				while (!q_int.empty())
				{
					int t = q_int.front();
					q_int.pop_front();
					if (q_int.empty())
					{
						printf("%d%c", t, ']');
					}
					else
						printf("%d%c", t, ',');
				}
				printf("\n");
			}
		}
	}
}