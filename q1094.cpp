#include<stdio.h>
int main(void)
{
    int k;
    scanf("%d", &k);
    int num = 1;
    int answer = 0;
    while (true)
    {
        if (k == 0)
            break;

        if (k >= num && num * 2 > k) // k = 23 가정
        {
            k = k - num; // num = 16 일때까지 2가 곱해짐, k는 7
            num = 1;    // num은 1로 리셋되고 answer 값은 1로 추가됨
            answer++;    // num = 4 일때까지 2가 곱해지고 k는 3
        }                // num은 1로 리셋되고 answer은 2가 됨 (막대 2개가 필요)
        else            // num = 2 일때 k는 1이 되며 answer은 3 -> 한번 더 더해지고 k=0, 다음 번에 break;
            num *= 2;
    }

    printf("%d", answer);
}
//