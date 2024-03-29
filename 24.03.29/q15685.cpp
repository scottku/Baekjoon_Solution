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

int N;
// pair<bool, bool> arr[101][101]; 
// arr[a][b].first : (b,a)에서 오른쪽으로 가는 변이 드래곤 커브에 포함되는가 (그림상 x가 커지는 방향)
// arr[a][b].second : (b,a)에서 아래로 내려가는 변이 드래곤 커브에 포함되는가 (그림상 y가 커지는 방향)
bool included[101][101];

void makeDragonCurve(int y, int x, int d, int g)
{
	vector<pair<int, int>> v;
	v.push_back({ y,x });
	switch (d)
	{
	case 0:
		v.push_back({ y, x + 1 });
		break;
	case 1:
		v.push_back({ y - 1, x });
		break;
	case 2:
		v.push_back({ y,x - 1 });
		break;
	case 3:
		v.push_back({ y + 1,x });
		break;
	}

	while (g > 0)
	{
		int end_y = v[v.size() - 1].first;
		int end_x = v[v.size() - 1].second;

		for (int i = 0; i < v.size(); i++)
		{
			v[i].first -= end_y;
			v[i].second -= end_x;
		} // 회전할 기준이 되는 점을 0,0으로 변경
		for (int i = v.size() - 2; i >= 0; i--)
		{
			v.push_back({ v[i].second, v[i].first * (-1) });
		}
		for (int i = 0; i < v.size(); i++)
		{
			v[i].first += end_y;
			v[i].second += end_x;
		}
		g--;
	}

	for (int i = 0; i < v.size(); i++)
	{
		included[v[i].first][v[i].second] = true;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			//arr[i][j] = { false, false };
			included[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		makeDragonCurve(y, x, d, g);
	}

	int _count = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (included[i][j] && included[i + 1][j] && included[i][j + 1] && included[i + 1][j + 1])
				_count++;
		}
	}
	cout << _count;
}