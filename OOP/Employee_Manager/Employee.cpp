#include<iostream>
#pragma once
using namespace std;

class Employee{
private:
    string name;
    int salary;

public:
    Employee(string name, int salary) {
        this->name   = name;
        this->salary = salary;
    }

    void setSalary(int salary) {
        this->salary = salary;
    }

    int Salary()
    {
        return salary;
    }
    
    void display()
    {
        cout << "Name: "   << name << endl;
        cout << "Salary: " << salary << endl;
    }
};