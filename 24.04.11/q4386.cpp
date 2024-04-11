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
double x, y;
pair<double, double> arr[101];
int parent[101];
double answer = 0;

class comp
{
public:
    bool operator() (const pair<double, pair<int, int>>& p1, const pair<double, pair<int, int>>& p2)
    {
        return p1.first > p2.first;
    }
};

int findParent(int child)
{
    if (parent[child] == child)
        return child;
    else
        return parent[child] = findParent(parent[child]);
}

void makeUnion(int a, int b)
{
    int x = findParent(a);
    int y = findParent(b);
    parent[y] = x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        arr[i] = { x, y };
        parent[i] = i;
    }
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, comp> pq;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double dist = (arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second);
            pq.push({ sqrt(dist),{i,j} });
        }
    }

    int c = 0;
    while (!pq.empty())
    {
        double d = pq.top().first;
        int node1 = pq.top().second.first;
        int node2 = pq.top().second.second;
        pq.pop();

        if (findParent(node1) != findParent(node2)) // 다른 부모 = 사이클 안생김 = 이어도 됨
        {
            makeUnion(node1, node2);
            answer += d;

            c++;
        } // 같은 부모 = 이미 다른방식으로 이어져있으므로 굳이 이을 필요 없다
        if (c == n - 1)
            break;
    }

    cout << answer;
}