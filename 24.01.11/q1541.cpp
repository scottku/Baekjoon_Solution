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

using namespace std;

int main(void)
{
	string str;
	cin >> str; // 55-50+40
	istringstream s(str);
	string stringBuffer;

	vector<string> v;
	// 1. 맨 앞자리가 음수다 = - 나올때마다 묶어버리면 죄다 음수로 만들 수 있다 -> 뒤에 나올 숫자들 그냥 다 더해서 음수로 변경
	if (str[0] == '-')
	{
		vector<string> vTemp;
		istringstream ss(str);
		string strTemp;
		while (getline(ss, strTemp, '-'))
		{
			vTemp.push_back(strTemp);
		}
		for (int i = 0; i < vTemp.size(); i++)
		{
			string st = vTemp[i];
			if (st.find('+') == string::npos) // - 문자도 + 문자도 없는 숫자만 있는 string이라면
				v.push_back(st);
			else
			{
				istringstream str1(st);
				string temp1;
				while (getline(str1, temp1, '+'))
				{
					v.push_back(temp1);
				}
			}
		}

		int result = 0;
		for (int i = 0; i < v.size(); i++)
		{
			result += stoi(v[i]);
		}
		printf("%d", result);
		return 0;
	}
	else
	{
		// 맨 앞자리가 -이 아니면 -> 처음 나오는 '-' 앞부분은 양수, 뒷부분은 전부 음수
		while (getline(s, stringBuffer, '-'))
		{
			if (stringBuffer.empty())
				continue;
			v.push_back(stringBuffer);
		}
		// 벡터 v의 첫번째 인자는 더해서 양수로, 나머지 뒤쪽 친구들은 전부 더하고 마지막에 음수로 변경
		istringstream streamTemp1(v[0]);
		string maybelast;
		vector<string> lastVector;
		int _plus = 0;
		int _minus = 0;
		if (v[0].find('+') == string::npos)
			_plus += stoi(v[0]);
		else
		{
			while (getline(streamTemp1, maybelast, '+'))
			{
				lastVector.push_back(maybelast);
			}

			for (int j = 0; j < lastVector.size(); j++)
			{
				_plus += stoi(lastVector[j]);
			}
		} // 앞쪽 양수 부분 체크 완료

		if (v.size() > 1) // v 원소 갯수가 2 이상 = 양수 부분과 음수 부분이 있다 
		{
			for (int k = 1; k < v.size(); k++)
			{
				istringstream notthelast(v[k]);
				string stringcensored;
				while (getline(notthelast, stringcensored, '+'))
				{
					_minus += stoi(stringcensored);
				}
			}
			printf("%d", _plus - _minus);
			return 0;
		}
		else // = 1 이하면 양수 부분만 있다
		{
			printf("%d", _plus);
			return 0;
		}
	}

}