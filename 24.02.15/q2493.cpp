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
vector<int> v_input;
vector<int> v_accept;

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		v_input.push_back(temp);
		if (v_input.size() == 1)
			v_accept.push_back(0);
		else
		{
			if (v_input[v_input.size() - 2] >= v_input[v_input.size() - 1]) // 내 앞놈이 나보다 크거나 같다면, 내 정보는 그 친구가 가져갈 것
				v_accept.push_back(v_input.size() - 2 + 1); // 0은 안받는애로 해뒀으니 맨 앞을 1로 변경
			else
			{
				// 나보다 작으면, 그 친구의 데이터를 받는 녀석을 확인해본다.
				int bf = v_accept[v_input.size() - 2];
				if (bf == 0) // 나보다 작은 친구도 데이터를 못받으면 당연히 나도 못받는다.
					v_accept.push_back(0);
				else
				{
					int height = v_input[bf - 1]; // 내 앞 친구의 정보를 받는 송전탑 높이
					while (true)
					{
						if (height >= v_input[v_input.size() - 1])
						{
							v_accept.push_back(bf);
							break;
						}
						else
						{
							bf = v_accept[bf - 1]; // 그 녀석의 앞 녀석을 찾으러 이동한다.
							if (bf == 0)
							{
								v_accept.push_back(0);
								break;
							}
							height = v_input[bf - 1];
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < v_accept.size(); i++)
	{
		printf("%d ", v_accept[i]);
	}
}