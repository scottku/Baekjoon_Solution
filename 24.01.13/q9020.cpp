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
#include <algorithm>
#include <queue>

using namespace std;

bool arr[10001];

int main(void)
{
	memset(arr, 0, sizeof(arr));

	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i < 5000; i++)
	{
		for (int j = 2; i * j <= sizeof(arr) - 1; j++)
		{
			arr[i * j] = true;
		}
	} // true = 소수x , false = 소수

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{

		int temp;
		scanf("%d", &temp);
		int num = temp / 2;
		while (true)
		{
			if (!arr[num])
			{
				if (!arr[temp - num])
				{
					if (num > temp - num)
						printf("%d %d\n", temp - num, num);
					else
						printf("%d %d\n", num, temp - num);
					break;
				}
			}
			num++;
		}
	}
}