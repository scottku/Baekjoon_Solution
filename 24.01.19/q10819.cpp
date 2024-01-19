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

using namespace std;

vector<int> v;
deque<int> dq;
deque<int> dq_answer_big;
deque<int> dq_answer_small;

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);

		v.push_back(temp);
	}

	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++)
	{
		dq.push_back(v[i]); // dq 랑 v의 모양은 동일
	}

	// 가장 큰 값을 기준으로 양 옆으로 가장 작은 값 2개를 넣는다 -> 1 20 4
	// 양 옆으로 큰 값들을 채워준다 (차이 크도록) -> 15 1 20 4 10
	// 계속해서 2개씩 골라서 양 옆으로 넣는다 -> 8 15 1 20 4 10 -> 7 + 14 + 19 + 16 + 6 = 21 + 35 + 6 = 56 + 6 = 62
	// 맨 처음을 큰거부터 채워넣을지, 작은거부터 채워넣을지...

	deque<int> dq_big = dq;
	dq_answer_big.push_back(dq_big.front());
	dq_big.pop_front();
	deque<int> dq_small = dq;
	dq_answer_small.push_back(dq_small.back());
	dq_small.pop_back();

	bool b_back = true;
	while (!dq_big.empty()) // 어차피 같은 deque를 사용하니 비워지는 타이밍은 동일할 것
	{
		if (b_back)
		{
			dq_answer_big.push_front(dq_big.back());
			dq_big.pop_back();
			dq_answer_small.push_front(dq_small.front());
			dq_small.pop_front();
			if (dq_big.empty())
				break;
			dq_answer_big.push_back(dq_big.back());
			dq_big.pop_back();
			dq_answer_small.push_back(dq_small.front());
			dq_small.pop_front();
			b_back = false;
		}
		else
		{
			dq_answer_big.push_front(dq_big.front());
			dq_big.pop_front();
			dq_answer_small.push_front(dq_small.back());
			dq_small.pop_back();
			if (dq_big.empty())
				break;
			dq_answer_big.push_back(dq_big.front());
			dq_big.pop_front();
			dq_answer_small.push_back(dq_small.back());
			dq_small.pop_back();
			b_back = true;
		}
	}

	int answer_big = 0;
	int answer_small = 0;
	for (int i = 0; i < dq_answer_small.size() - 1; i++) //small 이나 big 이나 사이즈는 동일
	{
		answer_small += abs(dq_answer_small[i] - dq_answer_small[i + 1]);
		answer_big += abs(dq_answer_big[i] - dq_answer_big[i + 1]);
	}
	printf("%d", max(answer_big, answer_small));
}