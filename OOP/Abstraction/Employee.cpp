#include "Person.cpp"

class Employee : public Person {
private:
	int salary;

public:
	Employee(string name, string address, int salary) :Person(name, address) {
		this->salary = salary;
	}

	void display() {
		cout << "Employee name: " << Person::getName() << endl;
		cout << "Employee address: " << Person::getAddress() << endl;
		cout << "Employee salary: " << salary << endl;
	}
};