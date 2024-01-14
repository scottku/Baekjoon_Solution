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
#include <algorithm>
#include <queue>

using namespace std;

vector<long long> v1;
vector<long long> v2;

int main(void)
{
	// 시간초과 -> 보통 이진탐색인건가?
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		long long temp;
		scanf("%lld", &temp);
		v1.push_back(temp);
		v2.push_back(temp);
	}

	sort(v1.begin(), v1.end()); // 정렬
	v1.erase(unique(v1.begin(), v1.end()), v1.end()); // unique 함수 : 중복된 값 1개 제외 후 나머지들은 맨뒤로 보내고 그 뒤로간 인덱스 값을 가져옴
	for (int i = 0; i < n; i++)
	{
		printf("%lld ", lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin());
	}
}
// 아래는 시간 초과
/*
vector<pair<int, int>> v;
priority_queue<int> pq;
int arr[1000001];

int main(void)
{
	int n;
	scanf("%d", &n);
	int temp_n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &temp_n);
		pair<int, int> tp;
		tp.first = temp_n;
		tp.second = i;
		v.push_back(tp);
		pq.push(temp_n);
	}

	for (int i = 0; i < n; i++)
	{
		if (pq.size() == 1) // 사이즈 1개 = 마지막 0 짜리 1개
			break;

		int _top = pq.top(); // 제일 큰거 가져오기
		int _same = 1;
		pq.pop(); // 가져왔으니 빼기
		while (true)
		{
			if (_top == pq.top()) // 같은 수가 중복으로 뒤에 더 있으면
			{
				pq.pop(); // 빼버리기
				_same++;
				continue;
			}
			break;
		}
		int _size = pq.size(); // pq는 현재 내림차순으로 정렬됨 -> 현재 위치 랑 갯수만 알면 자기보다 작은게 몇개인지 바로 확인 가능
		// size가 100개면 0번째에 있는 친구는 자기보다 99개가 작은 친구들이 있음. 물론 같은거면 예외지만
		for (int j = 0; j < n; j++)
		{
			if (v[j].first == _top)
			{
				arr[v[j].second] = _size;
				_same--;
			}
			if (_same == 0)
				break;
		}
	}

	for (int i = 1; i <= n-1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%d", arr[n]);
}
*/