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

int arr[10][10];
vector<pair<int, int>> v;

bool findPos(int v_pos);

int main(void)
{
	memset(arr, 0, sizeof(arr));
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
			if (temp == 0)
				v.push_back({ i,j });
		}
	}

	findPos(0);
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

bool findPos(int v_pos)
{
	if (v_pos == v.size()) // 비어있는 부분을 끝까지 확인해 더이상 확인할 게 없음
		return true;

	int x = v[v_pos].first;
	int y = v[v_pos].second;

	bool b_X[10];
	memset(b_X, false, sizeof(b_X));
	for (int i = 1; i <= 9; i++)
	{
		if (y == i)
			continue;
		else
			b_X[arr[x][i]] = true;
	}

	bool b_Y[10];
	memset(b_Y, false, sizeof(b_Y));
	for (int i = 1; i <= 9; i++)
	{
		if (x == i)
			continue;
		else
			b_Y[arr[i][y]] = true;
	}

	bool b_XY[10];
	memset(b_XY, false, sizeof(b_XY));

	int m_x = x / 3;
	int n_x = x % 3;
	int m_y = y / 3;
	int n_y = y % 3;
	int num_x = -1;
	int num_y = -1;

	if (m_x == 0 || (m_x == 1 && n_x == 0)) // 1~3
		num_x = 0;
	else if ((m_x == 1 && n_x != 0) || (m_x == 2 && n_x == 0)) // 4~6
		num_x = 1;
	else // 7~9
		num_x = 2;

	if (m_y == 0 || (m_y == 1 && n_y == 0)) // 1~3
		num_y = 0;
	else if ((m_y == 1 && n_y != 0) || (m_y == 2 && n_y == 0)) // 4~6
		num_y = 1;
	else // 7~9
		num_y = 2;

	for (int i = num_x * 3 + 1; i <= num_x * 3 + 3; i++)
	{
		for (int j = num_y * 3 + 1; j <= num_y * 3 + 3; j++)
		{
			if (x == i || y == j)
				continue;
			else
				b_XY[arr[i][j]] = true;
		}
	}

	for (int i = 1; i <= 9; i++)
	{
		if (!b_X[i] && !b_Y[i] && !b_XY[i]) // 어느 방향으로 보나 들어갈 수 있는 수
		{
			arr[x][y] = i; // 해당 위치에 수 집어넣고
			if (!findPos(v_pos + 1)) // 다음 벡터 인자 체크하러 들어감
			{
				// 올바른 수가 아니었다면
				arr[x][y] = 0; // 롤백 후 다른 숫자 집어넣어봄
			}
			else
				return true;
		}

		if (i == 9) // 마지막까지 체크해봤는데 들어갈 수 있는 숫자가 없다면
			return false; // false 리턴해서 전으로 돌아감
	}
}