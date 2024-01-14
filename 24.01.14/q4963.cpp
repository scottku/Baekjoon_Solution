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

vector<vector<int>> v_map;
int n_land = 0;

void isThisLand(int m, int n, int w_limit, int h_limit, bool _first)
{
	if (v_map[m][n] == 1)
	{
		v_map[m][n] = 0;
		if (m + 1 < w_limit)
		{
			if (v_map[m + 1][n] == 1)
			{
				isThisLand(m + 1, n, w_limit, h_limit, false);
			}
		}
		if (n + 1 < h_limit)
		{
			if (v_map[m][n + 1] == 1)
			{
				isThisLand(m, n + 1, w_limit, h_limit, false);
			}
		}
		if (m - 1 >= 0)
		{
			if (v_map[m - 1][n] == 1)
			{
				isThisLand(m - 1, n, w_limit, h_limit, false);
			}
		}
		if (n - 1 >= 0)
		{
			if (v_map[m][n - 1] == 1)
			{
				isThisLand(m, n - 1, w_limit, h_limit, false);
			}
		}
		if (m + 1 < w_limit && n + 1 < h_limit)
		{
			if (v_map[m + 1][n + 1] == 1)
			{
				isThisLand(m + 1, n + 1, w_limit, h_limit, false);
			}
		}
		if (m + 1 < w_limit && n - 1 >= 0)
		{
			if (v_map[m + 1][n - 1] == 1)
			{
				isThisLand(m + 1, n - 1, w_limit, h_limit, false);
			}
		}
		if (m - 1 >= 0 && n + 1 < h_limit)
		{
			if (v_map[m - 1][n + 1] == 1)
			{
				isThisLand(m - 1, n + 1, w_limit, h_limit, false);
			}
		}
		if (m - 1 >= 0 && n - 1 >= 0)
		{
			if (v_map[m - 1][n - 1] == 1)
			{
				isThisLand(m - 1, n - 1, w_limit, h_limit, false);
			}
		}

		if (_first)
			n_land++;
	}
}

int main(void)
{
	while (true)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;

		for (int i = 0; i < m; i++)
		{
			vector<int> v_temp;
			for (int j = 0; j < n; j++)
			{
				int temp;
				scanf("%d", &temp);
				v_temp.push_back(temp);
			}
			v_map.push_back(v_temp);
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				isThisLand(i, j, m, n, true);
			}
		}

		printf("%d\n", n_land);
		n_land = 0;
		v_map.clear();
	}
}