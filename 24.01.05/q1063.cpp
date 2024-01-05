#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

int main(void)
{
    //char s[10];
    string s = "";
    string movement = "";
    int pKing[2];
    int pStone[2];
    getline(cin, s); // "A" "1" "" "A" "2" "" "5" "0"
    //  0   1  2   3   4   5  6   7
// 변환 테스트
//int i = int('A'); -> 65
//int j = int('H'); -> 72
    pKing[0] = int(s[0]) - 65; // 0~7
    pKing[1] = int(s[1]) - '0' - 1; // 0~7
    pStone[0] = int(s[3]) - 65;
    pStone[1] = int(s[4]) - '0' - 1;
    int loop = 0;
    if (s.size() > 7)
    {
        if (int(s[7]) != 10 && int(s[7]) != 32)
        {
            loop = (int(s[6]) - '0') * 10 + (int(s[7]) - '0');
        }
        else
            loop = int(s[6]) - '0';
    }
    else
    {
        loop = int(s[6]) - '0';
    }

    for (int i = 0; i < loop; i++)
    {
        getline(cin, movement);
        char c_front = movement[0];
        char c_back = '\n';
        if (movement.size() > 1)
            c_back = movement[1]; // '' = 32, '\n' = 10
        switch (c_front)
        {
            case int('B') :
                if (pKing[1] - 1 >= 0) // 아래로 넘어가버리는거 아니면
                {
                    pKing[1] -= 1; // 일단 아래로 이동
                    if (pKing[0] == pStone[0] && pKing[1] == pStone[1]) // 이동으로 인해 돌과 킹의 위치가 동일해졌다면 돌을 옮김
                    {
                        if (pStone[1] - 1 >= 0) // 돌도 범위 밖으로 나가는게 아니면
                            pStone[1] -= 1; // 아래로 이동하고 이동 종료
                        else // 돌 이동시켰는데 범위 밖이다?
                            pKing[1] += 1; // 킹의 이동 취소
                    }
                    else // 킹을 옮겼을 때 돌과 겹치는게 아니면
                    {
                        // 킹만 옮기면 끝, 돌은 건들 필요 없다.
                    }
                }
                else
                    break; // 만약 킹이 맵 밖으로 이동해서 넘어가버리면 이동 무시

                break;
                case int('T') :
                    if (pKing[1] + 1 <= 7) // 위로 넘어가버리는거 아니면
                    {
                        pKing[1] += 1; // 일단 위로 이동
                        if (pKing[0] == pStone[0] && pKing[1] == pStone[1]) // 이동으로 인해 돌과 킹의 위치가 동일해졌다면 돌을 옮김
                        {
                            if (pStone[1] + 1 <= 7) // 돌도 범위 밖으로 나가는게 아니면
                                pStone[1] += 1; // 위로 이동하고 이동 종료
                            else // 돌 이동시켰는데 범위 밖이다?
                                pKing[1] -= 1; // 킹의 이동 취소
                        }
                        else // 킹을 옮겼을 때 돌과 겹치는게 아니면
                        {
                            // 킹만 옮기면 끝, 돌은 건들 필요 없다.
                        }
                    }
                    else
                        break; // 만약 킹이 맵 밖으로 이동해서 넘어가버리면 이동 무시

                    break;
                    case int('R') :
                        if (int(c_back) == 32 || int(c_back) == 10) // 뒷글자가 공백이거나 줄바꿈일 때
                        {
                            if (pKing[0] + 1 <= 7) // 오른쪽으로 넘어가버리는거 아니면
                            {
                                pKing[0] += 1; // 일단 이동
                                if (pKing[0] == pStone[0] && pKing[1] == pStone[1]) // 이동으로 인해 돌과 킹의 위치가 동일해졌다면 돌을 옮김
                                {
                                    if (pStone[0] + 1 <= 7) // 돌도 범위 밖으로 나가는게 아니면
                                        pStone[0] += 1; // 이동하고 이동 종료
                                    else // 돌 이동시켰는데 범위 밖이다?
                                        pKing[0] -= 1; // 킹의 이동 취소
                                }
                                else // 킹을 옮겼을 때 돌과 겹치는게 아니면
                                {
                                    // 킹만 옮기면 끝, 돌은 건들 필요 없다.
                                }
                            }
                            else
                                break; // 만약 킹이 맵 밖으로 이동해서 넘어가버리면 이동 무시
                        }
                        else // 뒤에 글자가 있을 때
                        {
                            if (int(c_back) == int('T'))
                            {
                                if (pKing[0] + 1 <= 7 && pKing[1] + 1 <= 7)
                                {
                                    pKing[0] += 1; pKing[1] += 1;
                                    if (pKing[0] == pStone[0] && pKing[1] == pStone[1])
                                    {
                                        if (pStone[0] + 1 <= 7 && pStone[1] + 1 <= 7)
                                        {
                                            pStone[0] += 1; pStone[1] += 1;
                                        }
                                        else
                                        {
                                            pKing[0] -= 1; pKing[1] -= 1;
                                        }
                                    }
                                    else
                                    {
                                        // 안겹치면 안옮겨요
                                    }
                                }
                                else
                                    break;
                            }
                            else if (int(c_back) == int('B'))
                            {
                                if (pKing[0] + 1 <= 7 && pKing[1] - 1 >= 0)
                                {
                                    pKing[0] += 1; pKing[1] -= 1;
                                    if (pKing[0] == pStone[0] && pKing[1] == pStone[1])
                                    {
                                        if (pStone[0] + 1 <= 7 && pStone[1] - 1 >= 0)
                                        {
                                            pStone[0] += 1; pStone[1] -= 1;
                                        }
                                        else
                                        {
                                            pKing[0] -= 1; pKing[1] += 1;
                                        }
                                    }
                                    else
                                    {
                                        // 안겹치면 안옮겨요
                                    }
                                }
                                else
                                    break;
                            }
                        }

                    break;
                    case int('L') :
                        if (int(c_back) == 32 || int(c_back) == 10) // 뒷글자가 공백이거나 줄바꿈일 때
                        {
                            if (pKing[0] - 1 >= 0) // 왼쪽으로 넘어가버리는거 아니면
                            {
                                pKing[0] -= 1; // 일단 이동
                                if (pKing[0] == pStone[0] && pKing[1] == pStone[1]) // 이동으로 인해 돌과 킹의 위치가 동일해졌다면 돌을 옮김
                                {
                                    if (pStone[0] - 1 >= 0) // 돌도 범위 밖으로 나가는게 아니면
                                        pStone[0] -= 1; // 이동하고 이동 종료
                                    else // 돌 이동시켰는데 범위 밖이다?
                                        pKing[0] += 1; // 킹의 이동 취소
                                }
                                else // 킹을 옮겼을 때 돌과 겹치는게 아니면
                                {
                                    // 킹만 옮기면 끝, 돌은 건들 필요 없다.
                                }
                            }
                            else
                                break; // 만약 킹이 맵 밖으로 이동해서 넘어가버리면 이동 무시
                        }
                        else // 뒤에 글자가 있을 때
                        {
                            if (int(c_back) == int('T'))
                            {
                                if (pKing[0] - 1 >= 0 && pKing[1] + 1 <= 7)
                                {
                                    pKing[0] -= 1; pKing[1] += 1;
                                    if (pKing[0] == pStone[0] && pKing[1] == pStone[1])
                                    {
                                        if (pStone[0] - 1 >= 0 && pStone[1] + 1 <= 7)
                                        {
                                            pStone[0] -= 1; pStone[1] += 1;
                                        }
                                        else
                                        {
                                            pKing[0] += 1; pKing[1] -= 1;
                                        }
                                    }
                                    else
                                    {
                                        // 안겹치면 안옮겨요
                                    }
                                }
                                else
                                    break;
                            }
                            else if (int(c_back) == int('B'))
                            {
                                if (pKing[0] - 1 >= 0 && pKing[1] - 1 >= 0)
                                {
                                    pKing[0] -= 1; pKing[1] -= 1;
                                    if (pKing[0] == pStone[0] && pKing[1] == pStone[1])
                                    {
                                        if (pStone[0] - 1 >= 0 && pStone[1] - 1 >= 0)
                                        {
                                            pStone[0] -= 1; pStone[1] -= 1;
                                        }
                                        else
                                        {
                                            pKing[0] += 1; pKing[1] += 1;
                                        }
                                    }
                                    else
                                    {
                                        // 안겹치면 안옮겨요
                                    }
                                }
                                else
                                    break;
                            }
                        }

                    break;
        }
    }

    char kx = pKing[0] + 65;
    char ky = pKing[1] + '0' + 1;
    char sx = pStone[0] + 65;
    char sy = pStone[1] + '0' + 1;
    string pos_King = "A1"; string pos_Stone = "A1";
    pos_King[0] = kx; pos_King[1] = ky;
    pos_Stone[0] = sx; pos_Stone[1] = sy;

    printf("%s\n%s", pos_King.c_str(), pos_Stone.c_str());
}