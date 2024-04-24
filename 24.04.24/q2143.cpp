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

int T;
int n, m;
int dp1[1001];
int dp2[1001];
map<int, long long> m_dp1;
map<int, long long> m_dp2;
map<int, bool> m_visit;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp1[0] = 0;
	dp2[0] = 0;

	cin >> T;
	cin >> n;
	int temp;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		dp1[i] = dp1[i - 1] + temp;
	}

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> temp;
		dp2[i] = dp2[i - 1] + temp; // 구간 합들을 미리 구해둔다
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++) // 구간 합에 따른 숫자가 나올텐데 해당 숫자들이 몇개씩 생기는지 map 에 저장해둔다
		{							// 구간 합의 값이 3 나오는게 2번, 5 나오는게 4번 이런 식으로 저장
			if (m_dp1.find(dp1[j] - dp1[i - 1]) == m_dp1.end()) // 내부에 들어있는 값이 없다
				m_dp1.insert({ dp1[j] - dp1[i - 1], 1 });
			else
				m_dp1[dp1[j] - dp1[i - 1]]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = i; j <= m; j++)
		{
			if (m_dp2.find(dp2[j] - dp2[i - 1]) == m_dp2.end()) // 내부에 들어있는 값이 없다
				m_dp2.insert({ dp2[j] - dp2[i - 1], 1 });
			else
				m_dp2[dp2[j] - dp2[i - 1]]++;
		}
	}

	long long answer = 0;
	for (auto iter = m_dp1.begin(); iter != m_dp1.end(); ++iter) // T - dp1의 구간합 = dp2의 구간합 을 만족할 때, m_dp2[T - dp1] 의 값이 존재한다면 갯수끼리 곱해줌
	{
		if (m_dp2.find(T - iter->first) != m_dp2.end()) // T를 만들 수 있는 숫자가 있다면
		{
			answer += iter->second * m_dp2[T - iter->first];
		}
	}

	cout << answer;
}