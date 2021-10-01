#include <iostream>
using namespace std;

void XuatMang(float **, int, int);

void CapPhatKhoiTaoMang(float **&a, int &sodong, int &socot)
{
	do{
		//cout << "\nNhap vao so dong = ";
		//cin >> sodong;
		printf("\nNhap vao so dong = ");
		scanf("%d", &sodong);

		if(sodong < 0)
			cout << "\nSo dong phai >= 0. Xin kiem tra lai!";
	}while(sodong < 0);

	do{
		cout << "\nNhap vao so cot = ";
		cin >> socot;

		if(socot < 0)
			cout << "\nSo cot phai >= 0. Xin kiem tra lai!";
	}while(socot < 0);

	/*
mảng 2 chiều cấp phát động => con trỏ cấp 2
mảng 2 chiều cần có số dòng & số cột

nguyên tắc cấp phát:
đầu tiên là cấp phát các con trỏ đầu mỗi dòng để quản lý các cột
sau đó là cấp phát các con trỏ trong mỗi dòng

*/

	//a = new float*[sodong];
	//a = (float**)malloc(sodong * sizeof(float));
	//a = (float**)calloc(sodong, sizeof(float));
	a = (float**)realloc(0, sodong * sizeof(float));
	for(int i = 0; i < sodong; ++i)
		//a[i] = new float[socot];
			//a[i] = (float*)malloc(socot * sizeof(float));
				//a[i] = (float*)calloc(socot, sizeof(float));
					a[i] = (float*)realloc(0, socot * sizeof(float));

	// Xử lý
	// Nhập dữ liệu
	for(int i = 0; i < sodong; ++i)
	{
		for(int j = 0; j < socot; ++j)
		{
			cout << "\nNhao vao a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

void XuatMang(float **a, int sodong, int socot)
{
	// Xuất dữ liệu
	for(int i = 0; i < sodong; ++i)
	{
		for(int j = 0; j < socot; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

float TinhTongPhanTuKhongAmCuaMang(float **a, int sodong, int socot)
{
	float Tong = 0;
	for(int i = 0; i < sodong; ++i)
	{
		for(int j = 0; j < socot; ++j)
		{
			if(a[i][j] > 0)
				Tong += a[i][j];
		}
	}
	return Tong;
}

int main()
{
	int sodong;
	int socot;
	float **a;

	CapPhatKhoiTaoMang(a, sodong, socot);
	XuatMang(a, sodong, socot);

	float TongKhongAm = TinhTongPhanTuKhongAmCuaMang(a, sodong, socot);
	cout << "\nTong cac phan tu khong am cua mang la: " << TongKhongAm;

	// Chức năng cấp phát thêm ô nhớ của realloc
	//realloc(a[0], (socot + 1) * sizeof(float));
	//a[0][2] = 100;
	//cout << "\na[0][2] = " << a[0][2];

	// giải phóng bộ nhớ
	// Lưu ý: giải phóng bộ nhớ thì đi theo chiều ngược lại thứ tự so với cấp phát
	for(int i = 0; i < sodong; ++i)
		//delete[] a[i];
			free(a[i]);

	//delete[] a;
	free(a);

	system("pause");
	return 0;
}