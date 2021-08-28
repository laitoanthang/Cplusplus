// input: "   kI   thuaT  lAp    triNH   "
// out: "Ky Thuat Lap Trinh"
#include <iostream>
using namespace std;

int lens(char* s)
{
	int i=0;
	while (s[i] != NULL)
		i++;
	return i;
}

char ToUpper(char c)
{
	if (c>='a' and c<='z')
		return c-'a'+'A';
	return c;
}

char ToLower(char c)
{
	if (c>='A' and c<='Z')
		return c-'A'+'a';
	return c;
}

char* Normalize(char* s)
{
	int i = 0;
	int lenstr = lens(s);
	while (s[i] == ' ') i++; // If the first character is space then skip 
	char* str = new char[lenstr];
	for ( ; i<lenstr; i++) //let i run from the first character which is not a space
	{
		if ((s[i-1] == ' ') || (i = 0)) // If the first cha or the cha after the space then upcase it
		{
			
		}
	}

}

int main()
{
	char* s = nullptr;
	s = new char[50];
	cout << "Input string\n";
	cin.getline(s, 51);
	
	cout << lens(s);
	cout << ToUpper(s[0]);

	delete[] s;
	return 0;
}