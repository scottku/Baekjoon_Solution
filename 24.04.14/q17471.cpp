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

int N;
int Population[11];
bool Linked[11][11];
vector<int> v1;
vector<int> v2;
bool b_v1[11];
int answer = 987654321;

bool CanMakeLink(vector<int>& v)
{
    queue<int> q;
    bool linked[11];
    for (int i = 1; i <= 10; i++)
        linked[i] = false;

    if (b_v1[v[0]]) // v = v1
    {
        q.push(v[0]);
        while (!q.empty())
        {
            int num = q.front();
            q.pop();

            linked[num] = true;

            for (int i = 1; i <= N; i++)
            {
                if (i == num)
                    continue;

                if (Linked[num][i] && b_v1[i] && !linked[i]) // num과 연결되어 있으며 같은 조합(v1)에 포함되어 있다면
                {
                    q.push(i);
                }
            }
        }
    }
    else // v = v2
    {
        q.push(v[0]);
        while (!q.empty())
        {
            int num = q.front();
            q.pop();

            linked[num] = true;

            for (int i = 1; i <= N; i++)
            {
                if (i == num)
                    continue;

                if (Linked[num][i] && !b_v1[i] && !linked[i]) // num과 연결되어 있으며 같은 조합(v2)에 포함되어 있다면
                {
                    q.push(i);
                }
            }
        }
    }

    bool b = true;
    for (int i = 0; i < v.size(); i++)
    {
        if (!linked[v[i]])
        {
            b = false;
            break;
        }
    }

    if (b)
        return true;
    else
        return false;
}

void DFS(int n, int count, int max_count)
{
    if (count == max_count)
    {
        for (int i = 1; i <= N; i++)
        {
            if (!b_v1[i])
                v2.push_back(i);
        }
        // 2. 조합끼리 서로 연결되는지 확인
        if (CanMakeLink(v1) && CanMakeLink(v2))
        {
            // 3. 인구수 합의 차이가 최솟값인지 확인
            int a = 0;
            for (int i = 0; i < v1.size(); i++)
            {
                a += Population[v1[i]];
            }
            int b = 0;
            for (int i = 0; i < v2.size(); i++)
            {
                b += Population[v2[i]];
            }
            if (answer > abs(a - b))
                answer = abs(a - b);
        }
        while (!v2.empty())
            v2.pop_back();
    }
    else
    {
        for (int i = n; i <= N; i++)
        {
            if (b_v1[i])
                continue;

            v1.push_back(i);
            b_v1[i] = true;
            DFS(i + 1, count + 1, max_count);
            v1.pop_back();
            b_v1[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int p;
    for (int i = 1; i <= N; i++)
    {
        cin >> p;
        Population[i] = p;
        b_v1[i] = false;
    }
    for (int i = 1; i <= N; i++)
    {
        int n;
        cin >> n;
        int temp;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            Linked[i][temp] = true;
            Linked[temp][i] = true;
        }
    }
    // 조합 제작
    for (int i = 1; i < N / 2 + 1; i++) // 5개중에 2개 고르나 3개 고르나 양쪽 조합은 같음
    {
        v1.clear();
        v2.clear();
        DFS(1, 0, i);
    }

    if (answer == 987654321)
        cout << -1;
    else
        cout << answer;
}