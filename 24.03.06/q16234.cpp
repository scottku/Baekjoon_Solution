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

int arr[51][51];
int n, l, r;
int _sum = 0;
int _count = 0;
int _day = 0;
bool b_noConnection = true;

bool visit[51][51];
bool visit_div[51][51];
bool connect[51][51][4];

void makeConnection(int x, int y, int range);
void connectionSum(int x, int y, bool b_start);
void connectionDiv(int x, int y, int div);

int main(void)
{
	scanf("%d %d %d", &n, &l, &r);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
		}
	}

	// 단순히 true로 국경이 연결됨을 확인하면 국경 연결 안되어있고 따로따로 섬처럼 연결되어있는데 모든 값이 더해져서 이상해짐
	// union-find 느낌으로 진행해봐야 겠음
	// 추가 궁금증 : 

	while (true)
	{
		b_noConnection = true;
		memset(connect, false, sizeof(connect));
		makeConnection(1, 1, n);

		if (b_noConnection)
			break;
		_day++;

		memset(visit, false, sizeof(visit));
		memset(visit_div, false, sizeof(visit_div));
		_sum = 0;
		_count = 0;
		connectionSum(1, 1, true);
	}

	printf("%d", _day);

	/*int _day = 0;
	while (true)
	{
		bool open[51][51] = { false };
		bool visit[51][51] = { false };
		bool isOpen = false; // 한개라도 국경이 열리는 곳이 있는가
		for (int i = 1; i <= n; i++) // 국경 열리는 곳 확인
		{
			for (int j = 1; j <= n; j++)
			{
				if (i - 1 >= 1) // 상
				{
					if (!visit[i - 1][j])
					{
						if (abs(nara[i][j] - nara[i - 1][j]) >= l && abs(nara[i][j] - nara[i - 1][j]) <= r)
						{
							open[i][j] = true;
							open[i - 1][j] = true;
							isOpen = true;
						}
					}
				}
				if (i + 1 <= n) // 하
				{
					if (!visit[i + 1][j])
					{
						if (abs(nara[i][j] - nara[i + 1][j]) >= l && abs(nara[i][j] - nara[i + 1][j]) <= r)
						{
							open[i][j] = true;
							open[i + 1][j] = true;
							isOpen = true;
						}
					}
				}
				if (j - 1 >= 1) // 좌
				{
					if (!visit[i][j - 1])
					{
						if (abs(nara[i][j] - nara[i][j - 1]) >= l && abs(nara[i][j] - nara[i][j - 1]) <= r)
						{
							open[i][j] = true;
							open[i][j - 1] = true;
							isOpen = true;
						}
					}
				}
				if (j + 1 <= n) // 하
				{
					if (!visit[i][j + 1])
					{
						if (abs(nara[i][j] - nara[i][j + 1]) >= l && abs(nara[i][j] - nara[i][j + 1]) <= r)
						{
							open[i][j] = true;
							open[i][j + 1] = true;
							isOpen = true;
						}
					}
				}

				visit[i][j] = true;
			}
		}

		if (!isOpen) // 한 곳도 국경이 열리지 않았다면
			break;

		int _sum = 0;
		int _count = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (open[i][j])
				{
					_sum += nara[i][j];
					_count++;
				}
			}
		}

		int _result = _sum / _count;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (open[i][j])
				{
					nara[i][j] = _result;
				}
			}
		}

		_day++;
	}

	printf("%d", _day);*/
}
// 추가 궁금증 : 방문했던 곳을 다시 체크하지 않기위해 connect[x][y][0] = true로 변경할 때 connect[x-1][y][2] = true로 미리미리 변경해주려고 하는데
// 해당 작업을 진행하면 시간 초과가 뜬다...
void makeConnection(int x, int y, int range)
{
	if (x - 1 >= 1) // 상
	{
		if (abs(arr[x][y] - arr[x - 1][y]) >= l && abs(arr[x][y] - arr[x - 1][y]) <= r)
		{
			connect[x][y][0] = true;
			b_noConnection = false;
		}
	}
	if (x + 1 <= n) // 하
	{
		if (abs(arr[x][y] - arr[x + 1][y]) >= l && abs(arr[x][y] - arr[x + 1][y]) <= r)
		{
			connect[x][y][2] = true;
			b_noConnection = false;
		}
	}
	if (y - 1 >= 1) // 좌
	{
		if (abs(arr[x][y] - arr[x][y - 1]) >= l && abs(arr[x][y] - arr[x][y - 1]) <= r)
		{
			connect[x][y][3] = true;
			b_noConnection = false;
		}
	}
	if (y + 1 <= n) // 우
	{
		if (abs(arr[x][y] - arr[x][y + 1]) >= l && abs(arr[x][y] - arr[x][y + 1]) <= r)
		{
			connect[x][y][1] = true;
			b_noConnection = false;
		}
	}

	if (y + 1 > range)
	{
		if (x + 1 > range)
			return;
		else
			makeConnection(x + 1, 1, range);
	}
	else
		makeConnection(x, y + 1, range);
}

void connectionSum(int x, int y, bool b_start)
{
	if (visit[x][y])
	{
		_sum = 0;
		_count = 0;
		if (y + 1 > n)
		{
			if (x + 1 > n)
				return;
			else
				connectionSum(x + 1, 1, true);
		}
		else
			connectionSum(x, y + 1, true);

		return;
	}

	_sum += arr[x][y];
	_count += 1;
	visit[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		if (connect[x][y][i]) // 0 상 1 우 2 하 3 좌 연결 여부
		{
			switch (i)
			{
			case 0:
				if (!visit[x - 1][y])
				{
					connectionSum(x - 1, y, false);
				}
				break;
			case 1:
				if (!visit[x][y + 1])
				{
					connectionSum(x, y + 1, false);
				}
				break;
			case 2:
				if (!visit[x + 1][y])
				{
					connectionSum(x + 1, y, false);
				}
				break;
			case 3:
				if (!visit[x][y - 1])
				{
					connectionSum(x, y - 1, false);
				}
				break;
			}
		}
	}

	if (b_start)
	{
		if (_count != 1)
		{
			int div = _sum / _count;
			connectionDiv(x, y, div);
		}

		_sum = 0;
		_count = 0;
		if (y + 1 > n)
		{
			if (x + 1 > n)
				return;
			else
				connectionSum(x + 1, 1, true);
		}
		else
			connectionSum(x, y + 1, true);
	}
}

void connectionDiv(int x, int y, int div)
{
	arr[x][y] = div;
	visit_div[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		if (connect[x][y][i]) // 0 상 1 우 2 하 3 좌 연결 여부
		{
			switch (i)
			{
			case 0:
				if (!visit_div[x - 1][y])
				{
					connectionDiv(x - 1, y, div);
				}
				break;
			case 1:
				if (!visit_div[x][y + 1])
				{
					connectionDiv(x, y + 1, div);
				}
				break;
			case 2:
				if (!visit_div[x + 1][y])
				{
					connectionDiv(x + 1, y, div);
				}
				break;
			case 3:
				if (!visit_div[x][y - 1])
				{
					connectionDiv(x, y - 1, div);
				}
				break;
			}
		}
	}
}