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

using namespace std;

int L, C;
vector<char> c_m;
vector<char> c_c;

bool compare_dictionary(vector<char>& v1, vector<char>& v2)
{
	int n = v1.size();
	for (int i = 0; i < n; i++)
	{
		if ((int)v1[i] < (int)v2[i])
			return true;
		else if ((int)v1[i] > (int)v2[i])
			return false;
		else // (int)v1[i] == (int)v2[i]
			continue; // 앞글자가 동일하면 뒷글자끼리 비교해야겠죠?
	}

}

int main(void)
{
	scanf("%d %d", &L, &C);
	char c;

	for (int i = 0; i < C; i++)
	{
		scanf("%c", &c);
		if ((int)c == (int)' ' || (int)c == (int)'\n')
		{
			i--;
			continue;
		}
		else
		{
			if ((int)c == (int)'a' || (int)c == (int)'e' || (int)c == (int)'i' ||
				(int)c == (int)'o' || (int)c == (int)'u')
			{
				c_m.push_back(c);
			}
			else
			{
				c_c.push_back(c);
			}
		}
	} // 모음과 자음을 따로 분리해서 보관

	int n_m = 1; // 모음은 처음에 1개로 시작
	vector<vector<char>> v_answer; // 모든 답을 이 벡터에 추가시킬 것
	while (true) // 모음 집합에서 갯수를 1개씩 늘려나갈 것, 총 갯수 - 모음 갯수가 2 아래로 떨어져버리면 조건을 만족하지 못하니 break;
	{
		if (n_m > L - 2 || n_m > c_m.size())
			break;

		if (L - n_m > c_c.size()) // 모음 갯수를 제외한 나머지 수가 자음 수보다 많으면 불가능
		{
			n_m++;
			continue;
		}
		else
		{
			int n_m_size = c_m.size(); // 전체 모음 갯수 -> 그 중에 n_m 개만을 선택할 예정
			vector<int> v_position;
			for (int i = 0; i < n_m_size - n_m; i++) // 전체 모음 갯수가 5개, 그중 2개를 넣어야 한다면 0을 3개 넣어야함 >> 0 1 2 <<
			{
				v_position.push_back(0);
			}
			for (int i = 0; i < n_m; i++)
				v_position.push_back(1); // 나머지는 1로 채워넣기

			queue<vector<char>> q_m_temp;
			do
			{
				vector<char> v_m_temp;
				for (int i = 0; i < v_position.size(); i++)
				{
					if (v_position[i] == 1)
						v_m_temp.push_back(c_m[i]);
				}
				q_m_temp.push(v_m_temp);
			} while (next_permutation(v_position.begin(), v_position.end()));
			// n_m 개의 모음을 사용할 때의 집합들을 q_m_temp에 위치했음. 이제 L - n_m 개의 자음을 뽑아내자

			int n_c_size = c_c.size(); // 전체 자음 갯수 -> 그 중에 L - n_m 개만을 선택할 예정
			v_position.clear();
			for (int i = 0; i < n_c_size - (L - n_m); i++) // 전체 자음 갯수가 7개, 그중 L(5) - n_c(2) 개를 넣어야 한다면 0을 4개 넣어야함 >> 0 1 2 3 <<
			{
				v_position.push_back(0);
			}
			for (int i = 0; i < (L - n_m); i++)
				v_position.push_back(1); // 나머지는 1로 채워넣기

			vector<vector<char>> q_c_temp;
			do
			{
				vector<char> v_c_temp;
				for (int i = 0; i < v_position.size(); i++)
				{
					if (v_position[i] == 1)
						v_c_temp.push_back(c_c[i]);
				}
				q_c_temp.push_back(v_c_temp);
			} while (next_permutation(v_position.begin(), v_position.end()));
			// L - n_m 개의 자음을 사용할 때의 집합들을 q_c_temp에 위치했음. 이제 두 친구를 붙여버리자.

			while (!q_m_temp.empty())
			{
				vector<char> v = q_m_temp.front();
				q_m_temp.pop();
				for (int i = 0; i < q_c_temp.size(); i++)
				{
					vector<char> v_v = v;
					for (int j = 0; j < q_c_temp[i].size(); j++)
					{
						v_v.push_back(q_c_temp[i][j]);
					}
					sort(v_v.begin(), v_v.end(), less<char>()); // 앞쪽 알파벳부터 정렬
					v_answer.push_back(v_v);
				}
			}

			n_m++;
		}
	}

	sort(v_answer.begin(), v_answer.end(), compare_dictionary); // 조건 함수를 만들어 정렬

	for (int i = 0; i < v_answer.size(); i++)
	{
		for (int j = 0; j < L; j++)
		{
			printf("%c", v_answer[i][j]);
		}
		if (i != v_answer.size() - 1)
			printf("\n");
	}
}