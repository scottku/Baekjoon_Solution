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
#include <time.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n;

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		pq.push(temp);
	}

	int answer = 0;
	while (pq.size() > 1) // size == 1 << 이때가 정답
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		answer += (a + b);
		pq.push(a + b);
	}

	printf("%d", answer);
}