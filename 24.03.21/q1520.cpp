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
#include <climits>
#include <time.h>

using namespace std;

int height, width;
int arr[501][501];
int dp[501][501];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int dfs(int x, int y)
{
	if (x == height && y == width)
		return 1;
	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 1 && xx <= height && yy >= 1 && yy <= width)
		{
			if (arr[x][y] > arr[xx][yy])
				dp[x][y] += dfs(xx, yy);
		}
	}
	return dp[x][y];
}

//class comp
//{
//public:
//	bool operator() (const pair<pair<int, int>, bool>& p1, const pair<pair<int, int>, bool>& p2)
//	{
//		if (p1.first.first != p2.first.first) // 더 위쪽인 순서
//			return p1.first.first > p2.first.first;
//		else if(p1.first.second != p2.first.second) // 더 왼쪽인 순서
//			return p1.first.second > p2.first.second;
//	}
//};

int main(void)
{
	memset(arr, 0, sizeof(arr));

	scanf("%d %d", &height, &width);
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			dp[i][j] = -1;
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
		}
	}

	int answer = dfs(1, 1);
	printf("%d", answer);
}