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

int n;
int arr[21][21];
int a_fish[7] = { 0, 0, 0, 0, 0, 0, 0 };
pair<int, int> p_shark;
int _time = 0;
int shark_size = 2;
int shark_eat = 0;
int dx[] = { -1, 0, 0, 1 }; // 상 좌 우 하
int dy[] = { 0, -1, 1, 0 };

bool findFood(int shark_size);
bool hunting();

class comp
{
public:
	bool operator() (const pair<pair<int, int>, bool>& p1, const pair<pair<int, int>, bool>& p2)
	{
		if (p1.first.first != p2.first.first) // 더 위쪽인 순서
			return p1.first.first > p2.first.first;
		else if (p1.first.second != p2.first.second) // 더 왼쪽인 순서
			return p1.first.second > p2.first.second;
	}
};

int main(void)
{
	memset(arr, 0, sizeof(arr));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
			switch (temp)
			{
			case 1:
				a_fish[1] += 1;
				break;
			case 2:
				a_fish[2] += 1;
				break;
			case 3:
				a_fish[3] += 1;
				break;
			case 4:
				a_fish[4] += 1;
				break;
			case 5:
				a_fish[5] += 1;
				break;
			case 6:
				a_fish[6] += 1;
				break;
			case 9:
				p_shark.first = i;
				p_shark.second = j;
				arr[i][j] = 0;
				break;
			default:
				break;
			}
		}
	}
	// 4. 해당 작업을 반복한다
	while (true)
	{
		// 1. 전체 맵에 먹을 수 있는 물고기가 있는가? -> 없으면 끝
		bool b_findFood = findFood(shark_size);
		if (b_findFood)
		{
			// 2. 먹을 수 있는 물고기 중, 가장 위, 가장 왼쪽을 우선시 해 최단 거리 물고기를 찾아낸다 -> 먹을 수 있는 물고기에게 도달 불가능하면 끝
			if (hunting()) // true = 사냥에 성공했다.
			{
				continue; // 계속 진행
			}
			else
			{
				printf("%d", _time);
				return 0;
			}
		}
		else
		{
			printf("%d", _time);
			return 0;
		}
	}
}

bool findFood(int shark_size)
{
	int sum = 0;
	for (int i = 1; i < shark_size; i++)
	{
		sum += a_fish[i];
	}
	if (sum != 0)
		return true;
	else
		return false;
}

bool hunting()
{
	bool visit[21][21];
	memset(visit, false, sizeof(visit)); // 크기가 작아서 자주 초기화해도 시간 초과는 안날듯?

	priority_queue<pair<pair<int, int>, bool>, vector<pair<pair<int, int>, bool>>, comp> pq;
	queue<pair<pair<int, int>, bool>> q;
	pq.push({ p_shark, false });
	visit[p_shark.first][p_shark.second] = true;
	int _t = 0;

	while (!pq.empty())
	{
		int pq_size = pq.size();
		for (int i = 0; i < pq_size; i++)
		{
			int xxx = pq.top().first.first;
			int yyy = pq.top().first.second;
			bool eaten = pq.top().second;
			pq.pop();

			if (eaten)
			{
				_time += _t;
				p_shark.first = xxx;
				p_shark.second = yyy;

				switch (arr[xxx][yyy])
				{
				case 1:
					a_fish[1] -= 1;
					break;
				case 2:
					a_fish[2] -= 1;
					break;
				case 3:
					a_fish[3] -= 1;
					break;
				case 4:
					a_fish[4] -= 1;
					break;
				case 5:
					a_fish[5] -= 1;
					break;
				case 6:
					a_fish[6] -= 1;
					break;
				}

				arr[xxx][yyy] = 0;
				// 3. 크기가 커지는지 확인한다
				if (shark_size == shark_eat + 1)
				{
					shark_size++;
					shark_eat = 0;
				}
				else
					shark_eat++;

				return true;
			}

			for (int i = 0; i < 4; i++)
			{
				int x = xxx + dx[i];
				int y = yyy + dy[i];
				if (x >= 1 && x <= n && y >= 1 && y <= n && !visit[x][y]) // 공간 범위 내인가 + 방문한 적 없는 곳
				{
					if (arr[x][y] == 0) // 아무것도 없음
					{
						q.push({ { x,y }, false });
						visit[x][y] = true;
						continue;
					}

					if (arr[x][y] > shark_size) // 이동 못함
					{
						visit[x][y] = true;
						continue;
					}
					else if (arr[x][y] == shark_size) // 이동만 가능
					{
						q.push({ { x,y }, false });
						visit[x][y] = true;
					}
					else // 이동 후 잡아먹을 수 있지만 우선순위인지 파악 필요
					{
						q.push({ {x,y}, true });
						visit[x][y] = true;
					}
				}
			}
		}

		while (!q.empty())
		{
			pq.push(q.front());
			q.pop();
		}

		_t++;
	}

	return false;
}