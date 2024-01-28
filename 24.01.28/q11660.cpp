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

int n, c;
int arr[1025][1025];
int dp[1025][1025];

int findDP(int x, int y)
{
	if (dp[x][y] != 0)
		return dp[x][y];

	if (x - 1 >= 1 && y - 1 >= 1)
		dp[x][y] = arr[x][y] + findDP(x - 1, y) + findDP(x, y - 1) - findDP(x - 1, y - 1);
	else if (x - 1 < 1)
		dp[x][y] = arr[x][y] + findDP(x, y - 1);
	else if (y - 1 < 1)
		dp[x][y] = arr[x][y] + findDP(x - 1, y);
	else // 1,1
		return arr[1][1];
	return dp[x][y];
}

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(dp, 0, sizeof(dp));
	scanf("%d %d", &n, &c);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
		}
	}

	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][1] + arr[1][2];
	dp[2][1] = arr[1][1] + arr[2][1];

	for (int loop = 0; loop < c; loop++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		if (x1 == x2 && y1 == y2)
		{
			printf("%d\n", arr[x1][y1]);
			continue;
		}

		if (x1 == 1 && y1 == 1)
			printf("%d\n", findDP(x2, y2));
		else if (x1 == 1)
			printf("%d\n", findDP(x2, y2) - findDP(x2, y1 - 1));
		else if (y1 == 1)
			printf("%d\n", findDP(x2, y2) - findDP(x1 - 1, y2));
		else
			printf("%d\n", findDP(x2, y2) - findDP(x1 - 1, y2) - findDP(x2, y1 - 1) + findDP(x1 - 1, y1 - 1));
	}
}