// input: "   kY   thuaT  lAp    triNH   "
// out: "Ky Thuat Lap Trinh"
#include <iostream>
using namespace std;

// hàm xoá một kí tự = xoá một hàm xoá một vị trí trong mảng một chiều
// chuỗi là mảng một chiều các kí tự "abcd" => 'a' 'b' 'c' 'd' '\0'



int lens(char* s)
{
	int i=0;
	while (s[i] != 0)
		i++;
	return i;
}

char ToUpper(char c)
{ // Nếu kí tự xét nằm trong a đến z thì 
// kí tự = kí tự - 'a' + 'A'
	if (c>='a' && c<='z')
		return c-'a'+'A';
	return c;
}

char ToLower(char c)
{ // Nếu kí tự nằm trong khoảng từ 'A' đến 'Z' thì 
// kí tự = kí tự - 'A' + 'a' (bỏ lớn lấy nhỏ)
	if (c>='A' && c<='Z')
		return c-'A'+'a';
	return c;
}


char* Normalize(char* s) {
    int len = lens(s);

    char * ns = new char[len];

    int i = 0;
    int j = 0;
    //Bo khoang trang dau
    while (s[i] == ' ') i++;

    for (; i < len; i++) {
        if (s[i]!=' ') {
            //Neu khong phai khoang trang thi them vao xau moi
            char c = s[i];

            //Neu dung dau cau hoac sau khoang trang thi viet hoa
            if (i == 0 || s[i-1] == ' ')
                c = ToUpper(c);
            //Con lai thi viet thuong
            else
                c = ToLower(c);

            ns[j] = c;
            j++;
        } // trường hợp cái kí tự đặc biệt
        else if (i+1 < len && s[i+1] != ' ') {
            // Neu la khoang trang nhung ki tu sau 
            // khong phai la khoang trang thi them vao
            ns[j] = s[i];
            j++;
        }
    }
    return ns;
}

int main()
{
	char s[50];
	cout << "Input string\n";
	cin.getline(s, 51);
	cout << Normalize(s);
	
	return 0;
}