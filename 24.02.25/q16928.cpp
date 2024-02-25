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

int arr[101];
int l, s;

int main()
{
    bool visit[101];
    memset(arr, 0, sizeof(arr));
    memset(visit, false, sizeof(visit));

    scanf("%d %d", &l, &s);
    for (int i = 0; i < l + s; i++)
    {
        int _start, _end;
        scanf("%d %d", &_start, &_end);
        arr[_start] = _end;
    }

    //priority_queue<pair<int, int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
    queue<pair<int, int>> pq;
    //q.push(make_pair(x, c));
    pq.push({ 0, 1 });
    while (!pq.empty())
    {
        int loc = pq.front().second; // 현재 좌표
        int cnt = pq.front().first; // 카운트
        pq.pop();

        for (int i = 1; i <= 6; i++)
        {
            int nx = loc + i; // 다음 좌표
            if (nx == 100)
            {
                cout << cnt + 1; // 도착했으면 출력
                return 0;
            }
            else if (nx < 100)
            { // 100보다 작은 좌표라면 
                while (arr[nx] != 0)
                { // 사다리 혹은 뱀인지 확인
                    nx = arr[nx]; // 점프한 자리로 이동
                }
                if (!visit[nx])
                { // 처음 방문한 좌표일때
                    pq.push({ cnt + 1,nx }); // 큐에 넣어줌
                    visit[nx] = true; // 방문처리
                }
            }
        }
    }
}