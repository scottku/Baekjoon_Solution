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

int N, M;
int wall_count = 0;
int Map[51][51];
int _time[51][51];
bool Selected[11];
vector<pair<int, int>> v;
queue<pair<int, int>> q;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int answer = 987654321;

void SelectVirus(int index, int cur_count, int max_count)
{
	if (cur_count == max_count) // 조합 완성 시 체크
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				_time[i][j] = -1;
		}

		int infectedPlace = v.size(); // 기본적으로 바이러스는 활성이든 비활성이든 감염된 곳으로 간주

		for (int i = 0; i < v.size(); i++)
		{
			if (Selected[i])
			{
				q.push(v[i]);
				_time[v[i].first][v[i].second] = 0;
			}
		}

		int _t = 0;

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && Map[nx][ny] != 1 && _time[nx][ny] == -1)
				{
					_time[nx][ny] = _time[x][y] + 1; // 퍼져나간 곳은 그 전 시간 + 1
					if (Map[nx][ny] == 0) // 비활성을 활성시킨게 아닌 빈 공간으로 전파된거면
					{
						infectedPlace++; // 감염 구역 갯수 추가
						_t = _time[nx][ny]; // 막판에 비활성들만 활성화 시키면서 시간 안흐르는 것 방지용으로
						// 빈 공간으로만 전파되었을 때 현재 시간(가장 오래 걸린 시간)을 체크함
					}

					q.push({ nx, ny });
				}
			}
		}
		if (infectedPlace == N * N - wall_count)
		{
			answer = min(answer, _t);
		}
	}
	else
	{
		for (int i = index; i < v.size(); i++)
		{
			Selected[i] = true;
			SelectVirus(i + 1, cur_count + 1, max_count);
			Selected[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(Selected, false, sizeof(Selected));

	cin >> N >> M;
	int temp;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> temp;
			Map[i][j] = temp;

			if (temp == 1)
				wall_count++;

			if (temp == 2)
				v.push_back({ i, j });
		}
	}

	SelectVirus(0, 0, M); // 1. 바이러스 조합 찾기

	if (answer == 987654321)
		cout << -1;
	else
		cout << answer;
}