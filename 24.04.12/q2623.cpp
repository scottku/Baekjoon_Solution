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

int N, M;
int arr_bf[1001];
vector<int> arr_af[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        arr_bf[i] = 0;
        arr_af[i] = vector<int>();
        visit[i] = false;
    }

    for (int i = 1; i <= M; i++)
    {
        vector<int> vt;
        int num;
        int temp;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> temp;
            vt.push_back(temp);
        } // 자기보다 먼저 입력되어야 하는 녀석들을 미리 vector로 체크해 둔다.
        for (int j = 0; j < vt.size(); j++)
        {
            for (int k = j + 1; k < vt.size(); k++)
            {
                arr_af[vt[j]].push_back(vt[k]);
                arr_bf[vt[k]]++;
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (arr_bf[i] == 0) // 그 누구보다 먼저 입력될 수 있는 친구들
        {
            q.push(i);
        }
    }

    vector<int> v_answer;
    while (!q.empty())
    {
        int num = q.front();
        q.pop();
        v_answer.push_back(num);

        for (int j = 0; j < arr_af[num].size(); j++)
        {
            arr_bf[arr_af[num][j]]--;
            if (arr_bf[arr_af[num][j]] == 0)
            {
                q.push(arr_af[num][j]);
            }
        }
    }
    if (v_answer.size() != N)
        cout << 0;
    else
    {
        for (int i = 0; i < v_answer.size(); i++)
        {
            cout << v_answer[i] << '\n';
        }
    }
}