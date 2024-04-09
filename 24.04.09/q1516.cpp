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
struct MyStruct
{
public:
    int build_count; // 선 조건 빌딩들 남은 갯수
    vector<int> build_bf; // 선 조건 빌딩들 번호
    vector<int> build_af; // 후에 지어질 수 있는 빌딩들 번호
};
MyStruct arr[501];
int _time[501];
int dp[501];
bool visit[501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int t;
    int temp;
    for (int i = 1; i <= N; i++)
    {
        cin >> t;
        _time[i] = t;

        while (true)
        {
            cin >> temp;
            if (temp != -1)
            {
                arr[i].build_count++;
                arr[i].build_bf.push_back(temp);
                arr[temp].build_af.push_back(i);
            }
            else
                break;
        }

        dp[i] = 0;
        visit[i] = false;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (arr[i].build_count == 0)
        {
            q.push(i);
        }
    }

    int total = 0;
    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        if (visit[num])
            continue;
        visit[num] = true;

        if (arr[num].build_bf.size() == 0) // 처음부터 지을 수 있는 빌딩
        {
            dp[num] = _time[num]; // 본래 건물 시간만큼 짓는데 걸림
        }
        else
        {
            for (int j = 0; j < arr[num].build_bf.size(); j++)
            {
                dp[num] = max(dp[num], dp[arr[num].build_bf[j]]);
            }
            dp[num] += _time[num]; // 가장 오래걸린 선 조건 빌딩 시간 + 본인 시간
        }

        for (int j = 0; j < arr[num].build_af.size(); j++)
        {
            arr[arr[num].build_af[j]].build_count--;
            if (arr[arr[num].build_af[j]].build_count == 0)
            {
                q.push(arr[num].build_af[j]);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << dp[i] << '\n';
    }

}