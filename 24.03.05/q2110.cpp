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

// 입력되는 값의 갯수와 범위가 어마어마하다
// = 일반적인 시간 내에는 풀기 어렵다
// = 시간복잡도가 적은 이진탐색일 확률이 매우 높다
// = 어떤 것을 절반씩 줄여나가면서 확인할 것인가
// = 결국 우리가 찾고자 하는 것은 공유기 간 거리
// = 공유기 설치가 가능한 거리를 이진탐색으로 찾아보자

vector<int> v;
int N, C;

int main(void)
{
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), less<int>());

	int _start = 1;
	int _end = v[v.size() - 1];
	int answer = 0;
	while (_start <= _end)
	{
		int mid = (_start + _end) / 2;
		int _count = 1; // 맨 앞에는 무조건 하나 박혀있음
		int _before = v[0]; // 바로 전에 공유기가 설치된 집 위치
		for (int i = 1; i < v.size(); i++)
		{
			if (_before + mid <= v[i])
			{
				_before = v[i];
				_count++;
			}
		}
		if (_count < C) // 갯수가 적다 = 텀이 짧아야 한다.
			_end = mid - 1;
		else
		{
			answer = mid; // _count == C
			_start = mid + 1; // _count > C
		}

	}

	printf("%d", answer);
}