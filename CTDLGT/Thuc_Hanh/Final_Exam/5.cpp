#include <iostream>

using namespace std;

int* res = new int[10000];

int countCoinMin(int a[], int n, int amount)
{
    for (int i = 0; i <= amount; i++)
        res[i] = 0;
    for (int i = 0; i < n; i++)
        res[a[i]] = 1;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= a[j])
            {
                if ((res[i] > res[i - a[j]] + 1 && res[i - a[j]] != 0) || (res[i] == 0 && res[i - a[j]] != 0))
                    res[i] = res[i - a[j]] + 1;
            }
        }
    }
    return res[amount];
    /*if (amount == 0) cách đệ quy chạy khá châm với số xu lớn cần đổi
        return 0;
    int num = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (amount >= a[i])
        {
            int temp = countCoinMin(a, n, amount - a[i]);
            if (temp != INT_MAX && temp + 1 < num)
                num = temp + 1;
        }
    }
    return num;*/
}

int main()
{
    int a[] = { 1, 2, 5, 10, 20, 50, 100}; //Phải có đồng xu mệnh giá 1 để bài toán luôn có đáp án
    int size = sizeof(a) / sizeof(a[0]);
    int amount;
    do
    {
        cout << "Nhap luong tien xu can doi: ";
        cin >> amount;
        if (amount < 0)
            cout << "Vui long nhap so xu khong am" << endl;
    } while (amount < 0);
    
    cout << "Luong tien xu it nhat de doi " << amount << " xu la: " << countCoinMin(a, size, amount) << " dong xu" << endl;
    return 0;
    delete[] res;
}
