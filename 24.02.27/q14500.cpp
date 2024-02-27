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

// 시간 체크용
//#include <time.h>
// clock_t start, end;
// start = clock();
// 체크해보고싶은 함수
// end = clock();
// double result = end - start;
// printf("%f", result / CLOCKS_PER_SEC);

using namespace std;

int n, m;
int arr[501][501];
bool visit[501][501];
int answer = 0;
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1, 1 };

void DFS(int x, int y, int _total, int _count) // _count = n 번째 칸이라는 뜻
{
	visit[x][y] = true;

	if (_count == 4)
	{
		answer = max(answer, _total);
		visit[x][y] = false; // 돌아갈 때 visit을 취소해야 다음에 다른 방식으로도 접근 가능
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int _dx = x + dx[i];
		int _dy = y + dy[i];
		if (_dx > 0 && _dx <= n && _dy > 0 && _dy <= m && !visit[_dx][_dy])
		{
			DFS(_dx, _dy, _total + arr[_dx][_dy], _count + 1);
		}
	}
	visit[x][y] = false; // 돌아갈 때 visit을 취소해야 다음에 다른 방식으로도 접근 가능
}

void CharA(int x, int y) // 중심점을 기준으로 주면 3방향을 선택해 ㅏ ㅗ 모양을 만듦
{
	int sum, _dx, _dy;
	for (int i = 0; i < 4; i++)
	{
		sum = arr[x][y];
		for (int dir = 0; dir < 4; dir++)
		{
			if (dir == i)
				continue;
			_dx = x + dx[dir];
			_dy = y + dy[dir];
			if (_dx > 0 && _dx <= n && _dy > 0 && _dy <= m)
				sum += arr[_dx][_dy];
		}
		answer = max(answer, sum);
	}
}

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(visit, false, sizeof(visit));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
		}
	}

	for (int i = 1; i <= n; i++) // 가운데 부분에 튀어나온 ㅗ 모양은 DFS로 확인 불가능함
	{
		for (int j = 1; j <= m; j++)
		{
			DFS(i, j, arr[i][j], 1);
			CharA(i, j);
		}
	}

	printf("%d", answer);
}