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

using namespace std;

int n;
int arr[17][17];

int main(void)
{
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

	// 2: 가로, 3: 세로, 4: 대각선
	queue<pair<int, pair<int, int>>> q;
	q.push({ 2, {1, 2} }); // 가로 방식의 파이프, 끝 점은 (1,2)
	int _count = 0;
	while (!q.empty())
	{
		int pipe_type = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (x == n && y == n)
		{
			_count++;
			continue;
		}

		switch (pipe_type)
		{
		case 2: // 가로
			if (arr[x][y + 1] != 1 && y + 1 <= n) // 가로방향에 벽이 없고 범위를 벗어나지 않는다.
			{
				q.push({ 2, {x, y + 1} });
				if (arr[x + 1][y + 1] != 1 && arr[x + 1][y] != 1 && x + 1 <= n)
					q.push({ 4, {x + 1,y + 1} });
			}
			break;
		case 3: // 세로
			if (arr[x + 1][y] != 1 && x + 1 <= n) // 세로방향에 벽이 없고 범위를 벗어나지 않는다.
			{
				q.push({ 3, {x + 1, y} });
				if (arr[x + 1][y + 1] != 1 && arr[x][y + 1] != 1 && y + 1 <= n)
					q.push({ 4, {x + 1,y + 1} });
			}
			break;
		case 4: // 대각선
			if (arr[x][y + 1] != 1 && y + 1 <= n) // 가로방향에 벽이 없고 범위를 벗어나지 않는다.
			{
				q.push({ 2, {x, y + 1} });
			}
			if (arr[x + 1][y] != 1 && x + 1 <= n) // 세로방향에 벽이 없고 범위를 벗어나지 않는다.
			{
				q.push({ 3, {x + 1, y} });
			}
			if (arr[x][y + 1] != 1 && arr[x + 1][y] != 1 && arr[x + 1][y + 1] != 1 && x + 1 <= n && y + 1 <= n)
			{
				q.push({ 4, {x + 1, y + 1} });
			}
			break;
		}
	}
	printf("%d", _count);
}