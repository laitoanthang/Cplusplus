#include <iostream>
using namespace std;

class Fraction {
	private:
		int tu;
		int mau;
	public:
		void Nhap();
		
		Fraction Cong(Fraction t);
		void cong(Fraction p1, Fraction p2);
		
		void Xuat()
		{
			cout << tu << "/" << mau << endl;
		}
		void RutGon();
};

int main()
{
	Fraction p1;
	Fraction p2;
	Fraction p3;
	cout << "Nhap phan so 1" << endl;
	p1.Nhap();
	p1.RutGon();
	p1.Xuat();
	p2.Nhap();
	p2.RutGon();
	p2.Xuat();
	
	cout << endl;
	p1.cong(p1,p2);
	cout << endl;
	p3 = p1.Cong(p2);
	p3.Xuat();
	return 0;
}

void Fraction::Nhap()
{
	cout << "Nhap tu\n";
	cin >> this->tu;
	do {
		cout << "Nhap mau\n";
		cin >> this->mau;
	} while (this->mau == 0);
	if (this->mau < 0) {
		this->tu = -this->tu;
		this->mau = - this->mau;
	}
}

Fraction Fraction::Cong(Fraction p2)
{
	Fraction p;
	p.tu = this->tu * p2.mau + this->mau * p2.tu;
	p.mau = this->mau * p2.mau;
	p.RutGon();
	return p;
}


void Fraction::cong(Fraction p1, Fraction p2)
{
	Fraction p;
	p.tu = p1.tu * p2.mau + p1.mau * p2.tu;
	p.mau = p1.mau * p2.mau;
	p.RutGon();
	cout << "2. Tong 2 ps la " << p.tu << "/" << p.mau;
}

int gcd(int a, int b)
{
	if (b == 0) return abs(a);
	return gcd(b, a%b);
}

void Fraction::RutGon()
{
	Fraction p;
	int ucln = gcd(this->tu, this->mau);
	this->tu = this->tu / ucln;
	this->mau = this->mau / ucln;
	if (mau < 0)
	{
		tu = -tu;
		mau = -mau;
	}
}