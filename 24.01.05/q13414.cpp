#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
	return a.second < b.second;
}

int main(void)
{
	unordered_map<string, int> m;

	int n_limit, n_wait;
	char n_student[10];
	scanf("%d %d", &n_limit, &n_wait);
	for (int i = 0; i < n_wait; i++)
	{
		scanf("%8s", &n_student);
		//if (m.find(n_student) != m.end()) // student와 관련된 값이 이미 있다. -> 삭제하고 다시 넣기
		//	m.erase(n_student);
		//m.insert({ n_student, i });
		m[n_student] = i;
	}

	vector<pair<string, int>> v(m.begin(), m.end()); // map을 vector로 이동
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < min(n_limit, (int)v.size()); i++)
	{
		printf("%s\n", v.at(i).first.c_str());
	}

}