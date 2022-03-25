#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> g1;
  	cout << g1.capacity() << endl;
    cout << g1.size() << endl;
    cout << g1.empty() << endl;
    for (int i = 1; i <= 100; i++)
        g1.push_back(i);
    g1.shrink_to_fit();
  	cout << g1.capacity() << endl;

    cout << g1.size() << endl;
    g1.reverse();
    // cout << g1.begin();
    for (int i = 0; i < g1.size(); i++)
    	cout << g1[i] << " ";
	return 0;
}