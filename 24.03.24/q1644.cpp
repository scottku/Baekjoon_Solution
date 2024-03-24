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
bool arr[4000001];
vector<int> v;

int main()
{
    memset(arr, false, sizeof(arr));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 2; i <= 2000000; i++)
    {
        for (int j = 2; j < 2000000; j++)
        {
            if (i * j > 4000000)
                break;

            arr[i * j] = true;
        }
    }

    for (int i = 2; i <= 4000000; i++)
    {
        if (!arr[i]) // false = 소수
            v.push_back(i);
    }

    int num = 0;
    int _count = 0;

    while (true)
    {
        if (num > v.size())
            break;
        if (v[num] > n)
            break;

        int sum = 0;
        for (int i = num; i < v.size(); i++)
        {

            sum += v[i];
            if (sum > n)
                break;
            else if (sum == n)
                _count++;
        }
        num++;
    }

    cout << _count;
}