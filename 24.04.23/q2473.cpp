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

int N;
vector<long long> v;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	long long temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), less<int>());
	vector<long long> v_ans = { LLONG_MAX, LLONG_MAX, LLONG_MAX };
	vector<long long> v_temp = { 0, 0, 0 };
	long long answer = LLONG_MAX;
	for (int i = 0; i < N; i++)
	{
		int front = i + 1;
		int back = N - 1;
		if (front >= back)
			break;

		long long temp;
		long long temp_before = LLONG_MAX;
		while (true)
		{
			if (front >= back)
				break;
			temp = v[i] + v[front] + v[back];
			if (temp_before == LLONG_MAX)
			{
				v_temp[0] = v[i];
				v_temp[1] = v[front];
				v_temp[2] = v[back];
				if (temp < 0)
				{
					front++;
					temp_before = temp;
				}
				else if (temp == 0)
				{
					cout << v[i] << ' ' << v[front] << ' ' << v[back];
					exit(0);
					return 0;
				}
				else
				{
					back--;
					temp_before = temp;
				}
			}
			else
			{
				if (abs(temp) < abs(temp_before)) // 절댓값이 더 작다 = 0에 가깝다 = 올바른 방향으로 이동 중
				{
					v_temp[0] = v[i];
					v_temp[1] = v[front];
					v_temp[2] = v[back];
					if (temp > 0)
					{
						back--;
						temp_before = temp;
					}
					else if (temp == 0)
					{
						cout << v[i] << ' ' << v[front] << ' ' << v[back];
						exit(0);
						return 0;
					}
					else
					{
						front++;
						temp_before = temp;
					}
				}
				else // 숫자가 모두 다르기 때문에 전 계산값하고 값이 같을 수는 없다
				{
					// 절댓값이 더 커졌다?
					if (temp > 0)
						back--;
					else
						front++;
				}
			}
		}

		if (abs(answer) > abs(temp_before))
		{
			answer = temp_before;
			v_ans[0] = v_temp[0];
			v_ans[1] = v_temp[1];
			v_ans[2] = v_temp[2];
		}
	}

	cout << v_ans[0] << ' ' << v_ans[1] << ' ' << v_ans[2];
}