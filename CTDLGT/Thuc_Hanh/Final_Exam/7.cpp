#include <iostream>

using namespace std;

//Tìm dãy con liên tục có tổng lớn nhất (dựa trên thuật toán Kadane)
void findSubSequence(int a[], int n)
{
    int max_index = 0;
    int max_current = 0;
    int start = 0, end = 0, x = 0;
    for (int i = 0; i < n; i++)
    {
        max_current = max_current + a[i];
        if (max_current < 0)
        {
            max_current = 0;
            x = i + 1;
        }
        if (max_index < max_current)
        {
            max_index = max_current;
            start = x;
            end = i;
        }
    }
    if (max_index < 0)
        cout << "{}" << endl;
    else
    {
        cout << "{ ";
        for (int i = start; i < end; i++)
            cout << a[i] << ", ";
        cout <<a[end] << " }" << endl;
    }
}

int main()
{
    int arr[] = { -2, -5, 6, -2, -3, 1, 5, -6 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Day con lien tuc co tong lon nhat: ";
    findSubSequence(arr, size);
    return 0;
}
