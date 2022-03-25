#include <iostream>
using namespace std;

class PhanSo{
private:
    int tu;
    int mau;
public:
    void input();
    void print();
    
    // Sơn Hà friend function
    // p1 + p2
    // PhanSo operator+(const PhanSo &p2);
    friend PhanSo operator+(const PhanSo &p1, const PhanSo &p2);
    
    // p1 + 7
    PhanSo operator+(int x);
    
    // PhanSo& operator+(const PhanSo &p2);
    int operator<(const PhanSo &p2);
    
    PhanSo& operator+=(const PhanSo &p2);
    // void operator+=(const PhanSo &p2);
    
    // ++p1 => 3/2
    PhanSo& operator++();
    
    // p1++ => 1/2
    PhanSo operator++(int dummy);
    
    friend PhanSo operator+(int x, const PhanSo &p);
    
};

//// 7 + p1
//// o ngoai class PhanSo, ta can cai dat operator+
//PhanSo operator+(int x, const PhanSo &p);

void PhanSo::input(){
    cout << "Nhap tu: ";
    cin >> tu;
    cout << "Nhap mau: ";
    cin >> mau;
}

void PhanSo::print(){
    cout << tu << "/" << mau;
}

////// Khong nen, vi reference den local variable, / 144 thay vi / 96
//// PhanSo& PhanSo::operator+(const PhanSo &p2){
//PhanSo PhanSo::operator+(const PhanSo &p2){
//    PhanSo temp;
//    temp.tu = tu * p2.mau + mau *p2.tu;
//    temp.mau = mau * p2.mau;
//    return temp;
//}

PhanSo operator+(const PhanSo &p1, const PhanSo &p2){
    PhanSo temp;
    temp.tu = p1.tu * p2.mau + p1.mau *p2.tu;
    temp.mau = p1.mau * p2.mau;
    return temp;
}

//// Khong nen, vi thay doi gia tri p1
//PhanSo PhanSo::operator+(const PhanSo &p2){
//    tu = tu * p2.mau + mau *p2.tu;
//    mau = mau * p2.mau;
//    return *this;
//}

//// Khong nen, vi gay nham lan cho nguoi goi operator<
// PhanSo PhanSo::operator<(const PhanSo &p2){
int PhanSo::operator<(const PhanSo &p2){
    if(1.0 *tu / mau < 1.0 * p2.tu / p2.mau){
        return 1;
    }
    else {
        return 0;
    }
}
//// Van ok, nhung mat cong goi copy constructor
//PhanSo PhanSo::operator+=(const PhanSo &p2){

//PhanSo& PhanSo::operator+=(const PhanSo &p2){
////    *this = *this + p2;
//    tu = tu * p2.mau + mau *p2.tu;
//    mau = mau * p2.mau;
//    return *this;
//}

//// Loi: p3 += p1 += p2;
//void PhanSo::operator+=(const PhanSo &p2){
////    *this = *this + p2;
//    tu = tu * p2.mau + mau *p2.tu;
//    mau = mau * p2.mau;
//}

PhanSo& PhanSo::operator++(){
    tu = tu + mau;
    
//    // p2: 1/1
//    tu = tu * 1 + mau * 1;
//    mau = mau * 1;
    
    return *this;
}

PhanSo PhanSo::operator++(int dummy){
    PhanSo temp = *this;
    tu = tu + mau;
    return temp;
}

PhanSo PhanSo::operator+(int x){
    PhanSo temp;
    temp.tu = tu + mau * x;
    temp.mau = mau;
    return temp;
}

PhanSo operator+(int x, const PhanSo &p){
    PhanSo temp;
    temp.tu = p.tu + p.mau * x;
    temp.mau = p.mau;
    return temp;
}
// van de: truy cap private
// C1: doi private thanh public
// C2: getter, setter: getTu(), getMau(), setTu(x), setMau(x)
// C3: khai bao operator+ la friend class PhanSo

int main(){
    PhanSo p1, p2;
    
    cout << "Nhap p1" << endl;
    p1.input();
    cout << "Nhap p2" << endl;
    p2.input();
    
    PhanSo p3 = p1 + p2;
//    PhanSo p3 = p1.operator+(p2);
    
//    PhanSo p4;
//    cout << "Nhap p4" << endl;
//    p4.input();
//    PhanSo p3 = (p1 + p2) + (p1 + p4);
    cout << "p1 + p2 = ";
    p3.print();
    cout << endl << endl;
//    p1.print();
    
    bool ans = p1 < p2;
    if(ans){
        cout << "p1 < p2" << endl;
    }
    else{
        cout << "p1 >= p2" << endl;
    }
    cout << endl;
    
//    p1 += p2;
//    cout << "p1 += p2 = ";
//    p1.print();
//    cout << endl;
    
//    p3 += p1 += p2;
//    cout << "p3 += p1 += p2 = ";
//    p3.print();
//    cout << endl;
    
    ++p1;
    p1.print();
    cout << endl;
    
    p1++;
    p1.print();
    cout << endl;
    
    p3 = p1 + 7;
    cout << "p1 + 7: ";
    p3.print();
    cout << endl << endl;
    
    p3 = 7 + p1;
    cout << "7 + p1: ";
    p3.print();
    cout << endl << endl;
    
    
    
    return 0;
}

// 1 / 2 + 3 / 4 = 10 / 8
// 1 / 2 + 5 / 6 =  16 / 12

// 10 / 8 + 16 / 12 = 248 / 96

// Gia su ban da cai dat cin >> p1; cout << p1; OK roi

// ifstream fin;
// fin.open("test.txt");
// fin >> p1;
// fin.close();
