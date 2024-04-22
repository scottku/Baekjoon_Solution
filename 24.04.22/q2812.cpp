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

int N, K;
int arr[500001];

int main(void)
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	cin >> N >> K;
	int temp;
	for (int i = 1; i <= N; i++)
	{
		scanf("%1d", &temp); // 연속된 글자를 하나씩 입력받는데 cin은 좀 사용하기 힘드니 scanf 활용
		arr[i] = temp;
	}

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); // scanf 더이상 안쓸거니 싱크 연결 해제

	stack<int> s1;
	int c = 0;
	for (int i = 1; i <= N; i++)
	{
		if (c == K) // 빼내는 횟수를 모두 소모했다.
		{
			s1.push(arr[i]);
		}
		else
		{
			while (true)
			{
				if (s1.empty())
				{
					s1.push(arr[i]);
					break;
				}
				else
				{
					if (s1.top() < arr[i]) // 지금 들어가는 숫자보다 앞의 숫자가 작다면
					{
						if (c < K)
						{
							s1.pop(); // 횟수를 소모해 한번 빼낸다.
							c++;
						}
						else
						{
							s1.push(arr[i]);
							break;
						}
					}
					else // 같거나 크면 그냥 집어넣는다
					{
						s1.push(arr[i]);
						break;
					}
				}
			}
		}
	}

	if (c < K) // 작아지는 순서대로 들어오면 count가 1도 증가하지 않으므로 뒤쪽에서부터 순서대로 제거하는 작업 추가
	{
		while (c < K)
		{
			s1.pop();
			c++;
		}
	}

	stack<int> s2;
	while (s1.size() > K - c) // 뒤집어서 출력
	{
		s2.push(s1.top());
		s1.pop();
	}

	while (!s2.empty())
	{
		cout << s2.top();
		s2.pop();
	}
}