#include<iostream>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;
int priority(char a)
//?????????????????????
{
	if (a == '+' || a == '-')
		return 1;
	else { return 2; }
}
bool compare(char a, char b)
//???a??b???????????true/false
{
	return priority(a) > priority(b);
}
char* change(char data[],int length)
{
	char* hou = (char*)malloc(length * sizeof(char));
	stack<char> s;
	int index{ 0 };
	//int length = strlen(data);
	for (int i = 0; i < length; i++)
	{
		if (data[i] >= 'A' && data[i] <= 'B')
		{//???????????????????
			hou[index] = data[i];
			index++;
		}
		else//?????????????��????????????????
		{	//	?????????????????????????????? ??????????????????????
			while (!s.empty() && !compare(data[i], s.top()))
			{
				hou[index] = s.top();
				index++;
				s.pop();
			}
			//??????????????????????????????
			s.push(data[i]);
		}
	}//??????????????
	while (!s.empty())
	{
		hou[index] = s.top();
		index++;
		s.pop();
	}
	//delete[]hou;
	return hou;
}
int main()
{
	int groups{ 0 };
	int length{ 0 };
	cin >> groups;//????????
	while (groups--)
	{	//?????????????��??
		string str;
		cin >>length>>str;//????????????
		char s[100];
		str.copy(s, length, 0);
		//??????
		char *results;
		results=change(s,length);
		cout << results << endl;
	}
	return 0;
}