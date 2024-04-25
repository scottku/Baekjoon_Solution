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
char arr[11][11];


struct Cur_Stat
{
	pair<int, int> r;
	pair<int, int> b;
	int prev_move_dir;
};

bool moveBalls(int dir, Cur_Stat& cs, pair<int, int>& p_r, pair<int, int>& p_b)
{
	pair<int, int> temp_r = cs.r;
	pair<int, int> temp_b = cs.b;
	bool b_r_move = true;
	bool b_b_move = true;
	switch (dir)
	{
	case 0: // 상
		while (true)
		{
			if (!b_r_move && !b_b_move)
				break;

			if (b_r_move)
			{
				if ((int)arr[temp_r.first - 1][temp_r.second] == (int)'#')
				{
					p_r = temp_r;
					b_r_move = false;
				}
				if ((int)arr[temp_r.first - 1][temp_r.second] == (int)'.')
				{
					if (temp_r.first - 1 == temp_b.first && temp_r.second == temp_b.second)
					{
						if (!b_b_move)
						{
							p_r = temp_r;
							b_r_move = false;
						}
					}
					else
						temp_r.first--;
				}
				if ((int)arr[temp_r.first - 1][temp_r.second] == (int)'O')
				{
					temp_r.first = -1;
					temp_r.second = -1;
					p_r.first = -1;
					p_r.second = -1;
					b_r_move = false;
				}
			}
			if (b_b_move)
			{
				if ((int)arr[temp_b.first - 1][temp_b.second] == (int)'#')
				{
					p_b = temp_b;
					b_b_move = false;
				}
				if ((int)arr[temp_b.first - 1][temp_b.second] == (int)'.')
				{
					if (temp_r.first == temp_b.first - 1 && temp_r.second == temp_b.second)
					{
						if (!b_r_move)
						{
							p_b = temp_b;
							b_b_move = false;
						}
					}
					else
						temp_b.first--;
				}
				if ((int)arr[temp_b.first - 1][temp_b.second] == (int)'O')
				{
					temp_b.first = -1;
					temp_b.second = -1;
					p_b.first = -1;
					p_b.second = -1;
					b_b_move = false;
				}
			}
		}
		break;
	case 1: // 하
		while (true)
		{
			if (!b_r_move && !b_b_move)
				break;

			if (b_r_move)
			{
				if ((int)arr[temp_r.first + 1][temp_r.second] == (int)'#')
				{
					p_r = temp_r;
					b_r_move = false;
				}
				if ((int)arr[temp_r.first + 1][temp_r.second] == (int)'.')
				{
					if (temp_r.first + 1 == temp_b.first && temp_r.second == temp_b.second)
					{
						if (!b_b_move)
						{
							p_r = temp_r;
							b_r_move = false;
						}
					}
					else
						temp_r.first++;
				}
				if ((int)arr[temp_r.first + 1][temp_r.second] == (int)'O')
				{
					temp_r.first = -1;
					temp_r.second = -1;
					p_r.first = -1;
					p_r.second = -1;
					b_r_move = false;
				}
			}
			if (b_b_move)
			{
				if ((int)arr[temp_b.first + 1][temp_b.second] == (int)'#')
				{
					p_b = temp_b;
					b_b_move = false;
				}
				if ((int)arr[temp_b.first + 1][temp_b.second] == (int)'.')
				{
					if (temp_r.first == temp_b.first + 1 && temp_r.second == temp_b.second)
					{
						if (!b_r_move)
						{
							p_b = temp_b;
							b_b_move = false;
						}
					}
					else
						temp_b.first++;
				}
				if ((int)arr[temp_b.first + 1][temp_b.second] == (int)'O')
				{
					temp_b.first = -1;
					temp_b.second = -1;
					p_b.first = -1;
					p_b.second = -1;
					b_b_move = false;
				}
			}
		}
		break;
	case 2: // 좌
		while (true)
		{
			if (!b_r_move && !b_b_move)
				break;

			if (b_r_move)
			{
				if ((int)arr[temp_r.first][temp_r.second - 1] == (int)'#')
				{
					p_r = temp_r;
					b_r_move = false;
				}
				if ((int)arr[temp_r.first][temp_r.second - 1] == (int)'.')
				{
					if (temp_r.first == temp_b.first && temp_r.second - 1 == temp_b.second)
					{
						if (!b_b_move)
						{
							p_r = temp_r;
							b_r_move = false;
						}
					}
					else
						temp_r.second--;
				}
				if ((int)arr[temp_r.first][temp_r.second - 1] == (int)'O')
				{
					temp_r.first = -1;
					temp_r.second = -1;
					p_r.first = -1;
					p_r.second = -1;
					b_r_move = false;
				}
			}
			if (b_b_move)
			{
				if ((int)arr[temp_b.first][temp_b.second - 1] == (int)'#')
				{
					p_b = temp_b;
					b_b_move = false;
				}
				if ((int)arr[temp_b.first][temp_b.second - 1] == (int)'.')
				{
					if (temp_r.first == temp_b.first && temp_r.second == temp_b.second - 1)
					{
						if (!b_r_move)
						{
							p_b = temp_b;
							b_b_move = false;
						}
					}
					else
						temp_b.second--;
				}
				if ((int)arr[temp_b.first][temp_b.second - 1] == (int)'O')
				{
					temp_b.first = -1;
					temp_b.second = -1;
					p_b.first = -1;
					p_b.second = -1;
					b_b_move = false;
				}
			}
		}
		break;
	case 3: // 우
		while (true)
		{
			if (!b_r_move && !b_b_move)
				break;

			if (b_r_move)
			{
				if ((int)arr[temp_r.first][temp_r.second + 1] == (int)'#')
				{
					p_r = temp_r;
					b_r_move = false;
				}
				if ((int)arr[temp_r.first][temp_r.second + 1] == (int)'.')
				{
					if (temp_r.first == temp_b.first && temp_r.second + 1 == temp_b.second)
					{
						if (!b_b_move)
						{
							p_r = temp_r;
							b_r_move = false;
						}
					}
					else
						temp_r.second++;
				}
				if ((int)arr[temp_r.first][temp_r.second + 1] == (int)'O')
				{
					temp_r.first = -1;
					temp_r.second = -1;
					p_r.first = -1;
					p_r.second = -1;
					b_r_move = false;
				}
			}
			if (b_b_move)
			{
				if ((int)arr[temp_b.first][temp_b.second + 1] == (int)'#')
				{
					p_b = temp_b;
					b_b_move = false;
				}
				if ((int)arr[temp_b.first][temp_b.second + 1] == (int)'.')
				{
					if (temp_r.first == temp_b.first && temp_r.second == temp_b.second + 1)
					{
						if (!b_r_move)
						{
							p_b = temp_b;
							b_b_move = false;
						}
					}
					else
						temp_b.second++;
				}
				if ((int)arr[temp_b.first][temp_b.second + 1] == (int)'O')
				{
					temp_b.first = -1;
					temp_b.second = -1;
					p_b.first = -1;
					p_b.second = -1;
					b_b_move = false;
				}
			}
		}
		break;
	}

	return true;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	char temp;
	Cur_Stat cs;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> temp;
			arr[i][j] = temp;
			if ((int)temp == (int)'R')
			{
				cs.r = { i, j };
				arr[i][j] = '.';
			}
			if ((int)temp == (int)'B')
			{
				cs.b = { i, j };
				arr[i][j] = '.';
			}


		}
	}
	cs.prev_move_dir = -1;

	queue<Cur_Stat> q;
	q.push(cs);
	int _count = 1;
	while (!q.empty())
	{
		if (_count > 10)
		{
			cout << -1;
			break;
		}
		int q_size = q.size();
		for (int t = 0; t < q_size; t++)
		{
			Cur_Stat temp_cs = q.front();
			q.pop();

			pair<int, int> temp_r;
			pair<int, int> temp_b;

			Cur_Stat new_cs;
			if (temp_cs.prev_move_dir != 0) // 좌우좌우좌우, 상하상하상하 반복되는 것 방지
			{
				moveBalls(0, temp_cs, temp_r, temp_b);
				if (temp_r.first == -1)
				{
					if (temp_b.first == -1)
					{
						// 답을 출력하지 않음
					}
					else
					{
						cout << _count;
						return 0;
					}
				}
				if (temp_b.first == -1)
				{
					// 큐에 추가하지 않음
				}
				else
				{
					new_cs.r = temp_r;
					new_cs.b = temp_b;
					new_cs.prev_move_dir = 0;
					q.push(new_cs);
				}
			}
			if (temp_cs.prev_move_dir != 1) // 좌우좌우좌우, 상하상하상하 반복되는 것 방지
			{
				moveBalls(1, temp_cs, temp_r, temp_b);
				if (temp_r.first == -1)
				{
					if (temp_b.first == -1)
					{
						// 답을 출력하지 않음
					}
					else
					{
						cout << _count;
						return 0;
					}
				}
				if (temp_b.first == -1)
				{
					// 큐에 추가하지 않음
				}
				else
				{
					new_cs.r = temp_r;
					new_cs.b = temp_b;
					new_cs.prev_move_dir = 1;
					q.push(new_cs);
				}
			}
			if (temp_cs.prev_move_dir != 2) // 좌우좌우좌우, 상하상하상하 반복되는 것 방지
			{
				moveBalls(2, temp_cs, temp_r, temp_b);
				if (temp_r.first == -1)
				{
					if (temp_b.first == -1)
					{
						// 답을 출력하지 않음
					}
					else
					{
						cout << _count;
						return 0;
					}
				}
				if (temp_b.first == -1)
				{
					// 큐에 추가하지 않음
				}
				else
				{
					new_cs.r = temp_r;
					new_cs.b = temp_b;
					new_cs.prev_move_dir = 2;
					q.push(new_cs);
				}
			}
			if (temp_cs.prev_move_dir != 3) // 좌우좌우좌우, 상하상하상하 반복되는 것 방지
			{
				moveBalls(3, temp_cs, temp_r, temp_b);
				if (temp_r.first == -1)
				{
					if (temp_b.first == -1)
					{
						// 답을 출력하지 않음
					}
					else
					{
						cout << _count;
						return 0;
					}
				}
				if (temp_b.first == -1)
				{
					// 큐에 추가하지 않음
				}
				else
				{
					new_cs.r = temp_r;
					new_cs.b = temp_b;
					new_cs.prev_move_dir = 3;
					q.push(new_cs);
				}
			}
		}
		_count++;
	}
}