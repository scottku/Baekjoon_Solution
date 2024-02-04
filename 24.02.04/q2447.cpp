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

int n;

bool arr[6562][6562];

void makePattern(int x_start, int y_start, int _size)
{
	for (int i = x_start + _size / 3; i < x_start + _size * 2 / 3; i++)
	{
		for (int j = y_start + _size / 3; j < y_start + _size * 2 / 3; j++)
		{
			arr[i][j] = false;
		}
	}
	if (_size == 3)
		return;
	else
	{
		makePattern(x_start, y_start, _size / 3);
		makePattern(x_start + _size / 3, y_start, _size / 3);
		makePattern(x_start + _size * 2 / 3, y_start, _size / 3);
		makePattern(x_start, y_start + _size / 3, _size / 3);
		makePattern(x_start + 2 * _size / 3, y_start + _size / 3, _size / 3);
		makePattern(x_start, y_start + 2 * _size / 3, _size / 3);
		makePattern(x_start + _size / 3, y_start + 2 * _size / 3, _size / 3);
		makePattern(x_start + 2 * _size / 3, y_start + 2 * _size / 3, _size / 3);
	}
}

int main(void)
{
	memset(arr, true, sizeof(arr));
	scanf("%d", &n);
	makePattern(1, 1, n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j])
				printf("%c", '*');
			else
				printf("%c", ' ');

			if (j == n)
				printf("\n");
		}
	}
}