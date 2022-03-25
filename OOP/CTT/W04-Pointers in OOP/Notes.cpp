class Graph{
private:
	void dfsRecursion(int start, int x, int y);
public:
	void dfs(int start);
	// expose, show
};


class PhanSo{
private:
	int tu, mau;
private:
	void reduce();
public:
	PhanSo add(PhanSo p);
};


// developer A
class Student{
private:
	string firstName; // Hữu Đan
	string lastName; // Phạm
	int age;
public:
	// Hữu Đan Phạm
	string getNameInEn(){
		return firstName + " " + lastName;
	}
	// Phạm Hữu Đan
	string getNameInVN(){
		return lastName + " " + firstName;
	}

	// Nguyễn Nhật Đăng
	void setName(string s){
		firstName = "Nhật Đăng";
		lastName = "Nguyễn";
	}

	int getAge(){
		return age;
	}
	void setAge(int x){
		if(x <= 0){
			x = 1;
		}
		if(x > 100){
			x = 100;
		}
		age = x;
	}
};

// develop B
int main(){
	Student student1;
	student1.age = 200;

}


// getter, setter
// USer
// FITer


// getter, setter violate data hiding property in OOP?
// Phát: NO

// getter là hàm trả về giá trị cho 1 thuộc tính ở trong class
// có thuộc tính: age => có hàm getAge()

// có getter nào, mà ko có thuộc tính tương ứng
// YES
class Triangle{
private:
	Point2D A, B, C; // option 1
	// double ab, bc, ac; // option 2
public:
	// int getArea();
	int calculateArea();
};


// có setter nào, mà ko có thuộc tính tương ứng
// NO!!!


class A{
private:
	int x, y, z, t, u, v;
public:
	// 6 getters
	// 6 setters
};


// framework F
// class A: int x, y, z => private + getter, setter


// bài tập lớn, project


// chuẩn
Point2D(const Point2D &other);

// Trí => OK
Point2D(Point2D &other);

// Trí => ERROR
Point2D(Point2D other);

Point2D p2(p1);
// gọi copy constructor ở trên
// trước khi chạy code của copy constructor, 
// thì cần copy giá trị p1 vào cho other (pass by value)
// cần gọi copy constructor
// copy constructor là cái mình đang viết!!!
// deadlock


Point2D Point2D::clone(){
	Point2D ans;
	ans.x = x;
	ans.y = y;
	return ans;
}

Point2D Point2D::copy(){
	Point2D ans;
	ans.x = x;
	ans.y = y;
	return ans;
}

Point2D p1(3, 4);
Point2D p2 = p1.clone();
Point2D p2 = p1.copy();
// Point2D p2(p1);


Point2D* Point2D::clone(){
	Point2D *ans = new Point2D;
	ans->x = x;
	ans->y = y;
	return ans;
}
Point2D p1(3, 4);
Point2D *p2 = p1.clone();


// Duy Trường - return Point2D
Point2D p1(1, 2);
Point2D p2 = p1.f1(1000);

Point2D Point2D::f1(int x){
	Point2D ans(3, 4);
	return ans;

}

// Duy Trường - return Point2D&
Point2D p1(1, 2);
Point2D p2 = p1.f2(1000);

Point2D& Point2D::f2(int x){
	Point2D ans(3, 4);
	return ans;

	// return *this;
}















