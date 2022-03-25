#include <iostream>

using namespace std;

//_a)Giải thuật có độ phức tạp thời gian tùy ý
void findPair(int a[], int n, int k)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == k)
            {
                cout << a[i] << " " << a[j] << endl;
                flag = 1;
            }
        }
    }
    if(flag == 0)
        cout << "Khong ton tai cap phan tu co tong bang " << k << endl;
}

//_b)Giải thuật có độ phức tạp thời gian O(n) và độ phức tạp không gian O(1)
void findPairImprove(int a[], int n, int k)
{
    int left = 0, flag = 0;
    int right = n - 1;
    while (left < right)
    {
        if (a[left] + a[right] == k)
        {
            cout << a[left] << " " << a[right] << endl;
            left++;
            flag = 1;
        }
        else if (a[left] + a[right] < k)
            left++;
        else
            right--;
    }
    if(flag == 0)
        cout << "Khong ton tai cap phan tu co tong bang " << k << endl;
}

int main()
{
    int arr[] = {1, 3 ,5 ,6, 8, 9, 11 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Nhap gia tri cua key: ";
    cin >> key;
    //a)
    findPair(arr, size, key);
    cout << "---------------------" << endl;
    //b)
    findPairImprove(arr, size, key);
    return 0;
}
