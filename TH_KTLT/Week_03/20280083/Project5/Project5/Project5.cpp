#include <iostream>
#include <algorithm>
using namespace std;

struct fraction
{
	int numerator;
	int denominator;
};

int GCD(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

void reduction(fraction& ps)
{
	int c = GCD(ps.numerator, ps.denominator);
	ps.numerator = ps.numerator / c;
	ps.denominator = ps.denominator / c;
}

void inputfraction(fraction& ps)
{
	cout << "Input numerator=";
	cin >> ps.numerator;
	do
	{
		cout<<"Input dennominator=";
		cin >> ps.denominator;
		if (ps.denominator == 0)
			cout << "Error input... Please try again\n";
	} while (ps.denominator == 0);
}

void outputfraction(fraction ps)
{
	cout << ps.numerator << "/" << ps.denominator;
	cout << "\t";
}

fraction addition(fraction a, fraction b)
{
	fraction add;
	add.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	add.denominator = a.denominator * b.denominator;
	reduction(add);
	return add;
}

fraction subtraction(fraction a, fraction b)
{
	fraction h;
	h.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
	h.denominator = a.denominator * b.denominator;
	reduction(h);
	return h;
}

fraction multiplication(fraction a, fraction b)
{
	fraction mul;
	mul.numerator = a.numerator * b.numerator;
	mul.denominator = a.denominator * b.denominator;
	reduction(mul);
	return mul;
}

fraction division(fraction a, fraction b)
{
	fraction divi;
	divi.numerator = a.numerator * b.denominator;
	divi.denominator = a.denominator * b.numerator;
	reduction(divi);
	return divi;
}

int compare(fraction p1, fraction p2)
{
	if (p1.numerator * p2.denominator > p1.denominator * p2.numerator)
		return 1;
	else if (p1.numerator == p2.numerator && p1.denominator == p2.denominator)
		return 0;
	else return -1;
}

void inputarray(fraction*& a, int& n)
{
	cout << "\nInput n=";
	cin >> n;
	a = new fraction[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Input fraction " << i + 1 << endl;
		inputfraction(a[i]);
	}
}

void outputarray(fraction* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		outputfraction(a[i]);
	}
}

fraction additioninarray(fraction* a, int n)
{
	fraction s;
	s.numerator = 0;
	s.denominator = 1;
	for (int i = 0; i < n; i++)
	{
		s = addition(s, a[i]);
	}
	return s;
}

void reductionallthefractions(fraction*& a, int& n)
{
	for (int i = 0; i < n; i++)
	{
		reduction(a[i]);
	}
}


void sortarray(fraction*& a, int& n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (compare(a[i], a[j]) == 1)
			{
				swap(a[i], a[j]);
			}
		}
	}
}

int kinarray(fraction* a, int n)
{
	fraction k;
	cout << "Input k=\n";
	inputfraction(k);
	for (int i = 0; i < n; i++)
	{
		if (compare(k,a[i])==0)
			return 1;
	}
	return 0;
}
int main()
{
	fraction p1;
	fraction p2;
	cout << "Input fraction 1\n";
	inputfraction(p1);
	cout << "Input fraction 2\n";
	inputfraction(p2);
	outputfraction(p1);
	outputfraction(p2);
	cout << endl;
	outputfraction(addition(p1, p2));
	outputfraction(subtraction(p1, p2));
	outputfraction(multiplication(p1, p2));
	outputfraction(division(p1, p2));
	reduction(p1);
	reduction(p2);
	cout<<endl<<"Compare 2 fraction: "<<compare(p1, p2);
	fraction* a = nullptr;
	int n = 0;
	inputarray(a, n);
	outputarray(a, n);
	cout << "\nAddition all of the fractions in the array is ";
	outputfraction(additioninarray(a, n));
	cout << "\nArray after reduction all the fractions: ";
	reductionallthefractions(a, n);
	outputarray(a, n);
	cout << "\n" << "Sort fractions in the array in ascending other\n";
	sortarray(a, n);
	outputarray(a, n);
	cout << endl << endl << "__________k in Array__________" << endl;
	cout << kinarray(a, n);
	delete[]a;
	system("pause");
	return 0;
}