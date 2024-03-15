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

int test_case;
int arr_to[4];
bool visit[10001]; // 시간 초과를 넘기지 않기 위해 이게 필요했다.

int calcD(int n);
int calcS(int n);
int calcL(int n); // 사실상 현재 코드에선 필요 없음
int calcR(int n); // 사실상 현재 코드에선 필요 없음
//int haveSameOrder(int check); // 숫자 배치 순서가 같으면 L 이나 R 만 넣어보려 했으나 그리 호락호락하지 않았다.

int main(void)
{
	scanf("%d", &test_case);
	for (int tc = 0; tc < test_case; tc++)
	{
		memset(visit, false, sizeof(visit));
		int from, to;
		scanf("%d %d", &from, &to);
		arr_to[0] = to / 1000;
		arr_to[1] = (to - (to / 1000) * 1000) / 100;
		arr_to[2] = (to - (to / 100) * 100) / 10;
		arr_to[3] = (to - (to / 10) * 10);

		queue<pair<int, string>> q;
		q.push({ from,"" });
		while (!q.empty())
		{
			int num = q.front().first;
			string order = q.front().second;
			q.pop();
			int after_calc = calcD(num);
			if (after_calc == to)
			{
				order += "D";
				printf("%s\n", order.c_str());
				break;
			}
			else
			{
				if (!visit[after_calc])
				{
					visit[after_calc] = true;
					q.push({ after_calc, order + "D" });
				}
			}

			after_calc = calcS(num);
			if (after_calc == to)
			{
				order += "S";
				printf("%s\n", order.c_str());
				break;
			}
			else
			{
				if (!visit[after_calc])
				{
					visit[after_calc] = true;
					q.push({ after_calc, order + "S" });
				}
			}

			after_calc = calcL(num);
			if (after_calc == to)
			{
				order += "L";
				printf("%s\n", order.c_str());
				break;
			}
			else
			{
				if (!visit[after_calc])
				{
					visit[after_calc] = true;
					q.push({ after_calc, order + "L" });
				}
			}

			after_calc = calcR(num);
			if (after_calc == to)
			{
				order += "R";
				printf("%s\n", order.c_str());
				break;
			}
			else
			{
				if (!visit[after_calc])
				{
					visit[after_calc] = true;
					q.push({ after_calc, order + "R" });
				}
			}
		}
	}
}

//int haveSameOrder(int check)
//{
//	int thou = check / 1000;
//	int h = (check - (check / 1000) * 1000) / 100;
//	int ten = (check - (check / 100) * 100) / 10;
//	int o = (check - (check / 10) * 10);
//
//	for (int i = 0; i < 4; i++) // 번호가 순서대로 배치되어 있는지 확인
//	{
//		if (thou == arr_to[i])
//		{
//			if (h == arr_to[(i + 1) % 4])
//			{
//				if (ten == arr_to[(i + 2) % 4])
//				{
//					if (o == arr_to[(i + 3) % 4])
//					{
//						return i;
//					}
//				}
//			}
//		}
//	}
//	return -1;
//}

int calcD(int n)
{
	return (n * 2) % 10000;
}
int calcS(int n)
{
	return n - 1 == -1 ? 9999 : n - 1;
}
int calcL(int n)
{
	if (n / 1000 > 0) // 4자리 수
	{
		return (n % 1000) * 10 + (n / 1000); // 1000으로 나눈 나머지들이 앞으로 한칸씩, 천의 자리가 맨 뒤로
	}
	else // 3자리 수 이하, 맨 앞이 0임
	{
		return n * 10;
	}
}
int calcR(int n)
{
	return (n / 10) + (n % 10) * 1000; // 앞의 3자리를 뒤로 한칸씩, 1의 자리를 맨 앞으로
}