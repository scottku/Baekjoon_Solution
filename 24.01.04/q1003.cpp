#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string.h>

// 시간초과 << 다른 단순한 해답이 있을 수 있다
// 해당 숫자를 쭉 풀어쓰다보면 0과 1의 호출 횟수가 피보나치 수열과 관계가 있음을 확인 가능했다.
// f(6) = f(5)+f(4) = 2f(4)+f(3) = 3f(3)+2f(2) = 5f(2)+3f(1) = 8f(1)+5f(0)
// 숫자 6을 기준으로 f(1)은 7번째, f(0)은 6번째 피보나치 수열 숫자만큼 호출된다.
// 그냥 피보나치 수열을 구해서 숫자만 빼오면 된다.

int dp[41];
// 호출 횟수를 따로 구할 필요가 없다.
//int n_zero = 0;
//int n_one = 0;

int fibonacci(int num)
{
    if (num == 0)
    {
        //n_zero++;
        return dp[0];
    }
    else if (num == 1)
    {
        //n_one++;
        return dp[1];
    }

    if (dp[num] != -1)
    {
        //    if (dp[num] == 0)
        //        n_zero++;
        //    else if (dp[num] == 1)
        //        n_one++;

        return dp[num];
    }

    dp[num - 1] = fibonacci(num - 1);
    // 어차피 dp[num]을 구하면 그 아래쪽은 다 구해져 있을 것
    //dp[num - 2] = fibonacci(num - 2);
    dp[num] = dp[num - 1] + dp[num - 2];

    return dp[num];
}

int main(void)
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 0; dp[1] = 1;

    int k, x;
    scanf("%d", &k);

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &x);
        if (x == 0)
        {
            printf("%d %d\n", 1, 0);
            continue;
        }
        if (dp[x] == -1)
            fibonacci(x);

        printf("%d %d\n", dp[x - 1], dp[x]);
    }
}