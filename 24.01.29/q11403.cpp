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
int arr[101][101];
int dp[101][101];

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
		}
	}

	vector<int> v;
	bool visit[101];
	for (int i = 1; i <= n; i++)
	{
		v.clear();
		memset(visit, false, sizeof(visit));
		queue<int> q;

		for (int j = 1; j <= n; j++)
		{
			v.push_back(arr[i][j]);
			if (arr[i][j] == 1)
				q.push(j);
		}

		while (!q.empty())
		{
			int _next = q.front();
			q.pop();
			visit[_next] = true;

			for (int j = 1; j <= n; j++)
			{
				v[j - 1] += arr[_next][j];
				if (arr[_next][j] == 1 && !visit[j])
					q.push(j);
			}
		}

		for (int j = 1; j <= n; j++)
		{
			if (v[j - 1] != 0)
				dp[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == n)
				printf("%d\n", dp[i][j]);
			else
				printf("%d ", dp[i][j]);
		}
	}
}