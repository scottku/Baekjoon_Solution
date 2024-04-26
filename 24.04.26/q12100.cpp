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
int arr[21][21];
int temp_arr[21][21];
int answer = 0;

void Move(int dir)
{
	queue<int> q;

	if (dir == 0) // 상
	{
		for (int i = 1; i <= N; i++) // i번째 열 움직이기
		{
			for (int j = 1; j <= N; j++)
			{
				q.push(temp_arr[j][i]);
				temp_arr[j][i] = 0;
			}

			int before = -1;
			int pos = 1;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				if (cur == 0)
					continue;

				if (before == -1)
				{
					before = cur;
					continue;
				}
				else
				{
					if (before == cur)
					{
						temp_arr[pos][i] = before * 2;
						before = -1;
						pos++;
					}
					else
					{
						temp_arr[pos][i] = before;
						before = cur;
						pos++;
					}
				}
			}
			if (before != -1)
				temp_arr[pos][i] = before; // 마지막에 남은 1개 추가로 입력
		}
	}
	if (dir == 1) // 하
	{
		for (int i = 1; i <= N; i++) // i번째 열 움직이기
		{
			for (int j = N; j >= 1; j--)
			{
				q.push(temp_arr[j][i]);
				temp_arr[j][i] = 0;
			}

			int before = -1;
			int pos = N;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				if (cur == 0)
					continue;

				if (before == -1)
				{
					before = cur;
					continue;
				}
				else
				{
					if (before == cur)
					{
						temp_arr[pos][i] = before * 2;
						before = -1;
						pos--;
					}
					else
					{
						temp_arr[pos][i] = before;
						before = cur;
						pos--;
					}
				}
			}
			if (before != -1)
				temp_arr[pos][i] = before; // 마지막에 남은 1개 추가로 입력
		}
	}
	if (dir == 2) // 좌
	{
		for (int i = 1; i <= N; i++) // i번째 행 움직이기
		{
			for (int j = 1; j <= N; j++)
			{
				q.push(temp_arr[i][j]);
				temp_arr[i][j] = 0;
			}

			int before = -1;
			int pos = 1;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				if (cur == 0)
					continue;

				if (before == -1)
				{
					before = cur;
					continue;
				}
				else
				{
					if (before == cur)
					{
						temp_arr[i][pos] = before * 2;
						before = -1;
						pos++;
					}
					else
					{
						temp_arr[i][pos] = before;
						before = cur;
						pos++;
					}
				}
			}
			if (before != -1)
				temp_arr[i][pos] = before; // 마지막에 남은 1개 추가로 입력
		}
	}
	if (dir == 3) // 우
	{
		for (int i = 1; i <= N; i++) // i번째 행 움직이기
		{
			for (int j = N; j >= 1; j--)
			{
				q.push(temp_arr[i][j]);
				temp_arr[i][j] = 0;
			}

			int before = -1;
			int pos = N;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				if (cur == 0)
					continue;

				if (before == -1)
				{
					before = cur;
					continue;
				}
				else
				{
					if (before == cur)
					{
						temp_arr[i][pos] = before * 2;
						before = -1;
						pos--;
					}
					else
					{
						temp_arr[i][pos] = before;
						before = cur;
						pos--;
					}
				}
			}
			if (before != -1)
				temp_arr[i][pos] = before; // 마지막에 남은 1개 추가로 입력
		}
	}
}

void DFS(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		Move(v[i]);
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			answer = max(answer, temp_arr[i][j]);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int temp;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> temp;
			arr[i][j] = temp;
		}
	}

	vector<vector<int>> v;
	vector<int> v_temp;
	for (int a = 0; a < 4; a++)
	{
		v_temp.push_back(a);
		for (int b = 0; b < 4; b++)
		{
			//if (b == a)
			//	continue;
			v_temp.push_back(b);
			for (int c = 0; c < 4; c++)
			{
				//if (c == b)
				//	continue;
				v_temp.push_back(c);
				for (int d = 0; d < 4; d++)
				{
					//if (d == c)
					//	continue;
					v_temp.push_back(d);
					for (int e = 0; e < 4; e++)
					{
						//if (e == d)
						//	continue;
						v_temp.push_back(e);
						v.push_back(v_temp);
						v_temp.pop_back();
					}
					v_temp.pop_back();
				}
				v_temp.pop_back();
			}
			v_temp.pop_back();
		}
		v_temp.pop_back();
	}

	for (int i = 0; i < v.size(); i++)
	{
		memcpy(temp_arr, arr, sizeof(arr));
		DFS(v[i]);
	}

	cout << answer;
}