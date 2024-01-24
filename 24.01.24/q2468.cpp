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
int arr[100][100];
bool visit[100][100];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 }; // 상 하 좌 우
int _count = 0;
void BFS(int water_height, int x, int y, bool _first)
{
	if (visit[x][y]) // 이미 방문한 곳
	{
		if (_first) // 처음 시작점을 찾는 중이라면
		{
			if (y + 1 < n)
				BFS(water_height, x, y + 1, true); // BFS를 다음 지점으로 보내 계속 찾는다
			else
			{
				if (x + 1 < n)
					BFS(water_height, x + 1, 0, true);
			}
		}
		return; // return 넣지 않으면 아래 _count++ 쪽에 모든 true 인자를 갖는 BFS 함수가 관여함
	}
	else
		visit[x][y] = true;

	if (arr[x][y] <= water_height) // 물 높이보다 낮은 땅은 시작점이 될 수 없고 연결점이 될 수 없다.
	{
		if (!_first) // 연결된 땅을 찾는 중이었다면 돌아가기
			return;

		if (y + 1 < n) // 시작점을 찾는 중이라면 위치를 이동시켜 다시 진행
			BFS(water_height, x, y + 1, true);
		else
		{
			if (x + 1 < n)
				BFS(water_height, x + 1, 0, true);
		}
	}
	else // 처음 방문했고, 물 높이보다도 높은 지점이다.
	{
		for (int i = 0; i < 4; i++) // 상하좌우에 존재하며, 방문하지 않은 점들을 찾아 이동한다.
		{
			int a = x + dx[i];
			int b = y + dy[i];
			if (a >= 0 && a < n && b >= 0 && b < n && !visit[a][b]) // 사각형 내부 + 방문 여부
			{
				BFS(water_height, a, b, false);
			}
		}

		if (_first) // 맨 처음 시작점을 기준으로 땅이 이어지므로 1번만 count를 추가한다, 연계된 false 땅들은 추가하면 안됨
		{
			_count++;

			if (y + 1 < n) // 맵이 끝난게 아니라면 계속 BFS 진행
				BFS(water_height, x, y + 1, true);
			else
			{
				if (x + 1 < n)
					BFS(water_height, x + 1, 0, true);
			}
		}
	}
}

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(visit, false, sizeof(visit));
	scanf("%d", &n);
	int _max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
			if (_max < temp)
				_max = temp;
		}
	}
	// _max => 최대 높이값 정해두기 // _max 값 아래로만 체크하면 됨
	int result = -1;
	for (int i = 0; i < _max; i++)
	{
		BFS(i, 0, 0, true);
		result = max(result, _count); // 땅 최댓값 저장
		_count = 0; // 땅 갯수 리셋
		memset(visit, false, sizeof(visit)); // 방문 리셋
	}
	printf("%d", result);
}