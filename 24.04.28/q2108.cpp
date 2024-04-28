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

int N;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int temp;
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
		sum += temp;
	}

	// 1.
	double d_sum = sum / N;
	if (round(d_sum) == -0)
		d_sum = 0;
	else
		d_sum = round(d_sum);
	cout << d_sum << '\n';

	// 2.
	sort(v.begin(), v.end());
	cout << v[N / 2] << '\n';

	// 3.
	temp = v[0];
	bool first = true;
	int m = temp;
	int m_count = 1;
	int m_max = 0;
	for (int i = 1; i < v.size(); i++)
	{
		if (temp == v[i])
			m_count++;
		else // 둘이 다르다
		{
			if (m_max == m_count)
			{
				if (first)
				{
					m = temp;
					first = false;
				}
			}
			else if (m_max < m_count)
			{
				first = true;
				m = temp;
				m_max = m_count;
			}

			m_count = 1;
			temp = v[i];
		}
	}
	// 맨 마지막 반복되지 못한 녀석을 위해 한번 더 진행
	if (m_max == m_count)
	{
		if (first)
			m = temp;
	}
	else if (m_max < m_count)
	{
		m = temp;
	}
	cout << m << '\n';

	// 4.
	cout << abs(v[0] - v[v.size() - 1]);
}