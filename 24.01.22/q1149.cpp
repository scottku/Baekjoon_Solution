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

int arr[1000][3];
int n;
int dp[1000][3];

int main(void)
{
	scanf("%d", &n);
	int x, y, z;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		arr[i][0] = x;
		arr[i][1] = y;
		arr[i][2] = z;
	}

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}
	int answer = min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
	printf("%d", answer);
}