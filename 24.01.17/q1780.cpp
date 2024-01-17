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

using namespace std;

int _minus_one = 0;
int _zero = 0;
int _one = 0;

vector<vector<int>> v;

void findPaper(int x, int y, int n)
{
	int tempNum = 404;
	bool b_same = true;
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (tempNum == 404)
				tempNum = v[i][j];
			else
			{
				if (tempNum == v[i][j])
					continue;
				else
				{
					b_same = false;
					break;
				}
			}
		}
		if (!b_same)
			break;
	}

	if (!b_same) // x = 0, y = 0, n = 9 라면 // x = 3, y = 3, n = 3 라면
	{
		n /= 3;
		findPaper(x, y, n);
		findPaper(x + n, y, n);
		findPaper(x + n * 2, y, n);

		findPaper(x, y + n, n);
		findPaper(x + n, y + n, n);
		findPaper(x + n * 2, y + n, n);

		findPaper(x, y + n * 2, n);
		findPaper(x + n, y + n * 2, n);
		findPaper(x + n * 2, y + n * 2, n);
	}
	else
	{
		if (tempNum == -1)
			_minus_one++;
		else if (tempNum == 0)
			_zero++;
		else if (tempNum == 1)
			_one++;
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		vector<int> v_temp;
		for (int j = 0; j < n; j++)
		{
			int n_t;
			scanf("%d", &n_t);
			v_temp.push_back(n_t);
		}
		v.push_back(v_temp);
	}

	findPaper(0, 0, n);
	printf("%d\n", _minus_one);
	printf("%d\n", _zero);
	printf("%d", _one);
}