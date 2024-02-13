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

int tc;
bool broken[10];
int arr[6] = { -1, -1, -1, -1, -1, -1 };
int idx;

bool canWeMakeThisChannel(int _channel)
{
	bool isFirst = true;
	int _c = _channel;
	for (int i = 0; i <= 5; i++)
	{
		int temp = _c / pow(10, 5 - i);
		if (temp != 0)
		{
			if (broken[temp])
				return false;
			if (isFirst)
			{
				idx = 6 - i;
				isFirst = false;
			}
		}
		else
		{
			if (!isFirst)
			{
				if (broken[temp])
					return false;
			}
			else
			{
				if (i == 5)
				{
					idx = 1; // 0만 있을 때, 1자리 수가 있을 수 있다는 걸 체크해줘야지!
					if (broken[temp])
						return false;
				}
			}
		}
		_c -= temp * pow(10, 5 - i);
	}
	return true;
}

int main(void)
{
	memset(broken, false, sizeof(broken));
	scanf("%d", &tc);
	int origin = tc;
	bool bFirst = true;
	int numberIndex = 1;
	for (int i = 0; i < 6; i++)
	{
		int temp = tc / pow(10, 5 - i);
		if (temp != 0)
		{
			if (bFirst)
				numberIndex = i; // 몇자리 수인지 확인용
			bFirst = false;
			arr[i] = temp;
			tc = tc - temp * pow(10, 5 - i);
		}
		else
		{
			if (!bFirst)
				arr[i] = 0;
		}

		if (i == 5 && bFirst && temp == 0)
		{
			arr[5] = 0;
			numberIndex = 5;
		}
	}

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		broken[temp] = true;
	}

	int answer = 100 > origin ? 100 - origin : origin - 100;
	for (int i = 0; i <= 1000000; i++)
	{
		int channel_pick = answer + origin + 1;
		if (canWeMakeThisChannel(i))
			channel_pick = i;
		else
			continue;
		answer = min(answer, abs(channel_pick - origin) + idx);
	}

	printf("%d", answer);
}