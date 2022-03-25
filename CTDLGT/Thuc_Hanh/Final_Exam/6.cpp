#include <iostream>

using namespace std;

//_a) Giải thuật có độ phức tạp về thời gian tùy ý
int findMajorityElement(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                count++;
        }
        if (count > n / 2)
            return a[i];
    }
    return 0;
}

//_b)Giải thuật có độ phức tạp về thời gian O(n)
int findMajorityElementImprove(int a[], int n)
{
    int majority_ele = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            majority_ele = a[i];
            count = 1;
        }
        else
        {
            if (majority_ele == a[i])
                count++;
            else
                count--;
        }
    }
    return majority_ele;
}

bool isMajorityElement(int a[], int n, int ele)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ele)
            count++;
    }
    if (count > n / 2)
        return true;
    else
        return false;
}

int main()
{
    int arr[] = { 1, 3, 5, 1, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    //a
    if (findMajorityElement(arr, size))
        cout << "Phan tu da so: " << findMajorityElement(arr, size) << endl;
    else
        cout << "Khong ton tai phan tu da so" << endl;
    cout << "------------------------" << endl;
    //b
    int element = findMajorityElement(arr, size);
    if(isMajorityElement(arr, size, element))
        cout << "Phan tu da so: " << element << endl;
    else
        cout << "Khong ton tai phan tu da so" << endl;
    return 0;
}