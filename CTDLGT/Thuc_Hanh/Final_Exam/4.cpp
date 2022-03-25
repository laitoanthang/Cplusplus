#include <iostream>
#include <algorithm>

using namespace std;

//_a)Giải thuật có độ phức tạp thời gian tùy ý
void findTriplet(int a[], int n, int key)
{
    int flag = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (a[i] + a[j] + a[k] == key)
                {
                    cout << a[i] << " " << a[j] << " " << a[k] << endl;
                    flag = 1;
                }
            }
        }
    }
    if (flag == 0)
        cout << "Khong tim thay 3 phan tu co tong bang " << key << endl;
}

//_b)Giải thuật có độ phức tạp thời gian O(n^2)
void findTripletImprove(int a[], int n, int key)
{
    sort(a, a + n);
    int left, right, flag = 0;
    for (int i = 0; i < n - 2; i++)
    {
        left = i + 1;
        right = n - 1;
        while (left < right)
        {
            if (a[i] + a[left] + a[right] == key)
            {
                cout << a[i] << " " << a[left] << " " << a[right] << endl;
                left++;
                flag = 1;
            }
            else if (a[i] + a[left] + a[right] < key)
                left++;
            else
                right--;
        }
    }
    if (flag == 0)
        cout << "Khong tim thay 3 phan tu co tong bang " << key << endl;
}

int main()
{
    int arr[] = {3, 1, 0, 5, 6, 8, 9, 11 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Nhap gia tri cua key: ";
    cin >> key;
    //a)
    findTriplet(arr, size, key);
    cout << "---------------------" << endl;
    //b)
    findTripletImprove(arr, size, key);
    return 0;
}