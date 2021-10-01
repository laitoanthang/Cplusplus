#include <iostream>
using namespace std;

int DemSoLuongSo7(int n)
{
	int dem = 0;
	while(n != 0)
	{
		int chuso = n % 10; // lấy ra chữ số
		n = n / 10; // bỏ đi chữ số vừa lấy ra

		if(chuso == 7)
			dem++;

		//cout << "\nchu so = " << chuso << " => dem = " << dem;
	}
	return dem;
}

int countSeven(int n)
{
	// điều kiện dừng
	if(n == 0)
		return 0;

	// bước lặp
	return (n % 10 == 7 ? 1 : 0) + countSeven(n / 10);
}

int countSeven_DeQuyDuoi(int n, int dem = 0)
{
	// điều kiện dừng
	if(n == 0)
		return dem;

	if(n % 10 == 7)
		dem++;

	return countSeven_DeQuyDuoi(n / 10, dem);
}

int main()
{
	int n = 717;

	cout << countSeven_DeQuyDuoi(n);

	system("pause");
	return 0;
}