/*
Làm theo cách 1: Kiểm tra đủ dấu ngoặc là được
ý tưởng đơn giản: Đếm số lượng các dấu mở ngoặc và đóng ngoặc có trong chuỗi 
sau đó kiểm tra nếu khớp nhau => true, không khớp nhau => false
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "( 1 + 2 ) ) + ( 3 + 4 ) (";
	int dem_mongoac = 0, dem_dongngoac = 0;
	int length = s.length();

	for(int i = 0; i < length; ++i)
	{
		if(s[i] == '(')
			dem_mongoac++;
		else if(s[i] == ')')
			dem_dongngoac++;
	}
	if(dem_mongoac == dem_dongngoac)
		cout << "true";
	else
		cout << "false";

	system("pause");
	return 0;
}