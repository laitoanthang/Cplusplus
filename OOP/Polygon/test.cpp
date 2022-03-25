#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;

class point{
private:
    float x,y;
public:
    void setPoint(float a,float b){
        x = a;y = b;
    };
    friend float calculateAreaTriangle(point A,point B,point C){
        return (0.5*abs((C.x-A.x)*(B.y-A.y)-(B.x-A.x)*(C.y-A.y)));
    };
};

class polygon{
private:
    point *p;
    int n;
    float Area;
public:
    polygon(int m){
        n = m;
        p = new point[m];
        Area = 0;
    };
    void setPolygon(){
        float a,b;
        for(int i=0;i<n;i++){
            cout<<"x("<<i+1<<") = ";
            cin>>a;
            cout<<"y("<<i+1<<") = ";
            cin>>b;
            p[i].setPoint(a,b);
        }
        for(int i=0;i<n-1;i++){
            Area = Area + calculateAreaTriangle(p[0],p[i],p[i+1]);
        }
	  cout << "\t Area: " << Area << endl;
    };
    void testInPolygon(point P){
        float sum = 0;
        for(int i=0;i<n-1;i++){
            sum = sum + calculateAreaTriangle(p[i],p[i+1],P);
        }
        sum = sum + calculateAreaTriangle(p[n-1],p[0],P);
        if(abs(Area-sum)<=0.01)
            cout<<"diem nam trong hinh";
        else
            cout<<"diem nam ngoai hinh";
    };
    ~polygon(){
        delete []p;
    };
};

int main() {
    int m;
    float a,b;
    cout<<"nhap so dinh cua da giac: ";
    cin>>m;
    polygon A(m);
    A.setPolygon();
    point P;

    P.setPoint(a,b);
    cout<<"nhap diem can xet: ";
    cout<<"x = ";
    cin>>a;
    cout<<"y = ";
    cin>>b;
    
    A.testInPolygon(P);
    return 0;
}