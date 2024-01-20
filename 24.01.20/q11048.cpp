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

int dp[1001][1001];
int as[1001][1001];
int h, w;

int GoToFinal(int _h, int _w)
{
	if (_h < 1 || _w < 1)
		return 0;

	if (as[_h][_w] != 0)
		return as[_h][_w];

	as[_h][_w] = max(max(GoToFinal(_h - 1, _w) + dp[_h][_w], GoToFinal(_h, _w - 1) + dp[_h][_w]), GoToFinal(_h - 1, _w - 1) + dp[_h][_w]);
	return as[_h][_w];
}

int main(void)
{
	memset(dp, 0, sizeof(dp));
	memset(as, 0, sizeof(as));


	scanf("%d %d", &h, &w);
	int temp;
	bool b_zero = true;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			scanf("%d", &temp);
			dp[i][j] = temp;
			if (b_zero && temp != 0)
				b_zero = false;
		}
	}

	if (b_zero) // 모든 인자가 0
		printf("%d", 0);
	else
	{
		as[1][1] = dp[1][1];
		int answer = GoToFinal(h, w);
		printf("%d", answer);
	}
}