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

#define INF 987654321
int N, S;
vector<int> v;

int main(void)
{
	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}

	int _tail = 0;
	int _sum = 0;
	int answer = INF;
	for (int i = 0; i < v.size(); i++)
	{
		_sum += v[i];
		if (_sum < S) // 합이 아직 목표보다 작다
		{
			continue;
		}
		else // 뒷부분을 더했을 때 목표보다 커졌다
		{
			while (true)
			{
				if (_sum - v[_tail] < S) // 그래서 맨 뒤에있는 수를 빼려했더니 빼면 목표보다 작아지더라
					break;
				else
				{
					_sum -= v[_tail];
					_tail++;
				}
			}
			answer = min(answer, i - _tail + 1);
		}
	}
	if (answer == INF)
		printf("0");
	else
		printf("%d", answer);
}