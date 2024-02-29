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

#define _UP_ 12
#define _DOWN_ 6
#define _RIGHT_ 3
#define _LEFT_ 9

int n, n_apple, n_turn;
bool arr_apple[101][101];
pair<bool, int> arr_snake[101][101]; // 몸통 존재 여부, 해당 몸통에서 다음 몸통으로의 방향 >> (12 3 6 9) 시 방향
vector<pair<int, char>> v_time;

int main(void)
{
	memset(arr_apple, false, sizeof(arr_apple));
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			arr_snake[i][j] = { false, 0 };
		}
	}

	scanf("%d", &n);
	scanf("%d", &n_apple);
	for (int i = 0; i < n_apple; i++)
	{
		int t_x, t_y;
		scanf("%d %d", &t_x, &t_y);
		arr_apple[t_x][t_y] = true;
	}
	scanf("%d", &n_turn);
	for (int i = 0; i < n_turn; i++)
	{
		int temp; char c;
		scanf("%d", &temp);
		while (true)
		{
			scanf("%c", &c);
			if ((int)c != (int)' ' && (int)c != (int)'\n')
				break;
		}
		v_time.push_back({ temp, c });
	}

	sort(v_time.begin(), v_time.end(), greater<pair<int, int>>()); // 시간 초가 큰 순서대로 배치해서 뒤쪽부터 빼낼 예정

	arr_snake[1][1] = { true, _RIGHT_ }; // 뱀 시작 지점
	pair<int, int> p_sh = { 1, 1 }; // 뱀의 머리
	pair<int, int> p_st = { 1, 1 }; // 뱀의 꼬리
	pair<int, int> p_dir = { 0, 1 }; // 오른쪽 방향
	int n_dir = _RIGHT_;
	int _time = 0;
	while (true)
	{
		if (!v_time.empty())
		{
			if (v_time.back().first == _time) // 해당 시간대에 방향 변경
			{
				switch (v_time.back().second)
				{
				case (int)'D': // 오른쪽으로 회전
					if (p_dir.first == -1 && p_dir.second == 0) // 위
					{
						p_dir.first = 0;
						p_dir.second = 1;
						n_dir = _RIGHT_;
					}
					else if (p_dir.first == 0 && p_dir.second == 1) // 오른쪽
					{
						p_dir.first = 1;
						p_dir.second = 0;
						n_dir = _DOWN_;
					}
					else if (p_dir.first == 1 && p_dir.second == 0) // 아래
					{
						p_dir.first = 0;
						p_dir.second = -1;
						n_dir = _LEFT_;
					}
					else // 왼쪽
					{
						p_dir.first = -1;
						p_dir.second = 0;
						n_dir = _UP_;
					}
					break;
				case (int)'L':
					if (p_dir.first == -1 && p_dir.second == 0) // 위
					{
						p_dir.first = 0;
						p_dir.second = -1;
						n_dir = _LEFT_;
					}
					else if (p_dir.first == 0 && p_dir.second == 1) // 오른쪽
					{
						p_dir.first = -1;
						p_dir.second = 0;
						n_dir = _UP_;
					}
					else if (p_dir.first == 1 && p_dir.second == 0) // 아래
					{
						p_dir.first = 0;
						p_dir.second = 1;
						n_dir = _RIGHT_;
					}
					else // 왼쪽
					{
						p_dir.first = 1;
						p_dir.second = 0;
						n_dir = _DOWN_;
					}
					break;
				}
				v_time.pop_back();
			}
		}

		arr_snake[p_sh.first][p_sh.second].second = n_dir; // 이동할 헤드의 방향 설정
		_time++;

		if (_time == 12)
			int i = 1;

		p_sh = { p_sh.first + p_dir.first, p_sh.second + p_dir.second }; // 현재 시간대에 뱀의 머리 위치

		if (p_sh.first < 1 || p_sh.first > n || p_sh.second < 1 || p_sh.second > n)// 맵 범위 밖으로 머리가 나갔다면 = 사망
			break;
		if (arr_snake[p_sh.first][p_sh.second].first) // 해당 위치가 이미 true다 = 뱀의 몸뚱아리가 차지하고 있는 곳이다 = 몸 줄어드는것보다 머리가 들이미는게 먼저
			break;

		arr_snake[p_sh.first][p_sh.second].first = true;
		//arr_snake[p_sh.first][p_sh.second].second = n_dir; // 머리 위치 변경

		if (!arr_apple[p_sh.first][p_sh.second]) // 해당 위치에 사과가 있지 않으면 뱀 꼬리 축소
		{
			arr_snake[p_st.first][p_st.second].first = false; // 꼬리 위치 데이터 지우기
			int t_dir = arr_snake[p_st.first][p_st.second].second;
			switch (t_dir)
			{
			case _UP_:
				arr_snake[p_st.first][p_st.second].second = 0; // 꼬리 방향 데이터 지우기
				p_st = { p_st.first - 1, p_st.second };
				break;
			case _RIGHT_:
				arr_snake[p_st.first][p_st.second].second = 0; // 꼬리 방향 데이터 지우기
				p_st = { p_st.first, p_st.second + 1 };
				break;
			case _DOWN_:
				arr_snake[p_st.first][p_st.second].second = 0; // 꼬리 방향 데이터 지우기
				p_st = { p_st.first + 1, p_st.second };
				break;
			case _LEFT_:
				arr_snake[p_st.first][p_st.second].second = 0; // 꼬리 방향 데이터 지우기
				p_st = { p_st.first, p_st.second - 1 };
				break;
			}
		}
		else
		{
			arr_apple[p_sh.first][p_sh.second] = false; // 사과만 비워주기
		}
	}

	printf("%d", _time);
}