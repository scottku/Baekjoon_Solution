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

int N, K;
long long DP[1001][1001];

// �Ľ�Į�� �ﰢ�� << ���� ����� ���� �ִٰ� ��
// DP[N][K] =DP[N-1][K-1] + DP[N-1][K] 

int main()
{
	scanf("%d %d", &N, &K);

	DP[0][0] = 1;
	DP[1][0] = 1;
	DP[1][1] = 1;

	for (int i = 2; i <= N; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) DP[i][0] = 1;
			else if (j == i) DP[i][j] = 1;
			else DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j]) % 10007;
			// �Ź� 10007�� �������� ������ �ڷ����� ũ�⸦ �ʰ��ϰ� ��.
		}


	printf("%lld", DP[N][K]);

}