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

vector<char> v;

int main(void)
{
	while (true)
	{
		char c;
		scanf("%c", &c);
		if ((int)c == (int)'\n')
			break;
		v.push_back(c);
	}

	int n_line = 0;
	int answer = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if ((int)v[i] == (int)'(' && (int)v[i + 1] == (int)')') // 레이저
		{
			if (n_line == 0) // 막대 생기기 전에 있는 레이저들
			{
				i++; // 레이저 그냥 넘어가기
			}
			else
			{
				answer += n_line; // 막대 있는 갯수만큼 잘려 나올 것
				i++; // 레이저에 포함되는 ')' 부분 건너뛰기
			}
			continue;
		}
		if ((int)v[i] == (int)'(') // 레이저는 아니고 그냥 막대의 시작이면
		{
			n_line++; // 막대의 갯수 추가
			continue;
		}
		if ((int)v[i] == (int)')') // 레이저는 아니고 그냥 막대의 마지막이면
		{
			n_line--; // 막대의 갯수 감소
			answer++; // 막대의 끝이 나오면서 기존에 잘렸던 부분을 추가해줌 ( 또 레이저에 잘릴까봐 잘린 막대에 추가 안했던 부분 )
			continue;
		}
	}

	printf("%d", answer);
}
