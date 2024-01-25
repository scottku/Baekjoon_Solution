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

int n;
vector<int> v;
int dp[1001][1001]; // dp[a][b] => ī�� a���� �ִ� b������ �����ؼ� �� �� ���� �� �ִ�
int _max = 0;

int findMax(int total, int index)  // total = �� ����ϴ� ī�� ����, index = �ѹ��� ���� ������ ī�� ��
{
	if (index == 0 || total == 0) // �� ����� ī�� ���� 0���ų�, �ѹ��� ���� ������ ī�� ���� 0���� 0�� return
		return 0;

	if (dp[total][index] != 0)
		return dp[total][index];

	// total ���� �ѹ��� index ��ŭ�� ������ �� ���� ���� �ִ���
	// total ���� �ѹ��� index - 1 ��ŭ�� ������ �� ���� ���� �ִ�
	// vs
	// index ��ŭ �ѹ� ���� ��, ������ ������ �ִ� index��ŭ�� ������ �� ���� ���� �ִ�
	dp[total][index] = v[index] + findMax(total - index, total - index >= index ? index : total - index);
	dp[total][index] = max(findMax(total, index - 1), dp[total][index]);
	return dp[total][index];
}

int main(void)
{
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);
	v.push_back(0);

	for (int i = 1; i <= n; i++)
	{
		int temp;
		scanf("%d", &temp);
		v.push_back(temp); // i ���� �� ���� ������ ������� vector�� ��ġ ��Ų��.
	}

	int answer = findMax(n, n);
	printf("%d", answer);
}