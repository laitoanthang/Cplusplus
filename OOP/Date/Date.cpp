#include<iostream>
#include<string>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;

public: Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

	  void setDate(int day, int month, int year) {
		  this->day = day;
		  this->month = month;
		  this->year = year;
	  }

	  int getDay() {
		  return day;
	  }

	  void setDay(int day) {
		  this->day = day;
	  }

	  int getMonth() {
		  return month;
	  }

	  void setMonth(int month) {
		  this->month = month;
	  }

	  int getYear() {
		  return year;
	  }

	  void setYear(int year) {
		  this->year = year;
	  }

	  void display() {
		  string day = to_string(this->day);
		  string month = to_string(this->month);
		  string year = to_string(this->year);
		  if (day.length() == 1) {
			  day = "0" + day;
		  }
		  if (month.length() == 1) {
			  month = "0" + month;
		  }
		  cout << day + "/" + month + "/" + year << endl;
	  }
};

int main() {
	Date d(1, 1, 1997);
	d.display();
	d.setDate(12, 12, 2004);
	d.display();
	d.setMonth(3);
	d.display();	
	return 0;
}