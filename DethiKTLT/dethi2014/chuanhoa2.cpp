#include <iostream>
#include <cstring>
using namespace std;
// cách một là chuyện từng ký tự cần thiết qua chuỗi mới
// cách hai: xoá khoảng trắng thừa và Normalize chuỗi
// hàm xoá một kí tự = xoá một hàm xoá một vị trí trong mảng một chiều
// chuỗi là mảng một chiều các kí tự "abcd" => 'a' 'b' 'c' 'd' '\0'

char ToUpper(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
	return c;
}

char ToLower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c - 'A' + 'a';
	return c;
}

void delete_char(char* &s, int &n, int index)
{
	for (int i = index; i < n; i++)
		s[i] = s[i+1];
	n--;
}

void delete_extra_spaces(char*& s, int& n)
{
	while (s[0] == ' ')
		delete_char(s, n, 0);
	while (s[n-1] == ' ')
		delete_char(s, n, n-1);
	// delete spaces which are in the middle of the string
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ' ' && s[i+1] == ' ')
		{
			delete_char(s, n, i);
			i--;
		}
	}
}

void Normalize(char* &s, int n)
{
	s[0] = ToUpper(s[0]);
	for (int i = 1; i < n; i++)
	{
		if (s[i-1] == ' ')
			s[i] = ToUpper(s[i]);
		else 
			s[i] = ToLower(s[i]);
	}
}

int main()
{
	char* s = nullptr;
	s = new char[50];
	cout << "Input string\n";
	cin.getline(s, 51);
	int n = strlen(s);
	delete_extra_spaces(s, n);
	Normalize(s, n);
	cout << s;
	
	return 0;
}