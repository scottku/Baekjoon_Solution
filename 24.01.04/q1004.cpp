#include<stdio.h>
#include<cmath>
int main(void)
{
    int T;
    scanf("%d", &T);
    // 출발점, 도착점을 포함하고있는 원 갯수가 결국 벗어나고 진입해야 하는 횟수 아닌가?
    int x1, y1, x2, y2, n, cx, cy, r;
    int answer = 0;
    double distance1, distance2, sub_radius;
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d %d %d", &cx, &cy, &r);

            distance1 = sqrt(pow(x1 - cx, 2) + pow(y1 - cy, 2));
            distance2 = sqrt(pow(x2 - cx, 2) + pow(y2 - cy, 2));
            if (distance1 < r)
            {
                if (distance2 < r) // 출발 도착점 모두 한 원안에 있으면 통과하지 않음
                    continue;
                answer++; // 둘중 하나에만 포함되어 있을때 값 1 올림
            }
            else // 만약 출발점을 포함하지 않는다면, 도착점을 포함하고 있어야 통과할 것
            {
                if (distance2 > r)
                    continue; // 둘다 원 밖에 있어도 통과하지 않는다
                answer++;
            }
        }

        printf("%d\n", answer);
        answer = 0;
    }
}
//