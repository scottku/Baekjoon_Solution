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

int n;
int arr[1001];
int dp[1001];
vector<int> v_dp[1001];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        arr[i] = temp;
        dp[i] = 1;
        v_dp[i] = vector<int>();
        v_dp[i].push_back(temp);
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            if (arr[i] > arr[j])
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    v_dp[i] = v_dp[j];
                    v_dp[i].push_back(arr[i]);
                }
            }
        }
    }

    int _max = 0;
    int _max_pos = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > _max)
        {
            _max = dp[i];
            _max_pos = i;
        }
    }
    printf("%d\n", dp[_max_pos]);
    for (int i = 0; i < v_dp[_max_pos].size(); i++)
    {
        printf("%d ", v_dp[_max_pos][i]);
    }
}