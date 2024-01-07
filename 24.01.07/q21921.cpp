#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <memory.h>

using namespace std;

int _array[250001];

int main(void)
{
	memset(_array, 0, sizeof(_array));
	int n_day, n_visit;
	scanf("%d %d", &n_day, &n_visit);
	for (int i = 1; i <= n_day; i++)
	{
		int temp;
		scanf("%d", &temp);
		_array[i] = temp;
	}

	int count = 0;
	for (int i = 1; i <= n_visit; i++)
	{
		count += _array[i]; //n_visit이 3 이면 1 2 3번째가 더해졌을 것
	}

	int max_visit = count;
	int max_day = 1;

	int temp;
	for (int i = 2; i <= n_day - n_visit + 1; i++)
	{
		temp = count;
		count = count - _array[i - 1] + _array[i - 1 + n_visit]; // 1 2 3 -> 2 3 4
		if (temp > count)
			continue;
		else if (temp == count)
		{
			max_day++;
		}
		else if (temp < count)
		{
			max_visit = count;
			max_day = 1;
		}
	}

	if (max_visit == 0)
		//printf("%s", "SAD");
		cout << "SAD" << endl;
	else
		printf("%d\n%d", max_visit, max_day);
}