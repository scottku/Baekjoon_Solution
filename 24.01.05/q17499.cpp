#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string.h>
#include <deque>

using namespace std;

// for문이 있으면 시간초과가 난다고 문제에 언급된다. 그때그때마다 shift하지 말고 shift를 가정해서 계산 위치를 조정한다.

int main(void)
{
    //memset(dp, -1, sizeof(dp));
    //dp[0] = 0; dp[1] = 1;

    int n_size, n_calc;
    scanf("%d %d", &n_size, &n_calc);

    int index = 0; // 시프트는 진행하지 않고 얼마나 움직였는지를 따져서 계산 후 나중에 출력하기

    deque<int> d;
    int num = n_size + 1;
    while (--num)
    {
        int temp;
        scanf("%d", &temp);

        d.push_back(temp);
    }

    int a, b, c;
    for (int i = 0; i < n_calc; i++)
    {
        scanf("%d", &a);
        int temp;
        switch (a)
        {
        case 1:
            scanf("%d %d", &b, &c);

            temp = b - 1 + index;
            if (temp > n_size - 1)
                temp -= n_size;
            d[temp] += c;
            break;
        case 2:
            scanf("%d", &b); // 뒤쪽을 앞으로 가져오기
            index += n_size - b; // 1 2 3 4 5가 있을때 b = 2 라면 index = 3, 즉 앞에서 뒤로 n_size - b 갯수만큼 옮긴거랑 모양이 같음. -> 4 5 1 2 3
            index %= n_size; // 1 2 3 4 5 기준 index가 12라면, 5 일때 1 2 3 4 5, 10 일때 1 2 3 4 5 이므로 n_size로 나눴을 때의 나머지와 구조가 동일
            //for (int j = 0; j < b; j++)
            //{
            //    d.push_front(d.back());
            //    d.pop_back();
            //}
            break;
        case 3:
            scanf("%d", &b);
            index += b;
            index %= n_size;
            //for (int j = 0; j < b; j++)
            //{
            //    d.push_back(d.front());
            //    d.pop_front();
            //}
            break;
        }
    }

    for (int k = 0; k < n_size; k++)
    {
        int temp = k + index;
        if (temp > n_size - 1)
            temp -= n_size;
        printf("%d ", d[temp]);
    }
}