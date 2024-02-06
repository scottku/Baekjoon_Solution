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

char c1[1001];
char c2[1001];
int dp[1001][1001];

int main(void)
{
	char c;
	int _cnt = 0;
	int n_c1 = 1;
	int n_c2 = 1;
	while (_cnt < 2)
	{
		scanf("%c", &c);

		if ((int)c == (int)'\n')
		{
			_cnt++;
			continue;
		}

		if (_cnt == 0)
		{
			c1[n_c1] = c;
			n_c1++;
		}
		else if (_cnt == 1)
		{
			c2[n_c2] = c;
			n_c2++;
		}
	}

	for (int i = 1; i < n_c1; i++)
	{
		if (dp[1][i - 1] == 1)
			dp[1][i] = 1;
		else
		{
			if ((int)c1[i] == (int)c2[1])
				dp[1][i] = 1;
			else
				dp[1][i] = 0;
		}
	}
	for (int i = 1; i < n_c2; i++)
	{
		if (dp[i - 1][1] == 1)
			dp[i][1] = 1;
		else
		{
			if ((int)c1[1] == (int)c2[i])
				dp[i][1] = 1;
			else
				dp[i][1] = 0;
		}
	}

	for (int i = 2; i < n_c1; i++)
	{
		for (int j = 2; j < n_c2; j++)
		{
			if ((int)c1[i] == (int)c2[j])
			{
				dp[j][i] = dp[j - 1][i - 1] + 1;
			}
			else
			{
				dp[j][i] = max(dp[j - 1][i], dp[j][i - 1]);
			}
		}
	}

	printf("%d", dp[n_c2 - 1][n_c1 - 1]);
}