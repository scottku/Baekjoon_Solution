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

int N, M, K;
int arr[11][11];
int arr_add[11][11];
vector<int> v[11][11];
vector<int> v_die[11][11];

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0 ,1, -1, 1, -1 ,0, 1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(arr, 0, sizeof(arr));
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int temp;
            cin >> temp;
            arr[i][j] = 5;
            arr_add[i][j] = temp;

            v[i][j] = vector<int>();
            v_die[i][j] = vector<int>();
        }
    }
    for (int i = 0; i < M; i++)
    {
        int x, y, age;
        cin >> x >> y >> age;
        v[x][y].push_back(age);
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (v[i][j].size() != 0)
                sort(v[i][j].begin(), v[i][j].end(), less<int>());
        }
    }

    while (K--)
    {
        // 봄
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (v[i][j].size() != 0)
                {
                    int n_die = -1;
                    for (int k = 0; k < v[i][j].size(); k++)
                    {
                        // 적은 나이부터 양분을 먹는다
                        if (v[i][j][k] <= arr[i][j])
                        {
                            arr[i][j] -= v[i][j][k];
                            v[i][j][k]++;
                        }
                        else
                        {
                            n_die = k;
                            break;
                        }
                    }
                    if (n_die != -1) // 양분이 부족해 죽는 친구가 있었다
                    {
                        while (v[i][j].size() != n_die) // 죽은 친구들은 제외
                        {
                            v_die[i][j].push_back(v[i][j].back());
                            v[i][j].pop_back();
                        }
                    }
                }
            }
        }

        // 여름
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (v_die[i][j].size() != 0)
                {
                    while (v_die[i][j].size() != 0)
                    {
                        arr[i][j] += v_die[i][j].back() / 2;
                        v_die[i][j].pop_back();
                    }
                }
            }
        }

        // 가을
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (v[i][j].size() != 0)
                {
                    for (int k = 0; k < v[i][j].size(); k++)
                    {
                        if (v[i][j][k] % 5 == 0) // 5의 배수
                        {
                            for (int a = 0; a < 8; a++)
                            {
                                int nx = i + dx[a];
                                int ny = j + dy[a];
                                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
                                {
                                    v[nx][ny].push_back(1); // 나이 1짜리 나무 번식
                                }
                            }
                        }
                    }
                }
            }
        }

        // 겨울
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                arr[i][j] += arr_add[i][j];
                if (v[i][j].size() != 0)
                    sort(v[i][j].begin(), v[i][j].end(), less<int>());
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            answer += v[i][j].size();
        }
    }

    cout << answer;
}