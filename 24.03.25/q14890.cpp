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

int N, L;
int arr[101][101];

int main()
{
    memset(arr, false, sizeof(arr));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }

    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        vector<pair<int, int>> v_row;
        vector<pair<int, int>> v_col;
        v_row.push_back({ 1, arr[i][1] });
        v_col.push_back({ 1, arr[1][i] });
        for (int j = 2; j <= N; j++)
        {
            if (arr[i][j] == v_row[v_row.size() - 1].second)
                v_row[v_row.size() - 1].first += 1;
            else
                v_row.push_back({ 1, arr[i][j] });

            if (arr[j][i] == v_col[v_col.size() - 1].second)
                v_col[v_col.size() - 1].first += 1;
            else
                v_col.push_back({ 1, arr[j][i] });
        }

        if (v_row.size() == 1)
            answer++;
        else
        {
            for (int j = 0; j < v_row.size() - 1; j++)
            {
                if (abs(v_row[j].second - v_row[j + 1].second) == 1)
                {
                    if (v_row[j].second > v_row[j + 1].second)
                    {
                        if (v_row[j + 1].first < L)
                            break;
                        else
                            v_row[j + 1].first -= L;
                    }
                    else
                    {
                        if (v_row[j].first < L)
                            break;
                        else
                            v_row[j].first -= L;
                    }
                    if (j == v_row.size() - 2)
                        answer++;
                }
                else
                    break;
            }
        }

        if (v_col.size() == 1)
            answer++;
        else
        {
            for (int j = 0; j < v_col.size() - 1; j++)
            {
                if (abs(v_col[j].second - v_col[j + 1].second) == 1)
                {
                    if (v_col[j].second > v_col[j + 1].second)
                    {
                        if (v_col[j + 1].first < L)
                            break;
                        else
                            v_col[j + 1].first -= L;
                    }
                    else
                    {
                        if (v_col[j].first < L)
                            break;
                        else
                            v_col[j].first -= L;
                    }

                    if (j == v_col.size() - 2)
                        answer++;
                }
                else
                    break;
            }
        }
    }

    cout << answer;
}