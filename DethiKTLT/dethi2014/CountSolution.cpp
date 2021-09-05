/*
câu 4: Giải
Ta có số phương án để đi hết n bậc thang là Pn (với mọi n)
Nếu n>=2
thì sẽ sinh ra trường hợp mới
TH1: Người đó bước 1 bậc đầu tiên
thì sẽ phải đi nốt Pn-1 bậc còn lại => số phương án: Pn-1
TH2: Người đó bước 2 bậc đầu tiên
thì sẽ phải đi nốt Pn-2 bậc còn lại => số phương án: Pn-2
Theo quy tắc cộng thì ta có 
tổng số phương án lên cầu thang n bậc là Pn = Pn-1 + Pn-2 (hoặc)
Nếu n = 0 hoặc n = 1 thì Pn = 1
*/

/*
Question 4:
I have the number of option to finish all the stairs is Pn (With n in R)
If n >= 2
then the appearing the new cases
- First case: walk firstly 1 stair
That person must have done the rest of the stairs
=> the solution in first case is Pn-1
- Second case: walk firstly 2 stairs
That person must completely have done the rest of the stairs
=> the solution in second case is Pn-2

So the sum to claim the stairs is Pn = Pn-1 + Pn-2
If n = 0 or n = 1 then Pn will be 1
*/

// It is the same of fibonacci
// 0 1 2 3 4 5 6...
// 1 1 2 3 5 8 13...

#include <iostream>
using namespace std;

int Count_Solution(int n)
{
	int* p = new int[n+1];
	p[0] = p[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		p[i] = p[i-1] + p[i-2];
	}
	int ans = p[n];
	delete p;
	return ans;

}

int main()
{
	int n = 0;
	cout << "Input n=";
	cin >> n;
	cout << Count_Solution(n);
	return 0;
}