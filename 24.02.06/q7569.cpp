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

int col, row, h;
int arr[101][101][101];
bool visit[101][101][101];
int _total = 0;
int _count = 0;
int _date = 0;
int dc[6] = { 0, 0, -1, 1, 0 ,0 }; // (평면) 상하좌우 (위아래) 상하
int dr[6] = { -1, 1, 0 ,0, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(visit, false, sizeof(visit));
	scanf("%d %d %d", &col, &row, &h);
	queue<vector<int>> q;

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= row; j++)
		{
			for (int k = 1; k <= col; k++)
			{
				int temp;
				scanf("%d", &temp);
				arr[i][j][k] = temp;
				if (temp == -1) // 비어있는 위치
					visit[i][j][k] = true; // 방문하지 못하도록 미리 막아둠
				else // 일단 토마토가 존재는 한다면
				{
					_total++; // 전체 개수에 포함
					if (temp == 1) // 익은 토마토라면 큐에 포함
					{
						visit[i][j][k] = true;
						_count++; // 이미 익은 것들은 익은 토마토 개수에 미리 포함시킴
						vector<int> t_v;
						t_v.push_back(i);
						t_v.push_back(j);
						t_v.push_back(k);
						t_v.push_back(0); // 0일차
						q.push(t_v);
					}

				}
			}
		}
	}

	while (!q.empty())
	{
		vector<int> t_v = q.front();
		q.pop();
		int _h = t_v[0];
		int _r = t_v[1];
		int _c = t_v[2];
		int _cnt = t_v[3];

		if (_cnt > _date)
			_date = _cnt;

		for (int i = 0; i < 6; i++)
		{
			int _dh = _h + dh[i];
			int _dr = _r + dr[i];
			int _dc = _c + dc[i];

			if (_dh >= 1 && _dh <= h && _dr >= 1 && _dr <= row && _dc >= 1 && _dc <= col && !visit[_dh][_dr][_dc]) // 빈 공간은 방문한 것으로 되어있어 방문 못함
			{
				_count++;
				visit[_dh][_dr][_dc] = true;
				vector<int> v;
				v.push_back(_dh);
				v.push_back(_dr);
				v.push_back(_dc);
				v.push_back(_cnt + 1);
				q.push(v);
			}
		}
	}

	if (_total != _count) // 빈 공간때문에 막혀서 다 못익음
		printf("%d", -1);
	else
		printf("%d", _date);
}