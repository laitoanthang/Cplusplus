#include <iostream>
using namespace std;

int check(int n)
{
    if (n%3==0 || n%10==3)
        return 0;
    else return 1;
}
int main()
{
    int a[10000];
    int i=0;
    int m=0;
    while (i<1666)
    {
        i++;
        if (check(i)==1)
        {
            a[m] = i;
            m++;
        }
    }
    for (int i=0; i<m; i++)
    {
        cout<<a[i]<<" ";
    }


    int x = 0;
    cout<<"Input x = ";
    cin >> x; 
    cout<<"Number you want: " << a[x-1];
    return 0;
}