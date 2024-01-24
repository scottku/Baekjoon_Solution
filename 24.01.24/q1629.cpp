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
// 2^100 => 2^3)^2)^2 * 2)^2)^2)^2 �� ��� ���� Ȯ ����
long long func(long long a, long long b, long long c) {
    if (b == 0) // a^0 �϶�
        return 1; // 1�� �������ְ�
    long long temp = func(a, b / 2, c); //c^(b/2) �� �����ְ�
    temp = (temp * temp) % c; // (c^(b/2))^2 �÷� ���� 
    if (b % 2 == 0) // b�� ¦���� ���
        return temp; // ���Ȱ� ����
    else // Ȧ���� ���� ������ �ϳ� �����־����. 
        return (temp * a) % c;
}

int main(void)
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    long long temp = func(a, b, c);
    printf("%lld", temp);
}