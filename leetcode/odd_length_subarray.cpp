/*
Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58

Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= 1000
*/

#include <iostream>
#include <vector>
using namespace std;


int sumOddLengthSubarrays(int arr[], int n) 
{
	int ans = 0;
	for (int i = 0; i < n; i++) {
	for (int j = i; j < n; j++) {
			if ((j - i + 1) % 2 == 1) {
				for (int k = i; k <= j; k++) {
				ans += arr[k];
				}
			}
		}
	}
	return ans;
}

int main()
{
	int arr[5] = {1,4,2,5,3};
	int n = 5;
	int result = sumOddLengthSubarrays(arr, n);
	cout << result << endl;
	system("pause");
	return 0;
}