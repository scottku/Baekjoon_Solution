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

deque<int> gear1;
deque<int> gear2;
deque<int> gear3;
deque<int> gear4;
vector<deque<int>> v = { gear1, gear2, gear3, gear4 };

void RotateGear_Right(int _gear, int _dir)
{
	int left = v[_gear - 1][6];
	int right = v[_gear - 1][2];

	if (_dir == 1) // 시계방향 -> 뒤에꺼 빼다가 앞으로 보내기
	{
		int _back = v[_gear - 1].back();
		v[_gear - 1].push_front(_back);
		v[_gear - 1].pop_back();
	}
	else
	{
		int _front = v[_gear - 1].front();
		v[_gear - 1].push_back(_front);
		v[_gear - 1].pop_front();
	}

	if (_gear != 4) // 가장 오른쪽 톱니바퀴가 아니라면
	{
		if (right != v[_gear][6])
			RotateGear_Right(_gear + 1, _dir * (-1));
	}
}

void RotateGear_Left(int _gear, int _dir)
{
	int left = v[_gear - 1][6];
	int right = v[_gear - 1][2];

	if (_dir == 1) // 시계방향 -> 뒤에꺼 빼다가 앞으로 보내기
	{
		int _back = v[_gear - 1].back();
		v[_gear - 1].push_front(_back);
		v[_gear - 1].pop_back();
	}
	else
	{
		int _front = v[_gear - 1].front();
		v[_gear - 1].push_back(_front);
		v[_gear - 1].pop_front();
	}

	if (_gear != 1)
	{
		if (left != v[_gear - 2][2])
			RotateGear_Left(_gear - 1, _dir * (-1));
	}
}

void RotateGear(int _gear, int _dir)
{
	int left = v[_gear - 1][6];
	int right = v[_gear - 1][2];

	if (_dir == 1) // 시계방향 -> 뒤에꺼 빼다가 앞으로 보내기
	{
		int _back = v[_gear - 1].back();
		v[_gear - 1].push_front(_back);
		v[_gear - 1].pop_back();
	}
	else
	{
		int _front = v[_gear - 1].front();
		v[_gear - 1].push_back(_front);
		v[_gear - 1].pop_front();
	}

	if (_gear != 4) // 가장 오른쪽 톱니바퀴가 아니라면
	{
		if (right != v[_gear][6])
			RotateGear_Right(_gear + 1, _dir * (-1));
	}
	if (_gear != 1)
	{
		if (left != v[_gear - 2][2])
			RotateGear_Left(_gear - 1, _dir * (-1));
	}
}

int main(void)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++) // 0 1 (2) 3 4 5 (6) 7
		{
			int temp;
			scanf("%1d", &temp);
			v[i].push_back(temp);
		}
	}
	int num_rotate;
	scanf("%d", &num_rotate);
	for (int i = 0; i < num_rotate; i++)
	{
		int num_gear, dir;
		scanf("%d %d", &num_gear, &dir);
		RotateGear(num_gear, dir);
	}
	printf("%d", v[0][0] + v[1][0] * 2 + v[2][0] * 4 + v[3][0] * 8);
}