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
// 2^100 => 2^3)^2)^2 * 2)^2)^2)^2 로 계산 수를 확 줄임
long long func(long long a, long long b, long long c) {
    if (b == 0) // a^0 일때
        return 1; // 1을 리턴해주고
    long long temp = func(a, b / 2, c); //c^(b/2) 을 구해주고
    temp = (temp * temp) % c; // (c^(b/2))^2 꼴로 해줌 
    if (b % 2 == 0) // b가 짝수일 경우
        return temp; // 계산된거 리턴
    else // 홀수인 경우는 남은거 하나 곱해주어야함. 
        return (temp * a) % c;
}

int main(void)
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    long long temp = func(a, b, c);
    printf("%lld", temp);
}