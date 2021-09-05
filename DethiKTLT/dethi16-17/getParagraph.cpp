#include <iostream>
using namespace std;
// Đọc từ bàn phím một đoạn văn
// có độ dài 0 xác định và lưu vào chuỗi cấp phát động
// Đoạn văn kết thúc bằng dấu chấm câu và ký tự
// xuống dòng

void getParagraph(char* &s)
{
	int i=0;
	s = new char[100];
	char c = '\0';
	cout << "Input your string: ";
	while (c!='\n')
	{
		c = getchar();
		s[i] = c;
		i++;
	}
	s[i] = '\0';
}

int main()
{
	char* s = NULL;
	getParagraph(s);
	cout << s;
	delete s;
	return 0;
}