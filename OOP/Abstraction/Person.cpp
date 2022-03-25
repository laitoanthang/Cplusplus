#pragma once
#include<iostream>

using namespace std;

class Person {
private:
	string name;
	string address;

public:
	Person(string name, string address) {
		this->name = name;
		this->address = address;
	}

	virtual void display() = 0;

	string getName() {
		return name;
	}

	void setName(string name) {
		this->name = name;
	}

	string getAddress() {
		return address;
	}

	void setAddress(string address) {
		this->address = address;
	}
};