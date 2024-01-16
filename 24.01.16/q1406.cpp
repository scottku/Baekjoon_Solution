#define _CRT_SECURE_NO_WARNINGS
// Linked List 활용 -> 조건 분기가 꽤나 까다로움
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

class _linked_List
{
public:
	_linked_List* front;
	_linked_List* back;
	char data;

	_linked_List(char c)
	{
		front = nullptr;
		back = nullptr;
		data = c;
	}
};

int main(void)
{
	deque<char> dq;
	_linked_List* ptr = nullptr;
	_linked_List* ptr_first = nullptr;
	bool isFront = false;

	while (true)
	{
		char c;
		scanf("%c", &c);
		if ((int)c == (int)'\n' || (int)c == (int)' ')
			break;
		dq.push_back(c);
	}
	while (!dq.empty())
	{
		_linked_List* t = new _linked_List(dq.front());
		dq.pop_front();
		if (ptr == nullptr) // 첫번째 생성된 LL
		{
			ptr = t;
			ptr_first = t;
		}
		else
		{
			ptr->back = t;
			t->front = ptr;
			ptr = t;
		}
	}
	// ptr 은 맨 마지막 단어의 포인터로 세팅된다.
	// 기본적으로 ptr 이 가리키고 있는 객체의 뒤쪽에 커서가 있다고 가정한다.
	// 그렇다면 커서가 맨 앞으로 왔을때에 대한 추가적인 데이터가 필요 => bool isFront;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char temp_c;
		scanf("%c", &temp_c);
		if ((int)temp_c == (int)'\n' || (int)temp_c == (int)' ') // 엔터값이 char로 잡히는 부분은 다시 데이터를 받는다.
		{
			i--;
			continue;
		}

		if ((int)temp_c == (int)'L') // 앞으로 한칸 커서 이동
		{
			if (ptr == nullptr) // 텅 비어있다면
			{
				isFront = false; // 혹시 데이터가 추가된다면 어차피 isFront는 false가 되어야 함
				continue; // 딱히 할거는 없다.
			}
			else // 글자가 있긴 있다면
			{
				if (ptr->front == nullptr && ptr->back == nullptr) // 글자가 한개 뿐이다
				{
					if (isFront) // 커서가 그마저도 맨 앞이다
						continue; // 할거 없음
					else // 그나마 문자 뒤에 커서가 있었다
					{
						isFront = true; // 커서마저 맨 앞으로 땡겨온다
						continue;
					}
				}
				else if (ptr->front == nullptr) // 글자가 여러개긴 한데 맨 앞글자다
				{
					if (isFront) // 커서가 그마저도 맨 앞이다
						continue; // 할거 없음
					else // 그나마 문자 뒤에 커서가 있었다
					{
						isFront = true; // 커서마저 맨 앞으로 땡겨온다
						continue;
					}
				}
				else if (ptr->back == nullptr)
				{
					isFront = false; // 혹시 모르니까 다시 한번 확인
					ptr = ptr->front; // 앞쪽으로 포인터 이동
					continue;
				}
				else // 글자가 여러개인데다가 맨 앞글자 쪽에 커서가 있지 않음
				{
					isFront = false; // 혹시 모르니까 다시 한번 확인
					ptr = ptr->front; // 앞쪽으로 포인터 이동
					continue;
				}
			}
		}
		else if ((int)temp_c == (int)'D') // 뒤로 한칸 커서 이동
		{
			if (ptr == nullptr) // 글자가 아예 없다
			{
				isFront = false; // 어차피 글자 추가되면 false로 되게 되어있음
				continue; // 딱히 할 건 없다
			}
			else // 일단 글자가 있긴 있다
			{
				if (ptr->front == nullptr && ptr->back == nullptr) // 글자가 딱 한개다
				{
					if (isFront) // 커서가 맨 앞에있다
					{
						isFront = false; // 커서 위치만 바꾸고 넘어간다
						continue;
					}
					else // 커서가 맨 뒤면 할 것 없다.
					{
						continue;
					}
				}
				else if (ptr->back == nullptr) // 글자가 여러개긴 한데 맨 뒤쪽이다
				{
					isFront = false; // 혹시 몰라서 다시 체크
					continue; // 이미 맨 뒤니까 할 것은 없다
				}
				else if (ptr->front == nullptr)
				{
					if (isFront)
						isFront = false;
					else
						ptr = ptr->back;
					continue;
				}
				else // 글자가 여러개고 뒤에 글자가 있다.
				{
					isFront = false;
					ptr = ptr->back; // 뒤쪽으로 이동
					continue;
				}
			}
		}
		else if ((int)temp_c == (int)'B') // 왼쪽 문자 삭제
		{
			if (ptr == nullptr) // 글자가 아예 없다
			{
				isFront = false; // 어차피 글자 추가되면 false로 되게 되어있음
				continue; // 딱히 할 건 없다
			}
			else // 일단 글자가 있긴 있다
			{
				if (ptr->front == nullptr && ptr->back == nullptr) // 글자가 딱 한개다
				{
					if (isFront) // 커서가 맨 앞이면 지울 건 없다.
					{
						continue;
					}
					else // 커서가 맨 뒤면
					{
						delete ptr;
						ptr = nullptr; // 마지막 남은 글자 없애주기
						ptr_first = nullptr; // 맨 앞 글자 포인터도 없다.
						continue;
					}
				}
				else if (ptr->back == nullptr) // 글자가 여러개긴 한데 맨 뒤쪽이다
				{
					_linked_List* tp = ptr->front;
					ptr->front->back = nullptr; // 앞 놈이 가장 뒷놈이 될 예정이므로 앞놈의 뒤쪽 포인터를 없앤다.
					delete ptr; // 맨 뒷놈인 ptr을 지우고 그 앞놈으로 옮겨감
					ptr = tp;
					continue;
				}
				else if (ptr->front == nullptr) // 글자가 여러개긴 한데 맨 앞쪽이다
				{
					if (isFront) // 완전 맨앞이면 지울건 없다.
						continue;
					else
					{
						ptr_first = ptr->back; // 맨 앞친구를 바꿔준다.
						ptr->back->front = nullptr; // 맨 앞친구가 될 뒷놈의 앞 포인터를 없앤다
						delete ptr; // 맨 앞놈을 없앤다.
						ptr = ptr_first; // 맨 앞놈이랑 같은 포인터를 공유한다.
						isFront = true; // 맨 앞을 지워버리는 바람에 포인터가 가장 앞으로 이동했다.
						continue;
					}
				}
				else // 글자가 여러개고 앞 뒤에 글자가 있다.
				{
					isFront = false; // 글자 중간이니 front일리 없다.
					_linked_List* tp = ptr->front; // ptr이 지워지면 커서는 그 앞놈의 뒤쪽에 위치하게 된다.
					ptr->front->back = ptr->back; // 앞놈의 뒤를 내 뒷놈과 연결
					ptr->back->front = ptr->front; // 뒷놈의 앞을 내 앞놈과 연결
					delete ptr; // 혼자 떨어져 나온 ptr 제거
					ptr = tp; // 커서의 앞놈으로 포인터 재 적용
					continue;
				}
			}
		}
		else if ((int)temp_c == (int)'P') // 문자 추가
		{
			char c_add;
			while (true)
			{
				scanf(" %c", &c_add); // 추가 입력
				if ((int)c_add != (int)'\n' && (int)c_add != (int)' ')
					break;
			}

			_linked_List* new_ll = new _linked_List(c_add);

			if (ptr == nullptr) // 글자가 아예 없다
			{
				ptr = new_ll;
				ptr_first = new_ll;
				isFront = false; // 커서 왼쪽에 글자가 추가되므로 커서는 글자 뒤에 위치한다.
				continue;
			}
			else // 일단 글자가 있긴 있다
			{
				if (ptr->front == nullptr && ptr->back == nullptr) // 글자가 딱 한개다
				{
					if (isFront) // 커서가 맨 앞이면
					{
						new_ll->back = ptr;
						ptr->front = new_ll; // ptr 앞을 new_ll로 세팅한다
						ptr_first = new_ll; // 첫번째 ptr도 변경해준다.
						isFront = false; // 커서 왼쪽에 글자가 추가되어 커서가 맨 앞은 아님
						ptr = ptr_first;
						continue;
					}
					else // 커서가 맨 뒤면
					{
						new_ll->front = ptr; // ptr의 뒤를 new_ll로 세팅한다.
						ptr->back = new_ll; // 이미 ptr이 첫번째일 것이니 굳이 세팅하지는 않는다.
						ptr = new_ll; // 커서가 맨 뒤쪽이니 뒤쪽 포인터로 변경
						continue;
					}
				}
				else if (ptr->back == nullptr) // 글자가 여러개긴 한데 맨 뒤쪽이다
				{
					new_ll->front = ptr; // ptr의 뒤를 new_ll로 세팅한다.
					ptr->back = new_ll; // 이미 ptr이 첫번째일 것이니 굳이 세팅하지는 않는다.
					ptr = new_ll; // 커서가 맨 뒤쪽이니 뒤쪽 포인터로 변경
					continue;
				}
				else if (ptr->front == nullptr) // 글자가 여러개긴 한데 맨 앞쪽이다
				{
					if (isFront) // 커서가 맨 앞이면
					{
						new_ll->back = ptr;
						ptr->front = new_ll; // ptr 앞을 new_ll로 세팅한다
						ptr_first = new_ll; // 첫번째 ptr도 변경해준다.
						isFront = false; // 커서 왼쪽에 글자가 추가되어 커서가 맨 앞은 아님
						ptr = ptr_first;
						continue;
					}
					else // 가장 앞에있는 글자 바로 뒤에 커서 = 글자가 여러개고 앞 뒤에 글자
					{
						new_ll->front = ptr;
						new_ll->back = ptr->back;
						ptr->back->front = new_ll;
						ptr->back = new_ll; // new_ll의 앞, 뒤를 ptr과 ptr->back으로 체크하고 각각의 뒤, 앞을 new_ll로 맞춰준다.
						ptr = new_ll; // 커서 왼쪽에 글자가 추가되었으므로 현재 커서는 new_ll 뒤쪽에 위치하고 있다.
						continue;
					}
				}
				else // 글자가 여러개고 앞 뒤에 글자가 있다.
				{
					new_ll->front = ptr;
					new_ll->back = ptr->back;
					ptr->back->front = new_ll;
					ptr->back = new_ll; // new_ll의 앞, 뒤를 ptr과 ptr->back으로 체크하고 각각의 뒤, 앞을 new_ll로 맞춰준다.
					ptr = new_ll; // 커서 왼쪽에 글자가 추가되었으므로 현재 커서는 new_ll 뒤쪽에 위치하고 있다.
					continue;
				}
			}
		}
	}

	ptr = ptr_first;
	while (true)
	{
		if (ptr == nullptr)
			break;
		printf("%c", ptr->data);
		if (ptr->back == nullptr)
			break;
		ptr = ptr->back;
	}
}

/* // 스택을 활용, 스택 2개를 활용해서 커서를 기준으로 1번 스택 2번 스택으로 글자들을 나눠둔다.
#include<iostream>
#include<stack>
using namespace std;


int main() {
    string str;
    int n, i;
    stack<char> stk1, stk2;
    getline(cin, str);
    for (i = 0; i < str.size(); i++) {
        stk1.push(str[i]);
    }
    cin >> n;
    for (i = 0; i < n; i++) {
        char c;
        char input;
        cin >> c;
        if (c == 'P') {
            cin >> input;
            stk1.push(input);
        }
        else if (c == 'L') {
            if (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        else if (c == 'D') {
            if (!stk2.empty()) {
                stk1.push(stk2.top());
                stk2.pop();
            }
        }
        else if (c == 'B') {
            if (!stk1.empty()) {
                stk1.pop();
            }
        }
    }
    while (!stk1.empty()) {
        stk2.push(stk1.top());
        stk1.pop();
    }
    while (!stk2.empty()) {
        cout << stk2.top();
        stk2.pop();
    }
    return 0;
}
*/