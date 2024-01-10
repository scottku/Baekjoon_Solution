#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int _arr[1000001];
int dp[1000001];
vector<int> v;

void myBinarySearch(int x)
{
	int start = 0; int end = v.size() - 1; int mid;
	int result = 0;
	while (end > start)
	{
		mid = (start + end) / 2;    // start�� 0, end�� 9, �ٲ����� ��ġ�� 7 �̶� ����
		if (v[mid] >= x)            // mid = 4 �� x ���� �����Ƿ� 4��° ���ĺ��� üũ -> start = 5
			end = mid;              // start�� 5, end�� 9�� mid = 7, 7��° ��ġ�� x���� ũ�ų� ����
		else                        // start�� 5, end�� 7�̸� mid = 6, 6��° ��ġ�� x���� ����
			start = mid + 1;        // ���� ģ���� �����ϱ� ���� start = 7, end = 7�� ��� �ٲ� ��ġ�� 7
		result = end;
	}

	v[result] = x;
}

int main(void)
{
	memset(_arr, 0, sizeof(_arr));
	memset(dp, 0, sizeof(dp));

	int n;
	scanf("%d", &n);

	int x;
	for (int i = 1; i <= n; i++) // 100������ 2�� for������ �ð��ʰ�
	{
		scanf("%d", &x);
		_arr[i] = x;
	}

	v.push_back(_arr[1]);
	for (int i = 2; i <= n; i++)
	{
		if (v.back() < _arr[i]) // ���� ������ ���������� ���� ��ġ ���ڰ� �� ũ��
			v.push_back(_arr[i]); // ���� �������� �ش� ���ڸ� �߰�
		else
			myBinarySearch(_arr[i]); // ���� ��ġ ���ڰ� �� ������, �ش� ���ں��� ���� ���� ������ �ٷ� ���� ��ġ�� �ش� ���� ����
	}
	// ���Ƿ� ������ ���� v�� ���� ���� �� ��ü�� ��Ÿ���� ���� �ƴ�, v�� size ��ü�� ���� ���̸� Ȯ�� ����
	printf("%d", v.size());
}