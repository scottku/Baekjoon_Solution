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

vector<int> v;
int arr[2][100000];
int dp[2][100000];

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(dp, 0, sizeof(dp));
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < temp; k++)
			{
				int t;
				scanf("%d", &t);
				arr[j][k] = t;
			}
		}

		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];
		for (int j = 2; j < temp; j++)
		{
			dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + arr[0][j];
			dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + arr[1][j];
		}
		int _max = max(dp[0][temp - 1], dp[1][temp - 1]);
		printf("%d\n", _max);
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
	}
}