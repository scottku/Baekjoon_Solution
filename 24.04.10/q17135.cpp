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

int N, M, D;
int Map[16][16];
bool Archer[16];
#define MAX 987654321
int Last_Enemy = MAX;
int answer = 0;

int distance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void ArcherPos(int pos, int count)
{
    if (count == 3)
    {
        vector<int> v;
        int Map_copy[16][16];

        for (int i = 1; i <= M; i++)
        {
            if (Archer[i])
                v.push_back(i); // 궁수들 위치 확인
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                Map_copy[i][j] = Map[i][j];
            }
        }

        int count = N - Last_Enemy + 1;
        int total = 0;
        while (count--)
        {
            vector<pair<int, pair<int, int>>> v_enemy = { {MAX, {0, 0}}, {MAX, {0, 0}}, {MAX, {0, 0}} };
            for (int i = N; i >= N - D; i--) // 궁수가 쏠 적 확인
            {
                for (int j = 1; j <= M; j++)
                {
                    if (Map_copy[i][j] == 1) // 적 위치
                    {
                        int d1 = distance(N + 1, v[0], i, j);
                        if (d1 < v_enemy[0].first && d1 <= D)
                        {
                            v_enemy[0].first = d1;
                            v_enemy[0].second.first = i;
                            v_enemy[0].second.second = j;
                        }
                        else if (d1 == v_enemy[0].first)
                        {
                            if (j < v_enemy[0].second.second)
                            {
                                v_enemy[0].second.first = i;
                                v_enemy[0].second.second = j;
                            }
                        }

                        int d2 = distance(N + 1, v[1], i, j);
                        if (d2 < v_enemy[1].first && d2 <= D)
                        {
                            v_enemy[1].first = d2;
                            v_enemy[1].second.first = i;
                            v_enemy[1].second.second = j;
                        }
                        else if (d2 == v_enemy[1].first)
                        {
                            if (j < v_enemy[1].second.second)
                            {
                                v_enemy[1].second.first = i;
                                v_enemy[1].second.second = j;
                            }
                        }

                        int d3 = distance(N + 1, v[2], i, j);
                        if (d3 < v_enemy[2].first && d3 <= D)
                        {
                            v_enemy[2].first = d3;
                            v_enemy[2].second.first = i;
                            v_enemy[2].second.second = j;
                        }
                        else if (d3 == v_enemy[2].first)
                        {
                            if (j < v_enemy[2].second.second)
                            {
                                v_enemy[2].second.first = i;
                                v_enemy[2].second.second = j;
                            }
                        }
                    }
                }
            }

            if (Map_copy[v_enemy[0].second.first][v_enemy[0].second.second] != 0 && v_enemy[0].first != MAX)
            {
                Map_copy[v_enemy[0].second.first][v_enemy[0].second.second] = 0;
                total++;
            }
            if (Map_copy[v_enemy[1].second.first][v_enemy[1].second.second] != 0 && v_enemy[1].first != MAX)
            {
                Map_copy[v_enemy[1].second.first][v_enemy[1].second.second] = 0;
                total++;
            }
            if (Map_copy[v_enemy[2].second.first][v_enemy[2].second.second] != 0 && v_enemy[2].first != MAX)
            {
                Map_copy[v_enemy[2].second.first][v_enemy[2].second.second] = 0;
                total++;
            }

            for (int i = N; i >= 1; i--)
            {
                for (int j = 1; j <= M; j++) // 적들 위치 이동
                {
                    if (i == N)
                    {
                        Map_copy[i][j] = 0;
                    }
                    else
                    {
                        Map_copy[i + 1][j] = Map_copy[i][j];
                        Map_copy[i][j] = 0;
                    }
                }
            }
        }
        if (total > answer)
            answer = total;
    }
    else
    {
        for (int i = pos; i <= M; i++)
        {
            Archer[i] = true;
            ArcherPos(i + 1, count + 1);
            Archer[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> D;
    for (int i = 1; i <= M; i++)
        Archer[i] = false;
    int temp;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> temp;
            Map[i][j] = temp;
            if (temp == 1 && Last_Enemy > i)
                Last_Enemy = i;
        }
    }

    ArcherPos(1, 0);

    cout << answer;
}