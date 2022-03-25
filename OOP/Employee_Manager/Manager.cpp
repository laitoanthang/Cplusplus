#include"Employee.cpp"
using namespace std;


class Manager:public Employee{
private:
    int bonus;

public:
    Manager(string name, int salary, int bonus):Employee(name, salary)
    {
        this->bonus = bonus;
    }

    int getSalary() {
        return Employee::Salary() + bonus;
    }

    void display()                    
    {                                   
        int sala = getSalary();
        Employee::setSalary(sala);
        Employee::display();
        // Employee::display(); 
        // cout << "Bonus: "       <<       bonus      << endl;
        // cout << "After bonus: " << Salary() + bonus << endl;
    }
};