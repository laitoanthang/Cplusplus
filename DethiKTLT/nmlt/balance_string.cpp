#include <iostream>
#include <cstring>
using namespace std;

// a. viết hàm đếm số từ trong chuỗi ký tự s
// mỗi từ cách nhau bằng khoảng trắng, dấu chấm hoặc dấu phẩy
// b. viết hàm xoá khoảng trắng thừa
int count_word(char* s)
{
	int i = 0;
	int count = 1;
	if (s[0] == ' ' || s[0] == ',' || s[0] == '.')
	{
		count = 0;	
	}
	while (s[i] != '\0')
	{
		if (s[i+1] == '\0') return count;
		if ((s[i] == ' ' || s[i] == ',' || s[i] == '.')
		&& (s[i+1] != ' ' && s[i+1] != ',' && s[i+1] != '.'))
		{ 
			count++;
		}
		i++;
	}
	return count;
}

void chuanhoa(char* s, int& n)
{
	// delete first spaces
	while (s[0] == ' ')
	{
		memmove(&s[0], &s[1], strlen(s) - 0);
	}
	// delete last spaces
	while (s[n-1] == ' ')
	{
		memmove(&s[n-1], &s[n-2], n - (n-1));
	}
	// delete middle spaces
	for (int i = 0; i<n-1 ;i++)
	{
		if (s[i] == ' ' && s[i+1] == ' ')
		{
			int indexDel = i;
			memmove(&s[i], &s[i+1], strlen(s) - indexDel);
			i--;
		}
	}
}

int main()
{
	char s[] = "  To  thich    cau..     ";
	int n = strlen(s);
	cout << count_word(s) << endl;
	chuanhoa(s, n);
	cout << s;
	// char Word[] = "abcdef";  
	// int idxToDel = 1; 
	// memmove(&Word[idxToDel], &Word[idxToDel + 1], strlen(Word) - idxToDel);
	// cout << Word;
	return 0;
}