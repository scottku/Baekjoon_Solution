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

#define INF 987654321
int test_case;

class comp
{
public:
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2)
    {
        if (p1.first != p2.first)
            return p1.first < p2.first;
        else
            return p1.second < p2.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> test_case;
    for (int tc = 0; tc < test_case; tc++)
    {
        bool answer_printed = false;
        int N, K;
        cin >> N >> K;

        int _time[1001];
        int dp[1001];
        bool build[1001];
        bool visit[1001];
        vector<int> v[1001];
        int end_building = 0;
        int ready_to_build = 0;

        for (int order = 1; order <= N; order++)
        {
            v[order] = vector<int>();
            dp[order] = 0;
            build[order] = false;
            visit[order] = false;
            cin >> _time[order];
        }
        for (int order = 1; order <= K; order++)
        {
            int from, to;
            cin >> from >> to;
            v[to].push_back(from);
        }
        cin >> end_building;

        // 1. 목표 빌딩을 짓기 위해 필요한 빌딩들을 파악한다.
        queue<int> temp_q;
        queue<int> q;
        temp_q.push(end_building);
        while (!temp_q.empty())
        {
            int num = temp_q.front();
            temp_q.pop();

            if (visit[num])
                continue;
            visit[num] = true;

            for (int j = 0; j < v[num].size(); j++)
            {
                if (!visit[v[num][j]])
                {
                    q.push(v[num][j]);
                    temp_q.push(v[num][j]);
                }
            }
        }

        // 2. 현재 지을 수 있는 빌딩들만 추려서 건설한다
        while (!q.empty())
        {
            int q_size = q.size();

            for (int i = 0; i < q_size; i++)
            {
                int num = q.front();
                q.pop();

                if (v[num].size() == 0)
                {
                    temp_q.push(num);
                }
                else
                {
                    // num 이 지어지기 위해 다른 조건들이 완성됐는지 확인
                    bool b_built = true;
                    for (int j = 0; j < v[num].size(); j++)
                    {
                        if (!build[v[num][j]]) // 조건 완성 안됨
                        {
                            b_built = false;
                            break;
                        }
                    }
                    if (b_built)
                        temp_q.push(num);
                    else
                        q.push(num);
                }
            }

            while (!temp_q.empty())
            {
                int t = temp_q.front();
                temp_q.pop();

                if (build[t])
                    continue;
                build[t] = true;

                int answer = 0;
                for (int i = 0; i < v[t].size(); i++)
                {
                    answer = max(answer, dp[v[t][i]]);
                }

                dp[t] = max(dp[t], answer + _time[t]);
            }
        }

        dp[end_building] = _time[end_building];
        for (int i = 0; i < v[end_building].size(); i++)
        {
            dp[end_building] = max(dp[end_building], dp[v[end_building][i]] + _time[end_building]);
        }

        cout << dp[end_building] << '\n';
    }
}