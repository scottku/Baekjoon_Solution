#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string.h>
#include <deque>
#include <vector>

using namespace std;

int main(void)
{
    vector<vector<int>> v;

    int width, height;
    int answer = 1;
    scanf("%d %d", &height, &width);

    for (int i = 0; i < height; i++)
    {
        vector<int> v_temp;
        int temp, calc;

        for (int j = 0; j < width; j++)
        {
            //calc = temp / pow(10, j); // 42101 / 10^4 = 4 (맨 앞자리)
            //v_temp.push_back(calc);
            //temp -= calc * pow(10, j); // 42101 - 40000 = 2101 (다음 계산용) 
            // 위 방식대로 진행시 숫자가 10^50승까지 가버리면 변수를 담을 수 없음
            scanf("%1d", &temp); // 42101 << 이거 따로따로 받아들여지질 않음, 입력받을 때 활용되는 기호 알아둘 것
            v_temp.push_back(temp);
        }
        v.push_back(v_temp);
    } // 사각형 입력받아서 만들기

    // 한 줄에서 같은 수 2개가 있는지부터 확인하기.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = 1; k < width; k++)
            {
                if (j + k >= width) break;
                if (v.at(i).at(j) == v.at(i).at(j + k)) // k+1 만큼의 길이를 한 변으로 하는 정사각형이 만들어질 수도 있다.
                {
                    if (i + k >= height) continue; // 변 길이가 높이보다 커버리면 못만듦
                    if (v.at(i + k).at(j) == v.at(i).at(j))
                    {
                        if (v.at(i).at(j) == v.at(i + k).at(j + k))
                        {
                            answer = (k + 1) * (k + 1) > answer ? (k + 1) * (k + 1) : answer;
                        }
                    }
                }
            }
        }
    }

    printf("%d", answer);
}